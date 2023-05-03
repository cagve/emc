function send_formula(){
	var formula = document.getElementById('formula').value;
	$.get("/check",
		{
			formula: formula,
		},
		function (data, status) {
			console.log(data)
			const myArray = data.formula.input.split(":");
			let word = myArray[0];
			if (data.error){
				console.log(data.error)
				return data.formula.input
			}
			$("#text-output").html("");
			$("#text-output").append("<p>The formula "+formula+" is "+data.model_result+" in the model</p>");
			for (const [key, value] of Object.entries(data.worlds_check)) {
				if (data.type == 'know'){ // EXPLANA
					if(data.acc_worlds[key].length === 0){ // FINAL WORLD
						$("#text-output").append("<p>The formula "+formula+" is "+value[0]+" in "+ key+" because there is no accesible world for agent "+data.agent+"</p>");
					}else if(value[0] == true){ //Ka p is True 
						$("#text-output").append("<p>The formula "+formula+" is "+value[0]+" in "+ key+" because agent "+data.agent+" accesses "+data.acc_worlds[key]+" and " + data.terms+" is true in these/those worlds</p>");
					}else{ //Ka p is false
						$("#text-output").append("<p>The formula "+formula+" is "+value[0]+" in "+ key+" because agent "+data.agent+" accesses "+value[1]+" and " + data.terms+" is false in this world</p>");
					}
				}
				else if(data.type == "pos"){
					if(data.acc_worlds[key].length === 0){ // FINAL WORLD
						$("#text-output").append("<p>The formula "+formula+" is "+value[0]+" in "+ key+" because there is no accesible world for agent "+data.agent+"</p>");
					}else if (value[0] == true){
						$("#text-output").append("<p>The formula "+formula+" is "+value[0]+" in "+ key+" because agent "+data.agent+" accesses "+value[1]+" and " + data.terms+" is true in this world</p>");					
					}else{
						$("#text-output").append("<p>The formula "+formula+" is "+value[0]+" in "+ key+" because agent "+data.agent+" accesses "+data.acc_worlds[key]+" and " + data.terms+" is false in these/those worlds</p>");					}
				} else{
					$("#text-output").append("<p>The formula "+formula+" is "+value[0]+" in "+ key+"</p>");
				}
			}


			$('#buttons').html("")
			const formulas = []
			Object.entries(data.graphs).forEach(element => formulas.push(element));
			for(var i=0; i < formulas.length;i++){
				if (i == formulas.length-1){
					const value = formulas[i][1];
					const str = JSON.stringify(value)
					console.log(str)
					$('#buttons').append("<button class='tablinks' onclick='return overwrite("+str+")'>"+i+"</button>")
					break;
				}
				const next = i+1;
				const token = tokenize(formulas[i][0]);
				const next_token = tokenize(formulas[next][0]);
				if (token.length == next_token.length){
					continue
				}else if (i == 1){
					const value = formulas[i][1];
					const str = JSON.stringify(value)
					$('#buttons').append("<button class='tablinks' onclick='return overwrite("+str+")'>Model</button>")
				}else{
					const value = formulas[i][1];
					const str = JSON.stringify(value)
					$('#buttons').append("<button class='tablinks' onclick='return overwrite("+str+")'>"+i+"</button>")
				}
			}
		});
}

function upload_file(){
	let formData = new FormData(); 
	formData.append("modelfile", modelfile.files[0]);
	$.ajax({
		url: "/upload",
		type: "POST",
		data: formData,
		processData: false,  // tell jQuery not to process the data
		contentType: false,   // tell jQuery not to set contentType
		success: function(data){
			console.log(data[0].graph);
			// $('#tabspane').append('<div class="tabcontent" id="0"></div>')
			$('#buttons').append("<button class='tablinks' onclick='return overwrite("+data[0].graph+")'>Model</button>")
			create_graph();
			overwrite(data[0].graph);
		}

	});
}

function create_graph(){
	let cy = cytoscape({
		container: document.getElementById('cy'),
		elements: [{data: { id: 'n1'}}],
		style: [
			{selector: '.valuation', style: { 'background-color':'red', 'text-valign':'center', 'text-halign':'center', 'content': 'data(name)'} },
			{selector: '.world', style: { 'background-color':'red', 'label':'data(id)' }},
			{selector: '.relation', style: {'target-arrow-shape': 'triangle', 'label': 'data(name)' }}
		]

	});
}

function overwrite(graph){
	const cy = document.getElementById('cy')._cyreg.cy
	var collection = cy.elements('node');
	cy.remove(collection)
	cy.add(graph);
	var layout = cy.layout({
		name: 'random'
	});
	layout.run();
	cy.fit();
}


function tokenize(formula){
	return formula.replace("-","0")
		.replace("&&","1")
		.replace("||","2")
		.replace("=>","3")
		.replace("Ka","4")
		.replace("Kb","5")
		.replace("Kc","6")
		.replace("Kd","7");
}

function showGraph(evt, graphName) {
	console.log(graphName)
	var i, tabcontent, tablinks;
	tabcontent = document.getElementsByClassName("tabcontent");
	for (i = 0; i < tabcontent.length; i++) {
		tabcontent[i].style.display = "none";
		  }
	  tablinks = document.getElementsByClassName("tablinks");
	  for (i = 0; i < tablinks.length; i++) {
		tablinks[i].className = tablinks[i].className.replace(" active", "");
	}
	  document.getElementById(graphName).style.display = "block";
	  evt.currentTarget.className += " active";
}

function replace(){
	$(document).ready(function(){
		$("#formula").on("input", function(){
			var formula = $(this).val().replace('&&','∧').replace('||', '∨').replace('=>','→').replace('-','¬')
			$("#result").text(formula);
			$("#formula").val(formula);
		});
	});
}


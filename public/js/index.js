function setup(){
	$(document).keyup(function(event) {
		if ($("#formula").is(":focus") && event.key == "Enter") {
			$("#run-button").trigger('click');
		}
	});
}

function send_formula(){
	var formula = document.getElementById('formula').value;
	$.get("/check",
		{
			formula: formula,
		},
		function (data, status) {
			console.log(data);
			if (data.error){
				alert(data.msg);
				return;
			}else if($('#cy').is(':empty')){
				alert("Model not found");
				return;
			}else if(!$('#formula').val()){
				alert("Formula not found");
				return;
			}
			const myArray = data.formula.input.split(":");
			let word = myArray[0];
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


			$('#tabs').html("")
			const formulas = []
			Object.entries(data.graphs).forEach(element => formulas.push(element));
			for(var i=0; i < formulas.length;i++){
				if (i == formulas.length-1){
					const value = formulas[i][1];
					const str = JSON.stringify(value)
					$('#tabs').append("<input id='"+i+"' class='radio' name='group' type='radio' onclick='return overwrite("+str+")' checked><label class='tab' for='"+i+"'>"+i+"</label>");
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
					$('#tabs').append("<input id='model' class='radio' name='group' type='radio' onclick='return overwrite("+str+")' checked><label class='tab' for='model'>Model</label>");
				}else{
					const value = formulas[i][1];
					const str = JSON.stringify(value)
					$('#tabs').append("<input id='"+i+"' class='radio' name='group' type='radio' onclick='return overwrite("+str+")' checked><label class='tab' for='"+i+"'>"+i+"</label>");
				}
			}
			$("#model").prop("checked", true);
		});

}

function upload_file(){
	let formData = new FormData(); 
	formData.append("modelfile", file.files[0]);
	$.ajax({
		url: "/upload",
		type: "POST",
		data: formData,
		processData: false,  // tell jQuery not to process the data
		contentType: false,   // tell jQuery not to set contentType
		success: function(data){
			console.log(data);
			$("#tabs").empty();
			$('#tabs').append("<input id='model' class='radio' name='group' type='radio' onclick='return overwrite("+data[0].graph+")' checked><label class='tab' for='model'>Model</label>");
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
			{selector: '.valuation', style: {"color":"white", "font-family":"bold",  'background-color':'#183153', 'text-valign':'center', 'text-halign':'center', 'content': 'data(name)'} },
			{selector: '.world', style: { 'background-color':'#183153',  'label':'data(id)', "text-background-opacity": 0.7, "color": "#183153", "text-background-color": "white"}},
			{selector: '.relation', style: {'target-arrow-shape': 'triangle', 'arrow-scale':'2', 'label': 'data(name)', "text-background-opacity": 1, "color": "#183153", "text-background-color": "white" }}
		]

	});
}

function overwrite(graph){
	const cy = document.getElementById('cy')._cyreg.cy
	var collection = cy.elements('node');
	cy.remove(collection)
	cy.add(graph);
	var layout = cy.layout({
		name: 'circle',
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

function keyboard(key, type){
	var key = key.replace('∧','&&').replace('∨','||', ).replace('→','=>').replace('¬','-',)
	value = $('#formula').val();
	switch (type){
		case '0':
			$(".type0").css('background', 'white');
			$(".type1").css('background', 'white');
			$(".type2").css('background', '#ffd43b');
			$(".type3").css('background', 'white');
			$(".type4").css('background', 'white');
			break;
		case '1':
			$(".type0").css('background', '#ffd43b');
			$(".type1").css('background', '#ffd43b');
			$(".type2").css('background', 'white');
			$(".type3").css('background', '#ffd43b');
			$(".type4").css('background', 'white');
			break;
		case '2':
			$(".type0").css('background', '#ffd43b');
			$(".type1").css('background', '#ffd43b');
			$(".type2").css('background', 'white');
			$(".type3").css('background', '#ffd43b');
			$(".type4").css('background', 'white');
			break;
		case '3':
			$(".type0").css('background', 'white');
			$(".type1").css('background', 'white');
			$(".type2").css('background', 'white');
			$(".type3").css('background', 'white');
			$(".type4").css('background', '#ffd43b');
			break;
		case '4':
			$(".type0").css('background', '#ffd43b');
			$(".type1").css('background', '#ffd43b');
			$(".type2").css('background', 'white');
			$(".type3").css('background', '#ffd43b');
			$(".type4").css('background', 'white');
			break;
		default:
			$(".type1").css('background', 'white');
			$(".type2").css('background', 'white');
			$(".type3").css('background', 'white');
			$(".type4").css('background', 'white');
			break;
	}

	switch (key){
		case "clear":
			$('#formula').val('');
			break;
		case "space":
			value += " ";
			$('#formula').val(value);
			break;
		case "return":
			$("#run-button").trigger('click');
			break;
		case "remove":
			$('#formula').val(value.substr(0, value.length - 1));
			break;
		case "right":
		case "left":
			break
		default:
			value += key;
			$('#formula').val(value);
			break;
	}
}

function toggleKeyboard() {
	if($("#keyboard-checkbox").is(":checked")){
		$(".base").show();
	}
	else{
		$(".base").hide();
	}
}




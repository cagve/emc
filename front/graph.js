function display_text_output(){
	var xhttp = new XMLHttpRequest(); 
	xhttp.onreadystatechange = function() { 
		if (this.readyState == 4 && this.status == 200) { 
			document.getElementById("text-output").innerHTML = this.responseText; 
		} 
	}; 
	xhttp.open("GET", "http://localhost:3000/check", true); 
	xhttp.send(); 
}

function hello(){
	let cy = cytoscape({
		container: document.getElementById('cy'),
		elements:[
			{data: {id:'w1'}, classes:['world']},
			{data: {id:'w2'}, classes:['world']},
			{data: {id:'w3'}, classes:['world']},
		],
	});
}
	

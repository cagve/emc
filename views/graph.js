function hello(){
	let file = "./"
	var rawFile = new XMLHttpRequest();
	rawFile.open("GET", file, false);
	rawFile.onreadystatechange = function ()
	{
		if(rawFile.readyState === 4)
		{
			if(rawFile.status === 200 || rawFile.status == 0)
			{
				var allText = rawFile.responseText;
				alert(allText);
			}
		}
	}
	rawFile.send(null);
	let cy = cytoscape({



		container: document.getElementById('cy'), elements:[{data: {id:'w1'}, classes:['world']},
			{data: {id:'w2'}, classes:['world']},
			{data: {id:'w3'}, classes:['world']},
		],
		style: [
			{selector: '.valuation', style: { 'background-color':'red', 'text-valign':'center', 'text-halign':'center', 'content': 'data(id)'} },
			{selector: '.world', style: { 'background-color':'red', 'label':'data(id)' }}]
	});
}
	



console.log("HELLO");

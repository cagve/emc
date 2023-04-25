function main() {
	parser.setLanguage(JavaScript);
	console.log("HELLO");
}

function print_text_output(text){
	var element = document.createElement("p");
	var output_area = document.getElementById("text-output");

	output_area.innerHTML = " ";
	element.innerHTML = text;
    document.getElementById('text-output').appendChild(element);
}

const express = require("express");
var fs = require('fs');
const app = express();
const file_upload = require('express-fileupload')
const ts = require('./src/treesitter')
const {World, Relation, Model} = require('./src/model')
const Formula = require('./src/formula')
const path = require("path");
var model;
  

app.use(file_upload())


// Setting path for public directory 
const static_path = path.join(__dirname, "public");
app.use(express.static(static_path));
app.use(express.urlencoded({ extended: true }));

app.get("/check", (req, res) => {
	var agent = "";
	const formula = new Formula(req.query.formula);
	if (formula.type() == "know"){
		agent = formula.agent();
	}
	const worlds = model.worldset

	let response = {
		formula:formula.tree,
		model_result: null,
		worlds_check: { },
		syntax_error:false,
		acc_worlds: { },
		agent: agent,
		terms: formula.term_string(),
		type: formula.type(),
		graph: model.output(),
		graphs: { }
	}

	for(k=0; k<formula.subformulas().length; k++){
		const cloned_model = model;
		const subformula= formula.subformulas()[k];
		cloned_model.model_checking(subformula);
		response.graphs[subformula.formula] = cloned_model.output();
	}

	response.model_result = model.model_checking(formula);
	if (!ts.parse_formula(formula.formula)) {
		response.error = true
	}
	for(i=0; i<worlds.length; i++){
		const world_name= worlds[i].name
		const world_model = model.get_world(world_name)
		var world_check = model.world_check(world_model, formula);
		response.worlds_check[world_name] = world_check ;
	}
	for(j=0; j<worlds.length; j++){
		const world_name= worlds[j].name
		const world_model = model.get_world(world_name)
		response.acc_worlds[world_name] = model.get_acc_from_world(world_model,agent).map(element => element.name);
	}
	res.json(response);
})

app.post('/upload', function(req, res) {
	let modelFile;
	if (!req.files || Object.keys(req.files).length === 0) {
		return res.status(400).send('No files were uploaded.');
	}
	loadedfile = req.files.modelfile.name

	const file_extension = req.files.modelfile.name.slice(
		((req.files.modelfile.name.lastIndexOf('.') - 1) >>> 0) + 2
	);

	if (file_extension != 'set'){
		return res.status(400).send('No files were uploaded.');
	}


	modelFile = req.files.modelfile;
	modelFile.mv('./public/model.set');

	modeldict = ts.extract_info(modelFile.data.toString());

	const worldset = []
	const relationset = []
	model = new Model(worldset, relationset);
	model.from_dict(modeldict);
	const graph = model.output();
	   res.json([{
		      	filename: modelFile,
				graph:graph,
		   }])
});


// app.listen(3000, () => {
// 	console.log("Application started and Listening on port 3000");
// });


const w0 = new World('w0');
const w1 = new World('w1');
const w2 = new World('w2');
const w3 = new World('w3');
const w4 = new World('w4');
const w5 = new World('w5');

const r1 = new Relation('a', w0, w1);
const r2 = new Relation('d', w2, w3);
const r3 = new Relation('b', w3, w5);
const r4 = new Relation('c', w1, w2);
const r5 = new Relation('a', w2, w4);
const r6 = new Relation('b', w4, w4);

const worldset = [w0,w1,w2,w3,w4,w5];
const relationset = [r1,r2,r3,r4,r5,r6];
const nmodel = new Model(worldset, relationset);
nmodel.group_relation(['a','c']);


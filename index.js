const express = require("express");
var fs = require('fs');
const app = express();
const file_upload = require('express-fileupload')
const ts = require('./src/treesitter')
const {World, Relation, Model} = require('./src/model')
const Formula = require('./src/formula')
const path = require("path");
  

app.use(file_upload())


// Setting path for public directory 
const static_path = path.join(__dirname, "public");
app.use(express.static(static_path));
app.use(express.urlencoded({ extended: true }));

app.get("/check", (req, res) => {
	if (!ts.parse_formula(req.query.formula)[0]){
		const errormsg =  ts.parse_formula(req.query.formula)[1];
		res.json({error:true, msg:"Syntax error in "+errormsg});
	}else if(!fs.existsSync('/tmp/model.set')){
		res.json({error:true, msg:"Model not found"});
	} else{
		const model = initialize_model()
		var agent = "";
		var formula = new Formula(req.query.formula);
		if (formula.type() == "parenthesis"){
			const root = formula.tree.rootNode;
			const children = root.namedChildren;
			formula = new Formula(children[0].text)
		}
		if (formula.type() == "know" || formula.type() == "pos" || formula.type() == "common"){
			agent = formula.agent();
		}

		if (formula.type() == "common"){
			agents = formula.agent();
			console.log("The agents are" + agents)
		}

		const worlds = model.worldset

		let response = {
			formula:formula.tree,
			error: false,
			model_result: null,
			worlds_check: { },
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
			if (agent.length == 1){
				response.acc_worlds[world_name] = model.get_acc_from_world(world_model,agent).map(element => element.name);
			}else{
				var acc_worlds = []
				for (var w = 0; w<agent.length;w++){
					acc_worlds.push(model.get_acc_from_world(world_model,agent[w]).map(element => element.name));
				}
				response.acc_worlds[world_name] = [...new Set(acc_worlds.flat(1))];
			}
		}
		res.json(response);
	}
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
	modelFile.mv('/tmp/model.set');

	modeldict = ts.extract_info(modelFile.data.toString());

	const worldset = []
	const relationset = []
	const model = new Model(worldset, relationset);
	model.from_dict(modeldict);
	const graph = model.output();
	   res.json([{
		      	filename: modelFile,
				graph:graph,
		   }])
});

function initialize_model(){
	var text = fs.readFileSync("/tmp/model.set").toString('utf8');
	const modeldict = ts.extract_info(text);
	const worldset = [];
	const relationset = [];
	const model = new Model(worldset, relationset);
	model.from_dict(modeldict)
	return model;
}

app.listen(3000, () => {
	console.log("Application started and Listening on port 3000");
});

//
// const w0 = new World('w0');
// const w1 = new World('w1');
// const w2 = new World('w2');
// const w3 = new World('w3');
// const w4 = new World('w4');
// const w5 = new World('w5');
//
// const ra0 = new Relation('a', w0, w0);
// const ra1 = new Relation('a', w1, w1);
// const ra2 = new Relation('a', w2, w2);
// const ra3 = new Relation('a', w3, w3);
// const ra4 = new Relation('a', w4, w4);
// const ra5 = new Relation('a', w5, w5);
//
// const rb0 = new Relation('b', w0, w0);
// const rb1 = new Relation('b', w1, w1);
// const rb2 = new Relation('b', w2, w2);
// const rb3 = new Relation('b', w3, w3);
// const rb4 = new Relation('b', w4, w4);
// const rb5 = new Relation('b', w5, w5);
//
// const rc0 = new Relation('c', w0, w0);
// const rc1 = new Relation('c', w1, w1);
// const rc2 = new Relation('c', w2, w2);
// const rc3 = new Relation('c', w3, w3);
// const rc4 = new Relation('c', w4, w4);
// const rc5 = new Relation('c', w5, w5);
//
// const r1 = new Relation('a', w0, w1);
// const r2 = new Relation('a', w1, w0);
//
// const r3 = new Relation('c', w1, w2);
// const r4 = new Relation('c', w2, w1);
//
// const r5 = new Relation('a', w1, w3);
// const r6 = new Relation('a', w3, w1);
//
// const r7 = new Relation('a', w0, w3);
// const r8 = new Relation('a', w3, w0);
// const r9 = new Relation('b', w0, w3);
// const r10 = new Relation('b', w3, w0);
//
// const r11 = new Relation('c', w0, w4);
// const r12 = new Relation('c', w4, w0);
//
// const r13 = new Relation('a', w5, w4);
// const r14 = new Relation('a', w4, w5);
// const r15 = new Relation('b', w5, w4);
// const r16 = new Relation('b', w4, w5);
//
// const p = new Formula("p")
// const q = new Formula("q")
// const r = new Formula("r")
//
// w0.add_formula(p)
// w0.add_formula(q)
// w0.add_formula(r)
//
// w1.add_formula(p)
//
// w2.add_formula(r)
//
// w3.add_formula(p)
// w3.add_formula(r)
//
// w4.add_formula(q)
//
// w5.add_formula(p)
// w5.add_formula(q)
//
// const worldset = [w0,w1,w2,w3,w4,w5];
// const relationset = [ ra0, ra1, ra2, ra3, ra4, ra5, rb0, rb1, rb2, rb3, rb4, rb5, rc0, rc1, rc2, rc3, rc4, rc5, r1 , r2 , r3 , r4 , r5 , r6 , r7 , r8 , r9 , r10, r11, r12, r13, r14, r15, r16];
//
//
// // const f = new Formula("C{ab}r && -Kcr")
// const f = new Formula("Map")
//
// const nmodel = new Model(worldset, relationset);
//
// console.log(nmodel.world_check(w0,f))


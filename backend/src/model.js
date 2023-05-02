const Formula = require('./formula');

class World {
	constructor(name, formulas=[]){
		this.name = name;	
		this.formulas = formulas;	
	}

	string_formulas(){
		const str_formulas = this.formulas.map( x => x.formula);
		return str_formulas;
	}

	contains_formula(formula){
		for(var i=0;i<this.formulas.length;i++){
			if(formula.formula == this.formulas[i].formula){
				return true
			}
		}
		return false;
	}

	add_formula(formula){
		if (!this.contains_formula(formula)){
			this.formulas.push(formula)
		}
	}

	equal(world){
		if (world.name == this.name){
			return true
		}
		return false
	}

	
}

class Relation {
	constructor(agent, world1,world2){
		this.agent=agent;
		this.world1=world1;
		this.world2=world2;
	}
	
	get_name(){
		return this.agent+this.world1.name+this.world2.name;
	}

	get_pair(){
		return [this.world1, this.world2];
	}

}

class Model {
	constructor(worldset, relationset){
		this.worldset=worldset;
		this.relationset=relationset;
	}

	contains_world(world){
		for(var i=0;i<this.worldset.length;i++){
			if(world.name == this.worldset[i].name){
				return true;
			}
		}
		return false;
	}

	worldset_to_string(){
		return this.worldset.map(element => element.name);
	}

	add_world(world){
		if (!this.contains_world(world)){
			this.worldset.push(world)
		}
	}

	contains_relation(relation){
		for(var i=0;i<this.relationset.length;i++){
			if(relation.get_name() == this.relationset[i].get_name()){
				return true;
			}
		}
		return false;
	}

	get_world(name){
		for(let i=0; i<this.worldset.length;i++){
			if(this.worldset[i].name==name){
				return this.worldset[i]
			}
		}
	}

	add_relation(relation){
		if (!this.contains_relation(relation)){
			this.relationset.push(relation)
		}
	}

	get_acc_relations_of_agent(agent){
		var agent_acc_set = this.relationset.filter(x => x.agent==agent);
		return agent_acc_set;
	}

	get_acc_from_world(world,agent){
		var agent_acc_set = this.get_acc_relations_of_agent(agent);
		var acc_set = agent_acc_set.filter(x => x.world1.name == world.name);
		var acc_world = acc_set.map(x => x.world2);
		return acc_world;
	}

	world_check(world, formula){
		const subformulas_set = formula.subformulas();
		var counterexample;
		for(var i=0;i<subformulas_set.length;i++){
			const curr_formula = subformulas_set[i];
			const terms = curr_formula.terms();
			const type = curr_formula.type();
			switch(type){
				case "atom": 
					if (world.contains_formula(curr_formula)){
					}
					break;
				case "not": 
					if (!world.contains_formula(terms[0])){
						world.add_formula(curr_formula);
					}
					break;
				case "and": 
					if (world.contains_formula(terms[0]) && world.contains_formula(terms[1])){
						world.add_formula(curr_formula);
					}
					break;
				case "or":
					if (world.contains_formula(terms[0]) || world.contains_formula(terms[1])){
						world.add_formula(curr_formula);
					}
					break;
				case "iff":
					if (!world.contains_formula(terms[0]) || world.contains_formula(terms[1])){
						world.add_formula(curr_formula);
					}
					break;
				case "know":
					const agent = curr_formula.agent();
					const acc_worlds = this.get_acc_from_world(world,agent);
					let flag = true;
					if (acc_worlds.length == 0) { //Final world
						world.add_formula(curr_formula);
					}else{
						for(var j = 0; j<acc_worlds.length; j++){
							const curr_acc_world = acc_worlds[j];
							this.world_check(curr_acc_world,terms[0]);
							if(!curr_acc_world.contains_formula(terms[0])){
								flag = false;
								counterexample = curr_acc_world.name;
								break;
							}
						}
						if (flag){
							world.add_formula(curr_formula);
						}
					}
					break;
				default:
			}
		}
		if(world.contains_formula(formula)){
			return true;
		}else{
			return [false, counterexample];
		}
	}

	model_checking(formula){
		for (var i=0;i<this.worldset.length;i++){
			const curr_world = this.worldset[i];
			if(!this.world_check(curr_world, formula)){
				return false;
			}
		}
		return true;
	}

	from_dict(model_dictionary){
		const worldset = model_dictionary.worldset;
		const valuationset = model_dictionary.valuationset;
		const relationset = model_dictionary.relationset;

		worldset.forEach(element => {
			const world = new World(element);
			valuationset.forEach( valuationstatement =>{
				const atom = valuationstatement.atom;
				const formula = new Formula(atom)
				const worlds = valuationstatement.worlds;
				if(worlds.includes(element)){
					world.add_formula(formula);
				}
			})
			this.add_world(world);
		});

		relationset.forEach(element => {
			const world1 = this.get_world(element.world1);
			const world2 = this.get_world(element.world2);
			const relation = new Relation(element.agent, world1, world2)
			this.add_relation(relation);
		});
	}

	output(){
		let output = []
		for(var i = 0; i<this.worldset.length; i++){
			const curr_world = this.worldset[i];
			var world_data = {
				data: {
					id: curr_world.name,
				},
				classes:['world']
			}
			output.push(world_data);
			if(curr_world.formulas != ''){
				var relation_data = {
					data: {
						id: curr_world.name+curr_world.string_formulas().toString(),
						parent: curr_world.name,
						name: curr_world.string_formulas().toString(), 
					},
					classes:['valuation']
				}
				output.push(relation_data)
			}
		}
		for(var i = 0; i<this.relationset.length; i++){
			const curr_relation = this.relationset[i];
			var relation_data = {
				data: {
					id: curr_relation.get_name(),
					source: curr_relation.world1.name,
					target: curr_relation.world2.name,
					name: curr_relation.agent
				},
				classes:['relation']
			}
			output.push(relation_data);
		}


		return output;
	}

	group_relation(agents){
		var rel_group = [];
		agents.forEach(element => rel_group.push(this.get_acc_relations_of_agent(element)));
		rel_group = rel_group.flat(1);
		const matrix = [] //MATRIX OF RELATIONS
		// <w1,w0><w2,w1>,<w0,w1>
		//	   w0 w1  w2
		// w0: 0   1  0	
		// w1: 1   0  0	
		// w2: 0   1  0	
		// Rows : FIRST WORLD
		// COLUMNS: SECOND ROW
		for (var i = 0;i< this.worldset.length; i++){//iterate over set of worlds to get first world
			const first_world = this.worldset[i];
			const row = [];
			for (var j = 0; j<this.worldset.length; j++){  //iterate over set of worlds to get second word
				const second_world = this.worldset[j];
				var agent_worlds = []
				agents.forEach(agent => agent_worlds.push(this.get_acc_from_world(first_world, agent)));
				agent_worlds = agent_worlds.flat(1);
				for (var z = 0; z<agent_worlds.length; z++){ //iterate over acc worlds from first world
					var exists_relation = 0
					if (second_world.equal(agent_worlds[z])){
						console.log('relation' + first_world.name +"-"+second_world.name);
						exists_relation = 1
						break;
					}
				}
				row.push(exists_relation)
			}
			matrix.push(row)
		}

		const closure = matrix.map(row => [...row])
		for (var k = 0;k< this.worldset.length; k++){
			for (var i = 0;i< this.worldset.length; i++){
				for (var j = 0;j< this.worldset.length; j++){
					if(closure[i][j]!=0 || (closure[i][k]!=0 && closure[k][j]!=0)){
						closure[i][j] = 1
					}else{
						closure[i][j] = 0
					}
				}
			}
		}

		const new_relations = []
		for (var i = 0;i< this.worldset.length; i++){
			for (var j = 0;j< this.worldset.length; j++){
				if(closure[i][j] == 1){
					const rel = [this.worldset[i].name, this.worldset[j].name]
					new_relations.push(rel)
				}
			}
		}

		console.log(new_relations);

	}

	

	print2darray(array){
		var text = '';
		for (var i = 0; i<array.length; i++){
			for (var j=0; j<array[i].length; j++){
				text = text + array[i][j];
			}
			console.log(text);
			text = ''
		}
	}
}


module.exports = {Relation, World, Model } // 👈 Export class

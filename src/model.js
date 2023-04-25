
class World {
	constructor(name, formulas=[]){
		this.name = name;	
		this.formulas = formulas;	
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
			return false;
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
}


module.exports = {Relation, World, Model } // 👈 Export class

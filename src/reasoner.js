const formula = require('./formula');

function model_check(model, world, formula){
	formula.subformulas().then((subformulas_set) => {
		for(var i=0;i<subformulas_set.length();i+p){
			console.log(subformulas_set[i]);

		}
	});

}


module.exports = {model_check} // 👈 Export class

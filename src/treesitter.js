const Parser = require('tree-sitter');
const Ep = require('../tree-sitter-ep/build/Release/tree_sitter_ep_binding.node');
const Set = require('../tree-sitter-set/build/Release/tree_sitter_set_binding.node')
const {Query, QueryCursor} = Parser
const parser = new Parser();

function parse_formula(formula){
	parser.setLanguage(Ep);
	const tree = parser.parse(formula)
	const query = new Query(Ep, "(ERROR) @error");
	const matches = query.matches(tree.rootNode);
	if (matches.length!=0){
		const errors = [];
		for (i=0; i<matches.length; i++) {
			var cap = matches[i].captures;
			cap.forEach(element => errors.push(element.node.startPosition.column));
		}
		// throw new Error('Invalid formula. Error at position: '+errors);
		return "Error: Syntax error at position: "+errors
	}else{
		return formula;
	}
}

function extract_info(file_string){
	parser.setLanguage(Set);
	const tree = parser.parse(file_string)
	let query = new Query(Set, "(statement (worldset(world) @world))");
	let matches = query.matches(tree.rootNode);
	let worlds = []
	for (i=0; i<matches.length; i++) {
		var cap = matches[i].captures;
		cap.forEach(element => worlds.push(element.node.text));
	}

	query = new Query(Set, "(statement (relationset) @relationset)");
	matches = query.matches(tree.rootNode);
	let relations = []
	for (j=0; j<matches.length; j++) {
		var cap = matches[j].captures;
		cap.forEach(element => {
			const agent = element.node.child(1).text;
			const tree_str = parser.parse(element.node.text);
			r_query = new Query(Set, "(statement (relationset(relation) @relation))");
			r_matches = r_query.matches(tree_str.rootNode);
			for (w=0; w<r_matches.length; w++) {
				var relationcap = r_matches[w].captures;
				relationcap.forEach(element => {
					let relation = {
						"agent":agent,
						"world1":element.node.child(1).text,
						"world2":element.node.child(3).text
					}
					relations.push(relation);
				})
			}
		});
	}
	query = new Query(Set, "(statement (valuationset) @valuation)");
	matches = query.matches(tree.rootNode);
	let valuations = [];
	for (k=0; k<matches.length; k++) {
		var caps = matches[k].captures;
		caps.forEach(element => { 
			const atom = element.node.child(1).text;
			const worlds = get_worlds_from_valuation(element.node.text) 
			const valuation = {
				'atom':atom,
				'worlds':worlds
			}
			valuations.push(valuation)
		});
	}

	return {
		'worldset':worlds,
		'relationset':relations,
		'valuationset':valuations
	}

}

function get_worlds_from_valuation(valuation){
	parser.setLanguage(Set);
	const tree = parser.parse(valuation)
	const query = new Query(Set, "(world) @world");
	var worlds  = []
	const matches = query.matches(tree.rootNode);
	for (i=0; i<matches.length; i++) {
		var cap = matches[i].captures;
		cap.forEach(element => worlds.push(element.node.text));
	}
	return worlds;
}

module.exports = { extract_info, parse_formula } // 👈 Export function


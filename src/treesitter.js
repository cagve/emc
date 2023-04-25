const Parser = require('tree-sitter');
const Ep = require('../tree-sitter-ep/build/Release/tree_sitter_ep_binding.node');
const {Query, QueryCursor} = Parser
const parser = new Parser();
parser.setLanguage(Ep);

function parse_formula(formula){
	const tree = parser.parse(formula)
	const query = new Query(Ep, "(ERROR) @error");
	const matches = query.matches(tree.rootNode);
	if (matches.length!=0){
		const errors = [];
		for (i=0; i<matches.length; i++) {
			var cap = matches[i].captures;
			cap.forEach(element => errors.push(element.node.startPosition.column));
		}
		throw new Error('Invalid formula. Error at position: '+errors);
	}else{
		return formula;
	}
}

module.exports = { parse_formula } // 👈 Export function


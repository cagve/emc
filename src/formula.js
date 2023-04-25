const ts = require('./treesitter');
const Parser = require('tree-sitter');
const Ep = require('../tree-sitter-ep/build/Release/tree_sitter_ep_binding.node');
const parser = new Parser();
const {Query, QueryCursor} = Parser
parser.setLanguage(Ep);

class Formula {
	constructor(formula) {
		this.formula = ts.parse_formula(formula);	
		this.tree = parser.parse(this.formula);
	}

	get_tree() {
		ts.get_tree(this.formula);
	}

	type(){
		const root = this.tree.rootNode;
		const childrens = root.namedChildren;
		switch (childrens.length){
			case 3: return childrens[1].type;
			case 2: return childrens[0].type;
			default: return "atom"
		}
	}

	length(){
		return this.formula.lenght
	}

	terms(){
		let terms = [];
		switch(this.type()) {
			case "atom": 
				terms.push(this);
				break;

			case "know":
			case "not":
				const term = this.tree.rootNode.namedChildren[1].text;
				terms.push(new Formula(term));
				break;
			default:
				const term1 = this.tree.rootNode.namedChildren[0].text;
				const term2 = this.tree.rootNode.namedChildren[2].text;
				terms.push(new Formula(term1));
				terms.push(new Formula(term2));
				break;
		}
		return terms
	}

	subformulas(){
		const tree = this.tree;
		const query = new Query(Ep,`
			(formula
				operator:(or))@or_formula
			(formula
				operator:(and))@and_formula
			(formula
				operator:(iff))@iff_formula
			(formula
				operator:(know))@know_formula
			(formula
				operator:(eq))@eq_formula
			(formula
				operator:(not))@not_formula
			(atom) @atom_formula
			`);
		const match = query.matches(tree.rootNode);
		const subformulas = [];
		for (var i = 0; i < match.length; i++) {
			var cap = match[i].captures;
			cap.forEach(element => subformulas.push(new Formula(element.node.text)));
		}
		return subformulas.sort(function(a, b){ return a.formula.length - b.formula.length; });
	}

	agent(){
		if (this.type()!="know" || this.type() == "pos"){
			throw new Error('Invalid formula. You can not get agent for '+ this.type() + ' formula');
		}
		const agent = this.tree.rootNode.firstChild.children[1].text 
		return agent
	}
	 
}


module.exports = Formula // 👈 Export class


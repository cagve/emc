const ts = require('./treesitter');
const Parser = require('tree-sitter');
const Ep = require('../tree-sitter-ep/build/Release/tree_sitter_ep_binding.node');
const parser = new Parser();
const {Query, QueryCursor} = Parser
parser.setLanguage(Ep);

class Formula {
	constructor(formula) {
		this.formula = formula;	
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
			case "pos":
			case "common":
			case "not":
				var term = this.tree.rootNode.namedChildren[1].text
				if (term[0] =="("){
				term = term.slice(1,term.length-1);
				}
				terms.push(new Formula(term));
				break;
			default:
				var term1 = this.tree.rootNode.namedChildren[0].text;
				var term2 = this.tree.rootNode.namedChildren[2].text;
				if (term1[0] =="("){
				term1 = term1.slice(1,term1.length-1);
				}
				if (term2[0] =="("){
				term2 = term2.slice(1,term2.length-1);
				}
				terms.push(new Formula(term1));
				terms.push(new Formula(term2));
				break;
		}
		return terms
	}

	term_string(){
		var terms = this.terms()
		const str = terms.map(element => element.formula);
		return str;
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
				operator:(common))@common_formula
			(formula
				operator:(know))@know_formula
			(formula
				operator:(pos))@pos_formula
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
		if (this.type()=="common"){
			return this.tree.rootNode.firstChild.namedChildren.map(element => element.text);
		}
		else if (this.type()=="know" || this.type() == "pos"){
			return this.tree.rootNode.firstChild.children[1].text 
		}else{
			throw new Error('Invalid formula. You can not get agent for '+ this.type() + ' formula');
		}
	}
	 
}


module.exports = Formula // 👈 Export class


module.exports = grammar({
	name: 'set',

  rules: {
	statement: $ => repeat(choice(
			$.worldset,
			$.relationset,
			$.valuationset,
			)
	),


	  valuationset: $=> seq(
		  'V(',
			$.atom,
		  ')={',
			  seq(repeat(seq($.world,",")),$.world),
		  '}'),

	  relationset: $=> seq(
		  "R",
		  $.agent,
		  "={",
			  seq(repeat(seq($.relation,",")), $.relation),
		   "}"),

	  worldset: $=> seq(
		  "W={",
			  seq(repeat(seq($.world,",")),$.world),
		   "}"),

	  relation: $=> seq("<",$.world,",",$.world,">"),
	  world: $=> seq("w",$.digit),
	  atom: $=> /[p-z]/,
	  agent: $=> /[a-d]/,
	  digit: $=> choice(
		  /\d/,
		  /\d+/
	  )
  }
});



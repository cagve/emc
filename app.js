var http = require('http'); 
const express = require("express");
const app = express();
const Formula = require('./src/formula');
const Graph = require('./src/graph');
const {World, Relation, Model} = require('./src/model');




app.listen(3000, () => {
  console.log("Application started and Listening on port 3000");
});

app.use(express.static(__dirname+"/public"));
app.use(express.static(__dirname+"/scripts"));
app.use(express.json());
app.use(express.urlencoded({extended:true}));

app.get("/", (req, res) => {
  res.sendFile(__dirname + "/index.html");
});


app.get('/formula', function(req,res){
	//to replace the content:
});


const world1 = new World("w1");
const world2 = new World("w2");
const world3 = new World("w3");
const world4 = new World("w4");

const relation1 = new Relation('a',world1,world2);
const relation2 = new Relation("b",world2,world3);

const model = new Model([world1,world2,world3], [relation1,relation2]);

const formula = new Formula('KaKbs')
console.log(model.model_checking(formula));
// console.log(model.world_check(world2, formula));



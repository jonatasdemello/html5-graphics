// main.js
// import { clamp, pmod, rotateNum, rotate_Num } from './util.js';
//const util = require('./util');
//import * as Util from './util.js';
const util = require('./util');
const wp = require('./wrap');


console.log("------------------------");
console.log("Testing pmod(n, m) = positive remainder");

let div = 3;
for (let i=-5; i<5; i++){
	console.log(`pmod (${div}, ${i}):`, util.pmod(div, i) );
}
console.log("------------------------");

for (let i=-5; i<5; i++){
	console.log(`pmod (${i}, ${div}):`, util.pmod(i, div) );
}

const MIN = 0;
const MAX = 3;

console.log("------------------------");
console.log("Testing rotate_Num(num, max)");

for (let i=-5; i<MAX+10; i++){
	console.log(`rotate_Num (${i}, ${MAX}):`, util.rotate_Num(i, MAX) );
}

console.log("------------------------");
console.log("Testing rotateNum(num, max)");

for (let i=-2; i<7; i++){
	console.log(`rotateNum (${i}, ${MAX}):`, util.rotateNum(i, MAX) );
}

console.log("------------------------");
console.log("Testing clamp(n, min, max)");

for (let i=-2; i<7; i++){
	console.log(`clamp (${i}, ${MIN}, ${MAX}):`, util.clamp(i, MIN, MAX) );
}

console.log("------------------------");
console.log("Testing wrap(n, min, max)");

for (let i=-2; i<7; i++){
	console.log(`wrap (${i}, ${MIN}, ${MAX}):`, wp.wrap(i, MIN, MAX) );
}

console.log("------------------------");
console.log("Testing wrap01_v2(n)");

for (let i=-2; i<7; i += .5){
	console.log(`wrap01_v2 (${i}):`, wp.wrap01_v2(i) );
}

// Pick the next 3 numbers for a list

// console.log(13 % 5);
// console.log("n = (n + 1) % 3");

let i, n = 0, m = 0;

// console.log("n = (n) => ", n);
// console.log("n = (n + 1) % 3 => ", (n + 1) % 3);
// console.log("n = (n + 2) % 3 => ", (n + 2) % 3);

for (i = 0; i < 21; i++) {

	console.log("i:", i);
	console.log("n = (n)         => ", n);
	console.log("n = (n + 1) % 3 => ", (n + 1) % 3);
	console.log("n = (n + 2) % 3 => ", (n + 2) % 3);
	console.log(" ");
	
	n = (n + 1) % 3;
}

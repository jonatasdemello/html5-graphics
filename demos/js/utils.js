var utils = {};

//var canvas = document.getElementById("drawingCanvas");
//var context = canvas.getContext("2d");

function clearCanvas(canvas, ctx) {
	ctx.clearRect(0, 0, canvas.width, canvas.height);
	ctx.beginPath();
	ctx.stroke();
}

function drawAxes(canvas, ctx) {
	ctx.font = "10px Arial";
	ctx.fillStyle = "white";
	// ctx.fillStyle = "rgb(0,0,0)";

	// X-axis
	for (var x = 0; x < canvas.width; x += 50) {
		ctx.fillText(x, x, 10);
	}
	// Y-axis
	for (var y = 0; y < canvas.height; y += 50) {
		ctx.fillText(y, 0, y);
	}
}

function plot(x, y, ctx) {
	ctx.fillStyle = "rgb(" + x + "," + y + ",40)";
	ctx.fillRect(x * 2, (200 - y) * 2, 1, 1);
}

function getRandomColor() {
	var letters = '0123456789ABCDEF';
	var color = '#';
	for (var i = 0; i < 6; i++) {
		color += letters[Math.floor(Math.random() * 16)];
	}
	return color;
}

function RND(start, end) {
	return Math.floor((Math.random() * end) + start);
}

// Create an array of 10 colors
const colors = ["red", "blue", "green", "yellow", "purple", "orange", "pink", "brown", "black", "white"];

// Function to randomly select a color
function getRandomColorArray(arr) {
	const randomIndex = Math.floor(Math.random() * arr.length);
	return arr[randomIndex];
}


// used in the main function
function pmod (n, m) {
	// calculates the positive remainder when dividing n (dividend) by m (divisor)
	return ((n % m + m) % m)
}

function rotate_Num (num, max) {
	let res = pmod(num, max+1);
	return res;
}

function rotateNum (num, max) {
	if (num > max) {
		return 1;
	}
	if (num < 1) {
		return max;
	}
	return num;
}

module.exports = { rotateNum, rotate_Num };

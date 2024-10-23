/*
https://en.wikipedia.org/wiki/Clamping_(graphics)

def clamp(x, minimum, maximum):
    if x < minimum:
        return minimum
    if x > maximum:
        return maximum
    return x
	
This is equivalent to max(minimum, min(x, maximum)) for languages that support the functions min and max. 

Y = clamp(X, 1, 3) // x, min, max
X 	Y
0 	1
1 	1
2 	2
3 	3
4 	3
*/

function clamp (n, min, max) {
	return Math.min(Math.max(n, min), max)
}

function pmod (n, m) {
	// calculates the positive remainder when dividing n by m
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



module.exports = { clamp, pmod, rotateNum, rotate_Num };


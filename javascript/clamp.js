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

module.exports = { clamp };
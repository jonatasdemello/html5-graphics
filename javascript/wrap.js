
// Pseudocode for wrapping of a value to a range other than 0–1 is

function wrap(X, Min, Max) {
	
    X = X - parseInt((X - Min) / (Max - Min)) * (Max - Min);
	// This corrects the problem caused by using Int instead of Floor
    if (X < 0) {
        X = X + Max - Min;
	}
    return X;
}

// Pseudocode for wrapping of a value to a range of 0–1 is

function wrap01_v1(X) {
    X = X - parseInt(X);
    if (X < 0) {
        X = X + 1;
	}
    return X;
}

// Pseudocode for wrapping of a value to a range of 0–1 without branching is, 

function wrap01_v2(X) {
    return ((X % 1.0) + 1.0) % 1.0;
}

module.exports = { wrap, wrap01_v1, wrap01_v2 };
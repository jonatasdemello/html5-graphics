/*
Function Name: pmod
Parameters:

	n: Represents the dividend (the number being divided).
	m: Represents the divisor (the number by which we divide).

Function Logic:

The expression ((n % m + m) % m) calculates the positive remainder when dividing n by m.

Here’s how it works:

First, compute n % m to get the remainder.
Add m to the remainder to ensure that the result is positive (since the remainder can be negative).
Finally, take the remainder of this sum when divided by m again.

Purpose:

The purpose of this function is to ensure that the result of the modulo operation is always positive, regardless of the signs of n and m.

In mathematical notation, the function can be expressed as:

	pmod(n,m)=((n mod m + m) mod m)

For example:

If n = 7 and m = 3, then:

7 % 3 gives a remainder of 1.
Adding 3 to 1 gives 4.
Finally, 4 % 3 results in 1.
So, pmod(7, 3) returns 1.

*/

function pmod (n, m) {
	// calculates the positive remainder when dividing n (dividend) by m (divisor)
	return ((n % m + m) % m)
}

module.exports = { pmod };
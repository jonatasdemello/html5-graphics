const util = require('./rotateNum');

test('rotate_Num tests', () => {
	expect( util.rotate_Num(-5, 3)).toBe( 3 );
	expect( util.rotate_Num(-4, 3)).toBe( 0 );
	expect( util.rotate_Num(-3, 3)).toBe( 1 );
	expect( util.rotate_Num(-2, 3)).toBe( 2 );
	expect( util.rotate_Num(-1, 3)).toBe( 3 );
	expect( util.rotate_Num(0, 3)).toBe( 0 );
	expect( util.rotate_Num(1, 3)).toBe( 1 );
	expect( util.rotate_Num(2, 3)).toBe( 2 );
	expect( util.rotate_Num(3, 3)).toBe( 3 );
	expect( util.rotate_Num(4, 3)).toBe( 0 );
	expect( util.rotate_Num(5, 3)).toBe( 1 );
	expect( util.rotate_Num(6, 3)).toBe( 2 );
	expect( util.rotate_Num(7, 3)).toBe( 3 );
	expect( util.rotate_Num(8, 3)).toBe( 0 );
	expect( util.rotate_Num(9, 3)).toBe( 1 );
	expect( util.rotate_Num(10, 3)).toBe( 2 );
	expect( util.rotate_Num(11, 3)).toBe( 3 );
	expect( util.rotate_Num(12, 3)).toBe( 0 );
});



const util = require('./util');

// Y = clamp(X, 1, 3) // x, min, max
// X 	Y
// 0 	1
// 1 	1
// 2 	2
// 3 	3
// 4 	3
test('clamp tests', () => {
  expect( util.clamp(0, 1, 3)).toBe(1);
  expect( util.clamp(1, 1, 3)).toBe(1);
  expect( util.clamp(2, 1, 3)).toBe(2);
  expect( util.clamp(3, 1, 3)).toBe(3);
  expect( util.clamp(4, 1, 3)).toBe(3);
});


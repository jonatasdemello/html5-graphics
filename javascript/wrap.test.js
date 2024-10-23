const util = require('./wrap');

describe("wrap tests", () => {
  it.each([
    [-1, 0],
    [0, 0],
	[0.5, 0.5],
	[1, 0]
  ])("when the input is '%s'", (num, expected) => {
    expect( util.wrap01_v2(num)).toBe(expected);
  });
});
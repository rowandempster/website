// art.h, a module for drawing some simple ASCII shapes


// triangle(len, c) draws a right angle triangle two equals sides
// (length len) made of character c. Dhe right angle placed to
// the bottom left.
// eg: triangle(3,'*') draws:
// *
// **
// ***
// requires: len > 0
// effects: len lines are printed to the screen
void triangle(int len, char c);


// box(width, height, c) draws width x height box using character c
// eg box(3,2,'X') draws
// XXX
// XXX
// effects: height lines are printed to the screen
// requires: width > 0
//           height > 0
void box(int width, int height, char c);


// diamond(len,c) draws a diamond with all four edges having length len,
// and drawn using character c.
// eg: diamond(3,'!') draws
//   !
//  !!!
// !!!!!
//  !!!
//   !
// effects: 2*len -1 lines are printed to the screen
// requires: len > 0
void diamond(int len, char c);




#include <stdio.h>
#include "posn.h"

// INTEGRITY STATEMENT (modify if necessary)
// I received help from the following sources:
// None. I am the sole author of this work 

// sign this statement by removing the line below and entering your name

// Name: Rowan Dempster
// login ID: R2DEMPST



void twice_the_difference(struct posn *p1, struct posn *p2) {
  // WRITE CODE HERE

  struct posn temp = {p2->y + p1->y, p2->x}; // {2+5,3}={7,3}
  p2->x = temp.x + temp.x; // now *p2 = {14,2}
  p2->y = temp.y + temp.y; // now *p2 = {14,6}

  //STACK FRAME SHOWN AT THIS POINT (the end of this function)
}

//DO NOT CHANGE THIS FUNCTION
int main(void) {
  struct posn first_posn = {10,5};
  struct posn second_posn = {3,2};
  twice_the_difference(&first_posn, &second_posn);
}

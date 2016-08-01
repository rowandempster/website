#include <stdio.h>
#include "art-black.h"
#include "readnat.h"
#include "readchar.h"

/**
  Interactive testing program for the art-black module.
  It first reads a command, 't' for triangle, 'b' for box, or 'd' for diamond
  It then reads the needed argument, and calls the function with those
  parameters. This is repeated until an invalid command is picked (for
  example, 'q'), an invalid argument (non-positive or non-numeric length) is
  read, or EOF is encountered.
 **/


int main(void) {
  char action;
  char c;
  int i1;
  int i2;

  while (true) {
    action = readchar(true);
    if (action == 't') { // triangle
      i1 = readnat();
      c = readchar(true);
      if ((i1 <= 0) || (c <= 32)) return 0; // invalid!
      triangle(i1,c);
    } else if (action == 'b') { // box
      i1 = readnat();
      i2 = readnat();
      c = readchar(true);
      if ((i1 <= 0) || (i2 <= 0) || (c <= 32)) return 0; // invalid!
      box(i1,i2,c);
    } else if (action == 'd') { // diamond
      i1 = readnat();
      c = readchar(true);
      if ((i1 <= 0) || (c <= 32)) return 0; // invalid!
      diamond(i1,c);
    } else {
      return 0; // invalid command, stop everything
    }
  }


}

#include <stdio.h>
#include "art-gold.h"
#include "readnat.h"
#include "readchar.h"

/**
  Interactive testing program for the art-gold module.
  it repeatedly reads in arguments for the checker function, and then calls
  checker using these arguments.
  if any arguments are unable to be read, or would violate the contract,
  then the program ends.
 **/


int main(void) {
  char action;
  char c1;
  char c2;
  int i1;
  int i2;
  int i3;

  while (true) {
    i1 = readnat();
    i2 = readnat();
    i3 = readnat();
    c1 = readchar(true);
    c2 = readchar(true);
    if (i1 < 1 || i2 < 1 || i3 < 1 || c1 < 32 || c2 < 32) {
      return 0;
    }
    checker(i1,i2,i3,c1,c2);
  }


}

#include "readnat.h"
#include <assert.h>

// INTEGRITY STATEMENT (modify if necessary)
// I received help from the following sources:
// None. I am the sole author of this work 

// sign this statement by removing the line below and entering your name

// Name: Rowan Dempster
// login ID: R2DEMPST

// implementation:

//see .h for description
int read_two(int *n1, int *n2) {
  assert(n1&&n2);
  int read1 = readnat();
  if (read1 == -1){
   return 0; 
  }
  *n1 = read1;
  int read2 = readnat();
  if (read2 == -1){
   return 1;
  }
  *n2 = read2;
  return 2;
}

  
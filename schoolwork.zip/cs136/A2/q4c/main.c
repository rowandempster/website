#include <stdio.h>
#include "readnat.h"

// INTEGRITY STATEMENT (modify if necessary)
// I received help from the following sources:
// None. I am the sole author of this work 

// sign this statement by removing the line below and entering your name

// Name: Rowan Dempster
// login ID: R2DEMPST
  
int read_larger_than(const int cutoff, const int larger_so_far) {
  const int n = readnat();
  if (n == -1) {
    return larger_so_far;
  } else if (n > cutoff) {
    return read_larger_than(cutoff, larger_so_far + 1);
  } else {
   return read_larger_than(cutoff, larger_so_far);
  }
}
  
int main(void) {
  const int cutoff = readnat();
  const int larger_than_nums = read_larger_than(cutoff, 0);
  printf("%d\n", larger_than_nums);  
}


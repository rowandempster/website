#include <stdio.h>
#include "readnat.h"

// INTEGRITY STATEMENT (modify if necessary)
// I received help from the following sources:
// None. I am the sole author of this work 

// sign this statement by removing the line below and entering your name

// Name: Rowan Dempster
// login ID: R2DEMPST
  
int read_even(const int even_so_far) {
  const int n = readnat();
  if (n == -1) {
    return even_so_far;
  } else if ((n % 2) == 0) {
    return read_even(even_so_far + 1);
  } else {
   return read_even(even_so_far);
  }
}
  
int main(void) {
  const int even_nums = read_even(0);
  printf("%d\n", even_nums);  
}

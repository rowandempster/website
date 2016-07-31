#include <stdio.h>
#include "readnat.h"

// INTEGRITY STATEMENT (modify if necessary)
// I received help from the following sources:
// None. I am the sole author of this work 

// sign this statement by removing the line below and entering your name

// Name: Rowan
// login ID: R2DEMPST
 
int read_largest(const int largest_so_far) {
  const int n = readnat();
  if (n == -1) {
    return largest_so_far;
  } else if (n > largest_so_far) {
    return read_largest(n);
  } else {
   return read_largest(largest_so_far);
  }
}

int main(void) {
  const int largest_num = read_largest(0);
  printf("%d\n", largest_num);  
}


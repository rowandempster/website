#include <stdio.h>
#include "readnat.h"

// INTEGRITY STATEMENT (modify if necessary)
// I received help from the following sources:
// None. I am the sole author of this work 

// sign this statement by removing the line below and entering your name

// Name: Rowan Dempster
// login ID: R2DEMPST


int read_difference(const int largest_so_far, const int smallest_so_far) {
  const int n = readnat();
  if (n == -1) {
    return largest_so_far-smallest_so_far;
  } else if (n >= largest_so_far) {
    return read_difference(n, smallest_so_far);
  } else if (n <= smallest_so_far) {
    return read_difference(largest_so_far, n);
  } else {
    return read_difference(largest_so_far, smallest_so_far);  
  }
}

int main(void) {
  const int initial_1 = readnat();
  const int initial_2 = readnat();
  if((initial_2 == -1||initial_2 == -1)) {
    printf("%d\n", 0); 

  }
  
  else if (initial_1>=initial_2) {
    printf("%d\n", read_difference(initial_1, initial_2));
  } else {
    printf("%d\n", read_difference(initial_2, initial_1));
  }
}


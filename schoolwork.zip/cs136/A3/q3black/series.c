#include <stdio.h>
#include "series.h"
#include <assert.h>

// INTEGRITY STATEMENT (modify if necessary)
// I received help from the following sources:
// None. I am the sole author of this work 

// sign this statement by removing the line below and entering your name

// Name: Rowan Dempster
// login ID: R2DEMPST

// implementation:

//see .h for description
void collatz(const int n) {
  assert(n>=1);
  if (n == 1) {
    printf("%d.\n", 1);
  } else if (n % 2 == 0) {
    printf("%d, ", n);
    collatz(n / 2);
  } else {
    printf("%d, ", n);
    collatz(3*n + 1);
    }
}


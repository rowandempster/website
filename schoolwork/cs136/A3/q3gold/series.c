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

//Fibbonacci x0 and x1 terms
const int fib_1 = 0;
const int fib_2 = 1;

//(fib_acc) produces the nth number in the fibonacci sequence
//   using accumulative recursion
//requires: n>=1
//effects: may print out a message
void fib_acc(const int n, const int oneB, const int twoB) {
  if(n!=0){
    printf("%d, ", oneB+twoB);
    fib_acc(n-1,oneB+twoB, oneB);
  }
  else {
    printf("%d.\n", oneB+twoB);
  }
}

void fibonacci(int n) {
  assert(n>=1);
  if(n==1){
    printf("%d.\n", fib_1);
  }
  else if(n==2){
    printf("%d, %d.\n", fib_1, fib_2);
  }
  else {
    printf("%d, ", fib_1);
    fib_acc(n-2, fib_1, fib_2);
  }
}






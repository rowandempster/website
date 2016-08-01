// Note: stdlib allows you to use NULL:
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

#include "basic_pointer.h"

// INTEGRITY STATEMENT (modify if necessary)
// I received help from the following sources:
// None. I am the sole author of this work 

// sign this statement by removing the line below and entering your name

// Name: Rowan Dempster
// login ID: R2DEMPST

// implementation:

//see .h for description
int *down_value (int *x, int *y){
  assert(x&&y);
  int x_val = *x;
  int y_val = *y;
  if (x_val>y_val) {
    *x = *y;
    return x;
  }
  else if (y_val>x_val) {
    *y = *x;
    return y;
  }
  else{
    return NULL; 
  }
}

//for testing
/*int main(void) {
  int x = 5;
  int y = 10;
  printf("The address of the larger number is: %p\n", &y);
  int *p = down_value(&x, &y);
  printf("The address of the number changed is: %p\n", p);
  printf("Now, x = %d and y = %d\n", x, y);
}*/

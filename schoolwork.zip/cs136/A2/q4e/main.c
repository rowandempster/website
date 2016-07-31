#include <stdio.h>
#include "readnat.h"

// INTEGRITY STATEMENT (modify if necessary)
// I received help from the following sources:
// None. I am the sole author of this work 

// sign this statement by removing the line below and entering your name

// Name: Rowan Dempster
// login ID: R2DEMPST
  
int read_largest_div(const int n, const int largest_div_so_far) {
  const int div_num = readnat();
  if (div_num == -1) {
    return largest_div_so_far;
  } else if ((div_num > largest_div_so_far) && ((div_num % n)==0)) {
    return read_largest_div(n, div_num);
  } else {
    return read_largest_div(n, largest_div_so_far);  
  }
}

int main(void) {
  const int initial = readnat();
  if(initial == -1) {
    printf("%d\n", 0); 
  }
  else {
    printf("%d\n", read_largest_div(initial, 0));
  }
}



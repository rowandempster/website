#include "readnat.h"
#include <stdio.h>

// INTEGRITY STATEMENT (modify if necessary)
// I received help from the following sources:
// None. I am the sole author of this work 

// sign this statement by removing the line below and entering your name

// Name: Rowan Dempster
// login ID: R2DEMPST

int sum (int m) {
  int sum = 0;
  int n = readnat();
  while(m>0) {
    sum = sum + n;
    if(m==1){
     break; 
    }
    n = readnat();
    m--;
  }
  return sum;
}

void many_sums (void) {
  int n = readnat();
  const int m = readnat();
  while(n>0){
    printf("%d\n", sum(m));
    n--;
  }
}


int main(void) {
  many_sums(); 
}
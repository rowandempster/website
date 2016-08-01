#include "readnat.h"
#include <stdio.h>

// INTEGRITY STATEMENT (modify if necessary)
// I received help from the following sources:
// None. I am the sole author of this work 

// sign this statement by removing the line below and entering your name

// Name: Rowan Dempster
// login ID: R2DEMPST

int max (void) {
  int largest = 0;
  int n = readnat();
  while(n!=-1) {
    if(n>=largest){
      largest = n; 
    }
    n = readnat();
  }
  return largest;
}

int main(void) {
  printf("%d\n", max()); 
}
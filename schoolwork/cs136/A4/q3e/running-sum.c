#include "readnat.h"
#include <stdio.h>

// INTEGRITY STATEMENT (modify if necessary)
// I received help from the following sources:
// None. I am the sole author of this work 

// sign this statement by removing the line below and entering your name

// Name: Rowan Dempster
// login ID: R2DEMPST

void running_sum(void){
  int sum = 0;
  int n = readnat();
  while(n!=-1){
    sum = sum+n;
    if(sum<0){
      printf("overflow\n");
      sum=0;
    }
    else{
      printf("%d\n", sum); 
    }
    n = readnat();
  }
}

int main(void){
  running_sum();
}
#include "readchar.h"
#include "readnat.h"
#include <stdio.h>
#include <stdbool.h>

// INTEGRITY STATEMENT (modify if necessary)
// I received help from the following sources:
// None. I am the sole author of this work 

// sign this statement by removing the line below and entering your name

// Name: Rowan Dempster
// login ID: R2DEMPST

void lower_count(void){
 int lower = 0;
  int c = readchar(false);
  while(c!=-1){
   if((c>=97) && (c<=122)){
    lower++; 
   }
    c = readchar(false);
  }
  printf("%d\n", lower);
}

int main(void){
 lower_count(); 
}
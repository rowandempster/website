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

void last_digit (void){
  int c = readchar(false);
  int last_num = -1;
  while(c!=-1){
    if((c>=48)&&(c<=57)){
      last_num = c-48;
    }
    c = readchar(false);
  }
  if(last_num == -1){
  }
  else{
    printf("%d\n", last_num);
  }
}

int main(void){
  last_digit(); 
}
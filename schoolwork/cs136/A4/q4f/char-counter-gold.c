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

void char_count(void){
  const int c = readchar(false);
  int n = readnat();
  if((c==-1)||(n==-1)){
    printf("insufficient input\n");  
  }
  int check = readchar(false);
  while(n>0){
    check = readchar(false);
    if(check==-1){
      break;
    }
    else if((c==check)||(c==check+32)||(c==check-32)){
      n--; 
    }
  }
  if(check==-1){
    printf("insufficient input\n");  
  }
  else{
    printf("done\n");
  }
}

int main(void){
 char_count(); 
}
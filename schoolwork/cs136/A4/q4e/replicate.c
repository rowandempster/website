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

void print_copies(int n, char c){
  while(n>0){
   printf("%c", c);
    if(n==1){
     printf("\n"); 
    }
    n--;
  }
}

void replicate(void){
  int n = readnat();
  char c = readchar(true);
  while((n!=-1)&&(c!=-1)){
  if(n==0){
  }
  else{

    if(c==-1){
     break; 
    }
    print_copies(n,c);
  }
    n=readnat();
    c=readchar(true);
  }
}

int main(void){
 replicate(); 
}
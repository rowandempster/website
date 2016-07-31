#include <stdio.h>

// INTEGRITY STATEMENT (modify if necessary)
// I received help from the following sources:
// None. I am the sole author of this work

// sign this statement by removing the line below and entering your name

// Name: Rowan Dempster
// login ID:

// implementation:

//see .h for descriptions
int readnat(void){
  int readnat;
  int count = scanf("%d", &readnat);
  if(count!=1){
    return -1;
  }
  if(readnat<0){
    readnat = -2; 
  }
  return readnat;
}

float readnonnegfloat(void){
 float readfloat;
  int count = scanf("%f", &readfloat);
  if(count!=1){
   return -1; 
  }
  if(readfloat<0){
   return -2; 
  }
  return readfloat;
}

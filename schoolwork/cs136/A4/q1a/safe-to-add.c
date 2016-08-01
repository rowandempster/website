// safe-to-add.c -- a module for checking if it is safe to do a calculation
#include <stdbool.h>
#include "safe-to-add.h"

// INTEGRITY STATEMENT (modify if necessary)
// I received help from the following sources:
// None. I am the sole author of this work 

// sign this statement by removing the line below and entering your name

// Name: Rowan
// login ID: R2DEMPST

//see .h for description
bool safe_to_add(int a, int b) {
  if(a>0 && b>0) {
    if(a+b<=1) {
      return false; 
    }
    else {
      return true; 
    }
  }
  else if (a<0 && b<0){
    if(a+b>=-1) {
      return false; 
    }
    else {
      return true;
    }
  }
  else {
    return true; 
  }

}




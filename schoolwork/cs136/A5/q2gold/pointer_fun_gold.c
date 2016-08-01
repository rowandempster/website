#include <stdbool.h>
#include <stdio.h>
#include "readnat.h"
#include <assert.h>

// INTEGRITY STATEMENT (modify if necessary)
// I received help from the following sources:
// None. I am the sole author of this work 

// sign this statement by removing the line below and entering your name

// Name: Rowan Dempster  
// login ID: R2DEMPST

// implementation:

//see .h for descruption
bool sum_and_range(int n, int *sum, int *smallest, int *largest) {
  assert(n>=0);
  assert(sum&&smallest&&largest);
  int init = readnat();
  int initial_good = 0;
  if ((init !=-1)&&(n>0)) {
    *sum = init;
    *smallest = init;
    *largest = init;
    if(n==1){
      initial_good = 1;
    }
  }
  else if (n==0) {
    *sum = 0;
    *smallest = 0;
    *largest = 0;
  }
  while(n>1) {
    int curr = readnat();
    int ended = 0;
    if(n==2){
      ended = 1; 
    }
    if(curr == -1) {
      break; 
    }
    *sum += curr;
    if(curr>*largest) {
      *largest = curr; 
    }
    if(curr<*smallest) {
      *smallest = curr; 
    }
    if (ended == 1) {
      return false; 
    }
    n--;
  }
  if(n==0 || initial_good){
    return false; 
  }
  return true;
}

//For testing part (a)
int main(void){
  int sum = -5;
  int largest = 0;
  int smallest = 100;
 bool result = sum_and_range(20, &sum, &smallest, &largest);
  printf("Result: %d\nSum: %d\nLargest: %d\nSmallest: %d\n",
         result, sum, largest, smallest);
}

//see .h for description
int sum_numbers(int *sum){
  *sum = 0;
  int n = readnat();
  int counter = 0;
  while (n != -1){
    counter++;
    *sum += n;
    n = readnat();
  }
  return counter;
}

//for testing part b
/*
int main(void){
  int sum = 5; 
  int counter = sum_numbers(&sum);
  printf("I read %d numbers and their sum is %d\n", counter, sum);
}*/

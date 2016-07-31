#include "readnat.h"
#include <stdio.h>

// INTEGRITY STATEMENT (modify if necessary)
// I received help from the following sources:
// None. I am the sole author of this work 

// sign this statement by removing the line below and entering your name

// Name: Rowan Dempster
// login ID: R2DEMPST

int abs (const int n){
 if (n<0){
  return -n; 
 }
  return n;
}

int closest_one_line(const int n, int m){
 int curr = readnat();
  int min_dist = abs(n-curr);
  int lowest = curr;
  while(m>1){
    int curr = readnat();
    if(abs(n-curr)<min_dist){
     min_dist =  abs(n-curr);
      lowest = curr;
    }
    m--;
  }
  return lowest;
}

void closest(void) {
  const int n = readnat();
  if(n==0){
   printf("%d", 0); 
  }
  else{
 int m = readnat();
  while((m!=-1)&&(m!=0)){
    int lowest = closest_one_line(n, m);
    if (lowest!=-1){
    printf("%d\n", lowest);
    }
    m = readnat();
  }
  }
}

int main(void){
 closest(); 
}
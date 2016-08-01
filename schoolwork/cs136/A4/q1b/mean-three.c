// mean-three.c -- a module for averaging three integers
#include "mean-three.h"
#include <stdio.h>
#include <limits.h>

// INTEGRITY STATEMENT (modify if necessary)
// I received help from the following sources:
// None. I am the sole author of this work 

// sign this statement by removing the line below and entering your name

// Name: Rowan
// login ID: R2DEMPST

//see .h for descriptions
int mean3(int a, int b, int c) {
  int max_num = max_3(a, b, c);
  int mid_num = mid_3(a,b,c);
  int min_num = min_3(a,b,c);
  while(max_num>(min_num+1)) {
    int increment = 1;
    if (min_2(max_num-mid_num, mid_num-min_num)!=0){
      increment = min_2(max_num-mid_num, mid_num-min_num);
    }
    int new_max = max_num - increment;
    int new_mid = mid_num;
    int new_min = min_num+ increment;
    max_num = max_3(new_max, new_mid, new_min);
    mid_num = mid_3(new_max, new_mid, new_min);
    min_num = min_3(new_max, new_mid, new_min);
  }
  if(min_num<0){
  return max_num;
  }
  else {
   return min_num;
  }
}

int max_3(int a, int b, int c) {
  if(a>=b && a>=c){
    return a; 
  }
  else if (b>=a && b>=c){
    return b; 
  }
  else {
    return c; 
  }
}

int min_3(int a, int b, int c) {
  if(a<=b && a<=c){
    return a; 
  }
  else if (b<=a && b<=c){
    return b; 
  }
  else {
    return c; 
  }
}

int mid_3(int a, int b, int c) {
  if((a<=b && a>=c)||(a>=b && a<=c)){
    return a; 
  }
  else if ((b<=a && b>=c)||(b>=a && b<=c)){
    return b; 
  }
  else {
    return c; 
  }
}

int min_2(int a, int b) {
  if(a<=b){
   return a; 
  }
  else{
   return b; 
  }
}


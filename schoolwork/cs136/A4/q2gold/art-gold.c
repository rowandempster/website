#include "art-gold.h"
#include <stdio.h>

// INTEGRITY STATEMENT (modify if necessary)
// I received help from the following sources:
// None. I am the sole author of this work 

// sign this statement by removing the line below and entering your name

// Name: Rowan
// login ID: R2DEMPST

// see interface file
void checker(int width, int height, int size, char c1, char c2) {
  int start_row_tracker = 0;
  while (height>0){
    make_row(c1,  c2,  size,  start_row_tracker,  width);
    start_row_tracker++;
    height--;
  }
}

void make_row(char c1, char c2, int size, int start_tracker, int width) {
  int orig_width = width;
  int orig_size=size;
  if(start_tracker%2==0){
    int next_block_tracker = 0;
    while(size>0) {
      while(width>0) {
        if(next_block_tracker%2 ==0){
          print_row(c1, orig_size);
        }
        else{
          print_row(c2, orig_size); 
        }
        next_block_tracker++;
        width--;
      }
      printf("\n");
      width = orig_width;
      size--;
      next_block_tracker = start_tracker;
    }
  }
  else {
    int next_block_tracker = 1;
    while(size>0) {
      while(width>0) {
        if(next_block_tracker%2 ==0){
          print_row(c1, orig_size);
        }
        else{
          print_row(c2, orig_size); 
        }
        next_block_tracker++;
        width--;
      }
      printf("\n");
      width = orig_width;
      size--;
      next_block_tracker = start_tracker;
    }
  }
}

void print_row(char c, int times) {
  while(times>0) {
    printf("%c", c);
    times--;
  }
}



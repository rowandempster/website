#include "art-black.h"
#include <stdio.h>

// INTEGRITY STATEMENT (modify if necessary)
// I received help from the following sources:
// None. I am the sole author of this work 

// sign this statement by removing the line below and entering your name

// Name: Rowan
// login ID: R2DEMPST

// see art-black.h
void triangle(int len, char c) {
  int oneMore = len+1;
  while (len>0) {
    int num_char = oneMore - len;
    while(num_char>0) {
      printf("%c", c);
      num_char--;
    }
    printf("\n");
    len--;
  }
}

// see art-black.h
void box(int width, int height, char c) {
  int orig_width = width;
  while(height>0){
    while(width >0){
      printf("%c", c);
      width--;
    }
    width = orig_width;
    height--;
    printf("\n");
  }
}

// see art-black.h
void diamond(int len, char c) {
  int orig_len = len;
  int col_index = 0;
  int row_length = len*2 -1;
  int row_index = 0;
  while(len>0) {
    while(col_index<row_length){
      if((col_index>=(len - 1)) &&
         (col_index-(row_index*2)<len)){
        printf("%c", c);
      }
      else if (col_index-(row_index*2)>=len) {
        
      }
      else {
        printf("%c", ' '); 
      }
      col_index++;
    }
    printf("\n");
    len--;
    col_index =0;
    row_index++;
  }

  col_index = 0;
  row_index = 0;
  len = orig_len;
  int end_counter = 1;
  while(len>1) {
    while(col_index<row_length){
      if((col_index>=(row_index + 1)) && 
         (col_index< (row_length - end_counter))){
        printf("%c", c);
      }
      else if (col_index>= (row_length - end_counter)){
      }
      else {
        printf("%c", ' '); 
      }
      col_index++;
    }
    printf("\n");
    len--;
    col_index =0;
    row_index++;
    end_counter++;
  }
}




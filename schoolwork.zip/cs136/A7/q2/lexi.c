/**
 File: lexi.c
 String I/O
*/
#include <stdbool.h>
#include <stdio.h>
#include <string.h>
// INTEGRITY STATEMENT (modify if necessary)
// I received help from the following sources:
// None. I am the sole author of this work 

// sign this statement by removing the line below and entering your name

// Name: Rowan Dempster
// login ID: R2DEMPST

// implementation:

//change_str(old, new) replaces the elements of old with 
//   the elements of new, oops I made my own strcpy...
//requires: both old and new have 100 elements
//effects: mutates old
void change_str(char old[100], const char new[100]){
 for(int i = 0; i<100; i++){
  old[i] = new[i]; 
 }
}

int main(void) {
  char front[100];
  char back[100];
  char temp[100];
  int read = scanf("%s", temp);
  if(read != 1){
   printf("NO STRINGS\n"); 
  }
  else{
  change_str(front, temp);
  change_str(back, temp); 
   while(read == 1){
     read = scanf("%s", temp);
     if(strcmp(temp, front) < 0){
       change_str(front, temp);
     }
     if(strcmp(temp, back) > 0){
       change_str(back, temp);
     }
   }
    printf("%s %s\n", front, back);
  }
}
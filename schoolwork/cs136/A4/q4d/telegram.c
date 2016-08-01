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

void telegram (void){
  char prev_c = '*';
  char c = readchar(false);
  int c_int = c;
  while(c!=-1){
    if((c_int>=97)&&(c_int<=122)){
      printf("%c", c_int-32); 
    }
    else if((c_int>=65)&&(c_int<=90)){
      printf("%c", c); 
    }
    else if((c_int>=48)&&(c_int<=57)){
      printf("%c", c);
    }
    else if((c_int==' ')||(c=='\n')){
      printf("%c", c);
    }
    else if((c=='%')&&((prev_c==' ')||prev_c=='\n'||prev_c=='*')){
      printf("PERCENT");
    }
    else if(c=='%'){
      printf(" PERCENT");
    }
    else if((c=='.')&&((prev_c==' ')||prev_c=='\n'||prev_c=='*')){
      printf("STOP");
    }
    else if(c=='.'){
      printf(" STOP");
    }
    else{
    }
    prev_c = c;
    c = readchar(false);
    c_int = c;
    if((c==-1)&&(prev_c!='\n')){
      printf("\nMESSAGE ENDS\n");
    }
    else if(c==-1){
      printf("MESSAGE ENDS\n");
    }
  }
}

int main(void){
  telegram(); 
}
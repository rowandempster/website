#include "crypto.h"
#include <stdio.h>

int main(void){
  struct character_map m[5] = {{'a','b'},{'b','c'},
  {'z','f'},{'c','z'},{'f','a'}};
  char message[5] = {'Z','e','b','r','a'};
  int m_len = 5;
  int message_len = 5;
  encode_message(m, m_len, message, message_len);
  for(int i =0; i<message_len; i++){
    if(i==message_len-1){
      printf("%c\n", message[i]); 
    }
    else{
      printf("%c ", message[i]); 
    }
  }
  decode_message(m, m_len, message, message_len);
  for(int i =0; i<message_len; i++){
    if(i==message_len-1){
      printf("%c\n", message[i]); 
    }
    else{
      printf("%c ", message[i]); 
    }
  }
  
  struct character_map m2[5] = {{'a','b'},{'b','c'},
  {'c','d'},{'d','e'},{'e','f'}};
  char message2[5] = {'a','B','c','D','e'};
  int m_len2 = 5;
  int message_len2 = 5;
  encode_message(m2, m_len2, message2, message_len2);
  for(int i =0; i<message_len2; i++){
    if(i==message_len2-1){
      printf("%c\n", message2[i]); 
    }
    else{
      printf("%c ", message2[i]); 
    }
  }
  decode_message(m2, m_len2, message2, message_len2);
  for(int i =0; i<message_len2; i++){
    if(i==message_len2-1){
      printf("%c\n", message2[i]); 
    }
    else{
      printf("%c ", message2[i]); 
    }
  }
}
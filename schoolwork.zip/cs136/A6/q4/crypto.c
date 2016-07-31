#include "crypto.h"
#include <assert.h>

// INTEGRITY STATEMENT (modify if necessary)
// I received help from the following sources:
// None. I am the sole author of this work

// sign this statement by removing the line below and entering your name

// Name: Rowan Dempster
// login ID: R2DEMPST

// implementation:

//see .h for descriptions
void encode_message(struct character_map m[], int len_m, 
                    char message[], int message_len){
  assert(m&&message);
  int cap = 0;
  char message_char;
  char message_char_lower;
  for(int message_i = 0; message_i<message_len; message_i++){
    for(int m_i = 0; m_i<len_m; m_i++){
      message_char = message[message_i];
      if(message_char>64 && message_char<91){
        cap = 1;
        message_char_lower = message_char + 32;
      }
      if(message_char == m[m_i].orig || message_char_lower == m[m_i].orig){
        if(cap){
          message[message_i] = m[m_i].rep - 32;
          break;
        }
        else {
          message[message_i] = m[m_i].rep; 
          break;
        }
      }
      message_char_lower = -1;
      cap = 0;
    }
  }
}

void decode_message(struct character_map m[], int len_m, 
                    char message[], int message_len){
  assert(m&&message);
  int cap = 0;
  char message_char;
  char message_char_lower;
  for(int message_i = 0; message_i<message_len; message_i++){
    for(int m_i = 0; m_i<len_m; m_i++){
      message_char = message[message_i];
      if(message_char>64 && message_char<91){
        cap = 1;
        message_char_lower = message_char + 32;
      }
      if(message_char == m[m_i].rep || message_char_lower == m[m_i].rep){
        if(cap){
          message[message_i] = m[m_i].orig - 32;
          break;
        }
        else {
          message[message_i] = m[m_i].orig; 
          break;
        }
      }
      message_char_lower = -1;
      cap = 0;
    }
  }
}


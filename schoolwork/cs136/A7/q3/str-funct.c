/**
 File: str_funct.c
*/

#include <string.h>
#include <stdbool.h>
#include <assert.h>
#include <stdio.h>
#include "str-funct.h"

// INTEGRITY STATEMENT (modify if necessary)
// I received help from the following sources:
// None. I am the sole author of this work 

// sign this statement by removing the line below and entering your name

// Name: Rowan Dempster
// login ID: R2DEMPST

// implementation:

const int LENGTH_OF_ALPHABET = 26;

//see .h for descriptions
void letter_freq_count(const char *s,int count[]) { 
  assert(s&&count);
  for(int j = 0; j<LENGTH_OF_ALPHABET; j++){
    count[j]=0; 
  }
  for(const char *i = s; *i ; i++){
    if(*i>='A' && *i <='Z'){
      count[*i-'A']++; 
    }
    else{
      count[*i-'a']++; 
    }
  }
}

bool anagram(const char *s1,const char *s2)
{ 
  assert(s1&&s2);
  int s1_char_count[LENGTH_OF_ALPHABET];
  int s2_char_count[LENGTH_OF_ALPHABET];
  letter_freq_count(s1, s1_char_count);
  letter_freq_count(s2, s2_char_count);
  int yes_anagram = true;
  for(int i = 0; i<LENGTH_OF_ALPHABET; i++){
    if(s1_char_count[i] != s2_char_count[i]){
      yes_anagram = false; 
    }
  }
  return yes_anagram;
}

int ccount(const char *strings[], int len, char ch) { 
  assert(strings);
  assert(len>0);
  assert(ch>0);
  int count = 0;
  int diff = 'A' - 'a';
  for(int i = 0; i< len; i++){
    const char *curr_string = strings[i];
    for(const char *i = curr_string; *i; i++){
      if((*i == ch)||(*i + diff == ch)||(*i - diff == ch)){
        count++; 
      }
    }
  }
  return count;
}

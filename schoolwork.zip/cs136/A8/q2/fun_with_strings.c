#include <string.h>
#include "fun_with_strings.h"
#include <stdbool.h>
#include <assert.h>

// INTEGRITY STATEMENT (modify if necessary)
// I received help from the following sources:
// None. I am the sole author of this work 

// sign this statement by removing the line below and entering your name

// Name: Rowan Dempster
// login ID: R2DEMPST

// implementation:


bool is_palindrome(const char *str){
  assert(str);
  int end = strlen(str) - 1;
  int begin = 0;
  bool is_palin = true;
  while(begin<end){
    if(str[begin] != str[end]){
      is_palin = false; 
    }
    begin++;
    end--;
  }
  return is_palin;
}


void pig_latin(const char *input, char *output){
  assert(input&&output);
  char first_char = input[0];
  int input_len = strlen(input);
  for(int i = 1; i< input_len; i++){
    output[i - 1] = input[i]; 
  }
  output[input_len - 1] = first_char;
  output[input_len] = 'a';
  output[input_len + 1] = 'y';
  output[input_len + 2] = 0;
}

//member(c, arr, len) returns true is c is an element in arr,
//   false otherwise
//requires: arr!=NULL and len is the length of arr
//time: O(n), where n is len
static bool member(char c, const char arr[], int len){
  assert(arr);
  for(int i = 0; i<len; i++){
   if(arr[i] == c){
    return true; 
   }
  }
  return false;
}
// time: O(n), where n is strlen(str)
// Loop times are documented in function, 
//   and O(1) + O(n) + O(1) + O(1) + O(n) = O(n)

char mostfreq(const char *str){
  assert(str);
  //let n = strlen(str)
  int num_chars = 127;
  int freq_arr[num_chars];
  //O(1) time, since num_chars is a constant
  for(int i = 0; i<num_chars; i++){
    freq_arr[i] = 0; 
  }
  int str_len = strlen(str);
  //O(n) time, since going through n loops
  for(int i = 0; i<str_len; i++){
    freq_arr[(int)str[i]]++; 
  }
  int max_freq = 0;
  //O(1) time, since num_chars is a constant
  for(int i = 0; i<num_chars; i++){
    if(freq_arr[i]>max_freq){
      max_freq = freq_arr[i]; 
    }
  }
  char max_chars[num_chars];
  int max_char_counter = 0;
  //O(1) time, since num_chars is a constant
  for(int i = 0; i<num_chars; i++){
    if(freq_arr[i] == max_freq){
      max_chars[max_char_counter] = i;
      max_char_counter++;
    }
  }
  //O(n) time, since going through n loops of O(1) member 
  //   calls
  for(int i = 0; i<str_len; i++){
    //member() is O(1) since max_chars in a constant
   if(member(str[i], max_chars, max_char_counter)){
    return str[i]; 
   }
  }
  return 0;
}


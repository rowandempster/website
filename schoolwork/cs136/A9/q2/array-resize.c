#include "array-resize.h"
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#include <assert.h>

// INTEGRITY STATEMENT (modify if necessary)
// I received help from the following sources:
// None. I am the sole author of this work 

// sign this statement by removing the line below and entering your name

// Name: Rowan Dempster
// login ID: R2DEMPST

// implementation:
//check_subtring(s, s_start, check_str, check_str_len) returns true if s is 
//   equal to check_str on the interval [s_start,check_str_len), false otherwise
//requires: s, check_str != NULL
//          check_str_len = length of check_str
//time: O(n) where n is check_str_len
static bool check_substring(char *s, int s_start, 
                            const char* check_str, int check_str_len){
  assert(s&&check_str);
  for(int i = 0; i<check_str_len; i++, s_start++){
    if(s[s_start] != check_str[i]){
      return false; 
    }
  }
  return true;
}

char *replace(char *s, const char *find, const char *rep){
  assert(s&&find&&rep);
  int s_len = strlen(s);
  int find_len = strlen(find);
  int rep_len = strlen(rep);
  int find_occur = 0;
  int s_index = 0;
  while(s_index<s_len){
    if(s[s_index] == find[0] && check_substring(s, s_index, find, find_len)){
      find_occur++;
      s_index += find_len;
    }
    else{
      s_index++; 
    }
  }
  int rep_str_len = s_len - (find_len-rep_len)*find_occur + 1;
  char *rep_str = malloc(sizeof(char)*rep_str_len);
  int rep_str_index = 0;
  s_index = 0;
  while(s_index<s_len){
    if(s[s_index] == find[0] && check_substring(s, s_index, find, find_len)){
      for(int i = 0; i<rep_len; i++, rep_str_index++){
        rep_str[rep_str_index] = rep[i];
      }
      s_index += find_len;
    }
    else{
      rep_str[rep_str_index] = s[s_index];
      rep_str_index++;
      s_index++;
    }
  }
  rep_str[rep_str_index] = 0;
  free(s);
  return rep_str;
}

int *filter(bool (*f)(int), int *a, int *len){
  assert(a&&f&&len);
  int a_len = *len;
  int filter_occur = 0;
  for(int i = 0; i<a_len; i++){
    if(!f(a[i])){
      filter_occur++; 
    }
  }
  if(filter_occur == a_len){
    *len = 0;
    free(a);
    return NULL;
  }
  if(filter_occur == 0){
    return a; 
  }
  int filter_a_len = a_len - filter_occur;
  *len = filter_a_len;
  int *filter_buffer = malloc(sizeof(int)*filter_a_len);
  int a_index = 0;
  int buffer_index = 0;
  while(a_index<a_len){
    if(f(a[a_index])){
      filter_buffer[buffer_index] = a[a_index];
      buffer_index++;
    }
    a_index++;
  }
  a = realloc(a, sizeof(int)*filter_a_len);
  for(int i = 0; i<filter_a_len; i++){
    a[i] = filter_buffer[i];
  }
  free(filter_buffer);
  return a;
}
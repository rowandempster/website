#include "dyn-arrays.h"
#include <string.h>
#include <assert.h>
#include <stdlib.h>
#include <stdio.h>

// INTEGRITY STATEMENT (modify if necessary)
// I received help from the following sources:
// None. I am the sole author of this work 

// sign this statement by removing the line below and entering your name

// Name: Rowan Dempster
// login ID: R2DEMPST

// implementation:

char *my_strappend(const char *s1, const char *s2){
  assert(s1&&s2);
  int len_1 = strlen(s1);
  int len_2 = strlen(s2);
  int len_of_append = len_1 + len_2;
  char *str_append = malloc(sizeof(char)*(len_of_append+1));
  for(int i = 0; i<len_1; i++){
    str_append[i] = s1[i];
  }
  int s2_counter = 0;
  for(int i = len_1; s2_counter < len_2; i++, s2_counter++){
    str_append[i] = s2[s2_counter]; 
  }
  str_append[len_1+len_2] = 0;
  return str_append;
}

char *hex_to_bin(const char *h){
  assert(h);
  int hex_len = strlen(h);
  char *bin_str = malloc(sizeof(char)*(4*hex_len+1));
  for(int i = 0; i<hex_len; i++){
    char first_digit = '0';
    int second_digit = '0';
    int third_digit = '0';
    int fourth_digit = '0';
    if(h[i] > 55){
      first_digit = '1'; 
    }
    if((h[i]>=52 && h[i]<=55) || (h[i]>=67 && h[i]<=70)){
      second_digit = '1'; 
    }
    if(h[i]==50||h[i]==51||h[i]==54||h[i]==55||
       h[i]==65||h[i]==66||h[i]==69||h[i]==70){
      third_digit = '1';
    }
    if((h[i]>=48 && h[i]<=57 && (h[i]%2==1)) || 
       (h[i]>=65 && h[i]<=70 && (h[i]%2==0))){
      fourth_digit = '1'; 
    }
    bin_str[i*4] = first_digit;
    bin_str[i*4+1] = second_digit;
    bin_str[i*4+2] = third_digit;
    bin_str[i*4+3] = fourth_digit;
  }
  bin_str[hex_len*4] = 0;
  return bin_str;
}

char *hex_to_bin_short(const char *h){
  assert(h);
  char *long_bin = hex_to_bin(h);
  int long_bin_len = strlen(long_bin);
  int num_leading_zero = 0;
  while(long_bin[num_leading_zero]=='0'){
    num_leading_zero++;
  }
  if(num_leading_zero == long_bin_len){
    char *short_bin = malloc(sizeof(char)*2);
    short_bin[0] = '0';
    short_bin[1] = 0;
    free(long_bin);
    return short_bin;
  }
  int short_bin_len = long_bin_len - num_leading_zero +1;
  char *short_bin = malloc(sizeof(char)*short_bin_len);
  int short_bin_counter = 0;
  for(int i = num_leading_zero; i<long_bin_len; i++,short_bin_counter++){
    short_bin[short_bin_counter] = long_bin[i];
  }
  short_bin[short_bin_len-1] = 0;
  free(long_bin);
  return short_bin;
}
/**
 File: test-str.c
 A simple test file for str-funct module
*/
#include <stdbool.h>
#include <assert.h>
#include "str-funct.h"



int main(void) {
  //test letter_freq_count
  int letters[27] ={0};
  letter_freq_count("aAbc", letters);
  assert(letters[0]==2);
  assert(letters[1]==1);
  assert(letters[2]==1);
  letter_freq_count("ZZaaZzazaHihIbye", letters);
  assert(letters[0]==4);
  assert(letters['z'-'a'] == 5);
  assert(letters['h'-'a']==2);
  assert(letters['i'-'a']==2);
  assert(letters['b'-'a']==1);
  assert(letters['y'-'a']==1);
  assert(letters['e'-'a']==1);
  assert(letters['h'-'f']==0);

  //test anagram
  assert(anagram("Comedian", "Demoniac"));
  assert(anagram("Listen", "silenT"));
  assert(!anagram("Listen", "silenTt"));

  //test ccount
  char s1[] = "abcd";
  char s2[] = "abc";
  const char *arr[] = {s1, s2};
  assert(ccount(arr, 2, 'a') == 2);
  assert(ccount(arr, 2, 'd') == 1);
  assert(ccount(arr, 2, 'A') == 2);
  assert(ccount(arr, 2, 'e') == 0);
}
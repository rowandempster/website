/* File: str-funct.h
A Module for working with Strings 
*/
#include <stdbool.h>

//letter_freq_count(s,count) updates count[i] to be the frequency count 
//  of each letter in string s.
//effects: modifies count
//requires: (length of count ==26)
//          s!=NULL
             
void letter_freq_count(const char *s, int count[]);


//anagram(s1,s2) returns true is s1 and s2 are anagrams
//  false otherwise
//requires: s1!=NULL
//          s2!=NULL
bool anagram(const char *s1,const char *s2);

//ccount(strings,len,ch) returns the number of occurences of character ch,
//  in all the strings within the array strings
//requires: ch > 0
//          strings!=NULL
//          len>0
int ccount(const char *strings[], int len, char ch);

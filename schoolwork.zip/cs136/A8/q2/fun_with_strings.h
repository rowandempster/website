#include <stdbool.h>

// a module for having fun with strings


// is_palindrome(str) determines if str is a palindrome
// time: O(n), n is the length of str

bool is_palindrome(const char *str);


// pig_latin(input, output) stores in output the Pig Latin of input
// requires: output is large enough to store the result
// effects: modifies output
// time: O(n), n is the length of input

void pig_latin(const char *input, char *output);


// mostfreq(str) finds the character that occurs the most
//   frequently in str (see assignment for more details)
// time: ???? You must specify this in your implementation

char mostfreq(const char *str);


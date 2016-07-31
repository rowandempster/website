// readchar: A C module for reading in ASCII characters from Input
#include <stdbool.h>


// readchar(ignore_ws) reads in an ASCII character from input
//   and returns the character or -1 if EOF.
//   if ignore_ws is true then it ignores whitespace (returns the next
//   non-whitespace character).  If false then it returns the next char
//   Note: maximum return value is 127
char readchar(bool ignore_ws);

// safe-to-add.h -- a module for checking if it is safe to do a calculation
#include <stdbool.h>

//safe_to_add(a, b) returns true if a and b can be added 
//   without overflow occuring, false otherwise
bool safe_to_add(int a, int b);

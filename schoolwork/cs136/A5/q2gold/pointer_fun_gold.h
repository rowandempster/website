#include <stdbool.h>

// You should complete this interface

//sum_and_range(n, sum, smallest, largest) returns false if n 
//   numbers are read succesfully, true otherwise
//requires: n>=0
//effects: may mutate sum, smallest, and or largest
bool sum_and_range(int n, int *sum, int *smallest, int *largest);

//sum_numbers(sum) returns how many numbers are read
//effects: mutates sum
int sum_numbers(int *sum);

#include <stdio.h>
#include <stdbool.h>

// A module for computing square roots

// within_tolerance(a,b,tolerance) determines if the absolute difference
//   between a and b is less than or equal to the tolerance
// requires: tolerance >= 0
bool within_tolerance(double a, double b, double tolerance);

//find_sqrt(n, tolerance) uses Newton's Iteration to 
//   approximate the square root of n up to accuracy 
//   'toleralnce'
//requires: n>=0
double find_sqrt(double n, double tolerance);

#include <stdbool.h>
#include <assert.h>
#include "sqrt.h"

// INTEGRITY STATEMENT (modify if necessary)
// I received help from the following sources:
// None. I am the sole author of this work 

// sign this statement by removing the line below and entering your name

// Name: Rowan Dempster
// login ID: R2DEMPST

// Implementation:

// see sqrt.h for details

bool within_tolerance(const double a, const double b, const double tolerance) {
  assert(tolerance >= 0);
  if (a < b) {
    return (b - a <= tolerance);
  } else {
    return (a - b <= tolerance);
  }
}

//find_sqrt_acc(n, tolerance, xk) returns the square root of n
//   with an accuracy of tolerance using accumulative 
//   recursion
//requires: n>=0;
double find_sqrt_acc(double n, double tolerance, double xk){
  assert(n>=0);
  if(within_tolerance(xk*xk, n, tolerance)){
    return xk;
  }
  else {
    return find_sqrt_acc(n, tolerance, (xk+(n/xk))/2); 
  }
}

double find_sqrt(double n, double tolerance){
  assert(n>=0 && tolerance>=0);
  return find_sqrt_acc(n, tolerance, 1);
}

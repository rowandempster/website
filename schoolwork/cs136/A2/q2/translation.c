#include "translation.h"

// see translation.h for documentation

// INTEGRITY STATEMENT (modify if necessary)
// I received help from the following sources:
// None. I am the sole author of this work 

// sign this statement by removing the line below and entering your name

// Name: Rowan Dempster
// login ID: R2DEMPST

// implementation functions below:


int polyeval(const int a, const int b, const int c, const int x) {
  return (a*(x*x)) + (b*x) + c;
}

int selector(const int a, const int x, const int y) {
 if (a != 0) {
  return x; 
 }
  else {
   return y; 
  }
}

int max3(const int a, const int b, const int c) {
 if ((a >= b) && (a >= c)) {
  return a; 
 }
 else if ((b >= a) && (b >= c)) {
  return b; 
 }
 else {
  return c; 
 }
}

int sumsqr1(const int n) {
 if (n == 0) {
  return 0; 
 }
 else {
  return (n*n) + sumsqr1(n-1); 
 }
}

//(sumsqr2acc n sofar) produces the sum of 1^2, 2^2, .... n^2 + sofar
int sumsqr2acc (const int n, const int sofar) {
 if (n == 0) {
  return sofar; 
 }
 else {
  return sumsqr2acc(n-1, (n*n) + sofar);
 }
}
int sumsqr2(const int n) {
  return sumsqr2acc(n,0);
}
                    
int sumsqr3(const int n) {
   return (n*(n+1)*(1+2*n))/6;
}
                    
int sameparity(const int a, const int b) {
 if ((((a%2)==0) && ((b%2)==0)) || (((a%2)==1) && ((b%2)==1))) {
  return 1; 
 }
  else {
   return 0; 
  }
}

// TRANSLATE THE RACKET CODE INTO C AS DIRECTLY AS POSSIBLE
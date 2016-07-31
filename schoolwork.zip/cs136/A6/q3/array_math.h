#include <stdbool.h>

// INTEGRITY STATEMENT (modify if necessary)
// I received help from the following sources:
// None. I am the sole author of this work

// sign this statement by removing the line below and entering your name

// Name: Rowan Dempster
// login ID: R2DEMPST

// interface:

//dot_product(a[], b[], s) returns the dot product of a and b
//requires: s>0;
int dot_product(int a[], int b[], int s);

//is_orthoganal(a[], b[], s) returns true if a and b are 
//   orthoganal, false otherwise
//requires: s>0
bool is_orthogonal(int a[], int b[], int s);

//add_to_vector(a[], b[], c[], s) changes the elements of c
//   to be the component wise sums of a and b
//requires: s>0
//effects: mutates c
void add_to_vector(int a[], int b[], int c[], int s);

//is_multiple(a[], b[], s) returns true if a is an integer
//   multiple of b, or if b is an integer multiple of a. 
//   Otherwise returns false.
//requires: s>0
bool is_multiple(int a[], int b[], int s);

//cross_product(a[], b[], c[]) stores the cross product of a
//   and b in c
//effects: mutates c
void cross_product(int a[], int b[], int c[]);



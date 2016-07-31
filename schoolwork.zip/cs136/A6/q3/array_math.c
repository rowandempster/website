#include "array_math.h"
#include <stdbool.h>
#include <assert.h>

// INTEGRITY STATEMENT (modify if necessary)
// I received help from the following sources:
// None. I am the sole author of this work

// sign this statement by removing the line below and entering your name

// Name: Rowan Dempster
// login ID: R2DEMPST

// implementation:

//see .h for descriptions
int dot_product(int a[], int b[], int s){
  assert(a&&b);
  assert(s>0);
  int result = 0;
  while(s>0){
    result+=a[s-1]*b[s-1];
    s--;
  }
  return result;
}

bool is_orthogonal(int a[], int b[], int s){
  assert(a&&b);
  assert(s>0);
  return 0 == dot_product(a, b, s); 
}

void add_to_vector(int a[], int b[], int c[], int s){
  assert(a&&b&&c);
  assert(s>0);
  int component_sum = 0;
  while(s>0){
    component_sum = a[s-1] + b[s-1];
    c[s-1] = component_sum;
    s--;
  }
}

bool is_multiple(int a[], int b[], int s){
  assert(a&&b);
  assert(s>0);
  int index = s-1;
  bool a_mult = true;
  bool b_mult = true;
  int a_mult_num;
  int b_mult_num;
  if((a[0]%b[0])!=0){
    a_mult = false; 
  }
  else{
    a_mult_num = a[0]/b[0];
  }
  if((b[0]%a[0]) != 0){
    b_mult = false; 
  }
  else{
    b_mult_num = b[0]/a[0];
  }
  while(index>=0){
    if(b[index]*a_mult_num != a[index]){
      a_mult = false; 
    }
    if(a[index]*b_mult_num != b[index]){
      b_mult = false; 
    }
    index--;
  }
  return a_mult || b_mult;
}

void cross_product(int a[], int b[], int c[]){
  assert(a&&b&&c);
  int first_row = a[1]*b[2] - a[2]*b[1]; 
  int second_row = a[2]*b[0] - a[0]*b[2]; 
  int third_row = a[0]*b[1] - a[1]*b[0];
  c[0] = first_row;
  c[1] = second_row;
  c[2] = third_row;
}
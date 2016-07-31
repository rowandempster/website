#include <stdio.h>
#include "user_io.h"

// INTEGRITY STATEMENT (modify if necessary)
// I received help from the following sources:
// None. I am the sole author of this work

// sign this statement by removing the line below and entering your name

// Name: Rowan Dempster
// login ID: R2DEMPST

// implementation:

//get_pos_float() returns the first valid positive float the
//   user enters
//effects: prints a message
static float get_pos_float(void){
  printf("Please enter a positive floating point number:\n");
  float read_float = readnonnegfloat();
  while(read_float<=0){
    printf("Invalid input.\n");
    printf("Please enter a positive floating point number:\n");
    read_float = readnonnegfloat();
  }
  return read_float;
}

//get_non_neg_int() returns the first valid non-negative 
//   integer the user enters
//effects: prints a message
static int get_non_neg_int(void){
  printf("Please enter a non-negative integer:\n");
  int read_int = readnat();
  while(read_int<0){
    printf("Invalid input.\n");
    printf("Please enter a non-negative integer:\n");
    read_int = readnat();
  }
  return read_int;
}

//get_float_greater() returns the first positive float 
//   greater than 0.5 that the user enters
//effects: prints a message
static float get_foat_greater(void){
  printf(
    "Please enter a positive floating point number greater or equal to 0.5:\n");
  float read_float = readnonnegfloat();
  while(read_float<=0.5){
    printf("Invalid input.\n");
    printf(
      "Please enter a positive floating \
point number greater or equal to 0.5:\n");
    read_float = readnonnegfloat();
  }
  return read_float;
}

//get_pos_int() returns the first positive integer that the
//   enters
//effects: prints a message
static int get_pos_int(void){
  printf("Please enter a positive integer:\n");
  int read_int = readnat();
  while(read_int<=0){
    printf("Invalid input.\n");
    printf("Please enter a positive integer:\n");
    read_int = readnat();
  }
  return read_int;
}

//print_kid(cones) prints out the number of cones a kid 
//   requested
//effects: prints a message
static void print_kid(int cones){
  if(cones==1){
    printf("requested 1 cone.\n");
  }
  else{
    printf("requested %d cones.\n", cones);
  }
}

int main(void){
  float f1 = get_pos_float();
  int n1 = get_non_neg_int();
  int n2 = get_non_neg_int();
  float f2 = get_foat_greater();
  int i1 = get_pos_int();
  int i2 = get_pos_int();
  int i3 = get_pos_int();
  int i4 = get_pos_int();
  int i5 = get_pos_int();
  int i6 = get_pos_int();
  int i7 = get_pos_int();
  printf("\n");
  printf("\n");
  printf("Seven kids, named Lesley, Rosina, Albert, Dan, \
Dave, Nomair and Tyler,\n\
went on their bikes to go to a playground %.2f kilometers away from\n\
their complex. They were all excited to spend %d hours playing there\n\
together. When they arrived, they heard %d bells ringing from a nearby\n\
ice-cream truck. Following their natural instincts, they ran to the truck\n\
immediately. Each ice-cream cone costs $%.2f, but the kids forgot to bring\n\
their money! Lucky for them, the ice-cream lady had had a good day, she\n\
decided to give each of them ice cream for free :-)\n", f1, n1, n2, f2);
  printf("Lesley ");
  print_kid(i1);
  if(i1>2){
    printf("Lesley was a greedy kid.\n");
  }
  printf("Rosina ");
  print_kid(i2);
  if(i2>2){
    printf("Rosina was a greedy kid.\n");
  }
  printf("Albert ");
  print_kid(i3);
  if(i3>2){
    printf("Albert was a greedy kid.\n");
  }
  printf("Dan ");
  print_kid(i4);
  if(i4>2){
    printf("Dan was a greedy kid.\n");
  }
  printf("Dave ");
  print_kid(i5);
  if(i5>2){
    printf("Dave was a greedy kid.\n");
  }
  printf("Nomair ");
  print_kid(i6);
  if(i6>2){
    printf("Nomair was a greedy kid.\n");
  }
  printf("Tyler ");
  print_kid(i7);
  if(i7>2){
    printf("Tyler was a greedy kid.\n");
  }

}


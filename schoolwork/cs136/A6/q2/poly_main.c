#include <stdio.h>
#include "poly_help.h"

// INTEGRITY STATEMENT (modify if necessary)
// I received help from the following sources:
// None. I am the sole author of this work

// sign this statement by removing the line below and entering your name

// Name: Rowan Dempster
// login ID: R2DEMPST

// implementation:

int main(void){
  printf("Please enter the degree of the polynomial you want to work with:\n");
  int orig_deg = 0;
  int deg_array[orig_deg+1];
  int deg_count = scanf("%d", &orig_deg);
  if(deg_count!=1 || orig_deg<0){
    printf("Haha, very funny!\n"); 
  }
  else{
    int early_exit = 0;
    int coef_entered;
    int copy_deg = orig_deg;
    printf("Please enter all the coefficients, beginning from\
 highest degree to lowest:\n");
    while(copy_deg>=0){
      int coef_count = scanf("%d", &coef_entered);
      if(coef_count!=1){
        printf("Preliminary exit of the program.\n"); 
        early_exit = 1;
      }
      else if(coef_entered==0 && copy_deg == orig_deg){
        while(coef_entered==0){
          printf("Leading coefficient is not allowed to be \
zero. Please enter a non-zero number:\n");
          scanf("%d", &coef_entered);
        }
        deg_array[copy_deg] = coef_entered;
      }
      else{
        deg_array[copy_deg] = coef_entered; 
      }
      copy_deg--;
    }
    printf("Successfully received all coefficients \
of the polynomial. It looks like:\n");
    print_polynomial(deg_array, orig_deg);
  }
  int x_val;
  int x_count = scanf("%d", &x_val);
  while(x_count == 1){
    printf("%d\n", eval_polynomial(deg_array, orig_deg, x_val));
    x_count = scanf("%d", &x_val);
  }
}

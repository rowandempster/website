#include <stdio.h>
#include "poly_help.h"
#include <assert.h>

// INTEGRITY STATEMENT (modify if necessary)
// I received help from the following sources:
// None. I am the sole author of this work

// sign this statement by removing the line below and entering your name

// Name: Rowan Dempster
// login ID: R2DEMPST

// implementation:

//see .h for description
void print_polynomial(int f[], int degf){
  assert(f);
  int first_term = 1;
  int put_zero = 1;
  while(degf>=0){
    int coef = f[degf];
    if(first_term){
      if(degf==0){
        printf("%d", coef); 
        put_zero = 0;
      }
      else if(coef == 0){
        //do nothing 
      }
      else{
        printf("%d*x^%d", coef, degf);
        first_term = 0;
      }
    }
    else{
      if(degf==0&&coef!=0){
        if(coef>0){
          printf(" + %d", coef);
        }
        else{
          printf(" - %d", -1*coef); 
        }
      }
      else{
        if(coef>0){
          printf(" + %d*x^%d", coef, degf);  
        }
        else if(coef==0){
          //do nothing 
        }
        else{
          printf(" - %d*x^%d", -1*coef, degf);  
        }
      }
    }
    degf--;
  }
  if(first_term&&put_zero){
    printf("0\n"); 
  }
  else{
    printf("\n"); 
  }
}

//exp(base, power) returns base raised to the power of 'power'
//requires: power>=1
static int my_exp(int base, int power){
  int result = 1;
 while(power>0){
   result *=base;
   power--;
 }
  return result;
}

//see .h for description
int eval_polynomial(int f[], int degf, int val){
  int result = 0;
  if(f==NULL){
   return 0; 
  }
  while(degf>=0){
    result += f[degf]*my_exp(val, degf);
    degf--;
  }
  return result;
}

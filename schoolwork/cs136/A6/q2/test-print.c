#include "poly_help.h"
#include <stdio.h>

int main(void){
  int f[4] = {1,0,-5,-4};
  int degf = 3;
  print_polynomial(f, degf);
  int f2[4] = {-1, 0, 0, 0};
  degf = 1;
  print_polynomial(f2, degf);
  int f3[4] = {0, 0, -2, 0};
  degf = 2;
  print_polynomial(f3, degf);
  int f4[7] = {-5, 2, 0, -3, 4, 0, 0};
  degf = 4;
  print_polynomial(f4, degf);
  int f5[3] = {1, 2, 1};
  degf = 2;
  printf("%d\n", eval_polynomial(f5, degf, 2));
  degf = 3;
  printf("%d\n", eval_polynomial(f, degf, -3));
  degf = 1;
  printf("%d\n", eval_polynomial(f2, degf, 50));
}
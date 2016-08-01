#include "array_math.h"
#include <stdio.h>

int main(void){
  int a[3] = {1,2,3};
  int b[3] = {3,2,1};
  int len = 3;
  printf("%d\n", dot_product(a, b, len));
  int a2[4] = {1, 2, 3, 4};
  int b2[4] = {4, -3, 2, -1};
  int len2 = 4;
  printf("%d\n", is_orthogonal(a2, b2, len2));
  int c[4];
  add_to_vector(a2, b2, c, len2);
  for(int i = 0; i<len2; i++){
    if(i==len2-1){
      printf("%d", c[i]); 
    }
    else{
      printf("%d ", c[i]); 
    }
  }
  printf("\n");
  int a3[3] = {2, 4, 6};
  int b3[3] = {1, 2, 3};
  int s3 = 3;
  printf("%d\n", is_multiple(a3,b3,s3));
  int a4[4] = {20, 60, 100, 250};
  int b4[4] = {10, 30, 50, 125};
  int s4 = 4;
  printf("%d\n", is_multiple(a4,b4,s4));
  int a5[3] = {3, -1, 5};
  int b5[3] = {2, 0, 2};
  int s5 = 3;
  int c5[3];
  cross_product(a5,b5,c5);
  for(int i = 0; i<s5; i++){
    if(i==s5-1){
      printf("%d", c5[i]); 
    }
    else{
      printf("%d ", c5[i]); 
    }
  }
  printf("\n");
  int a6[3] = {-1, 0, 5};
  int b6[3] = {4, 50, -4};
  int len6 = 3;
  printf("%d\n", dot_product(a6, b6, len6));
  int a7[3] = {-2, -4, 6};
  int b7[3] = {1, 2, -3};
  int len7 = 3;
  printf("%d\n", is_multiple(a7,b7,len7));
  int a8[3] = {-2, -4, -6};
  int b8[3] = {1, 2, -3};
  int len8 = 3;
  printf("%d\n", is_multiple(a8,b8,len8));
}
#include "user_io.c"
#include <stdio.h>

int main(void){
  printf("Int: %d\n", readnat());
  
  printf("Float: %f\n", readnonnegfloat());
  
}

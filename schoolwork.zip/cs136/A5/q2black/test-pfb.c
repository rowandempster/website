#include <stdio.h>
#include "pointer_fun_black.h"

// this is a very basic test client
// you should test your code more thoroughly

int main(void) {
  int a = 0;
  int b = 0;
  int n = read_two(&a, &b);

  printf("%d, %d, %d\n", n, a, b);
}
  
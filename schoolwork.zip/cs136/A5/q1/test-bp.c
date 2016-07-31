#include <assert.h>
#include "basic_pointer.h"

// this is a very basic test client
// you should test your code more thoroughly

int main(void) {
  int small = 1;
  int big = 2;
  
  down_value(&small, &big);
  assert(big == small);
}

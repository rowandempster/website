#include <stdio.h>
#include "readnat.h"

// INTEGRITY STATEMENT (modify if necessary)
// I received help from the following sources:
// None. I am the sole author of this work 

// sign this statement by removing the line below and entering your name

// Name: Rowan Dempster
// login ID: R2DEMPST
  
  

int read_longest_nodec(const int prev, const int curr_nondec, const int longest_so_far) {
  const int num = readnat();
  if (num == -1) {
    return longest_so_far;
  } else if ((num >= prev) && ((curr_nondec+1)>longest_so_far)) {
    return read_longest_nodec(num, curr_nondec+1, curr_nondec+1);
  } else if (num>=prev) {
    return read_longest_nodec(num, curr_nondec+1, longest_so_far);  
  }
  else {
   return  read_longest_nodec(num, 1, longest_so_far);
  }
}

int main(void) {
  const int longest = read_longest_nodec(0, 0, 0);
    printf("%d\n", longest);
  
}


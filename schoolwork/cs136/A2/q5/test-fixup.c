// INTEGRITY STATEMENT (modify if necessary)
// I received help from the following sources:
// None. I am the sole author of this work 

// sign this statement by removing the line below and entering your name

// Name: Rowan Dempster
// login ID: R2DEMPST

  
  
// complete this testing client using the assert method

#include <assert.h>
#include "fixup.h"


/*return ((cs_average >= min_cs_average) &&
          (math_average >= min_math_average) &&
          (total_average >= min_total_average) &&
          (num_failures <= max_failures));*/

int main(void){
 assert(cs136_final_grade(49, 50, 30) == 30);
 assert(cs136_final_grade(49, 50, 50) == 47);
 assert(cs136_final_grade(50, 49, 49) == 47);
 assert(cs136_final_grade(50, 49, 45) == 45);
 assert(cs136_final_grade(50, 50, 49) == 47);
 assert(cs136_final_grade(50, 50, 40) == 40);
 assert(cs136_final_grade(50, 50, 50) == 50);
 assert(cs136_final_grade(50, 50, 99) == 99);
  
  assert(can_switch_to_cs(70, 100, 100, 0) == 1);
  assert(can_switch_to_cs(69, 100, 100, 0) == 0);
  assert(can_switch_to_cs(100, 65, 100, 0) == 1);
  assert(can_switch_to_cs(100, 64, 100, 0) == 0);
  assert(can_switch_to_cs(100, 100, 65, 0) == 1);
  assert(can_switch_to_cs(100, 100, 64, 0) == 0);
  assert(can_switch_to_cs(100, 100, 100, 2) == 1);
  assert(can_switch_to_cs(100, 100, 100, 3) == 0);
  
}

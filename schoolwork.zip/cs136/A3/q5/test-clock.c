#include <stdio.h>
#include "clock.h"

// This is a VERY simple test client for the clock module.

int main(void) {
  struct time12 one_am = {1, 0, 0, false};
  struct time12 one_pm = {1, 0, 0, true};
  struct time24 one_am_24 = convert(one_am);
  struct time12 my_time = {12, 59, 59, false};
  struct time12 my_time_1 = {12, 59, 59, true};
  struct time12 my_time_2 = {1, 59, 59, true};
  struct time12 my_time_3 = {11, 59, 59, true};
  struct time12 my_time_4 = {12, 00, 00, false};
  struct time12 my_time_5 = {12, 2, 31, false};
  struct time12 my_time_6 = {1, 00, 00, false};
  struct time24 my_time24_incremented = {13, 0, 0};

  print12(one_am);
  printf("\n");
  print24(one_am_24);
  printf("\n");
  printf("%d\n", timediff(one_am, one_pm));
  print12(increment(one_am));
  printf("\n");
  print12(time_max(one_am, one_pm));
  printf("\n");
  printf("%d\n", time_to_midnight(one_am_24));
  print12(convert24_12(my_time24_incremented));
  printf("\n");
  print12(increment(my_time));
  printf("\n");
  print24(convert(my_time));
  printf("\n");
  print24(convert(my_time_1));
  printf("\n");
  print24(convert(my_time_2));
  printf("\n");
  print24(convert(my_time_3));
  printf("\n");
  print24(convert(my_time_4));
  printf("\n");
  printf("%d\n", timediff(my_time, my_time_4));
  printf("%d\n", timediff(my_time_4, my_time));
  printf("%d\n", timediff(my_time_4, my_time_5));
  printf("%d\n", timediff(my_time_5, my_time_4));
  print12(increment(my_time_1));
  printf("\n");
  print12(increment(my_time_2));
  printf("\n");
  print12(increment(my_time_3));
  printf("\n");
  print12(increment(my_time_4));
  printf("\n");
  print12(increment(my_time_5));
  printf("\n");
  print12(increment(my_time_6));
  printf("\n");
  print12(time_max(my_time_1, my_time_2));
  printf("\n");
  print12(time_max(my_time_2, my_time_1));
  printf("\n");
  print12(time_max(my_time_3, my_time_4));
  printf("\n");
  print12(time_max(my_time_5, my_time_6));
  printf("\n");
  printf("%d\n", time_to_midnight(convert(my_time_1)));
  printf("%d\n", time_to_midnight(convert(my_time_2)));
  printf("%d\n", time_to_midnight(convert(my_time_3)));
  printf("%d\n", time_to_midnight(convert(my_time_4)));
  printf("%d\n", time_to_midnight(convert(my_time_5)));
}

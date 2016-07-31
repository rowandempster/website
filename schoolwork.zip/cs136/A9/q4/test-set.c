#include "set.h"
#include <stdio.h>
#include <assert.h>

const int NUM_NUMBERS = 6;
int LOST_NUMBERS[NUM_NUMBERS] = {4,8,15,16,23,42};

const int NUM_SERIES = 8;

int main(void) {
  struct Set *lost = set_create();
  for (int i = 0; i < NUM_NUMBERS; ++i) {
    set_add(lost,LOST_NUMBERS[i]);
  }
  assert(set_size(lost) == NUM_NUMBERS);
  set_print(lost);

  struct Set *series = set_create();
  for (int i =1  ; i <= NUM_SERIES; ++i) {
    set_add(series, i);
  }	

  struct Set *u = set_union(lost,series);
  struct Set *i = set_intersect(lost,series);

  set_print(u);
  set_print(i);
  set_remove(i,4);
  set_print(i);

  set_destroy(lost);
  set_destroy(series);
  set_destroy(u);
  set_destroy(i);



  struct Set *my_set = set_create();
  set_add(my_set, 5);
  set_add(my_set, 0);
  set_add(my_set, 10);
  set_add(my_set, 8);
  set_add(my_set, 3);
  set_add(my_set, -1);
  set_add(my_set, 11);
  set_add(my_set, 11);
  set_add(my_set, 5);
  set_add(my_set, 0);
  set_add(my_set, 10);
  set_add(my_set, 8);
  set_add(my_set, 3);
  set_add(my_set, -1);
  set_add(my_set, 11);

  set_print(my_set);

  set_remove(my_set, 11);
  set_remove(my_set, 5);
  set_remove(my_set, -1);
  set_remove(my_set, 8);
  set_remove(my_set, 10);
  set_remove(my_set, 3);
  set_remove(my_set, 8);
  set_remove(my_set, 10);
  set_remove(my_set, 3);
  set_remove(my_set, 0);

  set_print(my_set);

  for (int i =0  ; i <= 551; ++i) {
    set_add(my_set, i);
  }	
  set_print(my_set);

  for (int i =55  ; i <= 500; ++i) {
    set_remove(my_set, i);
  }	
  set_print(my_set);

  for (int i =0  ; i <= 1000; ++i) {
    set_remove(my_set, i);
  }	
  set_print(my_set);

  struct Set *my_set_2 = set_create();
    for (int i =-5  ; i <= 20; ++i) {
    set_add(my_set, i);
  }
      for (int i =0  ; i <= 100; ++i) {
    set_add(my_set_2, i);
  }
  struct Set *my_u = set_union(my_set, my_set_2);
  set_print(my_u);
  struct Set *my_i = set_intersect(my_set, my_set_2);
  set_print(my_i);

  set_destroy(my_set);
  set_destroy(my_set_2);
  set_destroy(my_u);
  set_destroy(my_i);

}
#include <assert.h>
#include "student.h"
#include <stdio.h>


// this is a very basic test client
// you should test your code more thoroughly

int main(void) {
  struct student s = {.id = 12345};
  initialize_new_student(&s);
  print_status(&s);
  print_student(&s);
  assert(student_equals(&s, &s));
  take_course(&s, 70, true);
  take_course(&s, 72, false);
  adjust_grade(&s, 72, 73, false);
  assert(cs_average(&s) == 70);
  assert(cav(&s) == 71);
  assert(!can_graduate(&s));
  struct student test1 = {.id = 1};
  initialize_new_student(&test1);
  assert(cs_average(&test1) == 0);
  assert(cav(&test1) == 0);
  take_course(&test1, 100, true);
  assert(cs_average(&test1) == 100);
  assert(cav(&test1) == 100);
  take_course(&test1, 50, false);
  assert(cs_average(&test1) == 100);
  assert(cav(&test1) == 75);
  adjust_grade(&test1, 50, 100, false);
  assert(cav(&test1) == 100);
  take_course(&test1, 49, false);
  take_course(&test1, 49, false);
  take_course(&test1, 49, false);
  take_course(&test1, 49, false);
  take_course(&test1, 49, false);
  print_status(&test1);
  adjust_grade(&test1, 49, 50, false);
  print_status(&test1);
  adjust_grade(&test1, 49, 50, false);
  print_status(&test1);
  take_course(&test1, 49, false);
  print_status(&test1);
  struct student test2 = {.id = 2};
  take_course(&test2, 100, false);
  print_status(&test2);
  take_course(&test2, 0, true);
  print_status(&test2);
  struct student test3 = {.id = 3};
  take_course(&test3, 100, true);
  take_course(&test3, 0, false);
  print_status(&test3);
  struct student test4 = {.id = 4};
  take_course(&test4, 85, false);
  take_course(&test4, 85, false);
  take_course(&test4, 20, true);
  print_status(&test4);
  take_course(&test4, 100, true);
  print_status(&test4);
  take_course(&test4, 100, true);
  take_course(&test4, 100, true);
  take_course(&test4, 100, true);
  print_status(&test4);
  print_student(&test3);
  struct student s3_copy = {.id = 3};
  take_course(&s3_copy, 0, false);
  take_course(&s3_copy, 100, true);
  printf("%d\n", student_equals(&test3, &s3_copy));
  take_course(&s3_copy, 100, true);
  printf("%d\n", student_equals(&test3, &s3_copy));
}



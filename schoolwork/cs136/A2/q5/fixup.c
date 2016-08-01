#include "fixup.h"
#include <assert.h>

// no purposes are provided
// you must infer the purpose of each function

static const int passing_grade = 50;
static const int max_failing_grade = 47;

static int min(const int a, const int b) {
  if (a <= b) {
    return a;
  } else {
    return b;
  }
}

// a friendly reminder (from the interface):
// requires: 0 <= (all parameters) <= 100

int cs136_final_grade(const int assn_avg, 
                      const int exam_avg, 
                      const int calculated_grade) {
  assert(0<=assn_avg && assn_avg<=100);
  assert(0<=exam_avg && exam_avg <=100);
  assert(0<=calculated_grade && calculated_grade <=100);
  if ((min(assn_avg, exam_avg) < passing_grade) ||
      (calculated_grade < passing_grade)) {
    return min(max_failing_grade, calculated_grade);
  } else {
    return calculated_grade;
  }
}


static const int min_cs_average = 70;
static const int min_math_average = 65;
static const int min_total_average = 65;
static const int max_failures = 2;

// a friendly reminder (from the interface):
// requires: 0 <= (all _average parameters) <= 100
//           num_failures >= 0

int can_switch_to_cs(const int cs_average,
                     const int math_average,
                     const int total_average,
                     const int num_failures) {
  assert(0<=cs_average && cs_average<=100);
  assert(0<=math_average&&cs_average<=100);
  assert(0<=total_average&&total_average<=100);
  assert(0<=num_failures);
  return ((cs_average >= min_cs_average) &&
          (math_average >= min_math_average) &&
          (total_average >= min_total_average) &&
          (num_failures <= max_failures));
}

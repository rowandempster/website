// fixup.h

// no purposes are provided
// you must infer the purpose of each function


// requires: 0 <= (all parameters) <= 100

int cs136_final_grade(const int assn_avg, 
                      const int exam_avg, 
                      const int calculated_grade);


// requires: 0 <= (all _average parameters) <= 100
//           num_failures >= 0

int can_switch_to_cs(const int cs_average,
                     const int math_average,
                     const int total_average,
                     const int num_failures);

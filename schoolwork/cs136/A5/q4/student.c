#include <stdio.h>
#include <assert.h>
#include <stdbool.h>
#include "student.h"

// INTEGRITY STATEMENT (modify if necessary)
// I received help from the following sources:
// None. I am the sole author of this work 

// sign this statement by removing the line below and entering your name

// Name: Rowan Dempster
// login ID: R2DEMPST

// implementation:

//see .h for descriptions
void initialize_new_student(struct student *s) {
  assert(s);
  s->all_courses_taken = 0;
  s->cs_courses_taken = 0;
  s->all_total_points = 0;
  s->cs_total_points = 0;
  s->all_average = 0;
  s->cs_average = 0;
  s->failed = 0;
  s->failed_cs = 0;
}

void take_course(struct student *s, int grade, bool cs) {
  assert(s);
  assert(grade>=0 && grade<=100);
  if(grade<50){
    s->failed++; 
    if(cs){
      s->failed_cs++;
    }
  }
  if(cs){
    s->all_courses_taken++;
    s->cs_courses_taken++;
    s->all_total_points += grade;
    s->cs_total_points += grade;
    s->all_average = (s->all_total_points/s->all_courses_taken);
    s->cs_average = (s->cs_total_points/s->cs_courses_taken);
  }
  else{
    s->all_courses_taken++;
    s->all_total_points += grade;
    s->all_average = (s->all_total_points/s->all_courses_taken);
  }
}

void adjust_grade(struct student *s, int original_grade, 
                  int new_grade, bool cs){
  assert(s);
  assert(original_grade>=0 && original_grade<=100);
  assert(new_grade>=0 && new_grade<=100);
  if((original_grade<50)&&(new_grade>=50)){
    s->failed--; 
    if(cs){
      s->failed_cs--;
    }
  }
  if((original_grade>=50)&&(new_grade<50)){
    s->failed++; 
    if(cs){
      s->failed_cs++;
    }
  }
  int grade_diff = new_grade-original_grade;
  if(cs){
    s->all_total_points+=grade_diff;
    s->cs_total_points += grade_diff;
    s->all_average = s->all_total_points/s->all_courses_taken;
    s->cs_average = s->cs_total_points/s->cs_courses_taken;
  }
  else{
    s->all_total_points+=grade_diff;
    s->all_average = s->all_total_points/s->all_courses_taken;
  }
}

int cs_average(const struct student *s){
  assert(s);
  return s->cs_average; 
}

int cav(const struct student *s){
  assert(s);
  return s->all_average; 
}

void print_status (const struct student *s){
  assert(s);
  if((s->all_courses_taken) ==0){
    printf("NONE\n");
  }
  else if(s->failed>4){
    printf("FRW\n");
  }
  else if(s->failed>(s->all_courses_taken-s->failed)){
    printf("FRW\n");
  }
  else if(s->cs_courses_taken == 0){
    printf("NOCS\n"); 
  }
  else if((s->cs_average<60)&&(s->all_average<60)){
    printf("FLPP\n"); 
  }
  else if(s->all_average<60){
    printf("PRBO\n"); 
  }
  else if(s->cs_average<60){
    printf("CNDP\n"); 
  }
  else if((s->all_average>=60)&&(s->all_average<80)){
    printf("GOOD\n"); 
  }
  else if(s->all_average>=80){
    printf("EXCL\n"); 
  }
  else{
    printf("ERROR: No status achievable"); 
  }
}

void print_student(const struct student *s){
  assert(s);
  printf("Student: %d, CAV: %d, CS_AVG: %d, Failures: %d, Status: ",
         s->id, s->all_average, s->cs_average, s->failed);
  print_status(s);
}

bool student_equals(const struct student *s1, const struct student *s2){
  assert(s1&&s2);
  return ((s1->id == s2->id)&&
          (s1->all_courses_taken == s2->all_courses_taken)&&
          (s1->cs_courses_taken == s2->cs_courses_taken)&&
          (s1->all_total_points == s2->all_total_points)&&
          (s1->cs_total_points == s2->cs_total_points)&&
          (s1->all_average == s2->all_average)&&
          (s1->cs_average == s2->cs_average)&&
          (s1->failed == s2->failed)&&
          (s2->failed_cs == s2->failed_cs));
}

bool can_graduate(const struct student *s){
  assert(s);
  int course_criteria = 0;
  int grade_criteria = 0;
  if(((s->all_courses_taken)-(s->failed)>=40)&&
     (s->cs_courses_taken-(s->failed_cs)>=15)){
    course_criteria = 1; 
  }
  if(s->all_average >= 60){
    grade_criteria = 1; 
  }
  if(course_criteria&&grade_criteria){
    return true;
  }
  return false;
}








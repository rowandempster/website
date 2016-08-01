#include <stdio.h>
#include "clock.h"

// INTEGRITY STATEMENT (modify if necessary)
// I received help from the following sources:
// None. I am the sole author of this work 

// sign this statement by removing the line below and entering your name

// Name: Rowan Dempster
// login ID: R2DEMPST

//Time consants:
const int sec_per_min = 60;
const int min_per_hour = 60;
const int hour_per_day = 24;
const int convert12_24 = 12;
const int cutoff24_12 = 13;

// see clock.h for details

void print12(struct time12 t){
  if(t.pm) {
    printf("%02d:%02d:%02d pm", t.hour, t.minute, t.second); 
  }
  else {
    printf("%02d:%02d:%02d am", t.hour, t.minute, t.second); 
  }
}

void print24(struct time24 t){
  printf("%02d:%02d:%02d", t.hour, t.minute, t.second);
}

struct time24 convert(struct time12 t){
  if(t.pm && t.hour<convert12_24) {
    struct time24 t24 = {t.hour+convert12_24, t.minute, t.second};
    return t24; 
  }
  else if (t.pm && t.hour==convert12_24) {
    struct time24 t24 = {t.hour, t.minute, t.second};
    return t24; 
  }
  else if (!(t.pm) && t.hour==convert12_24) {
    struct time24 t24 = {t.hour-convert12_24, t.minute, t.second};
    return t24; 
  }
  else {
    struct time24 t24 = {t.hour, t.minute, t.second};
    return t24; 
  }
}

//abs(num) returns the abslute value of num
int abs(const int num) {
  if(num<0) {
    return (-1)*num;
  }
  else {
    return num; 
  }
}

int timediff(struct time12 t1, struct time12 t2){
  struct time24 t1_24 = convert(t1); 
  struct time24 t2_24 = convert(t2); 
  const int hour_diff = abs(t1_24.hour - t2_24.hour);
  const int minute_diff = abs(t1_24.minute - t2_24.minute);
  const int second_diff = abs(t1_24.second - t2_24.second);
  const int total_second_diff = hour_diff*sec_per_min*min_per_hour 
    + minute_diff*sec_per_min + second_diff;
  return total_second_diff;
}

//see .h for description 
struct time12 convert24_12 (struct time24 t) {
  if(t.hour>=convert12_24 && t.hour<cutoff24_12) {
    struct time12 t12 = {t.hour, t.minute, t.second, true};
    return t12; 
  }
  else if(t.hour>=cutoff24_12) {
    struct time12 t12 = {t.hour-convert12_24, t.minute, t.second, true};
    return t12; 
  }
  else if (t.hour<1) {
    struct time12 t12 = {t.hour+convert12_24, t.minute, t.second, false};
    return t12; 
  }
  else {
    struct time12 t12 = {t.hour, t.minute, t.second, false};
    return t12; 
  }
}

struct time12 increment(struct time12 t){
  struct time24 t_24 = convert(t);
  t_24.second +=1;
  if(t_24.second == sec_per_min){
    t_24.second = 0;
    t_24.minute +=1;
  }
  if(t_24.minute == min_per_hour) {
    t_24.minute = 0;
    t_24.hour +=1;
  }
  if(t_24.hour == hour_per_day) {
    t_24.hour = 0;
  }
  struct time12 t_12 = convert24_12(t_24);
  return t_12;
}

struct time12 time_max(struct time12 t1, struct time12 t2){
  struct time24 t24_1 = convert(t1);
  struct time24 t24_2 = convert(t2);
  int time_past1 = (t24_1.hour)*sec_per_min*min_per_hour 
    + (t24_1.minute)*sec_per_min + (t24_1.second);
  int time_past2 = (t24_2.hour)*sec_per_min*min_per_hour 
    + (t24_2.minute)*sec_per_min + (t24_2.second);
  if(time_past1>time_past2) {
    return t1; 
  }
  else {
    return t2; 
  }
}

int time_to_midnight(struct time24 t){
  int seconds = (hour_per_day-(t.hour+1))*sec_per_min*min_per_hour 
    + (sec_per_min-t.minute)*sec_per_min -t.second;
  return seconds;
}


#include <stdbool.h>

// A module for working with times

struct time12 {
  int hour;
  int minute;
  int second;
  bool pm;
};

struct time24 {
  int hour;
  int minute;
  int second;
};

// SEE THE ASSIGNMENT TEXT FOR ADDITIONAL DETAILS

// ALL of these functions also *require* that any parameters
// are valid time12 (or time24) structures
// however: you are NOT required to assert those requirements
// you may assume that the parameters are valid

// print12(t) prints out t
// effects: prints out a message
void print12(struct time12 t);

// print24(t) prints out t
// effects: prints out a message
void print24(struct time24 t);

// convert(t) converts t from a time12 to a time24
struct time24 convert(struct time12 t);

// timediff(t1, t2) determines the number of seconds between t1 and t2
int timediff(struct time12 t1, struct time12 t2);

// increment(t) returns t one second later
struct time12 increment(struct time12 t);

// time_max(t1, t2) returns either t1 or t2, whichever is later in the day
struct time12 time_max(struct time12 t1, struct time12 t2);

// time_to_midnight(t) determines how many seconds from t until midnight
int time_to_midnight(struct time24 t);

// convert24_12(t) converts t from a time24 to a time12
struct time12 convert24_12 (struct time24 t);

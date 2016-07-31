// a module for having fun with ints

// closest (arr, len, &first, &next) finds the closest pair
//   of integers in arr, stores the smaller of the pair
//   in *first, stores the larger of the pair in *next,
//   and returns the difference between them. 
// requires: arr, first and next are not NULL
//           len >= 2.
// effects: mutates first, next, and possibly arr
// time: ???? You must specify this in your implementation
int closest(int arr[], int len, int *first, int *next);


// longest_seq (arr, len) finds the length of the
//   longest sequence of non-decreasing integers in arr,
//   and returns the length of that sequence.
// requires: arr is not NULL
//           len > 0
// time: ???? You must specify this in your implementation
int longest_seq(int arr[], int len);

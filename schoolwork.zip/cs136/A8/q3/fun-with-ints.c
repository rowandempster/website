#include <string.h>
#include "fun-with-ints.h"
#include <assert.h>


// INTEGRITY STATEMENT (modify if necessary)
// I received help from the following sources:
// None. I am the sole author of this work 

// sign this statement by removing the line below and entering your name

// Name: Rowan Dempster
// login ID: R2DEMPST

// implementation:

//swap(x,y) swaps the value of what x and y points to
//requires: x and y != NULL
//effects: mutates x and y
//time: O(1)
static void swap(int *x, int *y) {
  int temp_x = *x;
  *x = *y;
  *y = temp_x;
}

//selection_sort(arr, len) sorts arr in non decending order
//requires: arr != NULL and the length of arr is len
//effects: mutates arr
//time: O(n^2), where n is len
static void selection_sort(int arr[], int len) {
  for (int next=0; next < len - 1; next++) {
    int smallest_pos = next;
    for (int smallest = next+1; smallest < len; smallest++) {
      if (arr[smallest] < arr[smallest_pos]) {
        smallest_pos = smallest;
      } }
    swap(&arr[next], &arr[smallest_pos]);
  }
}

// time: O(n^2) + O(n) + O(n) = O(n^2)
int closest(int arr[], int len, int *first, int *next) {
  assert(arr&&first&&next);
  //O(n^2) sorting
  selection_sort(arr, len);
  int dist = 0;
  int min_dist = arr[1] - arr[0];
  int temp_first = 0;
  int temp_next = 1;
  //O(n), where n is len
  for(; temp_next<len; temp_first++, temp_next++){
    dist = arr[temp_next] - arr[temp_first];
    if(dist<min_dist){
      min_dist = dist; 
    }
  }
  temp_first = 0;
  temp_next = 1;
  //O(n), where n is len
  for(; temp_next<len; temp_first++, temp_next++){
    dist = arr[temp_next] - arr[temp_first];
    if(dist == min_dist){
      *first = arr[temp_first];
      *next = arr[temp_next];
      return dist;
    }
  }
  return 0;
}


// time: O(n)
int longest_seq(int arr[], int len) { 
  int longest_seq = 0;
  int curr_seq = 1;
  int last_element = arr[0];
  if(len<=1){
    return curr_seq; 
  }
  //O(n) where n is len
  for(int i = 1; i<len; i++){
    if(arr[i]>=last_element){
      curr_seq++;
    }
    else{
      if(curr_seq>longest_seq){
        longest_seq = curr_seq; 
      }
      curr_seq = 1;
    }
    last_element = arr[i];
  }
  return longest_seq;
}
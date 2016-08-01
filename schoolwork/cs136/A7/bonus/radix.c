/**
File: radix.c
Bonus Question
*/

#include <stdio.h>
#include <assert.h>

// INTEGRITY STATEMENT (modify if necessary)
// I received help from the following sources:
// None. I am the sole author of this work 

// sign this statement by removing the line below and entering your name

// Name: Rowan Dempster
// login ID: R2DEMPST

// implementation:

//stacks acting as the radix sort buckets
struct stack {
  int len;
  int maxlen;
  int data[100];
};

// stack_pop(s) removes the top of stack s and returns it
// requires: s != NULL
//effects: mutates s
int stack_pop(struct stack *s) {
  assert(s);
  assert(s->len);
  s->len -= 1;
  return s->data[s->len];
}

//stack_push(item, s) pushes item onto the top of stack s
//requires: s != NULL
//effects: mutates s
void stack_push(int item, struct stack *s) {
  assert(s);
  s->data[s->len] = item;
  s->len += 1; }

//I coded this with 99% certainty that it wouldn't work...
//   but it did :D
//radix_sort(arr, len) sorts arr accoring to the Radix 
//   Algiorithm in place using the stack ADT
//requires: arr != NULL and len=length(arr)
//effects: mutates arr
void radix_sort(int arr[],int len)
{
  assert(arr);
  struct stack zero_stack;
  struct stack one_stack;
  struct stack two_stack;
  struct stack three_stack;
  struct stack four_stack;
  struct stack five_stack;
  struct stack six_stack;
  struct stack seven_stack;
  struct stack eight_stack;
  struct stack nine_stack;

  int s0_len = 0;
  int s1_len = 0;
  int s2_len = 0;
  int s3_len = 0;
  int s4_len = 0;
  int s5_len = 0;
  int s6_len = 0;
  int s7_len = 0;
  int s8_len = 0;
  int s9_len = 0;

  int largest_num = arr[0];
  for(int i = 1; i<len; i++){
    if(arr[i]>largest_num){
      largest_num = arr[i]; 
    }
  }
  int largest_num_copy = largest_num;
  int digits = 0;
  while (largest_num_copy){
    largest_num_copy/=10;
    digits++;
  }
  int mod_counter = 1;
  while(digits>0){
    for(int i = 0; i<len; i++){
      if(arr[i]/mod_counter % 10 == 0){
        stack_push(arr[i], &zero_stack);
        s0_len++;
      }
      else if(arr[i]/mod_counter % 10 == 1){
        stack_push(arr[i], &one_stack);
        s1_len++;
      }
      else if(arr[i]/mod_counter % 10 == 2){
        stack_push(arr[i], &two_stack);
        s2_len++;
      }
      else if(arr[i]/mod_counter % 10 == 3){
        stack_push(arr[i], &three_stack);
        s3_len++;
      }
      else if(arr[i]/mod_counter % 10 == 4){
        stack_push(arr[i], &four_stack);
        s4_len++;
      }
      else if(arr[i]/mod_counter % 10 == 5){
        stack_push(arr[i], &five_stack);
        s5_len++;
      }
      else if(arr[i]/mod_counter % 10 == 6){
        stack_push(arr[i], &six_stack);
        s6_len++;
      }
      else if(arr[i]/mod_counter % 10 == 7){
        stack_push(arr[i], &seven_stack);
        s7_len++;
      }
      else if(arr[i]/mod_counter % 10 == 8){
        stack_push(arr[i], &eight_stack);
        s8_len++;
      }
      else if(arr[i]/mod_counter % 10 == 9){
        stack_push(arr[i], &nine_stack);
        s9_len++;
      }
    }
    int arr_counter = s0_len+s1_len+s2_len+s3_len+s4_len+s5_len+s6_len+s7_len
      +s8_len+s9_len-1;
    while(arr_counter>=0){
      while(s9_len){
        arr[arr_counter] = stack_pop(&nine_stack);
        s9_len--;
        arr_counter--;
      }
      while(s8_len){
        arr[arr_counter] = stack_pop(&eight_stack);
        s8_len--;
        arr_counter--;
      }
      while(s7_len){
        arr[arr_counter] = stack_pop(&seven_stack);
        s7_len--;
        arr_counter--;
      }
      while(s6_len){
        arr[arr_counter] = stack_pop(&six_stack);
        s6_len--;
        arr_counter--;
      }
      while(s5_len){
        arr[arr_counter] = stack_pop(&five_stack);
        s5_len--;
        arr_counter--;
      }
      while(s4_len){
        arr[arr_counter] = stack_pop(&four_stack);
        s4_len--;
        arr_counter--;
      }
      while(s3_len){
        arr[arr_counter] = stack_pop(&three_stack);
        s3_len--;
        arr_counter--;
      }
      while(s2_len){
        arr[arr_counter] = stack_pop(&two_stack);
        s2_len--;
        arr_counter--;
      }
      while(s1_len){
        arr[arr_counter] = stack_pop(&one_stack);
        s1_len--;
        arr_counter--;
      }
      while(s0_len){
        arr[arr_counter] = stack_pop(&zero_stack);
        s0_len--;
        arr_counter--;
      }
    }
    mod_counter*=10;
    digits--;
  }
  return;
}

int main(void) {
  int len = 20;
  int arr[20] = {9, 75, 28, 45, 9, 38, 19, 150, 134, 500,
                 4563, 45682, 245, 435, 43, 2823, 583, 
                 38935, 23834, 834983};
  radix_sort(arr, len);
  for(int i = 0; i<len; i++){
    printf("%d\n", arr[i]); 
  }

}
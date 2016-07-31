#include "array-resize.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <stdbool.h>

bool odd(int x) {
  return x % 2;
}


int main(void) {

  // Basic test for 2(a)
  const char test_str[] = "Basic test";  

  char *my_str = strcpy(malloc(sizeof(char) * 
                               (strlen(test_str) + 1)), test_str);
  my_str = replace(my_str," ", "_");
  assert(strcmp(my_str,"Basic_test") == 0);
  free(my_str);

  const char my_test_str[] = "helllllolllllo";  
  my_str = strcpy(malloc(sizeof(char) * 
                         (strlen(my_test_str) + 1)), my_test_str);
  my_str = replace(my_str,"lllll", "l");
  assert(strcmp(my_str,"helolo") == 0);
  free(my_str);

  const char my_test_str_2[] = "hello";  
  my_str = strcpy(malloc(sizeof(char) * 
                         (strlen(my_test_str_2) + 1)), my_test_str_2);
  my_str = replace(my_str,"o", "oo");
  assert(strcmp(my_str,"helloo") == 0);
  free(my_str);

  const char my_test_str_3[] = "hellooo";  
  my_str = strcpy(malloc(sizeof(char) * 
                         (strlen(my_test_str_3) + 1)), my_test_str_3);
  my_str = replace(my_str,"oo", "OO");
  assert(strcmp(my_str,"hellOOo") == 0);
  free(my_str);

  const char my_test_str_4[] = "RorowanrodogRodawgrororO";  
  my_str = strcpy(malloc(sizeof(char) * 
                         (strlen(my_test_str_4) + 1)), my_test_str_4);
  my_str = replace(my_str,"ro", "Rowan");
  assert(strcmp(my_str,"RoRowanwanRowandogRodawgRowanRowanrO") == 0);
  my_str = replace(my_str,"Rowan", "ro");
  assert(strcmp(my_str,"RorowanrodogRodawgrororO") == 0);
  free(my_str);

  const char my_test_str_5[] = " ";  
  my_str = strcpy(malloc(sizeof(char) * 
                         (strlen(my_test_str_5) + 1)), my_test_str_5);
  my_str = replace(my_str," ", "");
  assert(strcmp(my_str,"") == 0);
  free(my_str);

  const char my_test_str_6[] = "";  
  my_str = strcpy(malloc(sizeof(char) * 
                         (strlen(my_test_str_6) + 1)), my_test_str_6);
  my_str = replace(my_str," ", "aaaa");
  assert(strcmp(my_str,"") == 0);
  free(my_str);

  // Basic test for 2(b)

  const int test_arr[] = {4,8,15,16,23,42};
  const int test_len = 6;

  const int test_arr_filtered[] = {15,23};
  const int test_arr_filtered_len = 2;

  int *my_arr = malloc(sizeof(int) * test_len);
  for (int i = 0; i < test_len; ++i) {
    my_arr[i] = test_arr[i];
  }
  int my_arr_len = test_len;


  my_arr = filter(odd, my_arr, &my_arr_len);
  for (int i = 0; i < my_arr_len; ++i) {
    assert(my_arr[i] = test_arr_filtered[i]);
  }
  assert(my_arr_len == test_arr_filtered_len);
  free(my_arr);



  const int my_test_arr[] = {5,7,15,17,23,43};
  const int my_test_len = 6;

  //const int test_arr_filtered[] = {15,23};
  //const int test_arr_filtered_len = 2;

  int *my_my_arr = malloc(sizeof(int) * my_test_len);
  for (int i = 0; i < my_test_len; ++i) {
    my_my_arr[i] = my_test_arr[i];
  }
  int my_my_arr_len = my_test_len;


  my_my_arr = filter(odd, my_my_arr, &my_my_arr_len);
  for (int i = 0; i < my_my_arr_len; ++i) {
    assert(my_my_arr[i] = my_test_arr[i]);
  }
  assert(my_my_arr_len == my_test_len);
  free(my_my_arr);




  const int my_test_arr_2[] = {4,6,14,16,22,44};
  const int my_test_len_2 = 6;

  //const int test_arr_filtered[] = {15,23};
  //const int test_arr_filtered_len = 2;

  int *my_my_arr_2 = malloc(sizeof(int) * my_test_len_2);
  for (int i = 0; i < my_test_len_2; ++i) {
    my_my_arr_2[i] = my_test_arr_2[i];
  }
  int my_my_arr_len_2 = my_test_len_2;


  assert(filter(odd, my_my_arr_2, &my_my_arr_len_2) == NULL);
  assert(my_my_arr_len_2 == 0);


}
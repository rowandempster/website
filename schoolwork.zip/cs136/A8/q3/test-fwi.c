#include <stdio.h>
#include <string.h>
#include "fun-with-ints.h"

// a simple test client for fun-with-ints.c

const int max_ints = 100;

int main(void) {
  char command[10];
  int arr[100];
  int len = 0;
  int x = 0;
  // Read in command  
  if (scanf("%s", command) != 1) {
    printf("No command given\n");
    return 0;
  }
  // Read in integers
  while (scanf("%d", &x) == 1 && len < max_ints) {
    arr[len] = x;
    ++len;
  }
  // Execute command
  if (strcmp(command, "closest") == 0) {
    int first;
    int next;
    int r = closest(arr, len, &first, &next);
    printf("%d %d %d\n", first, next, r);
  } else if (strcmp(command, "longest") == 0) {
    int r = longest_seq(arr, len);
    printf("%d\n",r);
  } else {
    printf("Invalid command\n");
  }
}

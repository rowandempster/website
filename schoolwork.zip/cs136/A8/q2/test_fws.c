#include <stdio.h>
#include <string.h>
#include "fun_with_strings.h"

// a simple test client for fun_with_strings.c

int main(void) {
  char command[10];
  char word[81];
  char result[83];
  
  while (1) {
    if (scanf("%s", command) != 1) break;
    if (scanf("%s", word) != 1) break;
    if (strcmp(command, "pal") == 0) {
      printf("%d\n", is_palindrome(word));
    } else if (strcmp(command, "pig") == 0) {
      pig_latin(word, result);
      printf("%s\n", result);
    } else if (strcmp(command, "freq") == 0) {
      printf("%c\n", mostfreq(word));
    } else {
      printf("invalid command: [%s]\n", command);
      break;
    }
  }
}

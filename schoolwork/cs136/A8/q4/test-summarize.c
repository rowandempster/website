#include <stdio.h>
#include <string.h>
#include <assert.h>
#include "arr_str_io.h"
#include "summarize.h"

// a simple test framework for summarize.c
// see the provided .in & .expect files for usage

char *keywords[100];
char *negative[100];
int freq[100] = { 0 };
char *words[1000];

int main(void) {
  char command[20];
  if (scanf("%s", command) != 1) return 0;

  if (strcmp(command, "count") == 0) { // count_words
    
    int num_keywords;
    if (scanf("%d", &num_keywords) != 1) return 0;
    assert(num_keywords <= 100);
    assert(num_keywords == fill_array_strings_io(keywords, num_keywords, 100));
    int num_words = fill_array_strings_io(words, -1, 1000);

    count_words(keywords, num_keywords, freq, words, num_words);

    for (int k=0; k < num_keywords; ++k) {
      printf("%s: %d\n", keywords[k], freq[k]);
    }
    free_array_strings(keywords, num_keywords);
    free_array_strings(words, num_words);

  } else if (strcmp(command, "sort") == 0) { // sort_words

    int num_words = fill_array_strings_io(words, -1, 1000);
    sort_words(words, num_words);    
    for (int w=0; w < num_words; ++w) {
      printf("%s\n", words[w]);
    }
    free_array_strings(words, num_words);

  } else if (strcmp(command, "fresh") == 0) { // is_fresh
    
    int num_keywords;
    if (scanf("%d", &num_keywords) != 1) return 0;
    assert(num_keywords <= 100);
    assert(num_keywords == fill_array_strings_io(keywords, num_keywords, 100));

    int num_negative;
    if (scanf("%d", &num_negative) != 1) return 0;
    assert(num_negative <= 100);
    assert(num_negative == fill_array_strings_io(negative, num_negative, 100));

    int num_words = fill_array_strings_io(words, -1, 1000);
    
    if (is_fresh(words, num_words,
                 keywords, num_keywords, 
                 negative, num_negative)) {
      printf("Fresh\n");
    } else {
      printf("Rotten\n");
    }
    free_array_strings(keywords, num_keywords);
    free_array_strings(negative, num_negative);
    free_array_strings(words, num_words);
    
  } else {
    printf("unknown command: %s\n", command);
  }  
}
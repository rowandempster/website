#include <string.h>
#include <stdbool.h>
#include <assert.h>

// INTEGRITY STATEMENT (modify if necessary)
// I received help from the following sources:
// None. I am the sole author of this work 

// sign this statement by removing the line below and entering your name

// Name: Rowan Dempster
// login ID: R2DEMPST

// implementation:

//index(word, keywords, num_keywords) returns the index of 
//   word inside keywords, or -1 if word is not in keywords
//requires: word, keywords != NULL
//          num_keywords = length of keywords
//time: O(n) where n = num_keywords
static int index(char *word, char *keywords[], int num_keywords){
  assert(word&&keywords);
  for(int i = 0; i<num_keywords; i++){
    if(strcmp(word, keywords[i]) == 0){
      return i; 
    }
  }
  return -1;
}


void count_words(char *keywords[], int num_keywords,
                 int freq[], char *words[], int num_words) {
  assert(keywords&&freq&&words);
  //O(n) where n = num_words
  for(int i = 0; i<num_words; i++){
    //O(m) where m = num_keywords
    if(index(words[i], keywords, num_keywords) != -1){
      freq[index(words[i], keywords, num_keywords)]++;
    }
  }
}

//swap(x,y) swaps the value of what x and y points to
//requires: x and y != NULL
//effects: mutates x and y
//time: O(1)
static void swap(char **x, char **y) {
  assert(x&&y);
  char *temp_x = *x;
  *x = *y;
  *y = temp_x;
}

void sort_words(char *words[], const int num_words) {
  assert(words);
  //O(n)
  for (int next=0; next < num_words - 1; next++) {
    int smallest_pos = next;
    //O(n)
    for (int smallest=next+1; smallest<num_words; smallest++){
      //O(n)
      if (strcmp(words[smallest], words[smallest_pos]) < 0) {
        smallest_pos = smallest;
      } }
    swap(&words[next], &words[smallest_pos]);
  }
}


bool is_fresh(char *review[], const int review_length, 
              char *positive[], const int num_positive, 
              char *negative[], const int num_negative) {
  assert(review&&positive&&negative);
  int pos_count = 0;
  int neg_count = 0;
  //O(n) where n is review_length
  for(int i = 0; i<review_length; i++){
    //O(m) where m is num_positive
   if(index(review[i], positive, num_positive) != -1){
    pos_count++; 
   }
    //O(p) where p is num_negative
    else if(index(review[i], negative, num_negative) != -1){
     neg_count++; 
    }
  }
  return (pos_count >= (2*neg_count)) || neg_count == 0;
}

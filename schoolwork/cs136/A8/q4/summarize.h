#include <stdbool.h>

//count_words(keywords,num_keywords,freq,words,num_words)
//   changes freq to store the number of times each
//   word in keywords appears in words
//requires: keywords, words, freq != NULL
//          num_keywords = length of keywords and freq
//          num_words = length of words
//effects: mutates freq
//time: O(n*m) where n is num_words and m is num_keywords
void count_words(char *keywords[], int num_keywords, int freq[], 
                 char *words[], int num_words);

//sort_words(words, num_words) sorts words in place using
//   their lexigraphical ordering using selection sort
//requires: words != NULL
//          num_words = length of words
//effects: mutates words
//time: O(n^3), uses selection sort with inner strcmp()
void sort_words(char *words[], int num_words);

//is_fresh(review,review_length,positive,num_positive,negative,num_negative)
//   returns true is the number of positive words in review
//   is greater than or equal to twice the number of 
//   negative words in review, or true if number of negative
//   words is zero. False otherwise.
//requires: review, positive, negative != NULL
//          review_length = length of review
//          num_positive = length of positive
//          num_negative = length of negative
//time: O(n*m) where n is review length 
//             and m is max(num_positive, num_negative)
bool is_fresh(char *review[], const int review_length, 
              char *positive[], const int num_positive, 
              char *negative[], const int num_negative);


// BONUS:

void sort_words_by_frequency(char *words[], int num_words, 
                             const int freq[], int order[]);

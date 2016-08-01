/*
 sequence.c
 Sequence ADT Implementation
*/
// INTEGRITY STATEMENT (modify if necessary)
// I received help from the following sources:
// None. I am the sole author of this work 

// sign this statement by removing the line below and entering your name

// Name: Rowan Dempster
// login ID: R2DEMPST

// implementation:
#include <assert.h>
#include <stdio.h>
#include <stdbool.h>
#include "sequence.h"

//see .h for descriptions
void Seq_init(struct Sequence *s){
  assert(s);
  s->length = 0;
  s->max_len = 100;
}

int Sequence_length(const struct Sequence *seq){
  assert(seq);
  return seq->length;
}

void Sequence_clear(struct Sequence *seq){
  assert(seq);
  int len = seq->length;
  for(int i = 0; i<len; i++){
    (seq->arr)[i] = 0; 
  }
  seq->length = 0;
}

int Sequence_item_at(const struct Sequence *seq, int pos){
  assert(seq);
  return (seq->arr)[pos];
}

void Sequence_insert_at(struct Sequence *seq, int pos, int val){
  assert(seq);
  int len = seq->length;
  int max = seq->max_len;
  assert((pos>=0)&&(pos<=len)&&(len<=max));
  if(pos == max){
    printf("Sequence Filled: max length is %d items.\n", max); 
  }
  else{
    for(int i = len -2; i>= pos; i--){
      (seq->arr)[i+1] = (seq->arr)[i];
    }
    (seq->arr)[pos] = val;
    seq->length++;
  }
}


int Sequence_remove_at(struct Sequence *seq, int pos){
  assert(seq);
  int len = seq->length;
  assert((0<=pos)&&(pos<len));
  int removed = (seq->arr)[pos];
  for(int i = pos; i<(seq->length)-1; i++){
    (seq->arr)[i] = (seq->arr)[i+1];
  }
  seq->length--;
  return removed;
}

void Sequence_print(const struct Sequence *seq){
  assert(seq);
  int len = seq->length;
  if(len==0){
    printf("[empty]\n"); 
  }
  else{
    printf("[%d]", len);
    for(int i = 0; i<len; i++){
      printf(" %d", (seq->arr)[i]);
    }
    printf("\n");
  }
}

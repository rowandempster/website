#include "sequence.h"
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

// INTEGRITY STATEMENT (modify if necessary)
// I received help from the following sources:
// None. I am the sole author of this work 

// sign this statement by removing the line below and entering your name

// Name: Rowan Dempster
// login ID: R2DEMPST

// implementation:

struct node {
  int item;
  struct node *next;
};

struct Sequence *Sequence_create(void){
  struct Sequence *new_seq = malloc(sizeof(struct Sequence));
  new_seq->front = NULL;
  return new_seq;
}

void Sequence_destroy(struct Sequence *seq){
  assert(seq);
  struct node *curr_node = seq->front;
  struct node *next_node = NULL;
  while(curr_node){
    next_node = curr_node->next;
    free(curr_node);
    curr_node = next_node;
  }
  free(seq);
}

int Sequence_length(const struct Sequence *seq){
  assert(seq);
  int len = 0;
  struct node *curr_node = seq->front;
  while(curr_node){
    len++;
    curr_node = curr_node->next;
  }
  return len;
}

int Sequence_item_at(const struct Sequence *seq, int pos){
  assert(seq);
  assert(pos>=0);
  assert(pos<Sequence_length(seq));
  struct node *curr_node = seq->front;
  while(pos>0){
    curr_node = curr_node->next; 
    pos--;
  }
  return curr_node->item;
}

void Sequence_insert_at(struct Sequence *seq, int pos, int val){
  assert(seq);
  assert(pos>=0);
  assert(pos<=Sequence_length(seq));
  struct node *new_node = malloc(sizeof(struct node));
  new_node->item = val;
  new_node->next = NULL;
  struct node *curr_node = seq->front;
  if(pos==0){
    seq->front = new_node;
    new_node->next = curr_node;
    return;
  }
  struct node *prev_node = curr_node;
  curr_node = curr_node->next;
  while(pos>1){
    curr_node = curr_node->next;
    prev_node = prev_node->next;
    pos--;
  }
  prev_node->next = new_node;
  new_node->next = curr_node;
}

int Sequence_remove_at(struct Sequence *seq, int pos){
  assert(seq);
  assert(pos>=0);
  assert(pos<Sequence_length(seq));
  struct node *curr_node = seq->front;
  struct node *next_node = NULL;
  if(pos==0){
    int item = curr_node->item;
    curr_node = curr_node->next;
    free(seq->front);
    seq->front = curr_node;
    return item;
  }
  struct node *prev_node = curr_node;
  curr_node = curr_node->next;
  while(pos>1){
    curr_node = curr_node->next;
    prev_node = prev_node->next;
    pos--;
  }
  int item = curr_node->item;
  next_node = curr_node->next;
  free(curr_node);
  prev_node->next = next_node;
  return item;
}

void Sequence_print(const struct Sequence *seq){
  assert(seq);
  if(Sequence_length(seq) == 0){
    printf("[empty]\n");
    return;
  }
  printf("[%d]", Sequence_length(seq));
  struct node *curr_node = seq->front;
  while(curr_node){
    printf(" %d", curr_node->item); 
    curr_node = curr_node->next;
  }
  printf("\n");
}

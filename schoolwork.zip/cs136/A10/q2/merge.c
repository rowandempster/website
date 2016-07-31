#include "merge.h"
#include <stdbool.h>
#include <stdlib.h>
#include <assert.h>

// INTEGRITY STATEMENT (modify if necessary)
// I received help from the following sources:
// None. I am the sole author of this work 

// sign this statement by removing the line below and entering your name

// Name: Rowan Dempster
// login ID: R2DEMPST

// implementation:

void merge(struct llist *dest, struct llist *src1, struct llist *src2) {
  assert(dest&&src1&&src2);
  struct llnode *curr_dest_node;
  struct llnode *curr_s1_node = src1->front;
  struct llnode *curr_s2_node = src2->front;
  bool s1_ended = false;
  bool s2_ended = false;
  if((!curr_s1_node)&&(!curr_s2_node)){
    return; 
  }
  if((!curr_s1_node) || (curr_s1_node->item > curr_s2_node->item)){
    dest->front = curr_s2_node; 
    curr_dest_node = curr_s2_node;
    curr_s2_node = curr_s2_node->next;
  }
  else{
    dest->front = curr_s1_node; 
    curr_dest_node = curr_s1_node;
    curr_s1_node = curr_s1_node->next;
  }
  while(!s1_ended || !s2_ended){
    if(!curr_s1_node){
      s1_ended = true; 
    }
    if(!curr_s2_node){
      s2_ended = true; 
    }
    if(s1_ended){
      curr_dest_node->next = curr_s2_node;
      curr_s2_node = curr_s2_node->next;
    }
    else if(s2_ended){
      curr_dest_node->next = curr_s1_node;
      curr_s1_node = curr_s1_node->next;
    }
    else if(curr_s1_node->item < curr_s2_node->item){
      curr_dest_node->next = curr_s1_node;
      curr_s1_node = curr_s1_node->next;
    }
    else{
      curr_dest_node->next = curr_s2_node; 
      curr_s2_node = curr_s2_node->next;
    }
    if(!curr_s1_node){
      s1_ended = true; 
    }
    if(!curr_s2_node){
      s2_ended = true; 
    }
    curr_dest_node = curr_dest_node->next;
  }
}

//split(lst, first_half, second_half) changes first_half so
//   that it contains the first half of the nodes in lst,
//   and changes second_half so that it contains the second
//   half of the nodes in lst
//requires: all paramters are not NULL
//effects: mutates lst, first_half, and second_half
//time: O(n) where n is the length of lst
void split(struct llist *lst, struct llist **first_half,
           struct llist **second_half){
  assert(lst&&first_half&&second_half);
  int len = 0;
  struct llnode *curr_node = lst->front;
  while(curr_node){
    len++; 
    curr_node = curr_node->next;
  }
  int first_half_len = len/2;
  curr_node = lst->front;
  for(int i = 1; i<first_half_len; i++){
    curr_node = curr_node->next;
  }
  struct llnode *second_half_start = curr_node->next;
  curr_node->next = NULL;
  (*first_half)->front = lst->front;
  (*second_half)->front = second_half_start;
}

void merge_sort(struct llist *lst){
  assert(lst);
  if(!(lst->front) || !((lst->front)->next)){
    return; 
  }
  struct llist *first_half = malloc(sizeof(struct llist));
  struct llist *second_half = malloc(sizeof(struct llist));
  split(lst, &first_half, &second_half);
  merge_sort(first_half);
  merge_sort(second_half);
  merge(lst, first_half, second_half);
  free(first_half);
  free(second_half);
}
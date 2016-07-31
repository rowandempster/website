#include "pq.h"
#include <stdio.h>
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



struct node {
  int item;
  int prio;
  struct node *next;
};

struct pq *pq_create(void){
  struct pq *new_pq = malloc(sizeof(struct pq));
  new_pq -> front = NULL;
  new_pq -> len = 0;
  return new_pq;
}

void pq_destroy(struct pq *pqueue){
  while(pqueue->front){
    pq_remove(pqueue);
  }
  free(pqueue);
}

void pq_add(struct pq *pqueue, int item, int priority){
  assert(pqueue);
  assert(priority>0);
  pqueue->len++;
  struct node *new_node = malloc(sizeof(struct node));
  new_node->item = item;
  new_node->prio = priority;
  new_node->next = NULL;
  if(pqueue->front == NULL || (pqueue->front)->prio>priority){
    struct node *old_front = pqueue->front;
    pqueue->front = new_node;
    new_node->next = old_front;
    return;
  }
  struct node *cur_node = (pqueue->front)->next;
  struct node *prev_node = pqueue->front;
  bool last_node = true;
  while(cur_node){
    if(cur_node->prio>priority){
      last_node = false;
      break; 
    }
    cur_node = cur_node->next; 
    prev_node = prev_node->next;
  }
  if(last_node){
    prev_node->next = new_node;
    return;
  }
  prev_node -> next = new_node;
  new_node->next = cur_node;
}

int pq_remove(struct pq *pqueue){
  assert(pqueue);
  assert(pqueue->front);
  pqueue->len--;
  struct node *old_front = pqueue->front;
  pqueue->front = (pqueue->front)->next;
  int old_item = old_front->item;
  free(old_front);
  return old_item;
}

bool pq_is_empty(const struct pq *pqueue){
  assert(pqueue);
  return (pqueue->front == NULL); 
}

void pq_print(const struct pq *pqueue){
  assert(pqueue);
  struct node *curr_node = pqueue->front;
  if(curr_node == NULL){
    return; 
  }
  int curr_prio = curr_node->prio;
  printf("[%d]", curr_prio);
  while(curr_node){
    if(curr_prio == curr_node->prio){
      printf(" %d", curr_node->item); 
    }
    else{
      printf("\n");
      curr_prio = curr_node->prio;
      printf("[%d]", curr_prio);
      continue;
    }
    curr_node = curr_node->next;
  }
  printf("\n");
}

int pq_length(const struct pq *pqueue){
  assert(pqueue);
  return pqueue->len;
}

int pq_front_priority(const struct pq *pqueue){
  assert(pqueue);
  assert(pqueue->front);
  return (pqueue->front)->prio;
}

int pq_front_item(const struct pq *pqueue){
  assert(pqueue);
  assert(pqueue->front);
  return (pqueue->front)->item;
}


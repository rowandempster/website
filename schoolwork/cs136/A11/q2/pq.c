#include <stdlib.h>
#include <stdio.h>
#include "pq.h"

// INTEGRITY STATEMENT (modify if necessary)
// I received help from the following sources:
// None. I am the sole author of this work 

// sign this statement by removing the line below and entering your name

// Name: Rowan Dempster
// login ID: R2DEMPST

// implementation:

const int initial_max_len = 1;

struct pq {
  int len;
  struct node *root;
  int max_len;
};

struct node {
  int prio;
  int item;
};

struct pq *pq_create(void){
  struct pq *new_pq = malloc(sizeof(struct pq));
  new_pq->len = 0;
  struct node *root = malloc(sizeof(struct node)*initial_max_len);
  new_pq->root=root;
  new_pq->max_len = 1;
  return new_pq;
}

void pq_destroy(struct pq *pqueue){
  free(pqueue->root);
  free(pqueue);
}

void pq_add(struct pq *pqueue, int item, int priority){
  struct node new_node;
  new_node.item = item;
  new_node.prio = priority;
  int insert_index = pqueue->len;
  (pqueue->root)[insert_index] = new_node;
  pqueue->len++;
  if(pqueue->len == pqueue->max_len){
    pqueue->max_len*=2;
    pqueue->root = realloc(pqueue->root, sizeof(struct node)*pqueue->max_len);
  }
  while((priority < ((pqueue->root)[(insert_index-1)/2]).prio)
        && insert_index>0){
    struct node backup = (pqueue->root)[(insert_index-1)/2];
    (pqueue->root)[(insert_index-1)/2] = new_node;
    (pqueue->root)[insert_index] = backup;
    insert_index = (insert_index - 1)/2;
  }
}

int pq_remove(struct pq *pqueue){
  struct node *arr = pqueue->root;
  int len = pqueue->len;
  pqueue->len--;
  int item_to_return = arr[0].item;
  struct node out_of_place = arr[len-1];
  arr[0] = out_of_place;
  int oop_index = 0;
  while(oop_index*2+1<pqueue->len &&
        (out_of_place.prio > arr[oop_index*2+1].prio ||
         out_of_place.prio > arr[oop_index*2+2].prio)){
    if(out_of_place.prio > arr[oop_index*2+1].prio){
      struct node backup = arr[oop_index*2+1];
      arr[oop_index*2+1] = out_of_place;
      arr[oop_index] = backup;
      oop_index = oop_index*2+1;
    }
    else{
      struct node backup = arr[oop_index*2+2];
      arr[oop_index*2+2] = out_of_place;
      arr[oop_index] = backup;
      oop_index = oop_index*2+2;
    }
  }
  return item_to_return;
}

bool pq_is_empty(const struct pq *pqueue){
  return pqueue->len == 0; 
}

void pq_print(const struct pq *pqueue){
  if(pqueue->len == 0){
    return; 
  }
  printf("[");
  struct node *arr = pqueue->root;
  int len = pqueue->len;
  for(int i = 0; i<len; i++){
    if(i==len-1){
      printf("(%d,%d)", arr[i].item, arr[i].prio);
    }
    else{
      printf("(%d,%d),", arr[i].item, arr[i].prio);
    }
  }
  printf("]\n");
}

int pq_length(const struct pq *pqueue){
  return pqueue->len;
}

int pq_front_priority(const struct pq *pqueue){
  return (pqueue->root)->prio; 
}

int pq_front_item(const struct pq *pqueue){
  return (pqueue->root)->item; 
}

/*int main(void){
  struct pq *pq = pq_create(); 
  pq_add(pq, 1, 10);
  pq_add(pq, 3, 30);
  pq_add(pq, 2, 20);
  pq_add(pq, 0, 5);

  pq_print(pq);
  printf("removed: %d\n", pq_remove(pq));
  pq_print(pq);
  printf("removed: %d\n", pq_remove(pq));
  pq_print(pq);
  printf("removed: %d\n", pq_remove(pq));
  pq_print(pq);
  printf("removed: %d\n", pq_remove(pq));
  pq_print(pq);
  pq_destroy(pq);
}*/
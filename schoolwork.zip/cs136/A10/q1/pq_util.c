#include "pq.h"
#include "pq_util.h"
#include <stdlib.h>
#include <assert.h>

// INTEGRITY STATEMENT (modify if necessary)
// I received help from the following sources:
// None. I am the sole author of this work 

// sign this statement by removing the line below and entering your name

// Name: Rowan Dempster
// login ID: R2DEMPST

// implementation:

void to_array(struct pq *pqueue, int **arr_ptr, int *len){
  assert(pqueue&&arr_ptr);
  assert(!(*arr_ptr));
  int pq_len = pq_length(pqueue);
  if(pq_len == 0){
    *len = 0;
    return;
  }
  int arr_index = 0;
  int *arr = malloc(sizeof(int)*pq_len);
  while(arr_index<pq_len){
    arr[arr_index] = pq_remove(pqueue);
    arr_index++;
  }
  *len = pq_len;
  *arr_ptr = arr;
  pq_destroy(pqueue);
}

struct pq **k_way_split(struct pq *pqueue, const int k){
  assert(pqueue);
  assert(k>0);
  int pq_len = pq_length(pqueue);
  struct pq **k_way_split = malloc(sizeof(struct pq)*k);
  int split_index = 0;
  while(split_index<k){
    struct pq *copy = pq_create();
    struct pq *split_pq = pq_create();
    for(int pos = 0; pos< pq_len; pos++){
      if(pos%k == split_index){
        pq_add(split_pq, pq_front_item(pqueue), pq_front_priority(pqueue));
      }
      pq_add(copy, pq_front_item(pqueue), pq_front_priority(pqueue)); 
      pq_remove(pqueue);
    }
    pq_destroy(pqueue);
    pqueue = copy;
    k_way_split[split_index] = split_pq;
    split_index++;
    if(split_index == k){
      pq_destroy(copy); 
    }
  }
  return k_way_split;
}


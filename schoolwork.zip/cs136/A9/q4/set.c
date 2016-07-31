#include "set.h"
#include <stdlib.h>
#include <assert.h>
#include <stdio.h>

// INTEGRITY STATEMENT (modify if necessary)
// I received help from the following sources:
// None. I am the sole author of this work 

// sign this statement by removing the line below and entering your name

// Name: Rowan Dempster
// login ID: R2DEMPST

// implementation:

struct Set{
  int *elements;
  int len;
  int max_len;
};

static const int initial_max_len = 2;

struct Set *set_create(void){
  struct Set *new_set = malloc(sizeof(struct Set));
  int *new_elements = malloc(initial_max_len*sizeof(int));
  new_set->elements = new_elements;
  new_set->len = 0;
  new_set->max_len = initial_max_len;
  return new_set;
}

void set_destroy(struct Set *s){
  assert(s);
  free(s->elements);
  free(s);
}

int set_size(const struct Set *s){
  assert(s);
  return s->len;
}

void set_add(struct Set *s, int i){
  assert(s);
  int insert_index = -1;
  if(s->len == 0){
    (s->elements)[0] = i; 
    s->len++;
    return;
  }
  if(i<(s->elements)[0]){
    insert_index = 0;
  }
  if(i>(s->elements)[(s->len)-1]){
    (s->elements)[s->len] = i;
    s->len++;
    if(s->len == s->max_len){
      s->max_len *= 2;
      s->elements=realloc(s->elements, s->max_len*sizeof(int));
    }
    return;
  }
  for(int j = 1; j<s->len; j++){
    if(((s->elements)[j-1]<i) && ((s->elements)[j]>i)){
      insert_index = j;
    }
  }
  if(insert_index == -1){
    return; 
  }
  s->len++;
  if(s->len == s->max_len){
    s->max_len *= 2;
    s->elements=realloc(s->elements, s->max_len*sizeof(int));
  }
  for(int end = s->len-1; insert_index<end; end--){
    (s->elements)[end]=(s->elements)[end-1];
  }
  (s->elements)[insert_index] = i;
}

void set_remove(struct Set *s, int i){
  assert(s);
  int index = -1;
  for(int j = 0; j<s->len; j++){
    if((s->elements)[j] == i){
      index = j; 
    }
  }
  if(index == -1){
    return; 
  }
  for(; index<(s->len-1); index++){
    (s->elements)[index] = (s->elements)[index+1];
  }
  s->len--;
}

struct Set *set_union(const struct Set *s1, const struct Set *s2){
  assert(s1&&s2);
  int max_u_len = s1->len + s2->len;
  int *u_elements = malloc(sizeof(int)*max_u_len);
  struct Set *u_set = malloc(sizeof(struct Set));
  int s1_index = 0;
  int s2_index = 0;
  int u_index = 0;
  while(s1_index<s1->len || s2_index<s2->len){
    if(((s1->elements)[s1_index] < (s2->elements)[s2_index]) || 
       s2_index == s2->len){
      u_elements[u_index] = (s1->elements)[s1_index];
      u_index++;
      s1_index++;
    }
    else if(((s1->elements)[s1_index] > (s2->elements)[s2_index]) || 
            s1_index == s1->len){
      u_elements[u_index] = (s2->elements)[s2_index];
      u_index++;
      s2_index++;
    }
    else {
      u_elements[u_index] = (s1->elements)[s1_index];
      u_index++;
      s1_index++;
      s2_index++;
    }
  }
  u_elements = realloc(u_elements, sizeof(int)*(u_index+initial_max_len));
  u_set->elements = u_elements;
  u_set->len = u_index;
  u_set->max_len = u_index+initial_max_len;
  return u_set;
}

struct Set *set_intersect(const struct Set *s1, const struct Set *s2){
  assert(s1&&s2);
  int max_i_len = s1->len;
  int *i_elements = malloc(sizeof(int)*max_i_len);
  struct Set *i_set = malloc(sizeof(struct Set));
  int s1_index = 0;
  int s2_index = 0;
  int i_index = 0;  
  while(s1_index<s1->len && s2_index<s2->len){
    if((s1->elements)[s1_index] < (s2->elements)[s2_index]){
      s1_index++;
    }
    else if((s1->elements)[s1_index] > (s2->elements)[s2_index]){
      s2_index++;
    }
    else {
      i_elements[i_index] = (s1->elements)[s1_index];
      i_index++;
      s1_index++;
      s2_index++;
    }
  }
  i_elements = realloc(i_elements, sizeof(int)*(i_index+initial_max_len));
  i_set->elements = i_elements;
  i_set->len = i_index;
  i_set->max_len = i_index+initial_max_len;
  return i_set;
}

void set_print(const struct Set *s){
  assert(s);
  printf("[");
  for(int i = 0;i<s->len; i++){
    if(i==(s->len-1)){
      printf("%d", (s->elements)[i]); 
    }
    else{
      printf("%d,", (s->elements)[i]);
    }
  }
  printf("]\n");
}






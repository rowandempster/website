#include "pantry.h"
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <assert.h>

// INTEGRITY STATEMENT (modify if necessary)
// I received help from the following sources:
// Office Hours to discuss structure layout

// sign this statement by removing the line below and entering your name

// Name: Rowan Dempster
// login ID: R2DEMPST

// implementation:

struct Item{
  char *name;
  int stock;
};

struct Pantry{
  struct Item *items;
  int len;
  int max_len;
};

static const int initial_max_len = 2;

struct Pantry *pantry_create(void) {
  struct Pantry *pantry = malloc(sizeof(struct Pantry));
  pantry->len = 0;
  pantry->max_len = initial_max_len;
  struct Item *items = malloc(sizeof(struct Item)*pantry->max_len);
  pantry->items = items;
  return pantry;
}

void pantry_destroy(struct Pantry *p){
  assert(p);
  for(int i = 0; i<p->len;i++){
    free(p->items[i].name);
  }
  free(p->items);
  free(p);
}

int pantry_count(struct Pantry *p, const char *ing){
  assert(p&&ing);
  for(int i = 0; i<p->len; i++){
    if(strcmp(ing, ((p->items)[i]).name) == 0){
      return (((p->items)[i]).stock);
    }
  }
  return 0;
}

void pantry_add(struct Pantry *p, const char *ing, int amt){
  assert(p&&ing);
  bool found_item = false;
  for(int i = 0; i<p->len; i++){
    if(strcmp(ing, ((p->items)[i]).name) == 0){
      (((p->items)[i]).stock) += amt;
      found_item = true;
      break;
    }
  }
  if(!found_item){
    char *ing_copy = malloc(sizeof(char)*(strlen(ing)+1));
    strcpy(ing_copy, ing);
    ((p->items)[p->len]).name = ing_copy;
    ((p->items)[p->len]).stock = amt;
    p->len++;
    if(p->len == p->max_len){
      p->max_len *= 2;
      p->items = realloc(p->items, p->max_len * sizeof(struct Item)); 
    }
  }
}

void pantry_remove(struct Pantry *p, const char *ing, int amt){
  assert(p&&ing);
  for(int i = 0; i<p->len; i++){
    if(strcmp(ing, ((p->items)[i]).name) == 0){
      (((p->items)[i]).stock) -= amt;
    }
  }
}



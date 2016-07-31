#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include "bst.h"

// IMPORTANT: DO NOT CHANGE THESE VALUES
const int PRE_ORDER = 0;
const int IN_ORDER = 1;
const int POST_ORDER = 2;

// INTEGRITY STATEMENT (modify if necessary)
// I received help from the following sources:
// None. I am the sole author of this work 

// sign this statement by removing the line below and entering your name

// Name: Rowan Dempster
// login ID: R2DEMPST

// implementation:

struct bst *bst_create(void) {
  struct bst *new_bst = malloc(sizeof(struct bst));
  new_bst->root = NULL;
  return new_bst;
}

//free_node(node) frees node's left and right fields and then
//   frees node
//effects: memory at node is no longer valid
//time: O(n)
void free_node(struct bstnode *node){
  if(!node){
    return; 
  }
  else{
    free_node(node->left);
    free_node(node->right);
    free(node);
  }
}

void bst_destroy(struct bst *t) {
  assert(t);
  free_node(t->root);
  free(t);
}

int bst_size(struct bst *t) {
  assert(t);
  if(!(t->root)){
    return 0; 
  }
  return (t->root)->size;
}

void bst_insert(int i, struct bst *t) {
  assert(t);
  struct bstnode *new_node = malloc(sizeof(struct bstnode));
  new_node->item = i;
  new_node->left = NULL;
  new_node->right = NULL;
  new_node->size = 1;
  if(!(t->root)){
    t->root = new_node;
    return;
  }
  struct bstnode *curr_node = t->root;
  struct bstnode *prev_node = NULL;
  while(curr_node){
    if(curr_node->item == i){
      free(new_node);
      return; 
    }
    else if(curr_node->item>i){
      curr_node->size++;
      prev_node = curr_node;
      curr_node = curr_node->left; 
    }
    else{
      curr_node->size++;
      prev_node = curr_node;
      curr_node = curr_node->right; 
    }
  }
  if(prev_node->item < i){
    prev_node->right = new_node;
  }
  else{
    prev_node->left = new_node; 
  }
}

bool bst_find(int i, struct bst *t) {
  assert(t);
  if(!(t->root)){
    return false; 
  }
  struct bstnode *curr_node = t->root;
  while(curr_node){
    if(curr_node->item == i){
      return true; 
    }
    else if(curr_node->item > i){
      curr_node = curr_node->left; 
    }
    else{
      curr_node = curr_node->right; 
    }
  }
  return false;
}

//node_select(k, node) returns the kth smallest node out of 
//   node and its children 
//requires: node != NULL and node has at least k children
//time: O(h) where h is the height of the node
int node_select(int k, struct bstnode *node){
  assert(node);
  assert(k>=0 && k<=node->size);
  if(k==0 && !(node->left)){
    return node->item;
  }
  else if (k == 0){
    return node_select(k, node->left); 
  }
  else if(k == (node->left)->size){
    return node->item; 
  }
  else if(k<(node->left)->size){
    return node_select(k, node->left); 
  }
  else{
    return node_select(k-((node->left)->size+1), node->right); 
  }
}

int bst_select(int k, struct bst *t) {
  assert(t);
  assert(k>=0 && k<=(t->root)->size);
  return node_select(k, t->root);
}

//remove_node(i, node) removes i from node or its children
//requires: node != NULL
//effects: mutates node
//time: O(h) where h is the height of the node 
struct bstnode *remove_node(int i, struct bstnode *node){
  assert(node);
  node->size--;
  if(!node){
    return NULL; 
  }
  if(i < node->item){
    node->left = remove_node(i, node->left);
  }
  else if(i > node->item){
    node->right = remove_node(i, node->right);
  }
  else if(!(node->left)){
    struct bstnode *promoted_child = node->right;
    free(node);
    return promoted_child;
  }
  else if(!(node->right)){
    struct bstnode *promoted_child = node->left;
    free(node);
    return promoted_child;
  }
  else{
    struct bstnode *next_largest = node->right;
    struct bstnode *prev_largest = node;
    while(next_largest->left){
      prev_largest = next_largest;
      next_largest = next_largest->left; 
    }
    node->item = next_largest->item;
    if(prev_largest == node){
      prev_largest->right = NULL;
    }
    else{
      prev_largest->left = NULL; 
    }
    free(next_largest);
  }
  return node;
}

void bst_remove (int i, struct bst *t) {
  assert(t);
  assert(bst_find(i,t));
  t->root = remove_node(i, t->root);
}

//safe_node_size(node) removes 0 if node is NULL, size of 
//   node otherwise
//time: O(n)
int safe_node_size(struct bstnode *node){
  if(!node){
    return 0; 
  }
  else{
    return node->size; 
  }
}

//nodes_smaller_than(k, node, smaller_so_far) returns the 
//   number of nodes exclusively smaller than k in node
//requires: smaller_so_far is passed in as 0
//time: O(n) where n is the number of nodes
int nodes_smaller_than(int k, struct bstnode *node, int smaller_so_far){
  if(!node){
    return smaller_so_far; 
  }
  else if(k<=node->item){
    return nodes_smaller_than(k, node->left, smaller_so_far);
  }
  else{
    return nodes_smaller_than(k, node->right, smaller_so_far 
                              + safe_node_size(node->left) 
                              + 1);
  }
}

//nodes_larger_than(k, node, smaller_so_far) returns the 
//   number of nodes exclusively larger than k in node
//requires: larger_so_far is passed in as 0
//time: O(n) where n is the number of nodes
int nodes_larger_than(int k, struct bstnode *node, int larger_so_far){
  if(!node){
    return larger_so_far; 
  }
  else if(k>=node->item){
    return nodes_larger_than(k, node->right, larger_so_far);
  }
  else{
    return nodes_larger_than(k, node->left, larger_so_far 
                             + safe_node_size(node->right) 
                             + 1);
  } 
}

int bst_range(int start, int end, struct bst *t) {
  return bst_size(t) - nodes_smaller_than(start, t->root, 0)
    - nodes_larger_than(end, t->root, 0);
}

//print_pre_order(node_left, node_right) prints out node_left
//   in pre-order, then node_right in pre-order
//effects: prints a message
//time: O(n)
void print_pre_order(struct bstnode *node_left, 
                     struct bstnode *node_right){
  if(!node_left && !node_right){
    return; 
  }
  else if(!node_right){
    printf(",%d", node_left->item);
    print_pre_order(node_left->left, node_left->right);
  }
  else if(!node_left){
    printf(",%d", node_right->item);
    print_pre_order(node_right->left, node_right->right);
  }
  else{
    printf(",%d", node_left->item);
    print_pre_order(node_left->left, node_left->right);
    printf(",%d", node_right->item);
    print_pre_order(node_right->left, node_right->right);
  }
}

//print_in_order(node, min) prints out node in-order
//effects: prints a message
//time: O(n)
void print_in_order(struct bstnode *node, int min){
  if(!node){
    return; 
  }
  else {
    print_in_order(node->left, min);
    if(node->item == min){
      printf("%d", node->item);
    }
    else{
      printf(",%d", node->item);
    }
    print_in_order(node->right, min);
  }
}

//print_post_order(node, first_printed) prints out node in
//   post-order
//effects: prints a message
//time: O(n)
void print_post_order(struct bstnode *node, 
                      bool *first_printed){
  if(!node){
    return; 
  }
  else{
    print_post_order(node->left, first_printed);
    print_post_order(node->right, first_printed);
    if(!(*first_printed)){
      printf("%d", node->item); 
      *first_printed = true;
    }
    else{
      printf(",%d", node->item);
    }
  }
}

void bst_print (int o, struct bst *t) {
  if(!(t->root)){
    return; 
  }
  if(o==PRE_ORDER){
    printf("[%d", (t->root)->item);
    print_pre_order((t->root)->left, (t->root)->right); 
    printf("]\n");
  }
  else if(o==IN_ORDER){
    int smallest = bst_select(0, t);
    printf("[");
    print_in_order(t->root, smallest);
    printf("]\n");
  }
  else if(o==POST_ORDER){
    bool *first_printed = malloc(sizeof(bool));
    *first_printed = false;
    printf("[");
    print_post_order(t->root, first_printed); 
    printf("]\n");
    free(first_printed);
  }
}

//add_node(arr, node, next_index) adds the items of node and
//   its children to arr in sorted order, starting at index
//   'next_index'
//requires: arr != NULL and sizeof(node)<length(arr)-next_index
//effects: mutates arr
//time: O(n)
void add_node(int *arr, struct bstnode *node, 
              int *next_index){
  if(!node){
    return; 
  }
  else{
    add_node(arr, node->left, next_index);
    arr[*next_index] = node->item;
    (*next_index)++;
    add_node(arr, node->right, next_index);
  }
}

int *bst_to_sorted_array(struct bst *t) {
  int *arr = malloc(sizeof(int)*bst_size(t));
  int *next_index = malloc(sizeof(int));
  *next_index = 0;
  add_node(arr, t->root, next_index);
  free(next_index);
  return arr;
}

//add_middle(arr, t, len, start) adds the subset of arr 
//   starting at 'start' and spanning 'len' such that the
//   balance of t is preserved
//requires: len<=len(arr), 0<=start<=len(arr), arr,t!=NULL
//effects: mutates t
//time: O(1) + O(h) + 2T(n/2)...which is somewhere in 
//      between O(n) and O(nlog(n)) since h~log(n).
//      I think the fact that we're inserting into a balanced
//      tree makes it pretty close to O(n) :) (gimme bonus)
void add_middle(int *arr, struct bst *t, int len, int start){
  if(len <= 0){
    return; 
  }
  int middle = len/2; //O(1)
  bst_insert(arr[middle+start], t); //O(h)
  add_middle(arr, t, middle, start); //T(n/2)
  if(len%2 == 0){
    add_middle(arr, t, middle-1, start+middle+1); //T(n/2)
  }
  else{
    add_middle(arr, t, middle, start+middle+1); //T(n/2)
  }
}

//time analysis: see add_middle
struct bst *sorted_array_to_bst(int *arr, int len) {
  struct bst *new_bst = malloc(sizeof(struct bst));
  new_bst->root = NULL;
  add_middle(arr, new_bst, len, 0);
  return new_bst;
}

void bst_rebalance(struct bst *t) {
  int *arr = bst_to_sorted_array(t);
  int len = bst_size(t);
  add_middle(arr, t, len, 0);
  free(arr);
}
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#include "dictionary.h"
#include "rexp.h"
#include "strutils.h"

// INTEGRITY STATEMENT (modify if necessary)
// I received help from the following sources:
// None. I am the sole author of this work 

// sign this statement by removing the line below and entering your name

// Name: Rowan Dempster
// login ID: R2DEMPST

// implementation:

struct enode *setup_num_node(int num){
  struct enode *num_enode = malloc(sizeof(struct enode));
  num_enode->type = 'n';
  num_enode->number = num;
  num_enode->left = NULL;
  num_enode->right = NULL;
  return num_enode;
}

struct enode *setup_op_node(char op, struct enode *left,
                            struct enode *right){
  struct enode *op_enode = malloc(sizeof(struct enode));
  op_enode->type = op;
  op_enode->left = left;
  op_enode->right = right;
  return op_enode;
}

struct enode *setup_var_node(char *id){
  struct enode *var_enode = malloc(sizeof(struct enode));
  var_enode->type = 'v';
  int var_len = strlen(id);
  for(int i = 0; i<=var_len; i++){
    (var_enode->id)[i] = id[i];
  }
  var_enode->left = NULL;
  var_enode->right = NULL;
  free(id);
  return var_enode;
}

char *get_arg_at(const char *s, int start){
  int orig_start = start;
  int arg_len = 0;
  if(s[start] == '('){
    int open_bracket = 1;
    start++;
    arg_len++;
    while(open_bracket>0){
      if(s[start] == '('){
        open_bracket++; 
      }
      else if(s[start] == ')'){
        open_bracket--; 
      }
      start++;
      arg_len++;
    }
  }
  else if(s[start] == 45){
    start++;
    arg_len++;
    while(s[start]>=48 && s[start]<=57){
      start++;
      arg_len++;
    }
  }
  else if((s[start]>=65 && s[start]<=90) ||
          (s[start]>=97 && s[start]<=122)){
    while((s[start]>=65 && s[start]<=90) ||
          (s[start]>=97 && s[start]<=122)){
      start++;
      arg_len++;
    }
  }
  else{
    while(s[start]>=48 && s[start]<=57){
      start++;
      arg_len++;
    }
  }
  char *arg = malloc(sizeof(char)*(arg_len+1));
  for(int i = 0; i<arg_len; i++){
    arg[i] = s[orig_start + i]; 
  }
  arg[arg_len] = 0;
  return arg;
}

struct enode *string_to_enode(const char *s){
  if((s[0]>=48 && s[0]<=57) ||
     (s[1]>=48 && s[1]<=57)){
    int num;
    sscanf(s, "%d", &num);
    return setup_num_node(num); 
  }
  else if((s[0]>=65 && s[0]<=90) ||
          (s[0]>=97 && s[0]<=122)){
    char *var_name = malloc(sizeof(char)*21);
    int start = 0;
    while((s[start]>=65 && s[start]<=90) ||
          (s[start]>=97 && s[start]<=122)){
     var_name[start] = s[start]; 
     start++;
    }
    var_name[start] = 0;
    var_name = realloc(var_name, sizeof(char)*(start+1));
    return setup_var_node(var_name);
  }
  char op = s[1];
  char *arg1_str = get_arg_at(s, 3);
  int arg1_len = strlen(arg1_str);
  char *arg2_str = get_arg_at(s, 4 + arg1_len);
  struct enode *left = string_to_enode(arg1_str);
  struct enode *right = string_to_enode(arg2_str);
  free(arg1_str);
  free(arg2_str);
  return setup_op_node(op, left, right);
}

struct rexp *string_to_rexp(const char *s) {
  struct rexp *rexp = malloc(sizeof(struct rexp));
  struct enode *root = string_to_enode(s);
  rexp->root = root; 
  return rexp;
}

int enode_eval(const struct enode *node, 
               const struct dictionary *dictionary){
  if(node->type == 'n'){
    return node->number; 
  }
  else if(node->type == '*'){
    return enode_eval(node->left, dictionary)*
      enode_eval(node->right, dictionary);
  }
  else if(node->type == '/'){
    return enode_eval(node->left, dictionary)/
      enode_eval(node->right, dictionary);
  }
  else if(node->type == '-'){
    return enode_eval(node->left, dictionary)-
      enode_eval(node->right, dictionary);
  }
  else if(node->type == '+'){
    return enode_eval(node->left, dictionary)+
      enode_eval(node->right, dictionary);
  }
  else{
    return dict_lookup(node->id, dictionary);
  }
}

int rexp_eval(const struct rexp *r, const struct dictionary *constants) {
  return enode_eval(r->root, constants);
}

void free_node(struct enode *node){
  if(node->left){
    free_node(node->left); 
  }
  if (node->right){
    free_node(node->right); 
  }
  /*if(node->type == 'v'){
    free(node->id); 
  }*/
  free(node);
}

void rexp_destroy(struct rexp *r) {
  free_node(r->root);
  free(r);
  //dict_destroy(constants);
}


void add_constant(const char *s, struct dictionary *constants) {
  int start_of_var = 8;
  char *var_name = malloc(sizeof(char)*21);
  int i = 0;
  for(; s[i+start_of_var] != ' '; i++){
    var_name[i] = s[i+start_of_var]; 
  }
  var_name[i] = 0;
  var_name = realloc(var_name, sizeof(char)*(i+1));
  char *rexp_str = get_arg_at(s, start_of_var + i + 1);
  struct rexp *rexp = string_to_rexp(rexp_str);
  int var_val = rexp_eval(rexp, constants);
  dict_add(var_name, var_val, constants);
  free(rexp_str);
  free(var_name);
  rexp_destroy(rexp);
}

/*int main(void){
  const char *s="(+ (+ -1 1) (+ 2 -1))";
  struct rexp *rexp = string_to_rexp(s);
  struct dictionary *dict = NULL;
  print_rexp(rexp);
  printf("%d\n", rexp_eval(rexp, dict));
  rexp_destroy(rexp);
}*/


///////////////////////////////////////////////////////////////////////
// do NOT modify these functions: they are used for marmoset testing //
// (you may find them useful for your own testing)                   //
///////////////////////////////////////////////////////////////////////

void print_enode(const struct enode *e) {
  assert(e);
  if (e->type == 'n') {
    printf("%d", e->number);
  } else if (e->type == 'v') {
    printf("%s", e->id);
  } else {
    printf("(%c ", e->type);
    print_enode(e->left);
    printf(" ");
    print_enode(e->right);
    printf(")");
  }
}

void print_rexp(const struct rexp *r) {
  assert(r);
  print_enode(r->root);
  printf("\n");
}

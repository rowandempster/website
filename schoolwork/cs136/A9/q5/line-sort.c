#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

// INTEGRITY STATEMENT (modify if necessary)
// I received help from the following sources:
// None. I am the sole author of this work 

// sign this statement by removing the line below and entering your name

// Name: Rowan Dempster
// login ID: R2DEMPST

static const int initial_max_len = 2;

//line_reader(void) returns a pointer to the next read line  
//   in the character steam (reading only stops when a new 
//   line is encountered)
//effects: function caller must free malloced string address
//time: O(n) (amortized)
static char *line_reader(void) {
  char read_char;
  int len = 0;
  int max_len = 1;
  if (scanf("%c", &read_char) != 1){
    return NULL;
  }
  char *str_so_far = malloc(max_len * sizeof(char));
  do {
    str_so_far[len] = read_char;
    len++;
    if (len == max_len) {
      max_len *= 2;
      str_so_far=realloc(str_so_far, max_len * sizeof(char));
    }
    if (scanf("%c", &read_char) != 1){
      break;
    }
  } while (read_char != '\n');
  str_so_far[len] = '\0';
  str_so_far = realloc(str_so_far, (len + 1) * sizeof(char));
  return str_so_far;
}

//add_line(line_arr, line, len) adds the line pointer to the
//   line_arr in lexographical order
//requires: line_arr, line != NULL
//          len = length of line_arr
//effects: mutates line_arr
//time: O(n) where n is len
static void add_line(char **line_arr, char *line, int len){
  assert(line_arr&&line);
  int insert_index;
  if(len == 0){
    line_arr[0] = line; 
    return;
  }
  if(strcmp(line,line_arr[0])<0){
    insert_index = 0;
  }
  if(strcmp(line,line_arr[len-1])>0){
    line_arr[len] = line;
    return;
  }
  for(int j = 1; j<len; j++){
    if(strcmp(line, line_arr[j-1])>0 &&
       strcmp(line, line_arr[j])<=0){
      insert_index = j; 
    }
  }
  for(int end = len; insert_index<end; end--){
    line_arr[end]=line_arr[end-1];
  }
  line_arr[insert_index] = line;
}

int main(void) {
  int max_len = initial_max_len;
  int len = 0;
  char *read_line = line_reader();
  char **line_arr = malloc(sizeof(char*)*max_len);
  line_arr[len] = read_line;
  len++;
  while(1){
    if(len==max_len){
      max_len*=2;
      line_arr = realloc(line_arr, sizeof(char*)*max_len);
    }
    read_line = line_reader();
    if(read_line==NULL){
      break; 
    }
    add_line(line_arr, read_line, len);
    len++;
  }
  for(int i = 0; i<len; i++){
    printf("%s\n", line_arr[i]);
  }
  for(int i = 0; i<len; i++){
    free(line_arr[i]);
  }
  free(line_arr);
}
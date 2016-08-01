#include "testing-module.h"
#include "pantry.h"
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>


// INTEGRITY STATEMENT (modify if necessary)
// I received help from the following sources:
// None. I am the sole author of this work 

// sign this statement by removing the line below and entering your name

// Name: Rowan Dempster
// login ID: R2DEMPST


//  START OF DANGER ZONE!  DO NOT EDIT ANYTHING IN HERE
// ====================================================

// These are all of the message strings printed by the program.

const char MSG_QUIT[] = "Bye!\n";
const char MSG_CREATE[] = "Pantry created.\n";
const char MSG_DESTROY[] = "Pantry destroyed.\n";
const char MSG_COMMAND[] = "Enter Command: ";
const char MSG_UPDATE[] = "Pantry updated.\n";
const char MSG_COUNT[] = "The Pantry contains %d of ingredient '%s'.\n";

// These are all of the error messages printed by the program.

const char ERR_INVALID[] = "Invalid command.\n";
const char ERR_CREATE[] = "Free current Pantry before creating a new one.\n";
const char ERR_NO_PANTRY[] = "You must create a Pantry first.\n";
const char ERR_REMOVE[] = 
  "You cannot remove %d of '%s', the Pantry only contains %d.\n";
const char ERR_TUT[] = "Tut tut, you forgot to free the Pantry!\n";
const char ERR_AMT[] = "All amounts must be positive integers.\n";

// =================================================
// END OF THE DANGER ZONE.  YOU CAN EDIT THINGS AGAIN

//readstr(void) returns a pointer to the next read string in 
//   the character steam (reading only stops when a new line
//   is encountered)
//effects: function caller must free malloced string address
//time: O(n) (amortized)
static char *readstr(void) {
  char read_char;
  int len = 0;
  int max_len = 1;
  if (scanf(" %c", &read_char) != 1){
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

void interactive_pantry_test(void) {
  struct Pantry *p = NULL;
  bool p_exists = false;
  char c;
  while(1){
    scanf(" %c", &c);
    printf(MSG_COMMAND);
    if(c=='q'){
      if(p_exists){
        printf(ERR_TUT);
        pantry_destroy(p);
      }
      printf(MSG_QUIT);
      break;
    }
    else if(c=='n'){
      if(!p_exists){
        p = pantry_create();
        printf(MSG_CREATE);
        p_exists = true;
      }
      else{
        printf(ERR_CREATE);
      }
    }
    else if(c=='d'){
      if(!p_exists){
        printf(ERR_NO_PANTRY);
      }
      else{
        printf(MSG_DESTROY);
        pantry_destroy(p); 
        p_exists = false;
      }
    }
    else if(c=='c'){
      char *ing = readstr();
      if(!p_exists){
        printf(ERR_NO_PANTRY);
      }
      else{
        printf(MSG_COUNT, pantry_count(p, ing), ing);
      }
      free(ing);
    }
    else if(c=='a'){
      int amount;
      scanf("%d", &amount);
      char *ing = readstr();
      if(!p_exists){
        printf(ERR_NO_PANTRY);
      }
      else if(amount<0){
        printf(ERR_AMT);
      }
      else{
        pantry_add(p, ing, amount);
        printf(MSG_UPDATE);
      }
      free(ing);
    }
    else if (c=='r'){
      int amount;
      scanf("%d", &amount);
      char *ing = readstr();
      int stock = pantry_count(p, ing);
      if(!p_exists){
        printf(ERR_NO_PANTRY);
      }
      else if(amount<0){
        printf(ERR_AMT);
      }
      else if(amount>stock){
        printf(ERR_REMOVE, amount, ing, stock);
      }
      else{
        pantry_remove(p, ing, amount);
        printf(MSG_UPDATE);
      }
      free(ing);
    }
    else{
      printf(ERR_INVALID);
    }
  }
}

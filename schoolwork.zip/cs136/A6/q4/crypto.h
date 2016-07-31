// INTEGRITY STATEMENT (modify if necessary)
// I received help from the following sources:
// None. I am the sole author of this work

// sign this statement by removing the line below and entering your name

// Name: Rowan Dempster
// login ID: R2DEMPST

// interface:

struct character_map
{
  char orig;
  char rep;
};

//encode_message(m[], len_m, message[], message_len) changes
//   the char elements in message[] according to the 
//   encryptions rules stored in m[]
//requires: m[] and message[] are not null
//effects: mutates message[]
void encode_message(struct character_map m[], int len_m, 
                    char message[], int message_len);

//decode_message(m[], len_m, message[], message_len) changes
//   the char elements in message[] to their original state
//   according to the decrytion rules stored in m[]
//requires: m[] and message[] are not null
//effects: mutates message[]
void decode_message(struct character_map m[], int len_m, 
               char message[], int message_len);

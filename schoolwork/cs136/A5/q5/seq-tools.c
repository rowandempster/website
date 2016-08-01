#include <stdio.h>
#include "sequence.h"
#include "seq-tools.h"
#include <assert.h>


// INTEGRITY STATEMENT (modify if necessary)
// I received help from the following sources:
// None. I am the sole author of this work 

// sign this statement by removing the line below and entering your name

// Name: Rowan Dempster
// login ID: R2DEMPST

// implementation:


void Sequence_add_one(struct Sequence *seq) {
  assert(seq);
  int seq_len = Sequence_length(seq);
  for(int i = 0; i<seq_len; i++){
    int removed = Sequence_remove_at(seq, i);
    removed++;
    Sequence_insert_at(seq, i, removed);
  }
}


struct Sequence *Sequence_build(int n) {
  struct Sequence *seq = Sequence_create();
  for (int i = 0; i<n; i++){
    Sequence_insert_at(seq, i, i);
  }
  return seq;
}


void Sequence_map(int (*fp)(int), struct Sequence *seq) {
  assert(seq&&fp);
  int seq_len = Sequence_length(seq);
  for(int i = 0; i<seq_len; i++){
    int removed = Sequence_remove_at(seq, i);
    int altered = fp(removed);
    Sequence_insert_at(seq, i, altered);
  }
}


/////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////


bool Sequence_equal(const struct Sequence *seq1, const struct Sequence *seq2) {
  assert(seq1&&seq2);
  int len1 = Sequence_length(seq1);
  int len2 = Sequence_length(seq2);
  if(len1!=len2){
    return false; 
  }
  for(int i = 0; i<len1; i++){
    if(Sequence_item_at(seq1, i) !=  
       Sequence_item_at(seq2, i)){
      return false; 
    }
  }
  return true;
}


void Sequence_add_sum(struct Sequence *seq) {
  assert(seq);
  int sum_so_far = Sequence_item_at(seq, 0);
  int len = Sequence_length(seq);
  for(int i = 1; i<len; i++){
    int removed = Sequence_remove_at(seq, i);
    sum_so_far += removed;
    Sequence_insert_at(seq, i, sum_so_far);

  }
}


void Sequence_avg_and_variance(const struct Sequence *seq, 
                               int *avg, int *var) {
  assert(seq);
  assert(Sequence_length(seq)>0);
  int sum = 0;
  for(int i = 0; i<Sequence_length(seq); i++){
    sum += Sequence_item_at(seq, i); 
  }
  *avg = sum/Sequence_length(seq);
  int diff_sqr = 0;
  for(int i = 0; i<Sequence_length(seq); i++){
    diff_sqr += ((Sequence_item_at(seq, i) - *avg)*
                 (Sequence_item_at(seq, i) - *avg)); 
  }
  *var = diff_sqr/Sequence_length(seq);
}


void Sequence_filter(bool (*fp)(int), struct Sequence *seq) {
  assert(seq&&fp);
  int i = 0;
  while(i<Sequence_length(seq)) {
    if(!fp(Sequence_item_at(seq, i))){
      Sequence_remove_at(seq, i);
      i--;
    }
    i++;
  }
}


int Sequence_foldl(int (*fp)(int, int), int base, 
                   const struct Sequence *seq) {
  assert(fp&&seq);
  if(Sequence_length(seq)==0){
    return base; 
  }
  int result_so_far = 0;
  for(int i = 0; i<Sequence_length(seq); i++){
    if(i==0){
      result_so_far = fp(Sequence_item_at(seq, i), base);
    }
    else {
      result_so_far = fp(Sequence_item_at(seq, i),
                         result_so_far);
    }
  }
  return result_so_far;
}


struct Sequence *Sequence_fib(int n) {
  assert(n>=1);
  struct Sequence *seq = Sequence_create();
  int two_behind = 0;
  int one_behind = 1;
  int curr;
  if(n==1){
    Sequence_insert_at(seq, 0, two_behind);
    return seq;
  }
  if(n==2){
    Sequence_insert_at(seq, 0, two_behind);
    Sequence_insert_at(seq, 1, one_behind);
    return seq;
  }
  Sequence_insert_at(seq, 0, two_behind);
  Sequence_insert_at(seq, 1, one_behind);
  for(int i = 2; i<n; i++){
    curr = two_behind + one_behind;
    Sequence_insert_at(seq, i, curr);
    two_behind = one_behind;
    one_behind = curr;
  }
  return seq;
}


struct Sequence *Sequence_collatz(int n) {
  assert(n>=1);
  struct Sequence *seq = Sequence_create();
  int index_counter = 0;
  while(n!=1){
    if (n % 2 == 0) {
      Sequence_insert_at(seq, index_counter, n);
      index_counter++;
      n/=2;
    } 
    else {
      Sequence_insert_at(seq, index_counter, n);
      index_counter++;
      n = 3*n + 1;
    }
  }
  Sequence_insert_at(seq, index_counter, 1);
  return seq;
}

void Sequence_reverse(struct Sequence *seq) {
  int len = Sequence_length(seq);
  int i = 0;
  while(i<len/2){
    int first_half =  Sequence_item_at(seq, i);
    int second_half = Sequence_item_at(seq, len-1-i);
    Sequence_insert_at(seq, i, second_half);
    Sequence_remove_at(seq, i+1);
    Sequence_insert_at(seq, len-i-1, first_half);
    Sequence_remove_at(seq, len-i);
    i++;
  }
}

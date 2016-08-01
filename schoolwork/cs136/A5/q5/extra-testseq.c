#include <assert.h>
#include "sequence.h"

// this is an extra simple test client for the sequence module

// most of you will want to use test-seqtools

// This is only here to provide extra examples of how a Sequence can be used
// and to provide alternative ideas for your own testing.

int main(void) {
  struct Sequence *s = Sequence_create();
  assert (Sequence_length(s) == 0);
  for (int i=0; i < 10; ++i) {
    Sequence_insert_at(s, i, i*i);
  }
  Sequence_print(s);
  assert(Sequence_item_at(s, 4) == 16);
  Sequence_remove_at(s, 2);
  Sequence_print(s);
  assert(Sequence_item_at(s, 3) == 16);
  Sequence_clear(s);
  Sequence_print(s);
}

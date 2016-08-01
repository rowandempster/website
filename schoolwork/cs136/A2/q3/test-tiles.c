#include "io_test.h"
#include "tiles.h"

// DO NOT MODIFY THIS FILE

// this is an I/O test client for translation
// see the assignment for more details

// look at the sample.in and sample.expect for
// a concrete example of how to use this test client

int main(void) {
  add_int_test("min_tiles", min_tiles, 4);
  add_stop_test("quit");
  io_test();
}

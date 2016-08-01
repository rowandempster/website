#include "io_test.h"
#include "translation.h"

// DO NOT MODIFY THIS FILE

// this is an I/O test client for translation
// see the assignment for more details

// look at the sample.in and sample.expect for
// a concrete example of how to use this test client

int main(void) {
  add_int_test("polyeval", polyeval, 4);
  add_int_test("selector", selector, 3);
  add_int_test("max3", max3, 3);
  add_int_test("sumsqr1", sumsqr1, 1);
  add_int_test("sumsqr2", sumsqr2, 1);
  add_int_test("sumsqr3", sumsqr3, 1);
  add_int_test("sameparity", sameparity, 2);
  add_stop_test("quit");
  io_test();
}

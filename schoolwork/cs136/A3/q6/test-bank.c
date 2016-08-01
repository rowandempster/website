#include "io_test.h"
#include "bank.h"

// DO NOT MODIFY THIS FILE

// this is an I/O test client for bank

// look at the simple.in and simple.expect for
// a concrete example of how to use this test client

int main(void) {
  add_void_test("deposit", deposit, 1);
  add_void_test("withdrawal", withdrawal, 1);
  add_void_test("balance", print_balance, 0);
  add_void_test("limit", print_limit, 0);
  add_void_test("newday", new_day, 0);
  add_void_test("increase", request_limit_increase, 0);
  add_stop_test("quit");
  io_test();
}

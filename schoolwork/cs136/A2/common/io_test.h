
// io_test: A module for testing C functions with I/O

// DO NOT WORRY ABOUT THE TYPES BELOW.
// THEY WILL BE INTRODUCED LATER IN THE TERM

// add_int_test(name, func, param_count) adds a new test [name]
//   for an integer function [func] with param_count parameters
void add_int_test(const char *name, // Str
                  void *func,       // Function
                  int param_count);

// add_stop_test(name) adds a stop command [name]
void add_stop_test(const char *name);  // Str

// io_test() starts the test, reading commands from
//   input, and printing the results of each test
//   until an error, stop command or EOF is reached
void io_test(void);


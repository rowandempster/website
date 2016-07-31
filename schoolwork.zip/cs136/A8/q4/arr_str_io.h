// arr_str_io module: a module for reading in strings from I/O

extern const int max_string_len;

// fill_array_string_io(strings, len, maxlen) reads in from I/O len strings
//   into the the array [strings].  If len is -1, then up to maxlen strings
//   are read in until EOF is encountered. returns the number of
//   successfully read in strings.
// requires: 0 <= len <= maxlen, or len is -1
//           client must call free_array_strings(strings, len) before exiting
// effects: modifies strings, reads in from I/O
// time: O(n), where n is the total number of characters

int fill_array_strings_io(char *strings[], int len, int maxlen);

// free_array_strings(strings, len) frees all strings in the array [strings]
// effects: replaces each element of strings with NULL
// time: O(n), where n is len
void free_array_strings(char *strings[], int len);

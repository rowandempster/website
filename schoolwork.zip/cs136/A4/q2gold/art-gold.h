//checker(width, height, size, c1, c2) draws a checked board out of characters c1 and c2
//requries: size, width, height >= 0
//effects: prints out a checkered board
void checker(int width, int height, int size, char c1, char c2);

//print_row(c, times) draws a single row of char c
// times times
//requires: times>=0
//effects: prints out c
void print_row(char c, int times);

//make_row( c1, c2, size, start_tracker, width) draws size's rows of alternating c1 and c2
//requries: size, width >=0
//effects: prints out a row
void make_row(char c1, char c2, int size, int start_tracker, int width);

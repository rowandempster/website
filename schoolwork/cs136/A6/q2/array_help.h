// array_help -- A module to obtain polynomials of a certain length - Interface.

// get_polynomial(deg): returns an integer array of size deg+1.
// requires: deg>=0
// effects: May print error message and exit program if not enough memory
//          could be allocated.
int *get_polynomial(int deg);

// delete_polynomial(poly): Deletes the polynomial from the memory.
// requires: poly is not the NULL-pointer.
// effects: May print a message if poly was the NULL pointer.
void delete_polynomial(int poly[]);

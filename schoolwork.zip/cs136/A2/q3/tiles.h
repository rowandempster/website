
// interface:

// tiles: A C module for caclulating the number of tiles needed to tile a room

//Calculates the minimum tiles, with width tile_width and 
//height tile_height, needed to tile a room with width 
//room_width and height room_height
//requires: all parameters >= 0
int min_tiles(const int tile_width, const int tile_height, 
              const int room_width, const int room_height);


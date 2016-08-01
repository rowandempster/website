#include "tiles.h"

// INTEGRITY STATEMENT (modify if necessary)
// I received help from the following sources:
// None. I am the sole author of this work 

// sign this statement by removing the line below and entering your name

// Name: Rowan Dempster
// login ID: R2DEMPST

// implementation:

int fill_room (const int tile_width, const int tile_height, 
               const int room_width, const int room_height, 
               const int tiles_used) {
 if ((room_width == 0) || (room_height ==0)) {
  return tiles_used; 
 }
  else if ((tile_height<=room_height) && 
           ((room_width % tile_width) == 0)) 
  {
   return fill_room(tile_width, tile_height, room_width, 
                    room_height-tile_height, 
                    tiles_used + (room_width/tile_width)); 
  }
  else if (tile_height<=room_height) 
  {
    return fill_room(tile_width, tile_height, room_width, 
                     room_height-tile_height, 
                     tiles_used + (room_width/tile_width)+1); 
  }
  else {
   return fill_room(tile_width, tile_height - 1, 
                    room_width, room_height, tiles_used); 
  }
}

//See (.h) for purpose descriptions
int min_tiles(const int tile_width, const int tile_height, 
              const int room_width, const int room_height) {
  if (fill_room(tile_width, tile_height, 
                room_width, room_height, 0) >= 
      fill_room(tile_height, tile_width, 
                room_width, room_height, 0))  
  {
    return fill_room(tile_height, tile_width, 
                     room_width, room_height, 0);
  }
  else {
    return fill_room(tile_width, tile_height, 
                     room_width, room_height, 0);
  }
}




              
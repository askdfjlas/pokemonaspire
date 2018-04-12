#include "Collision.h"

byte collisionDetect(byte direction) {
    int x = ahri.x/16;
    int y = ahri.y/16;
    
    switch(direction) {
      case RIGHT: 
        if(getObject(currentTilemap.spriteMap[y*currentTilemap.dimX + x + 1]) == WALL) return 0;
        return 1;
      case LEFT:
        if(getObject(currentTilemap.spriteMap[y*currentTilemap.dimX + x - 1]) == WALL) return 0;
        return 1;
      case UP:
        if(getObject(currentTilemap.spriteMap[(y-1)*currentTilemap.dimX + x]) == WALL) return 0;
        return 1;
      case DOWN:
        if(getObject(currentTilemap.spriteMap[(y+1)*currentTilemap.dimX + x]) == WALL) return 0;
        return 1;
  }
}

// Converts a value in the spritemap to an interaction object (described in Collision.h)
byte getObject(byte spriteMapNumber) {
  switch(spriteMapNumber) {
    case 0:
      return FREESPACE; 
    case 1:
      return WALL; 
    case 2:
      return FREESPACE; 
    case 3: 
      return WALL;
    case 4: 
      return WALL;
    case 5: 
      return WALL;
  }
}


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
    case 6:
      return WALL; 
    case 7:
      return WALL;
    case 8: 
      return WALL; 
    case 9:
      return FREESPACE; 
    case 10:
      return WALL; 
    case 11: 
      return FREESPACE; 
  }
}

byte checkTileProperty() {
  if(ahri.movingState == STOP) {
    for(int i = 0; i < currentTilemap.tileProperties[0]/3; i++) {
      if(ahri.x/16 == currentTilemap.tileProperties[3*i + 1] && ahri.y/16 == currentTilemap.tileProperties[3*i + 2])
        return currentTilemap.tileProperties[3*i + 3];
    }
  }

  return NONE;
}


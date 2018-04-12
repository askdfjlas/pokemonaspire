#include <Arduboy2.h>
#include "Sprites.h"
#include "Tilemaps.h"

void loadTilemap(tileMapData T, byte* spriteMap, byte* collisionMap) {
  currentTilemap.spriteMap = calloc(T.dimY*T.dimX, sizeof(byte)); 
  currentTilemap.collisionMap = calloc(T.dimY*T.dimX, sizeof(byte)); 

  for(int i = 0; i < T.dimX*T.dimY; i++)
    currentTilemap.spriteMap[i] = pgm_read_byte(spriteMap + i); 

  for(int i = 0; i < T.dimX*T.dimY; i++)
    currentTilemap.collisionMap[i] = pgm_read_byte(collisionMap + i); 
 
  currentTilemap.dimX = T.dimX;
  currentTilemap.dimY = T.dimY; 

  ahri.x = T.Entrance1X*16;
  ahri.y = T.Entrance1Y*16;
}

void drawMap() {
  int x, y; 
  for(x = 0; x < currentTilemap.dimX; x++) 
    for(y = 0; y < currentTilemap.dimY; y++)
      arduboy.drawBitmap(x*16 - ahri.x + PLAYERTRUEX, y*16 - ahri.y + PLAYERTRUEY, getTile(currentTilemap.spriteMap[y*currentTilemap.dimX + x]), 16, 16, WHITE);
}

char* getTile(byte num) {
  switch(num) {
    case 0: 
      return Tile1;
    case 1:
      return Tile2;
    case 2:
      return Tile3;
  }
}


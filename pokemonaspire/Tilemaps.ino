#include <Arduboy2.h>
#include "Sprites.h"
#include "Tilemaps.h"

void loadTilemap(tileMapData T, byte* spriteMap, byte* tileProperties) {
  free(currentTilemap.spriteMap); 
  free(currentTilemap.tileProperties); 
  
  currentTilemap.spriteMap = calloc(T.dimY*T.dimX, sizeof(byte)); 
  currentTilemap.tileProperties = calloc(tileProperties[0], sizeof(byte)); 

  for(int i = 0; i < T.dimX*T.dimY; i++)
    currentTilemap.spriteMap[i] = pgm_read_byte(spriteMap + i); 

  for(int i = 0; i < tileProperties[0]; i++)
    currentTilemap.tileProperties[i] = pgm_read_byte(tileProperties + i); 
 
  currentTilemap.dimX = T.dimX;
  currentTilemap.dimY = T.dimY; 
}

void drawMap() {
  int x, y; 
  for(x = 0; x < currentTilemap.dimX; x++) 
    for(y = 0; y < currentTilemap.dimY; y++) {
      int xPos = x*16 - ahri.x + PLAYERTRUEX; 
      int yPos = y*16 - ahri.y + PLAYERTRUEY; 
      if(xPos < -16 || xPos > 128 || yPos < -16 || yPos > 64) continue; 
      arduboy.drawBitmap(xPos, yPos, getTile(currentTilemap.spriteMap[y*currentTilemap.dimX + x]), 16, 16, WHITE);
    }
}

char* getTile(byte num) {
  switch(num) {
    case 0: 
      return Tile1;
    case 1:
      return Tile2;
    case 2:
      return Tile3;
    case 3:
      return Tile4;
    case 4:
      return Tile5;
    case 5:
      return Tile6; 
    case 6:
      return Tile7; 
    case 7:
      return Tile8;
    case 8: 
      return Tile9; 
    case 9:
      return Tile10;
    case 10:
      return Tile11; 
    case 11:
      return Tile12; 
    /*
    case 12:
      return Tile13; */
  }
}


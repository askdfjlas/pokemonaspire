#ifndef TILEMAPS_H
#define TILEMAPS_H
#include <stdio.h>

// Tilemap struct (stored in program memory)
typedef struct tileMapData {
  // Tilemap dimensions
  byte dimX PROGMEM;
  byte dimY PROGMEM; 

  // Pointers to another tilemap (area) are reserved for 253, 254, 256 in the collisionMap
  struct Tilemap* Exit1 PROGMEM; 
  struct Tilemap* Exit2 PROGMEM;
  struct Tilemap* Exit3 PROGMEM; 

  // Entrance coordinates corresponding with other exits
  byte Entrance1X PROGMEM; 
  byte Entrance1Y PROGMEM; 
  byte Entrance2X PROGMEM; 
  byte Entrance2Y PROGMEM; 
  byte Entrance3X PROGMEM; 
  byte Entrance3Y PROGMEM; 
}tileMapData; 

// Similar struct but stored in RAM, a single Tilemap is loaded at a time
typedef struct loadedTilemap {
  byte dimX;
  byte dimY; 
  
  byte* spriteMap;

  struct Tilemap* Exit1; 
  struct Tilemap* Exit2;
  struct Tilemap* Exit3; 

  byte Entrance1X; 
  byte Entrance1Y; 
  byte Entrance2X; 
  byte Entrance2Y; 
  byte Entrance3X; 
  byte Entrance3Y; 
}loadedTileMap;

loadedTileMap currentTilemap; 

// Prototypes
void drawMap();
char* getTile(byte num);
void loadTilemap(tileMapData T, byte* spriteMap);

// Sprite maps
const byte S1[] PROGMEM = 
{1, 1, 1, 1, 1, 1, 1, 1, 1,
1, 3, 3, 3, 3, 3, 3, 3, 1,
1, 2, 2, 2, 2, 2, 2, 2, 1, 
1, 2, 2, 2, 2, 2, 2, 2, 1,
1, 2, 2, 2, 2, 2, 2, 2, 1,
1, 2, 2, 2, 2, 2, 2, 2, 1, 
1, 2, 2, 2, 2, 2, 2, 5, 1,
1, 2, 2, 2, 2, 2, 2, 4, 1, 
1, 1, 1, 1, 1, 1, 1, 1, 1}; 


// Map Data
const tileMapData T1 PROGMEM = {9, 9, NULL, NULL, NULL, 1, 2, 0, 0, 0, 0}; 


#endif

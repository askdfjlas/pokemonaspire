#define STARTX 4
#define STARTY 5

#ifndef TILEMAPS_H
#define TILEMAPS_H
#include <stdio.h>

enum TileProperties{NONE, ITEM, EXIT1, EXIT2, EXIT3}; 

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
  byte* tileProperties; 

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

// Bedroom
const byte S1[] PROGMEM = 
{1, 1, 1, 1, 1, 1, 1, 1, 1,
1, 3, 3, 6, 3, 3, 6, 3, 1,
1, 5, 2, 2, 2, 2, 2, 11, 1, 
1, 4, 2, 9, 10, 9, 2, 2, 1,
1, 2, 2, 9, 9, 9, 2, 2, 1,
1, 2, 2, 9, 9, 9, 2, 2, 1, 
1, 8, 2, 2, 2, 2, 2, 5, 1,
1, 7, 2, 2, 2, 2, 2, 4, 1, 
1, 1, 1, 1, 1, 1, 1, 1, 1}; 

// Map Data
const tileMapData T1 PROGMEM = {9, 9, NULL, NULL, NULL, 4, 5, 0, 0, 0, 0}; 

// Tile Properties (format: first item = length, then: x, y, Tile Property)
const byte P1[] PROGMEM = 
{4, 7, 2, EXIT1}; 

#endif

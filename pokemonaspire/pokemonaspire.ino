#include "Sprites.h"
#include "Tilemaps.h"
#include "Player.h"
#include "Aspire.h"
#include "Collision.h"
#include "Input.h"

void setup() {
  arduboy.begin();
  arduboy.clear();
  arduboy.setFrameRate(30);
  ahri.x = STARTX*16;
  ahri.y = STARTY*16;
  loadTilemap(T1, S1, P1); 
}

void loop() {
  if(!(arduboy.nextFrame())) return; 
  arduboy.clear();
  overworld(); 
  arduboy.display();
}

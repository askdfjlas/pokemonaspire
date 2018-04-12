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
  loadTilemap(T1, S1); 
}

void loop() {
  if(!(arduboy.nextFrame())) return; 
  arduboy.clear();
  getInputs(); 
  playerMovement(); 
  drawMap();
  drawPlayer();
  arduboy.display();
}

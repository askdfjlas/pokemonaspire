#ifndef PLAYER_H
#define PLAYER_H

#define PLAYERTRUEX 56
#define PLAYERTRUEY 24
#define SPEED 2
#define INPUTBUFFERTHRESHOLD 2

// Prototypes
void playerMovement();  
void drawPlayer(); 
void walkAnim(byte direction); 

enum movement{STOP, UP, DOWN, LEFT, RIGHT, BUMPUP, BUMPDOWN, BUMPLEFT, BUMPRIGHT}; 
enum spriteType{UPS, DOWNS, LEFTS, RIGHTS, UPMOVES, DOWNMOVES, RIGHTMOVES, LEFTMOVES};
// "S" stands for sprite, each one corresponds to a sprite in the moving animation

typedef struct player {
  int x = 0;
  int y = 0; 
  byte movingState = STOP;
  byte sprite = DOWNS; 
  byte movBuffer = 0; 
  byte inputBuffer = 0; // allows for turn around without moving (2 frame window) 
  byte contMovement = 0; // alternate footsteps when continuously moving
}player;

#endif

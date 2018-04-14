#ifndef COLLISION_H
#define COLLISION_H

enum interactionType{FREESPACE, WALL}; 

// FREESPACE = passable
// WALL = impassable 

// Prototypes
byte collisionDetect(byte direction);
byte getObject(byte spriteMapNumber); // gets the interaction type
byte checkTileProperty(); // gets the tile property of the tile the player is standing on

#endif

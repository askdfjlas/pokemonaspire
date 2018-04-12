#ifndef COLLISION_H
#define COLLISION_H

enum interactionType{FREESPACE, WALL}; 

// FREESPACE = passable
// WALL = impassable 

// Prototypes
byte collisionDetect(byte direction); 
byte getObject(byte spriteMapNumber);



#endif

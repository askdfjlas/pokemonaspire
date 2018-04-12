#ifndef ASPIRE_H
#define ASPIRE_H

#include <Arduboy2.h>

Arduboy2 arduboy;
Sprites sprites;

#define ARDBITMAP_SBUF arduboy.getBuffer()
#include <ArdBitmap.h>
ArdBitmap<WIDTH, HEIGHT> ardbitmap;

player ahri; //I always call the player struct/class "ahri"

#endif

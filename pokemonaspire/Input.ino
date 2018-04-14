#include "Input.h"

// overworld inputs
void getInputs() {
  if(ahri.movingState == STOP) {
    if(arduboy.pressed(RIGHT_BUTTON)) { 
      ahri.sprite = RIGHTS; 
      if(ahri.inputBuffer >= INPUTBUFFERTHRESHOLD) {
        if(collisionDetect(RIGHT)) ahri.movingState = RIGHT; 
        else ahri.movingState = BUMPRIGHT;
      }
    }
    if(arduboy.pressed(LEFT_BUTTON)) { 
      ahri.sprite = LEFTS; 
      if(ahri.inputBuffer >= INPUTBUFFERTHRESHOLD) {
        if(collisionDetect(LEFT)) ahri.movingState = LEFT; 
        else ahri.movingState = BUMPLEFT;
      }
    }
    if(arduboy.pressed(UP_BUTTON)) { 
      ahri.sprite = UPS; 
      if(ahri.inputBuffer >= INPUTBUFFERTHRESHOLD) {
        if(collisionDetect(UP)) ahri.movingState = UP; 
        else ahri.movingState = BUMPUP;
      }
    }
    if(arduboy.pressed(DOWN_BUTTON)) {
      ahri.sprite = DOWNS; 
      if(ahri.inputBuffer >= INPUTBUFFERTHRESHOLD) {
        if(collisionDetect(DOWN)) ahri.movingState = DOWN; 
        else ahri.movingState = BUMPDOWN; 
      }
    }

    if(!arduboy.pressed(RIGHT_BUTTON) && !arduboy.pressed(LEFT_BUTTON) && !arduboy.pressed(UP_BUTTON) && !arduboy.pressed(DOWN_BUTTON)) {
      ahri.contMovement = 0; 
      ahri.inputBuffer = 0; 
    }
    else {
      ahri.inputBuffer++; 
      ahri.contMovement = (ahri.contMovement + 1) % 2; 
    }
  }
}

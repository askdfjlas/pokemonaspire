#include "Player.h"

void playerMovement() {
  switch(ahri.movingState) {
    case STOP: 
      break;
    case RIGHT: 
      walkAnim(RIGHT); 
      ahri.x += SPEED;
      break;
    case LEFT:
      walkAnim(LEFT);
      ahri.x -= SPEED; 
      break;
    case UP:
      walkAnim(UP);
      ahri.y -= SPEED;
      break;
    case DOWN:
      walkAnim(DOWN);
      ahri.y += SPEED;
      break;
    case BUMPUP:
      walkAnim(UP); 
      break;
    case BUMPDOWN:
      walkAnim(DOWN);
      break;
    case BUMPLEFT:
      walkAnim(LEFT);
      break;
    case BUMPRIGHT:
      walkAnim(RIGHT); 
      break;
  }

  if(ahri.movBuffer == 16/SPEED) {
    ahri.movingState = STOP;
    ahri.movBuffer = 0; 
  }
}

void walkAnim(byte direction) {
  switch(direction) {
    case RIGHT: 
      if(ahri.movBuffer > 1 && ahri.movBuffer < 7) 
        ahri.sprite = RIGHTMOVES;
      else 
        ahri.sprite = RIGHTS; 
      break;
    case LEFT:
      if(ahri.movBuffer > 1 && ahri.movBuffer < 7) 
        ahri.sprite = LEFTMOVES;
      else 
        ahri.sprite = LEFTS; 
      break;
    case UP: 
      if(ahri.movBuffer > 1 && ahri.movBuffer < 7) 
          ahri.sprite = UPMOVES;
      else 
        ahri.sprite = UPS;
      break;
    case DOWN:
      if(ahri.movBuffer > 1 && ahri.movBuffer < 7) 
        ahri.sprite = DOWNMOVES;
      else 
        ahri.sprite = DOWNS; 
      break;
  }

  ahri.movBuffer++; 
}

void drawPlayer() {
  const unsigned char *sprite; 
  const unsigned char *maskedSprite; 
  uint8_t flipped = MIRROR_NONE; 
  
  switch(ahri.sprite) {
    case DOWNS: 
      sprite = playerSpriteDown;
      maskedSprite = playerSpriteDownMask; 
      break;
    case UPS: 
      sprite = playerSpriteUp; 
      maskedSprite = playerSpriteUpMask;
      break;
    case RIGHTS:
      sprite = playerSpriteRight; 
      maskedSprite = playerSpriteRightMask; 
      break;
    case LEFTS:
      flipped = MIRROR_HORIZONTAL; 
      sprite = playerSpriteRight; 
      maskedSprite = playerSpriteRightMask;
      break;
    case UPMOVES:
      sprite = playerSpriteUpMove; 
      maskedSprite = playerSpriteUpMoveMask;
      if(ahri.contMovement) flipped = MIRROR_HORIZONTAL; 
      break;
    case DOWNMOVES: 
      sprite = playerSpriteDownMove;
      maskedSprite = playerSpriteDownMoveMask;
      if(ahri.contMovement) flipped = MIRROR_HORIZONTAL; 
      break;
    case RIGHTMOVES:
      sprite = playerSpriteRightMove;
      maskedSprite = playerSpriteRightMoveMask;
      break;
    case LEFTMOVES:
      flipped = MIRROR_HORIZONTAL; 
      sprite = playerSpriteRightMove;
      maskedSprite = playerSpriteRightMoveMask;
      break;
  }

  ardbitmap.drawCompressed(PLAYERTRUEX, PLAYERTRUEY, maskedSprite, BLACK, ALIGN_H_LEFT | ALIGN_V_TOP, flipped); 
  ardbitmap.drawCompressed(PLAYERTRUEX, PLAYERTRUEY, sprite, WHITE, ALIGN_H_LEFT | ALIGN_V_TOP, flipped); 
}

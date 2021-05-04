//***************************************************************************
// File name:  CardViewSDL.h
// Author:     Erin Melia
// Date:       4/30/2021
// Class:      CS485
// Assignment: Blackjack
// Purpose:    Declares a class used to display a card to the screen
//***************************************************************************
#pragma once

#include <memory>

#include "SDLSprite.h"

class CardViewSDL {
  public:
    CardViewSDL(SDLSprite* faceUp, SDLSprite* faceDown, bool isFaceUp);
    ~CardViewSDL();

    void flip();
    void draw(SDLApp &app);

    bool isFaceUp() { return bIsFaceUp; };

  private:
    SDLSprite* mpFaceUp;
    SDLSprite* mpFaceDown;
    bool bIsFaceUp;
};

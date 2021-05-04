//***************************************************************************
// File name:  CardViewSDL.h
// Author:     Erin Melia
// Date:       4/30/2021
// Class:      CS485
// Assignment: Blackjack
// Purpose:    Declares a class used to display a card to the screen
//***************************************************************************
#pragma once

#include "SDLSprite.h"

class CardViewSDL {
  public:
    CardViewSDL(SDLSprite* faceUp, SDLSprite* faceDown, bool isFaceUp);
    ~CardViewSDL();

    void flip() { mbIsFaceUp = true; };
    void draw(SDLApp &app);

    bool isFaceUp() { return mbIsFaceUp; };

  private:
    SDLSprite* mpFaceUp;
    SDLSprite* mpFaceDown;
    bool mbIsFaceUp;
};

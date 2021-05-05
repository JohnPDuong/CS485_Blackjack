//***************************************************************************
// File name:  CardViewSDL.h
// Author:     Erin Melia
// Date:       5/3/2021
// Class:      CS485
// Assignment: Blackjack
// Purpose:    Defines the class declared in CardViewSDL.h
//***************************************************************************
#include "CardViewSDL.h"

//***************************************************************************
// Constructor: CardViewSDL
//
// Description: Initialize the data in CardView to display a particular card
//
// Parameters:  faceUp   - the sprite that should be displayed when the card 
//                         is face up
//              faceDown - the sprite that should be displayed when the card 
//                         is face down
//              isFaceUp - whether the card should begin face up or face down
//
// Returned:    None
//***************************************************************************
CardViewSDL::CardViewSDL (SDLSprite* faceUp, SDLSprite* faceDown, bool isFaceUp)
{
  mpFaceUp = faceUp;
  mpFaceDown = faceDown;
  mbIsFaceUp = isFaceUp;
}

//***************************************************************************
// Destructor:  ~CardViewSDL
//
// Description: Delete the sprites
//
// Parameters:  None
//
// Returned:    None
//***************************************************************************
CardViewSDL::~CardViewSDL ()
{
  delete mpFaceUp;
  delete mpFaceDown;
}

//***************************************************************************
// Function:    draw
//
// Description: displays the card to the screen
//
// Parameters:  app - the app that the card is drawn to
//
// Returned:    None
//***************************************************************************
void CardViewSDL::draw (SDLApp& app)
{
  if(mbIsFaceUp)
    mpFaceUp->draw(app);
  else
    mpFaceDown->draw(app);
}

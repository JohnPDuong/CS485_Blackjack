//***************************************************************************
// File name:  PlayerView.cpp
// Author:     Erin Melia
// Date:       5/5/2021
// Class:      CS485
// Assignment: Blackjack
// Purpose:    Defines the functionality for the class declared in 
//             PlayerView.h
//***************************************************************************
#include "PlayerView.h"

//***************************************************************************
// Constructor: PlayerView
//
// Description: Initialize the display
//
// Parameters:  None
//
// Returned:    None
//***************************************************************************
PlayerView::PlayerView (int x, int y) :
mcNameDisplay("Name", "", x, y, 1, {255, 255, 255, 255}),
mcMoneyDisplay("Money", "", x, y+10, 1, {255, 255, 255, 255})
{
  mX = x;
  mY = y;
}

//***************************************************************************
// Destructor:  ~PlayerView
//
// Description: Clear the data in the player's hand/s
//
// Parameters:  None
//
// Returned:    None
//***************************************************************************
PlayerView::~PlayerView ()
{
  discardHand();
}

//***************************************************************************
// Function:    draw
//
// Description: Draws the PlayerView to the specified SDLApp
//
// Parameters:  app - the app to draw the Player to
//
// Returned:    None
//***************************************************************************
void PlayerView::draw (SDLApp& app)
{
  mcNameDisplay.draw(app);
  mcMoneyDisplay.draw(app);
  for (auto it = mcCards.begin(); it != mcCards.end(); it++)
    it->draw(app);
  for (auto it = mcSplitHand.begin(); it != mcCards.end(); it++)
    it->draw(app);
}

//***************************************************************************
// Function:    addCard
//
// Description: Adds a new card to the player's hand
//
// Parameters:  app      - the app to load the sprite to
//              card     - the string representing the card
//              isFaceUp - whether the card should initially be displayed face
//                         up or face down
//
// Returned:    None
//***************************************************************************
void PlayerView::addCard (SDLApp* app, std::string card, bool isFaceUp)
{
  SDLSprite* pFaceUp = new SDLSprite;
  SDLSprite* pFaceDown = new SDLSprite;

  pFaceUp->loadSprite(app, "Sprites\\" + card + ".png", 130, 200);
  pFaceDown->loadSprite(app, "grey_back.png", 130, 200);

  CardViewSDL cNewCard(pFaceUp, pFaceDown, isFaceUp);

  mcCards.push_back(cNewCard);
}

//***************************************************************************
// Function:    discardHand
//
// Description: Removes all cards from the player's hand
//
// Parameters:  None
//
// Returned:    None
//***************************************************************************
void PlayerView::discardHand ()
{
  mcCards.clear();
  mcSplitHand.clear();
}

//***************************************************************************
// Function:    showCards
//
// Description: turns all the cards in the user's hands face up
//
// Parameters:  None
//
// Returned:    None
//***************************************************************************
void PlayerView::showCards ()
{
  for (auto it = mcCards.begin (); it != mcCards.end (); it++) {
    if (!it->isFaceUp())
      it->flip();
  }
  for (auto it = mcSplitHand.begin (); it != mcSplitHand.end (); it++) {
    if (!it->isFaceUp())
      it->flip();
  }
}

//***************************************************************************
// Function:    splitHand
//
// Description: Splits the user's hand
//
// Parameters:  None
//
// Returned:    None
//***************************************************************************
void PlayerView::splitHand ()
{
  mcSplitHand.push_back(mcCards[1]);
  mcCards.pop_back();
}
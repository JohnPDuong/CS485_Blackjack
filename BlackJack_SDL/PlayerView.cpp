//***************************************************************************
// File name:  PlayerView.cpp
// Author:     Erin Melia
// Date:       5/4/2021
// Class:      CS485
// Assignment: Blackjack
// Purpose:    Defines the functions used to display a player to the screen
//***************************************************************************
#include "PlayerView.h"

//***************************************************************************
// Function:    draw
//
// Description: Display the information contained in PlayerView to the screen
//
// Parameters:  None
//
// Returned:    None
//***************************************************************************
void PlayerView::draw (SDLApp& app)
{
  for(auto it = mcCards.begin(); it != mcCards.end(); it++)
    it->draw(app);
  mcMoneyDisplay.draw(app);
  mcNameDisplay.draw(app);
}

//***************************************************************************
// Function:    addCard
//
// Description: Adds the specified card to the player's hand
//
// Parameters:  app      - the SDL app used to load the sprite
//              card     - a string representing the card to be added
//              isFaceUp - whether the card should be displayed face up
//
// Returned:    None
//***************************************************************************
void PlayerView::addCard (SDLApp* app, std::string card, bool isFaceUp)
{
  SDLSprite* pFaceUp = new SDLSprite(app, card, x, y);
  //need a way of determining what this x and y should be
  SDLSprite* pFaceDown = new SDLSprite(app, "green_back", x, y);
  CardViewSDL cCard(pFaceUp, pFaceDown, isFaceUp);
  mcCards.push_back(cCard);
}

//***************************************************************************
// Function:    discardHand
//
// Description: removes all the cards from the player's hand
//
// Parameters:  None
//
// Returned:    None
//***************************************************************************
void PlayerView::discardHand ()
{
  mcCards.clear();
}

//***************************************************************************
// Function:    showCards
//
// Description: flips all the cards in a player's hand face up
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
}

//***************************************************************************
// File name:  PlayerView.cpp
// Author:     Erin Melia
// Date:       5/4/2021
// Class:      CS485
// Assignment: Blackjack
// Purpose:    Defines the functions used to display a player to the screen
//***************************************************************************
#include "PlayerView.h"

void PlayerView::addCard (SDLApp* app, std::string card, bool isFaceUp)
{
  SDLSprite* pFaceUp = new SDLSprite(app, card, x, y);
  SDLSprite* pFaceDown = new SDLSprite(app, "green_back", x, y);
  CardViewSDL cCard(pFaceUp, pFaceDown, isFaceUp);
}

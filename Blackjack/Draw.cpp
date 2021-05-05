//***************************************************************************
// File name:  Draw.cpp
// Author:     Kitt Oster
// Date:       5/2/2021
// Class:      CS485
// Assignment: Blackjack
// Purpose:    implement draw command
//***************************************************************************

#include "Draw.h"

bool Draw::execute(Deck& cTableDeck, Player& cPlayer){
  cPlayer.receiveCard(cTableDeck.draw());
  return true;
}

bool Draw::execute(Deck& cTableDeck, Hand& cPlayerHand){
  cPlayerHand.addCard(cTableDeck.draw());
  return true;
}

std::string Draw::moveName(){
  return "Draw";
}

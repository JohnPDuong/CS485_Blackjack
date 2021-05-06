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
  Card cTemp = cTableDeck.draw();
  cTemp.flip();
  cPlayer.receiveCard(cTemp);
  return true;
}

bool Draw::execute(Deck& cTableDeck, Hand& cPlayerHand){
  Card cTemp = cTableDeck.draw();
  cTemp.flip();
  cPlayerHand.addCard(cTemp);
  return true;
}

std::string Draw::moveName(){
  return "Draw";
}

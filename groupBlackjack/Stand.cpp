//***************************************************************************
// File name:  Stand.cpp
// Author:     Kitt Oster
// Date:       5/2/2021
// Class:      CS485
// Assignment: Blackjack
// Purpose:    implement stand command
//***************************************************************************

#include "Stand.h"

bool Stand::execute(Deck& cTableDeck, Player& cPlayer){
  return true;
}

bool Stand::execute(Deck& cTableDeck, Hand& cPlayerHand){
  return true;
}

std::string Stand::moveName(){
  return "Stand";
}

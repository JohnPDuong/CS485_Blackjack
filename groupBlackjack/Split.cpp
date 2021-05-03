//***************************************************************************
// File name:  Split.cpp
// Author:     Kitt Oster
// Date:       5/2/2021
// Class:      CS485
// Assignment: Blackjack
// Purpose:    implement split command
//***************************************************************************

#include "Split.h"

bool Split::execute(Deck& cTableDeck, Player* cPlayer){
  return cPlayer->trySplit();
}

//***************************************************************************
// File name:  IMove.h
// Author:     Kitt Oster
// Date:       5/2/2021
// Class:      CS485
// Assignment: Blackjack
// Purpose:    Define Move command pattern
//***************************************************************************

#pragma once
#include "Deck.h"
#include "Player.h"

class IMove{
public:
  //Had to change player to pointer because reference caused dependency loop
  virtual bool execute(Deck& cTableDeck, Player* cPlayer) = 0;
  virtual std::string moveName() = 0;
};

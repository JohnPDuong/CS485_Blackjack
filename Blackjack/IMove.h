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

//Class forward declarations to avoid circular dependancy issues.
class IMoveStrategy;
class Player;

class IMove{
public:
  virtual bool execute(Deck& cTableDeck, Player& cPlayer) = 0;
  virtual bool execute(Deck& cTableDeck, Hand& cPlayerHand) = 0;
  virtual std::string moveName() = 0;
};

//***************************************************************************
// File name:  Player.h
// Author:     Kitt Oster
// Date:       5/2/2021
// Class:      CS485
// Assignment: Blackjack
// Purpose:    Define the player
//***************************************************************************

#pragma once

#include "IMoveStrategy.h"
#include "Hand.h"
#include "Money.h"
#include <memory>
#include <string>

class Player{
public:
  Player() = delete;
  Player(std::shared_ptr<IMoveStrategy> pcMoveStrat);
  Player(std::string name, std::shared_ptr<IMoveStrategy> pcMoveStrat);
  Player(std::string name, Money cBank,
         std::shared_ptr<IMoveStrategy> pcMoveStrat);
  
  void endTurn();
  void receiveCard(Card);
}

//***************************************************************************
// File name:  DrunkAI.h
// Author:     Kitt Oster
// Date:       5/2/2021
// Class:      CS485
// Assignment: Blackjack
// Purpose:    Define the drunk Move Strat
//***************************************************************************

#pragma once

#include "IComputerMoveStrategy.h"
#include "MoveStrategyFactory.h"
#include <cstdlib>

class DrunkAI : public IComputerMoveStrategy {
public:
  DrunkAI(std::string soberTypeName = "Card Counter");
  
  virtual bool determineMove(Hand& cCurrentHand,
                             std::shared_ptr<IMove> pcCurrentMove,
                             std::vector<Card>& cTableCards) override;
  virtual bool determineBet(Player& player, Money& bet) override;
  virtual bool isHuman() override;
private:
  bool drunkRisk();
  
  std::shared_ptr<IMoveStrategy> mpcSoberStrat;
  int numShots;
};

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

class DrunkAI : public IComputerMoveStrategy {
public:
  virtual bool determineMove(Hand& cCurrentHand,
                             std::shared_ptr<IMove> pcCurrentMove,
                             std::vector<Card>& cTableCards) override;
  virtual bool determineBet(Player& player, Money& bet) override;
  virtual bool isHuman() override;
};

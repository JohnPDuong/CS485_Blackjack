//***************************************************************************
// File name:  DealerAI.h
// Author:     Kitt Oster
// Date:       5/2/2021
// Class:      CS485
// Assignment: Blackjack
// Purpose:    Define the Dealer Move Strat
//***************************************************************************

#pragma once

#include "IComputerMoveStrategy.h"
#include "Stand.h"
#include "Draw.h"

class DealerAI : public IComputerMoveStrategy {
public:
  virtual bool determineMove(Hand& cCurrentHand,
                             std::shared_ptr<IMove>& pcCurrentMove,
                             std::vector<Card>& cTableCards) override;
  virtual bool determineBet(Player& player, Money& bet) override;
  virtual bool isHuman() override;
};

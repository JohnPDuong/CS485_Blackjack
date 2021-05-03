//***************************************************************************
// File name:  DealerAI.cpp
// Author:     Kitt Oster
// Date:       5/2/2021
// Class:      CS485
// Assignment: Blackjack
// Purpose:    Impements the Dealer Move Strat
//***************************************************************************

#include "DealerAI.h"

bool DealerAI::determineMove(Hand& cCurrentHand,
                             std::shared_ptr<IMove> pcCurrentMove,
                             std::vector<Card>& cTableCards){
  if(cCurrentHand.handValue < 16){
    pcCurrentMove = make_shared<Stand>;
  }
  else{
    
  }
}

bool DealerAI::determineBet(Player& player, Money& bet){
  bet.setAmount(player.getBank.getAmount/5);
  return true;
}

bool DealerAI::isHuman() {
  return IComputerMoveStrategy::isHuman();
}

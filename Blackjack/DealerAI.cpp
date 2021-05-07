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
                           std::shared_ptr<IMove>& pcCurrentMove,
                           std::vector<Card>& cTableCards){
  if(cCurrentHand.getHandValue() < 16){
    pcCurrentMove = std::make_shared<Draw>();
  }
  else{
    pcCurrentMove = std::make_shared<Stand>();
  }
  return true;
}

bool DealerAI::determineBet(Player& player, Money& bet){
  bet = player.getBank() * 0.2;
  return true;
}

bool DealerAI::isHuman() {
  return false;//IComputerMoveStrategy::isHuman();
}

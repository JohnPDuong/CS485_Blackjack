//***************************************************************************
// File name:  CardCounterAI.cpp
// Author:     Kitt Oster
// Date:       5/2/2021
// Class:      CS485
// Assignment: Blackjack
// Purpose:    Impements the CardCounter Move Strat
//***************************************************************************

#include "CardCounterAI.h"
#include "Draw.h"

bool CardCounterAI::determineMove(Hand& cCurrentHand,
                                  std::shared_ptr<IMove> pcCurrentMove,
                                  std::vector<Card>& cTableCards){
  if(cCurrentHand.getHandValue() < 16){
    pcCurrentMove = std::make_shared<Draw>;
  }
  else{
    pcCurrentMove = std::make_shared<Stand>;
  }
}

bool CardCounterAI::determineBet(Player& player, Money& bet){
  bet.setAmount(player.getBank.getAmount/5);
  return true;
}

bool CardCounterAI::isHuman() {
  return IComputerMoveStrategy::isHuman();
}

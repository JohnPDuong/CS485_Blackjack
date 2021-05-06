//***************************************************************************
// File name:  IHumanMoveStrategy.cpp
// Author:     Kitt Oster
// Date:       5/2/2021
// Class:      CS485
// Assignment: Blackjack
// Purpose:    Implement the Move Strategy for human players
//***************************************************************************

#include "HumanMoveStrategy.h"
//***************************************************************************
// Function:
//
// Description: 
//
// Parameters:  
//
// Return:			
//***************************************************************************
bool HumanMoveStrategy::determineMove(Hand& cCurrentHand,
                                      std::shared_ptr<IMove>& pcCurrentMove,
                                      std::vector<Card>& cTableCards){
  return pcCurrentMove != nullptr && (pcCurrentMove->moveName() != "Split"
                                      || true);
  //Need some check in hand for if can split to replace that true
}
//***************************************************************************
// Function:
//
// Description: 
//
// Parameters:  
//
// Return:			
//***************************************************************************
bool HumanMoveStrategy::determineBet(Player& player, Money& bet){
  return bet.getAmount() > 0 && bet.getAmount() <= player.getBank().getAmount();
}
//***************************************************************************
// Function:
//
// Description: 
//
// Parameters:  
//
// Return:			
//***************************************************************************
bool HumanMoveStrategy::isHuman(){
  return true;
}

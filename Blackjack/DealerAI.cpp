//***************************************************************************
// File name:  DealerAI.cpp
// Author:     Kitt Oster
// Date:       5/2/2021
// Class:      CS485
// Assignment: Blackjack
// Purpose:    Impements the Dealer Move Strat
//***************************************************************************

#include "DealerAI.h"
//***************************************************************************
// Function:
//
// Description: 
//
// Parameters:  
//
// Return:			
//***************************************************************************
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
//***************************************************************************
// Function:
//
// Description: 
//
// Parameters:  
//
// Return:			
//***************************************************************************
bool DealerAI::determineBet(Player& player, Money& bet){
  bet = player.getBank() * 0.2;
  return true;
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
bool DealerAI::isHuman() {
  return true;//IComputerMoveStrategy::isHuman();
}

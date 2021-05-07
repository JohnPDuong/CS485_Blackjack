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
// Function:    determineMove
//
// Description: determines what move the AI should make
//
// Parameters:  cCurrentHand  - the AI's current hand
//              pcCurrentMove - the move object that is being generated
//              cTableCards   - the cards on the table
//
// Return:			true if the AI was able to successfully determine a move,
//              otherwise false
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
// Function:    determineBet
//
// Description: determines how much money the AI should bet
//
// Parameters:  player - the player whose move strategy this is
//              bet    - the bet that will be set
//
// Return:			true
//***************************************************************************
bool DealerAI::determineBet(Player& player, Money& bet){
  bet = player.getBank() * 0.2;
  return true;
}

//***************************************************************************
// Function:    isHuman
//
// Description: determines whether the player is human
//
// Parameters:  None
//
// Return:			false
//***************************************************************************
bool DealerAI::isHuman() {
  return false;//IComputerMoveStrategy::isHuman();
}

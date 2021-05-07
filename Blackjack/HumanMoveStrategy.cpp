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
// Function:    determineMove
//
// Description: decides on the move to do
//
// Parameters:  cCurrentHand  - the currentHand
//              pcCurrentMove - the currentMove
//              cTableCards   - the cards everyone can see
//
// Return:			True if a turn was selected successfully
//***************************************************************************
bool HumanMoveStrategy::determineMove(Hand& cCurrentHand,
                                      std::shared_ptr<IMove>& pcCurrentMove,
                                      std::vector<Card>& cTableCards){
  return pcCurrentMove != nullptr && (pcCurrentMove->moveName() != "Split"
                                      || cCurrentHand.canSplit());
  //Need some check in hand for if can split to replace that true
}

//***************************************************************************
// Function:    determineBet
//
// Description: determines the bet at the beginning of a round
//
// Parameters:  player - the player
//              bet    - the amount of the bet
//
// Return:			None
//***************************************************************************
bool HumanMoveStrategy::determineBet(Player& player, Money& bet){
  return bet.getAmount() > 0 && bet.getAmount() <= player.getBank().getAmount();
}

//***************************************************************************
// Function:    isHuman
//
// Description: determines if the player is a human (true)
//
// Parameters:  None
//
// Return:			True if human (always true)
//***************************************************************************
bool HumanMoveStrategy::isHuman(){
  return true;
}

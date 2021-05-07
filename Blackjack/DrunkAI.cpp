//***************************************************************************
// File name:  DrunkAI.cpp
// Author:     Kitt Oster
// Date:       5/2/2021
// Class:      CS485
// Assignment: Blackjack
// Purpose:    Implement the drunk Move Strat
//***************************************************************************

#include "DrunkAI.h"

//***************************************************************************
// Constructor: DrunkAI
//
// Description: Initializes member variables
//
// Parameters:  soberTypeName - the name type of soberness
//
// Return:			None
//***************************************************************************
DrunkAI::DrunkAI(std::string soberTypeName){
  MoveStrategyFactory cStratFact;
  mpcSoberStrat = cStratFact.makeStrategy(soberTypeName);
  if(mpcSoberStrat == nullptr){
    mpcSoberStrat = cStratFact.makeStrategy("Card Counter");
  }
}

//***************************************************************************
// Function:    determineMove
//
// Description: cCurrentHand  - the hand
//              pcCurrentMove - the Current move
//              cTableCards   - the visible cards to everyone
//
// Parameters:  None
//
// Return:			if it decides on a move
//***************************************************************************
bool DrunkAI::determineMove(Hand &cCurrentHand,
                            std::shared_ptr<IMove>& pcCurrentMove,
                            std::vector<Card> &cTableCards)
{
  if(drunkRisk()){
    pcCurrentMove = std::make_shared<Draw>();
    return true;
  }
  else{
    return mpcSoberStrat->determineMove(cCurrentHand, pcCurrentMove, cTableCards);
  }
}

//***************************************************************************
// Function:    determineBet
//
// Description: player - the player
//              bet    - the amount to bet
//
// Parameters:  None
//
// Return:			true if a bet was decided on
//***************************************************************************
bool DrunkAI::determineBet(Player &player, Money &bet)
{
  numShots++;
  if(drunkRisk()){
    bet.setAmount(player.getBank().getAmount() * 0.75);
    return true;
  }
  else{
    return mpcSoberStrat->determineBet(player, bet);
  }
}

//***************************************************************************
// Function:    isHuman
//
// Description: returns if this is a human (false)
//
// Parameters:  None
//
// Return:			False - this an AI
//***************************************************************************
bool DrunkAI::isHuman()
{
    return false;
}

//***************************************************************************
// Function:    drunkRisk
//
// Description: determines if the AI is risky
//
// Parameters:  None
//
// Return:			True if risky
//***************************************************************************
bool DrunkAI::drunkRisk(){
  return rand() % 100 < numShots;
}

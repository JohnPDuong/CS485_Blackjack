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
// Function:
//
// Description: 
//
// Parameters:  
//
// Return:			
//***************************************************************************
DrunkAI::DrunkAI(std::string soberTypeName){
  MoveStrategyFactory cStratFact;
  mpcSoberStrat = cStratFact.makeStrategy(soberTypeName);
  if(mpcSoberStrat == nullptr){
    mpcSoberStrat = cStratFact.makeStrategy("Card Counter");
  }
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
// Function:
//
// Description: 
//
// Parameters:  
//
// Return:			
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
// Function:
//
// Description: 
//
// Parameters:  
//
// Return:			
//***************************************************************************
bool DrunkAI::isHuman()
{
    return false;
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
bool DrunkAI::drunkRisk(){
  return rand() % 100 < numShots;
}

//***************************************************************************
// File name:  DrunkAI.cpp
// Author:     Kitt Oster
// Date:       5/2/2021
// Class:      CS485
// Assignment: Blackjack
// Purpose:    Implement the drunk Move Strat
//***************************************************************************

#include "DrunkAI.h"

DrunkAI::DrunkAI(std::string soberTypeName){
  MoveStrategyFactory cStratFact;
  mpcSoberStrat = cStratFact.makeStrategy(soberTypeName);
  if(mpcSoberStrat == nullptr){
    mpcSoberStrat = cStratFact.makeStrategy("Card Counter");
  }
}

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

bool DrunkAI::isHuman()
{
    return false;
}

bool DrunkAI::drunkRisk(){
  return rand() % 100 < numShots;
}

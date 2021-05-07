//***************************************************************************
// File name:  
// Author:     
// Date:       5/7/2021
// Class:      CS485
// Assignment: Blackjack
// Purpose:    
//***************************************************************************

#include "MoveStrategyFactory.h"


//***************************************************************************
// Function:    makeStrategy
//
// Description: determines the strategy for a player to use
//
// Parameters:  stratName - the name of the strategy
//
// Return:			A shared pointer for the strategy to use
//***************************************************************************
std::shared_ptr<IMoveStrategy> MoveStrategyFactory::makeStrategy(std::string stratName){
  if(stratName == "Human"){
    return std::make_shared<HumanMoveStrategy>();
  }
  if(stratName == "Dealer"){
    return std::make_shared<DealerAI>();
  }
  if(stratName == "Card Counter"){
    return std::make_shared<CardCounterAI>();
  }
  if(stratName == "Drunk"){
    return std::make_shared<DrunkAI>();
  }
  return nullptr;
}

//***************************************************************************
// Function:    listStrats
//
// Description: determines the bet at the beginning of a round
//
// Parameters:  None
//
// Return:			A vector of strategy names as strings
//***************************************************************************
std::vector<std::string> MoveStrategyFactory::listStrats(){
  std::vector<std::string> stratList;
  stratList.push_back("Human");
  stratList.push_back("Dealer");
  stratList.push_back("Card Counter");
  stratList.push_back("Drunk");
  
  return stratList;
}


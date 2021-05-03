//***************************************************************************
// File name:  
// Author:     
// Date:       5/7/2021
// Class:      CS485
// Assignment: Blackjack
// Purpose:    
//***************************************************************************

#include "MoveStrategyFactory.h"

std::shared_ptr<IMoveStrategy> MoveStrategyFactory::makeStrategy(std::string stratName);
virtual static std::vector<std::string> listStrats()

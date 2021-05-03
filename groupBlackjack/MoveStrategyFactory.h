//***************************************************************************
// File name:  MoveStrategyFactory.h
// Author:     Kitt Oster
// Date:       5/2/2021
// Class:      CS485
// Assignment: Blackjack
// Purpose:    Define the move strat factory
//***************************************************************************

#pragma once

#include "HumanMoveStrategy.h"
#include "DealerAI.h"
#include "CardCounterAI.h"
#include "DrunkAI.h"
#include <string>

class MoveStrategyFactory
{
  public:
    virtual std::shared_ptr<IMoveStrategy> makeStrategy(std::string stratName);
    static std::vector<std::string> listStrats();
};

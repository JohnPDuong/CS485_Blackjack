//***************************************************************************
// File name:  Stand.h
// Author:     Kitt Oster
// Date:       5/2/2021
// Class:      CS485
// Assignment: Blackjack
// Purpose:    Define stand command
//***************************************************************************

#pragma once
#include "IMove.h"

class Stand: public IMove{
public:
  virtual bool execute(Deck& cTableDeck, Player& cPlayer) override;
};

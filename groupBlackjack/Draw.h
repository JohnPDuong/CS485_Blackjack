//***************************************************************************
// File name:  Draw.h
// Author:     Kitt Oster
// Date:       5/2/2021
// Class:      CS485
// Assignment: Blackjack
// Purpose:    Define draw command
//***************************************************************************

#pragma once
#include "IMove.h"

class Draw: public IMove{
public:
  virtual bool execute(Deck& cTableDeck, Player& cPlayer) override;
};

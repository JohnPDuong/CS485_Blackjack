//***************************************************************************
// File name:  Split.h
// Author:     Kitt Oster
// Date:       5/2/2021
// Class:      CS485
// Assignment: Blackjack
// Purpose:    Define split command
//***************************************************************************

#pragma once
#include "IMove.h"

class Split: public IMove{
public:
  virtual bool execute(Deck& cTableDeck, Player& cPlayer) override;
};

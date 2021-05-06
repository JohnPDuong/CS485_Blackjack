//***************************************************************************
// File name:  IBlackjackView.h
// Author:     Erin Melia
// Date:       4/30/2021
// Class:      CS485
// Assignment: Blackjack
// Purpose:    Define the interface from which all views inherit
//***************************************************************************
#pragma once

class IBlackjackView {
  public:
    virtual ~IBlackjackView() {};
    virtual void newGame(int) = 0;
    virtual void nextRound() = 0;
    virtual void stand() = 0;
    virtual void drawCard() = 0;
    virtual void split() = 0;
    virtual void bet(long long amount) = 0;

    virtual void onStand() = 0;
    virtual void onDrawCard() = 0;
    virtual void onSplit() = 0;
    virtual void onBet(long long amount) = 0;

    virtual void render() = 0;
};

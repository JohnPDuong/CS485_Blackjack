//***************************************************************************
// File name:  PlayerView.h
// Author:     Erin Melia
// Date:       4/30/2021
// Class:      CS485
// Assignment: Blackjack
// Purpose:    Defines the basic view used to display the players of the game
//***************************************************************************
#pragma once

#include <string>
#include <vector>

#include "SDLTextWidget.h"
#include "CardViewSDL.h"

class PlayerView {
  public:
    PlayerView();
    ~PlayerView();

    void draw(SDLApp& app);

    void addCard(std::string card, bool isFaceUp);
    void discardHand();
    void showCards();

    void setName();
    void setMoney();

  private:
    std::string mName;
    long long mMoney;

    SDLTextWidget* mpcNameDisplay;
    SDLTextWidget* mpcMoneyDisplay;
    std::vector<CardViewSDL> mcCards;
};

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

#include "SDLApp.h"
#include "SDLTextWidget.h"
#include "SDLSprite.h"
#include "CardViewSDL.h"

class PlayerView : public ISDLWidget {
  public:
    PlayerView(int x, int y, SDLApp& app);
    ~PlayerView();
    //we're going to need a way of determining where the PlayerView should be 
    //placed on the screen since TextWidget doesn't have a default constructor

    void draw(SDLApp& app);

    void addCard(SDLApp* app, std::string card, bool isFaceUp, 
      bool inMainHand);
    void discardHand();
    void showCards();
    void splitHand();

    void setName(std::string name) { mcNameDisplay.setData(name); };
    void setMoney(std::string amount) { mcMoneyDisplay.setData(amount); };
    void setBetDisplay(std::string amount) { mcBetDisplay.setData(amount); };
    void setBetVisible(bool visible) { mcBetDisplay.setVisible(visible); mcBetDisplay.setEditable(visible); };

    std::string getBet() { return mcBetDisplay.getData(); };

    void makeDealer() { setName("Dealer"); mcMoneyDisplay.setVisible(false); };

  private:
    SDLTextWidget mcNameDisplay;
    SDLTextWidget mcMoneyDisplay;
    SDLTextWidget mcBetDisplay;
    std::vector<CardViewSDL> mcCards;
    std::vector<CardViewSDL> mcSplitHand;
    int mX, mY; // need to store these so we can spawn cards in the right place
};

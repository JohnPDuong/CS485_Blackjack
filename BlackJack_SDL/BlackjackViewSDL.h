//***************************************************************************
// File name:  BlackjackViewSDL.h
// Author:     Erin Melia
// Date:       4/30/2021
// Class:      CS485
// Assignment: Blackjack
// Purpose:    Declares the primary view used in the SDL app
//***************************************************************************
#pragma once

#include <functional>
#include <vector>
#include <sstream>

#include "SDLApp.h"
#include "ISDLWidget.h"
#include "PlayerView.h"
#include "SDLTextWidget.h"
#include "../Blackjack/BlackjackPresenter.h"
#include "../Blackjack/IBlackjackPresenter.h"

//Should we add a next round button so the player can move on to the next round
class BlackjackViewSDL : public SDLApp {
  public:
    BlackjackViewSDL();
    ~BlackjackViewSDL();

    //events from Presenter
    void newGame (int numPlayers);
    void nextRound ();
    void stand ();
    void drawCard (std::string card, bool isFaceUp, bool inMainHand);
    void split ();
    void bet (long long amount);
    void endGame(); //should be called in endGame in the presenter

    //events from UI
    void onStand ();
    void onDrawCard ();
    void onSplit ();
    void onBet (long long amount);
    void onEndGame();
    void onNextRound();
    void onSetNumPlayers(int number);

    //widget function
    void onBetWidget(SDLTextWidget* widget);
    void onNumPlayersWidget(SDLTextWidget* widget);

    void initGame();
    void render ();

  private:
    IBlackjackPresenter* mpcPresenter;
    //not sure how we're going to make sure the player views are in the same
    //order as the players are in the model
    std::vector<PlayerView> mcPlayers;
    std::vector<PlayerView>::iterator mcCurrentPlayer;
    SDLTextWidget mcStandButton;
    SDLTextWidget mcBetButton;
    SDLTextWidget mcSplitButton;
    SDLTextWidget mcDrawButton;
    SDLTextWidget mcNumPlayersInput;
    SDLTextWidget mcEndGameButton;
    SDLTextWidget mcNextRound;

    std::vector<ISDLWidget*> mcDrawableWidget;
};
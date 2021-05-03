//***************************************************************************
// File name:  BlackjackView.h
// Author:     Erin Melia
// Date:       4/30/2021
// Class:      CS485
// Assignment: Blackjack
// Purpose:    Declares the primary view used in the SDL app
//***************************************************************************
#pragma once

#include <functional>
#include <vector>

#include "SDLApp.h"
#include "ButtonViewSDL.h"
#include "IBlackjackView.h"
#include "IBlackjackPresenter.h"
#include "ISDLWidget.h"
#include "PlayerView.h"
#include "SDLTextWidget.h"

class BlackjackViewSDL : public SDLApp, IBlackjackView {
  public:
    BlackjackViewSDL();
    ~BlackjackViewSDL();

    //events from presenter
    void newGame (int);
    void nextRound ();
    void stand ();
    void drawCard ();
    void split ();
    void bet (long long amount);
    void setNumPlayers();

    //events from UI
    void onStand ();
    void onDrawCard ();
    void onSplit ();
    void onBet (long long amount);
    void onSetNumPlayers();

    //events from UI Widgets
    void onSetNumPlayersWidget(SDLTextWidget* widget);
    void onBetWidget(SDLTextWidget* widget);

    void render ();

  private:
    IBlackjackPresenter* mpcPresenter;
    std::vector<PlayerView> mcPlayers;
    SDLTextWidget mcStandButton;
    SDLTextWidget mcBetButton;
    SDLTextWidget mcSplitButton;
    SDLTextWidget mcDrawButton;
    SDLTextWidget mcBetAmount;
    SDLTextWidget mcNumPlayersInput;
    //SDLTextWidget mcHumanPlayerInput;

    std::vector<ISDLWidget*> mcDrawableWidget;
};
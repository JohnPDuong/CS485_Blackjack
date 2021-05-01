//***************************************************************************
// File name:  BlackjackView.h
// Author:     Erin Melia
// Date:       4/30/2021
// Class:      CS485
// Assignment: Blackjack
// Purpose:    Define the primary view used in the SDL app
//***************************************************************************
#pragma once

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
    void newGame (int);
    void nextRound ();
    void stand ();
    void drawCard ();
    void split ();
    void bet (long long amount);

    void onStand ();
    void onDrawCard ();
    void onSplit ();
    void onBet (long long amount);

    void render ();

  private:
    IBlackjackPresenter mcPresenter;
    std::vector<PlayerView> mcPlayers;
    ButtonViewSDL mcStandButton;
    ButtonViewSDL mcBetButton;
    ButtonViewSDL mcSplitButton;
    ButtonViewSDL mcDrawButton;
    SDLTextWidget mcBetAmount;
    SDLTextWidget mcNumPlayersInput;

    std::vector<ISDLWidget*> mcDrawableWidget;
};
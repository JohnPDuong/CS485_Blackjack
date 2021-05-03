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

#include "..\SDLApp2\SDLApp.h"
#include "IBlackjackView.h"
#include "IBlackjackPresenter.h"
#include "..\SDLApp2\ISDLWidget.h"
#include "PlayerView.h"
#include "..\SDLApp2\SDLTextWidget.h"

class BlackjackViewSDL : public SDLApp, IBlackjackView {
  public:
    BlackjackViewSDL();
    ~BlackjackViewSDL();

    //events from presenter
    /*void newGame ();
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
    void onNewGame();

    //events from UI Widgets
    void onBetWidget(SDLTextWidget* widget);
    void onHumanPlayerWidget(SDLTextWidget* widget);*/

    void render ();

  private:
    IBlackjackPresenter* mpcPresenter;
    std::vector<PlayerView> mcPlayers;
    PlayerView* mpcCurrentPlayer;
    SDLTextWidget mcStandButton;
    SDLTextWidget mcSplitButton;
    SDLTextWidget mcDrawButton;
    SDLTextWidget mcBetAmount;
    SDLTextWidget mcNumPlayersInput;
    SDLTextWidget mcNewGame;
    SDLTextWidget mcStartNewGame;

    std::vector<ISDLWidget*> mcDrawableWidget;
};
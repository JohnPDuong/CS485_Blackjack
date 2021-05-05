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
#include <sstream>

#include "SDLApp.h"
#include "IBlackjackView.h"
#include "BlackjackPresenter.h"
#include "ISDLWidget.h"
#include "PlayerView.h"
#include "SDLTextWidget.h"

class BlackjackViewSDL : public SDLApp{
  public:
    BlackjackViewSDL();
    ~BlackjackViewSDL();

    //events from presenter
    void newGame (int); //I don't think this should take an int since we're
    //setting it in the first screen the player sees?
    void nextRound ();
    void stand ();
    void drawCard (std::string card);
    void split ();
    //how are we going to do player views for a player that split?
    void bet (long long amount);
    //would probably be easier to implement if it took the player's new bank
    //value
    void setNumPlayers();
    //void setPlayerType();
    void createPlayer(std::string name);
    //what are we going to do when the player busts?

    //events from UI
    void onStand ();
    void onDrawCard ();
    void onSplit ();
    void onBet (long long amount);
    void onSetNumPlayers(int number);
    //void onSetPlayerType(std::string type);
    void onNewGame();
    void onCreatePlayer(std::string name, std::string type);

    //events from UI Widgets
    void onSetNumPlayersWidget(SDLTextWidget* widget);
    void onBetWidget(SDLTextWidget* widget);
    void onCreatePlayerWidget(SDLTextWidget* name, SDLTextWidget* type);

    void render ();

  private:
    void advancePlayer();

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
    SDLTextWidget mcPlayerTypeInput;
    SDLTextWidget mcNewGame;
    SDLTextWidget mcNameInput;
    SDLTextWidget mcCreatePlayer;

    std::vector<ISDLWidget*> mcDrawableWidget;
};
//***************************************************************************
// File name:  BlackjackView.cpp
// Author:     Erin Melia
// Date:       5/1/2021
// Class:      CS485
// Assignment: Blackjack
// Purpose:    Define the primary view used in the SDL app
//***************************************************************************
#include "BlackjackViewSDL.h"

BlackjackViewSDL::BlackjackViewSDL () :
mcStandButton("Stand", "", 10, 10, 1, { 255,255,255,255 }),
mcBetButton("Bet", "", 10, 20, 1, { 255,255,255,255 }),
mcSplitButton("Split", "", 10, 30, 1, { 255,255,255,255 }),
mcDrawButton("Draw", "", 10, 40, 1, { 255,255,255,255 }),
mcBetAmount("Bet", "", 10, 50, 1, { 255,255,255,255 }),
mcNumPlayersInput("Number of Players", "", 10, 60, 1, { 255,255,255,255 })
//mcHumanPlayerInput("Number of Human Players", 10, 70, 1, {255, 255, 255, 255})
{
  mpcPresenter = new IBlackjackPresenter();
  loadFont ("c:/Windows/Fonts/Cour.ttf", 20);

  mcNumPlayersInput.registerStateChangeEventHandler 
    (std::bind
    (&BlackjackViewSDL::onSetNumPlayersWidget, this, &mcNumPlayersInput));
  mcBetAmount.registerStateChangeEventHandler
    (std::bind
    (&BlackjackViewSDL::onBetWidget,this, &mcBetAmount));

  enableTextInput();

  mcDrawableWidget.push_back(&mcBetAmount);
  mcDrawableWidget.push_back(&mcBetButton);
  mcDrawableWidget.push_back(&mcDrawButton);
  mcDrawableWidget.push_back(&mcNumPlayersInput);
  mcDrawableWidget.push_back(&mcSplitButton);
  mcDrawableWidget.push_back(&mcStandButton);
 }

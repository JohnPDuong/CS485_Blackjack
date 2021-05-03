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
mcSplitButton("Split", "", 10, 30, 1, { 255,255,255,255 }),
mcDrawButton("Draw", "", 10, 40, 1, { 255,255,255,255 }),
mcBetAmount("Bet", "", 10, 50, 1, { 255,255,255,255 }),
mcNumPlayersInput("Number of Players", "", 10, 60, 1, { 255,255,255,255 }),
mcNewGame("New Game", "", 10, 80, 1, { 255,255,255,255 }),
mcStartNewGame("Start New Game", "", 10, 90, 1, { 255, 255, 255, 255 })
{
  mpcPresenter = new IBlackjackPresenter();
  loadFont ("c:/Windows/Fonts/Cour.ttf", 20);

  /*mcNumPlayersInput.registerStateChangeEventHandler 
    (std::bind
    (&BlackjackViewSDL::onSetNumPlayersWidget, this, &mcNumPlayersInput));
  mcBetAmount.registerStateChangeEventHandler
    (std::bind
    (&BlackjackViewSDL::onBetWidget,this, &mcBetAmount));*/

  mpcCurrentPlayer = nullptr;

  enableTextInput();

  mcDrawButton.setEditable(false);
  mcSplitButton.setEditable(false);
  mcStandButton.setEditable(false);
  mcNewGame.setEditable(false);
  mcStartNewGame.setEditable(false);

  mcDrawButton.setVisible(false);
  mcSplitButton.setVisible(false);
  mcStandButton.setVisible(false);
  mcBetAmount.setVisible(false);
  mcNewGame.setVisible(false);

  mcDrawableWidget.push_back(&mcBetAmount);
  mcDrawableWidget.push_back(&mcDrawButton);
  mcDrawableWidget.push_back(&mcNumPlayersInput);
  mcDrawableWidget.push_back(&mcSplitButton);
  mcDrawableWidget.push_back(&mcStandButton);
  mcDrawableWidget.push_back(&mcStartNewGame);
 }

BlackjackViewSDL::~BlackjackViewSDL ()
{
  delete mpcPresenter;
}

void BlackjackViewSDL::render ()
{
  for (auto value : mcDrawableWidget) {
    if(value->isVisible())
      value->draw(*this);
  }
}

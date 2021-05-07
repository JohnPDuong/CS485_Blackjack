//***************************************************************************
// File name:  BlackjackTextUI.h
// Author:     John, Julian, Kitt, Erin
// Date:       5/7/2021
// Class:      CS485
// Assignment: Blackjack
// Purpose:    Defines the class declared in BlackjackModel.h
//***************************************************************************

#pragma once

#include "../Blackjack/BlackjackPresenter.h"

class BlackjackTextUI : public IBlackjackView {
public:
  BlackjackTextUI();
  BlackjackTextUI(int numPlayers);

  virtual void newGame(int numPlayers);
  virtual void nextRound();
  virtual void stand();
  virtual void drawCard();
  virtual void split();
  virtual void bet(long long amount);

  virtual void onStand();
  virtual void onDrawCard();
  virtual void onSplit();
  virtual void onBet(long long amount);

  virtual void render();

  // TextUI specific functions for Julian
  void printWelcome();
  void printHeader();
  void printGameState();
  void printPlayerCards();

  void onGameStartup();
  void playGame(); 

private:
  virtual void printEndRoundScreen();
  std::vector<std::string> mcHand;
  IBlackjackPresenter* mpcPresenter;
};

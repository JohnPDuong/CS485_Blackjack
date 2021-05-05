#pragma once

#include "../Blackjack/BlackjackView.h"
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

  // TextUI specific functions
  void printWelcome();
  void printHeader();
  void onGameStartup();
  void playGame(); 


private:
  IBlackjackPresenter* mpcPresenter;
};
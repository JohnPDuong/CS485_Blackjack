#pragma once

#include "IBlackjackView.h"

class BlackjackTextUI : public IBlackjackView {
public:
  virtual void newGame(int);
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
};
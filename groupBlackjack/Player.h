//***************************************************************************
// File name:  Player.h
// Author:     Kitt Oster
// Date:       5/2/2021
// Class:      CS485
// Assignment: Blackjack
// Purpose:    Define the player
//***************************************************************************

#pragma once

#include "IMoveStrategy.h"
#include "Hand.h"
#include "Money.h"
#include "IMove.h"
#include <memory>
#include <string>

class Player{
public:
  Player() = delete;
  Player(std::shared_ptr<IMoveStrategy> pcMoveStrat,
                 std::string name = "DEFAULT_NAME", Money cBank = 100000);
  
  void endTurn();
  void receiveCard(Card cNewCard);
  void receiveCard(Card cNewCard, int handNum);
  bool makeMove(std::shared_ptr<IMove> pcMove, std::vector<Card> tableCards);
  bool isHuman();
  bool trySplit();
  
  void changeStrat(std::shared_ptr<IMoveStrategy> newStrat);
  
  std::vector<Card> getFaceUpCards();
  std::vector<Hand> getHands();
  Hand getCurrentHand();
  int getNumHands();
  Money getBank();
  Money getBet();
  
  bool isFullyBust();
  
private:
  void clearHands();
  
  std::string mName;
  std::vector<Hand> mcHands;
  Money mcBank;
  Money mcBet;
  int mCurrentHand;
  std::shared_ptr<IMoveStrategy> mpcMoveStrat;
};

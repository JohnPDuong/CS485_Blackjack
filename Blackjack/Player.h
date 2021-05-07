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

//Class forward declarations to avoid circular dependancy issues.
class IMoveStrategy;
class IMove;

class Player{
public:
  Player(std::shared_ptr<IMoveStrategy> pcMoveStrat = nullptr,
                 std::string name = "DEFAULT_NAME", Money cBank = Money (10000, Currency::USD));
  
  void endTurn();
  void receiveCard(Card cNewCard);
  void receiveCard(Card cNewCard, int handNum);
  bool makeMove(std::shared_ptr<IMove>& pcMove, std::vector<Card> tableCards);
  bool makeBet(Money cAmount);
  bool isHuman();
  bool trySplit();
  void clearHand();
  
  bool hasLost();
  
  void changeStrat(std::shared_ptr<IMoveStrategy> newStrat);
  
  std::vector<Card> getFaceUpCards();
  std::vector<Hand> getHands();
  Hand& getCurrentHand();
  int getNumHands();
  Money getBank();
  Money getBet();
  std::string getName();
  void setName(std::string name);
  void setBalance(Money newBalance);
  
  bool isFullyBust();
  bool readyToStart();

  bool canSplit ();
  void endRound(int dealerVal);
  
  bool doneWithTurn();
  
private:
  std::string mName;
  std::vector<Hand> mcHands;
  Money mcBank;
  Money mcBet;
  int mCurrentHand;
  bool mbSplittable;
  std::shared_ptr<IMoveStrategy> mpcMoveStrat;
};

//***************************************************************************
// File name:  CardCounterAI.h
// Author:     Kitt Oster
// Date:       5/2/2021
// Class:      CS485
// Assignment: Blackjack
// Purpose:    Define the Dealer Move Strat
//***************************************************************************

#pragma once

#include "IComputerMoveStrategy.h"

class CardCounterAI : public IComputerMoveStrategy {
public:
  CardCounterAI();
  
  virtual bool determineMove(Hand& cCurrentHand,
                             std::shared_ptr<IMove>& pcCurrentMove,
                             std::vector<Card>& cTableCards) override;
  virtual bool determineBet(Player& player, Money& bet) override;
  virtual bool isHuman() override;
private:
  bool isEqual(Card& cCard1, Card& cCard2);
  int unhashSuit(Suit inputSuit);
  int unhashValue(Value inputValue);
  int estimateNumDecks();
  
  void evalCards(int& numGoodCards, int& numBadCards, int estimatedNumDecks, int refVal = 8);
  
  //Some of the slots may be unused because the enum has repeated values.
  int mTotalCardsFoundOfEachType[4][13];
  std::vector<Card> mcCardsSeenThisRound;
};

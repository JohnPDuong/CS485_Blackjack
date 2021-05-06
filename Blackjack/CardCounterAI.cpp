//***************************************************************************
// File name:  CardCounterAI.cpp
// Author:     Kitt Oster
// Date:       5/2/2021
// Class:      CS485
// Assignment: Blackjack
// Purpose:    Impements the CardCounter Move Strat
//***************************************************************************

#include "CardCounterAI.h"
#include "Draw.h"
#include "Stand.h"

CardCounterAI::CardCounterAI(){
  for(int i = 0; i < 13; i++){
    for(int j = 0; j < 4; j++){
      mTotalCardsFoundOfEachType[j][i] = 0;
    }
  }
}


bool CardCounterAI::determineMove(Hand& cCurrentHand,
                                  std::shared_ptr<IMove>& pcCurrentMove,
                                  std::vector<Card>& cTableCards){
  int estimatedNumDecks = 0;
  int numGoodCard = 0;
  int numBadCard = 0;
  
  //Check if first round
  if(mcCardsSeenThisRound.size() != 0){
  
    //Iterate through faceup cards and add any new ones to the count.
    //(Best method possible with our current setup. May mess up if two
    //identical cards are in a row (can't identify the new one?). It might
    //catch the second though and be good enough. Small enough edgecase that
    //it's probably ok to miss it.)
    int j = 0;
    for(int i = 0; i < cTableCards.size();){
      if(j >= mcCardsSeenThisRound.size() ||
         !isEqual(cTableCards.at(i), mcCardsSeenThisRound.at(j))){
        mTotalCardsFoundOfEachType[unhashSuit(cTableCards.at(i).getSuit())][unhashValue(cTableCards.at(i).getValue())]++;
        j--;
      }
      i++;
      j++;
    }
  }
  mcCardsSeenThisRound = cTableCards;
  
  estimatedNumDecks = estimateNumDecks();
  evalCards(numGoodCard, numBadCard, estimatedNumDecks,
            21 - cCurrentHand.getHandValue());
  //Estimate the number of cards that are good and the number that are bad
  //(will cause bust) assuming estimated num decks is correct.
  
  
  //If more helpful cards than bad ones, draw, otherwise don't.
  if(numGoodCard >= numBadCard){
    pcCurrentMove = std::make_shared<Draw>();
  }
  else{
    pcCurrentMove = std::make_shared<Stand>();
  }
  
  return true;
}

bool CardCounterAI::determineBet(Player& player, Money& bet){
  int numGood = 0;
  int numBad = 0;
  int numDecks = estimateNumDecks();
  
  evalCards(numGood, numBad, numDecks);
  
  bet.setAmount(((numGood-numBad)/(double)numDecks) *
                player.getBank().getAmount()/100);
  return true;
}

bool CardCounterAI::isHuman() {
  return false; //IComputerMoveStrategy::isHuman();
}

bool CardCounterAI::isEqual(Card &cCard1, Card &cCard2){
  return cCard1.getSuit() == cCard2.getSuit()
         && cCard1.getValue() == cCard2.getValue();
}

void CardCounterAI::evalCards(int &numGoodCards, int &numBadCards,
                              int estimatedNumDecks, int refVal){
  for(int i = 0; i < 13; i++){
    if(i <= refVal && i <= unhashValue(Value::Ten)){
      numGoodCards += estimatedNumDecks -
                  (mTotalCardsFoundOfEachType[0][i]
                  + mTotalCardsFoundOfEachType[1][i]
                  + mTotalCardsFoundOfEachType[2][i]
                  + mTotalCardsFoundOfEachType[3][i]);
    }
    else if(unhashValue(Value::Ten) <= refVal){
      numGoodCards += estimatedNumDecks -
                  (mTotalCardsFoundOfEachType[0][i]
                  + mTotalCardsFoundOfEachType[1][i]
                  + mTotalCardsFoundOfEachType[2][i]
                  + mTotalCardsFoundOfEachType[3][i]);
    }
    else{
      numBadCards += estimatedNumDecks -
                  (mTotalCardsFoundOfEachType[0][i]
                  + mTotalCardsFoundOfEachType[1][i]
                  + mTotalCardsFoundOfEachType[2][i]
                  + mTotalCardsFoundOfEachType[3][i]);
    }
  }
}

int CardCounterAI::unhashSuit(Suit inputSuit){
  switch(inputSuit){
    case Suit::Clubs:
      return 0;
    case Suit::Spades:
      return 1;
    case Suit::Hearts:
      return 2;
    case Suit::Diamonds:
      return 3;
    case Suit::Count:
      return -1; //This should never happen.
  }
}

int CardCounterAI::unhashValue(Value inputValue){
  switch(inputValue){
    case Value::Ace:
      return 0;
    case Value::Two:
      return 1;
    case Value::Three:
      return 2;
    case Value::Four:
      return 3;
    case Value::Five:
      return 4;
    case Value::Six:
      return 5;
    case Value::Seven:
      return 6;
    case Value::Eight:
      return 7;
    case Value::Nine:
      return 8;
    case Value::Ten:
      return 9;
    case Value::Jack:
      return 10;
    case Value::Queen:
      return 11;
    case Value::King:
      return 12;
    case Value::Count:
      return -1; //This should never happen.
  }
}

int CardCounterAI::estimateNumDecks(){
  int estimatedNumDecks = 0;
  for(int i = 0; i < 13; i++){
    for(int j = 0; j < 4; j++){
      if(mTotalCardsFoundOfEachType[j][i] > estimatedNumDecks){
        estimatedNumDecks = mTotalCardsFoundOfEachType[j][i];
      }
    }
  }
  return estimatedNumDecks;
}

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
#include "Split.h"

//***************************************************************************
// Constructor: CardCounterAI
//
// Description: Initializes member variables
//
// Parameters:  None
//
// Return:			None
//***************************************************************************
CardCounterAI::CardCounterAI(){
  for(int i = 0; i < 13; i++){
    for(int j = 0; j < 4; j++){
      mTotalCardsFoundOfEachType[j][i] = 0;
    }
  }
}

//***************************************************************************
// Function:    determineMove
//
// Description: determines what move the AI should make
//
// Parameters:  cCurrentHand  - the AI's current hand
//              pcCurrentMove - the move object that is being generated
//              cTableCards   - the cards on the table
//
// Return:			true if the AI was able to successfully determine a move,
//              otherwise false
//***************************************************************************
bool CardCounterAI::determineMove(Hand& cCurrentHand,
                                  std::shared_ptr<IMove>& pcCurrentMove,
                                  std::vector<Card>& cTableCards){
  if(cCurrentHand.canSplit()){
    pcCurrentMove = std::make_shared<Split>();
    return true;
  }
  
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

//***************************************************************************
// Function:    determineBet
//
// Description: determines how much money the AI should bet
//
// Parameters:  player - the player whose move strategy this is
//              bet    - the bet that will be set
//
// Return:			true
//***************************************************************************
bool CardCounterAI::determineBet(Player& player, Money& bet){
  int numGood = 0;
  int numBad = 0;
  int numDecks = estimateNumDecks();
  
  evalCards(numGood, numBad, numDecks, 8);
  
  bet.setAmount(((numGood-numBad)/(double)numDecks) *
                player.getBank().getAmount()/100);
  return true;
}

//***************************************************************************
// Function:    isHuman
//
// Description: determines whether the player is human
//
// Parameters:  None
//
// Return:			false
//***************************************************************************
bool CardCounterAI::isHuman() {
  return false; //IComputerMoveStrategy::isHuman();
}

//***************************************************************************
// Function:    isEqual
//
// Description: determines if two cards are equal
//
// Parameters:  cCard1 - the first card
//              cCard2 - the second card
//
// Return:			true if the cards are the same, otherwise false
//***************************************************************************
bool CardCounterAI::isEqual(Card &cCard1, Card &cCard2){
  return cCard1.getSuit() == cCard2.getSuit()
         && cCard1.getValue() == cCard2.getValue();
}

//***************************************************************************
// Function:    evalCards
//
// Description: determines the ratio of good cards to bad cards
//
// Parameters:  numGoodCards      - the number of good cards
//              numBadCards       - the number of bad cards
//              estimatedNumDecks - the number of decks the AI thinks there are
//              refVal            - the maximum value of a good card
//
// Return:			None
//***************************************************************************
void CardCounterAI::evalCards(int &numGoodCards, int &numBadCards,
                              int estimatedNumDecks, int refVal){
  for(int i = 0; i < 13; i++){
    if(i <= refVal && i <= unhashValue(Value::Ten)){
      numGoodCards += 4 * estimatedNumDecks -
                  (mTotalCardsFoundOfEachType[0][i]
                  + mTotalCardsFoundOfEachType[1][i]
                  + mTotalCardsFoundOfEachType[2][i]
                  + mTotalCardsFoundOfEachType[3][i]);
    }
    else if(unhashValue(Value::Ten) <= refVal){
      numGoodCards += 4 * estimatedNumDecks -
                  (mTotalCardsFoundOfEachType[0][i]
                  + mTotalCardsFoundOfEachType[1][i]
                  + mTotalCardsFoundOfEachType[2][i]
                  + mTotalCardsFoundOfEachType[3][i]);
    }
    else{
      numBadCards += 4 * estimatedNumDecks -
                  (mTotalCardsFoundOfEachType[0][i]
                  + mTotalCardsFoundOfEachType[1][i]
                  + mTotalCardsFoundOfEachType[2][i]
                  + mTotalCardsFoundOfEachType[3][i]);
    }
  }
}

//***************************************************************************
// Function:    unhashSuit
//
// Description: turns the suit into an index for an array
//
// Parameters:  inputSuit - the suit to be unhashed
//
// Return:			the unhashed suit
//***************************************************************************
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

//***************************************************************************
// Function:    unhashValue
//
// Description: turns the valuye into an index for an array
//
// Parameters:  inputValue - the value to be unhashed
//
// Return:			the unhashed value
//***************************************************************************
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

//***************************************************************************
// Function:    estimateNumDecks
//
// Description: estimates the number of decks
//
// Parameters:  None
//
// Return:			the approximate number of decks
//***************************************************************************
int CardCounterAI::estimateNumDecks(){
  int estimatedNumDecks = 1;
  for(int i = 0; i < 13; i++){
    for(int j = 0; j < 4; j++){
      if(mTotalCardsFoundOfEachType[j][i] > estimatedNumDecks){
        estimatedNumDecks = mTotalCardsFoundOfEachType[j][i];
      }
    }
  }
  return estimatedNumDecks;
}

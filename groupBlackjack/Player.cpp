//***************************************************************************
// File name:  Player.cpp
// Author:     Kitt Oster
// Date:       5/2/2021
// Class:      CS485
// Assignment: Blackjack
// Purpose:    Implement the player
//***************************************************************************

#include "Player.h"

Player::Player(std::shared_ptr<IMoveStrategy> pcMoveStrat,
               std::string name, Money cBank){
  mpcMoveStrat = pcMoveStrat;
  mName = name;
  mcBank = cBank;
}
  
void Player::endTurn(){
  
}

void Player::receiveCard(Card cNewCard){
  receiveCard(cNewCard, mCurrentHand);
}

void Player::receiveCard(Card cNewCard, int handNum){
  mcHands.at(handNum).addCard(cNewCard);
}

bool Player::makeMove(std::shared_ptr<IMove> pcMove,
                      std::vector<Card> tableCards){
  return mpcMoveStrat->determineMove(mcHands.at(mCurrentHand),
                                     pcMove, tableCards);
}

bool Player::isHuman(){
  return mpcMoveStrat->isHuman();
}
  
std::vector<Card> Player::getFaceUpCards(){
  std::vector<Card> cFaceUpCards;
  std::vector<Card> cCardsFromThisHand;
  for(int i = 0; i < getNumHands(); i++){
    cCardsFromThisHand = mcHands.at(i).getFaceUpCards();
    cFaceUpCards.insert(cFaceUpCards.end(), cCardsFromThisHand.begin(),
                        cCardsFromThisHand.end());
  }
  return cFaceUpCards;
}

std::vector<Hand> Player::getHands(){
  return mcHands;
}

Hand Player::getCurrentHand(){
  return mcHands.at(mCurrentHand);
}

int Player::getNumHands(){
  return mcHands.size();
}

Money Player::getBank(){
  return mcBank;
}

Money Player::getBet(){
  return mcBet;
}

void Player::clearHands(){
  for(int i = 0; i < getNumHands(); i++){
    //clear hand;
  }
}

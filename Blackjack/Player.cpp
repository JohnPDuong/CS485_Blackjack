//***************************************************************************
// File name:  Player.cpp
// Author:     Kitt Oster
// Date:       5/2/2021
// Class:      CS485
// Assignment: Blackjack
// Purpose:    Implement the player
//***************************************************************************

#include "Player.h"
//***************************************************************************
// Function:
//
// Description: 
//
// Parameters:  
//
// Return:			
//***************************************************************************
Player::Player(std::shared_ptr<IMoveStrategy> pcMoveStrat,
               std::string name, Money cBank){
  mpcMoveStrat = pcMoveStrat;
  mName = name;
  mcBank = cBank;
  mCurrentHand = 0;
  mcHands = std::vector<Hand>(1);
}
//***************************************************************************
// Function:
//
// Description: 
//
// Parameters:  
//
// Return:			
//***************************************************************************
void Player::endTurn(){
  
}
//***************************************************************************
// Function:
//
// Description: 
//
// Parameters:  
//
// Return:			
//***************************************************************************
void Player::receiveCard(Card cNewCard){
  receiveCard(cNewCard, mCurrentHand);
}
//***************************************************************************
// Function:
//
// Description: 
//
// Parameters:  
//
// Return:			
//***************************************************************************
void Player::receiveCard(Card cNewCard, int handNum){
  mcHands.at(handNum).addCard(cNewCard);
}
//***************************************************************************
// Function:
//
// Description: 
//
// Parameters:  
//
// Return:			
//***************************************************************************
bool Player::makeMove(std::shared_ptr<IMove>& pcMove,
                      std::vector<Card> tableCards){
  mbSplittable = false; //made a move this turn means they cannot split
  return mpcMoveStrat->determineMove(mcHands.at(mCurrentHand),
                                     pcMove, tableCards);
}
//***************************************************************************
// Function:
//
// Description: 
//
// Parameters:  
//
// Return:			
//***************************************************************************
bool Player::makeBet(Money cAmount){
  if(mpcMoveStrat->determineBet(*this, cAmount)){
    mcBet = cAmount;
    return true;
  }
  else{
    return false;
  }
}
//***************************************************************************
// Function:
//
// Description: 
//
// Parameters:  
//
// Return:			
//***************************************************************************
bool Player::isHuman(){
  return mpcMoveStrat->isHuman();
}
//***************************************************************************
// Function:
//
// Description: 
//
// Parameters:  
//
// Return:			
//***************************************************************************
bool Player::trySplit(){
  if (canSplit())
  {
    mbSplittable = false; // can no longer split after splitting
  }
  mcHands.push_back(Hand());
  ++mCurrentHand;
  mcHands.at(mCurrentHand).addCard(mcHands.at(mCurrentHand - 1).split());
  //Need a split in hand.
  return true;
}
//***************************************************************************
// Function:
//
// Description: 
//
// Parameters:  
//
// Return:			
//***************************************************************************
void Player::changeStrat(std::shared_ptr<IMoveStrategy> newStrat){
  mpcMoveStrat = newStrat;
}
//***************************************************************************
// Function:
//
// Description: 
//
// Parameters:  
//
// Return:			
//***************************************************************************
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
//***************************************************************************
// Function:
//
// Description: 
//
// Parameters:  
//
// Return:			
//***************************************************************************
std::vector<Hand> Player::getHands(){
  return mcHands;
}
//***************************************************************************
// Function:
//
// Description: 
//
// Parameters:  
//
// Return:			
//***************************************************************************
Hand& Player::getCurrentHand(){
  return mcHands.at(mCurrentHand);
}
//***************************************************************************
// Function:
//
// Description: 
//
// Parameters:  
//
// Return:			
//***************************************************************************
int Player::getNumHands(){
  return (int) mcHands.size();
}
//***************************************************************************
// Function:
//
// Description: 
//
// Parameters:  
//
// Return:			
//***************************************************************************
Money Player::getBank(){
  return mcBank;
}
//***************************************************************************
// Function:
//
// Description: 
//
// Parameters:  
//
// Return:			
//***************************************************************************
Money Player::getBet(){
  return mcBet;
}
//***************************************************************************
// Function:
//
// Description: 
//
// Parameters:  
//
// Return:			
//***************************************************************************
std::string Player::getName(){
  return mName;
}
//***************************************************************************
// Function:
//
// Description: 
//
// Parameters:  
//
// Return:			
//***************************************************************************
void Player::setName(std::string name){
  mName = name;
}
//***************************************************************************
// Function:
//
// Description: 
//
// Parameters:  
//
// Return:			
//***************************************************************************
bool Player::isFullyBust(){
  for(int i = 0; i < getNumHands(); i++){
    if(mcHands[i].getHandValue() <= 21){
      return false;
    }
  }
  return true;
}
//***************************************************************************
// Function:
//
// Description: 
//
// Parameters:  
//
// Return:			
//***************************************************************************
bool Player::readyToStart(){
  mbSplittable = true; //Start of turn, players can split
  return mpcMoveStrat != nullptr;
}
//***************************************************************************
// Function:
//
// Description: 
//
// Parameters:  
//
// Return:			
//***************************************************************************
bool Player::canSplit()
{
    return mbSplittable;
}
//***************************************************************************
// Function:
//
// Description: 
//
// Parameters:  
//
// Return:			
//***************************************************************************
void Player::endRound(){
  for(int i = 0; i < getNumHands(); i++){
    mcHands.pop_back();
  }
  mcHands.push_back(Hand());
  mcBet = Money(-1, mcBank.getCurrency());
  mCurrentHand = 0;
}

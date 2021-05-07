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
// Constructor: Player
//
// Description: Initializes the member variables for a player
//
// Parameters:  pcMoveStrategy - the move strategy to use
//              name           - the player's name
//              cBank          - the balance to start with
//
// Return:			None
//***************************************************************************
Player::Player(std::shared_ptr<IMoveStrategy> pcMoveStrat,
               std::string name, Money cBank){
  mpcMoveStrat = pcMoveStrat;
  mName = name;
  mcBank = cBank;
  mcBet = -1;
  mCurrentHand = 0;
  mcHands = std::vector<Hand>(1);
}

//***************************************************************************
// Function:    doneWithTurn
//
// Description: determines if the player is done with the turn
//
// Parameters:  None
//
// Return:			True if the player is done
//***************************************************************************
bool Player::doneWithTurn(){
  return mCurrentHand == 0;
}

//***************************************************************************
// Function:    endTurn
//
// Description: handles the post-round functions
//
// Parameters:  None
//
// Return:			None
//***************************************************************************
void Player::endTurn(){
  mbSplittable = true;
  mCurrentHand++;
  if(mCurrentHand >= getNumHands()){
    mCurrentHand = 0;
  }
}

//***************************************************************************
// Function:    receiveCard
//
// Description: gives the player a card
//
// Parameters:  cNewCard - the new card to give them
//
// Return:			None
//***************************************************************************
void Player::receiveCard(Card cNewCard){
  receiveCard(cNewCard, mCurrentHand);
}

//***************************************************************************
// Function:    receiveCard
//
// Description: Gives the player a card
//
// Parameters:  cNewCard - the card to give
//              handNum  - which hand to place it in
//
// Return:			None
//***************************************************************************
void Player::receiveCard(Card cNewCard, int handNum){
  mcHands.at(handNum).addCard(cNewCard);
}

//***************************************************************************
// Function:    makeMove
//
// Description: decids on a move
// 
// Parameters:  pcMove     - the move to return
//              tableCards - the cards that everyone can see
//
// Return:			true if a move was made successfully
//***************************************************************************
bool Player::makeMove(std::shared_ptr<IMove>& pcMove,
                      std::vector<Card> tableCards){
  mbSplittable = false; //made a move this turn means they cannot split
  return mpcMoveStrat->determineMove(mcHands.at(mCurrentHand),
                                     pcMove, tableCards);
}

//***************************************************************************
// Function:    makeBet
//
// Description: cAmounr - the amount to bet
//
// Parameters:  makes a bet
//
// Return:			true if the bet was made successfully
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
// Function:    isHuman
//
// Description: returns whether the player is a human
//
// Parameters:  None
//
// Return:			True if human
//***************************************************************************
bool Player::isHuman(){
  return mpcMoveStrat->isHuman();
}

//***************************************************************************
// Function:    trySplit
//
// Description: attempts to split
//
// Parameters:  None
//
// Return:			True if split successfully
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
// Function:    clearHand
//
// Description: clears the player of cards
//
// Parameters:  None
//
// Return:			None
//***************************************************************************
void Player::clearHand()
{
  Hand cHand;
  for (Hand h : mcHands)
  {
    h = cHand;
  }
  
  mcHands = std::vector<Hand>(1);
}

//***************************************************************************
// Function:    hasLost
//
// Description: returns whether the player has lost the round
//
// Parameters:  None
//
// Return:			True if the player has lost the round
//***************************************************************************
bool Player::hasLost(){
  return mcBank.getAmount() <= 0;
}

//***************************************************************************
// Function:    changeStrat
//
// Description: changes the strategy that the player uses
//
// Parameters:  newStrat - the new strategy
//
// Return:			None
//***************************************************************************
void Player::changeStrat(std::shared_ptr<IMoveStrategy> newStrat){
  mpcMoveStrat = newStrat;
}
  
//***************************************************************************
// Function:    getFaceUpCards
//
// Description: returns the face up cards
//
// Parameters:  None
//
// Return:			A vector of cards
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
// Function:    getHands
//
// Description: returns the Hands of the player
//
// Parameters:  None
//
// Return:			the hands of the player
//***************************************************************************
std::vector<Hand> Player::getHands(){
  return mcHands;
}

//***************************************************************************
// Function:    getCurrentHand
//
// Description: returns the current hand
//
// Parameters:  None
//
// Return:			the current hand
//***************************************************************************
Hand& Player::getCurrentHand(){
  return mcHands.at(mCurrentHand);
}

//***************************************************************************
// Function:    getNumHands
//
// Description: returns the numer of hands that the user has
//
// Parameters:  None
//
// Return:			the number of hands
//***************************************************************************
int Player::getNumHands(){
  return (int) mcHands.size();
}

//***************************************************************************
// Function:    getBank
//
// Description: returns the money that the player has
//
// Parameters:  None
//
// Return:			The dough
//***************************************************************************
Money Player::getBank(){
  return mcBank;
}

//***************************************************************************
// Function:    getBet
//
// Description: returns the player's bet
//
// Parameters:  None
//
// Return:			the money that the player bet
//***************************************************************************
Money Player::getBet(){
  return mcBet;
}

//***************************************************************************
// Function:    getName
//
// Description: returns the name of the player
//
// Parameters:  None
//
// Return:			the name
//***************************************************************************
std::string Player::getName(){
  return mName;
}

//***************************************************************************
// Function:    setName
//
// Description: Sets the player's name
//
// Parameters:  name - the new name
//
// Return:			None
//***************************************************************************
void Player::setName(std::string name){
  mName = name;
}

//***************************************************************************
// Function:    setBalance
//
// Description: sets the balance of the player
//
// Parameters:  newBalance - the new balance
//
// Return:			None
//***************************************************************************
void Player::setBalance(Money newBalance){
  mcBank = newBalance;
}

//***************************************************************************
// Function:    isFullyBust
//
// Description: determines if the player is bust
//
// Parameters:  None
//
// Return:			True if fullt busted
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
// Function:    readyToStart
//
// Description: Determines if the player is ready to start
//
// Parameters:  None
//
// Return:			True if ready
//***************************************************************************
bool Player::readyToStart(){
  mbSplittable = true; //Start of turn, players can split
  return mpcMoveStrat != nullptr;
}

//***************************************************************************
// Function:    canSplit
//
// Description: returns whether or not the player can split
//
// Parameters:  None
//
// Return:			True if can split
//***************************************************************************
bool Player::canSplit()
{
    return mbSplittable;
}

//***************************************************************************
// Function:    endRound
//
// Description: manages what happens after a round is over
//
// Parameters:  dealerVal - the value of the dealer's cards
//
// Return:			None
//***************************************************************************
void Player::endRound(int dealerVal){
  for(int i = 0; i < getNumHands(); i++){
    int sum = mcHands[i].getHandValue();

    if (sum == (int) Status::Blackjack)
    {
      mcBank.setAmount(mcBank.getAmount() + mcBet.getAmount() * 1.5);
    }
    else if ((sum > dealerVal || dealerVal > (int)Status::Blackjack) && sum < (int) Status::Blackjack)
    {
      mcBank.setAmount (mcBank.getAmount() + mcBet.getAmount());
    }
    else{
      mcBank.setAmount (mcBank.getAmount() + mcBet.getAmount());
    }
  }
  
  clearHand();
  mcBet = Money(-1, mcBank.getCurrency());
  mCurrentHand = 0;
}

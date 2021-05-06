//***************************************************************************
// File name:  
// Author:     
// Date:       5/7/2021
// Class:      CS485
// Assignment: Blackjack
// Purpose:    
//***************************************************************************

#include "BlackjackModel.h"

BlackjackModel::BlackjackModel()
{
  std::cout << "ctor BlackjackModel";
  mCurrentPlayerIndex = -1;
}

BlackjackModel::BlackjackModel(int numPlayers, int numDecks){
  mcPlayers = std::vector<Player>(numPlayers);
  mpcDeck = std::make_shared<Deck>(numDecks);
}

BlackjackModel::~BlackjackModel(){
  mpcDeck.reset();
}

bool BlackjackModel::newGame(){
  for(int i = 0; i < getNumPlayers(); i++){
    if(!mcPlayers.at(i).readyToStart()){
      return false;
    }
  }
  return true;
}

bool BlackjackModel::newGame(int numDecks){
  mpcDeck.reset();
  mpcDeck = std::make_shared<Deck>(numDecks);
  return newGame();
}

bool BlackjackModel::isBust(){
  return isBust(mCurrentPlayerIndex);
}

bool BlackjackModel::isBust(int playerIndex){
  return mcPlayers.at(playerIndex).isFullyBust();
}

void BlackjackModel::initialDeal(){
  
  mpcDeck->shuffle();
  for(int i = 0; i < getNumPlayers(); i++){
    mcPlayers.at(i).receiveCard(mpcDeck->draw());
  }
  for(int i = 0; i < getNumPlayers(); i++){
    Card cTemp = mpcDeck->draw();
    cTemp.flip();
    mcPlayers.at(i).receiveCard(cTemp);
  }
}

/*
bool BlackjackModel::isHuman(){
  return true; //isHuman(mCurrentPlayerIndex); INFINITE RECURSION
}*/

/*
bool BlackjackModel::isHuman(int index){
  return mcPlayers.at(index).isHuman();
}*/

bool BlackjackModel::isBetTime(){
  return true;
}

void BlackjackModel::moveDealer(){
  std::shared_ptr<IMove> cDealerMove;
  std::vector<Card> cFaceUpCards = getFaceUpCards(); //Dealer doesn't use these
  //so could be an empty vector. Populating it correctly anyway but if worried
  //about run time minor efficiency opportunity here.
  mcDealerBrain.determineMove(mcDealerHand, cDealerMove, cFaceUpCards);
  cDealerMove->execute(*mpcDeck, mcDealerHand);
}

void BlackjackModel::makeMove(){
  std::shared_ptr<IMove> cCompMove;
  mcPlayers.at(mCurrentPlayerIndex).makeMove(cCompMove, getFaceUpCards());
  cCompMove->execute(*mpcDeck,
                     mcPlayers.at(mCurrentPlayerIndex));
}

void BlackjackModel::nextRound() // Julian made this
{

}

bool BlackjackModel::makeBet(Money cBet){
  return mcPlayers.at(mCurrentPlayerIndex).makeBet(cBet);
}

void BlackjackModel::stand(){
  bool bSuccess = false;
  if(true){
    std::shared_ptr<IMove> pcMove = std::make_shared<Stand>();
    bSuccess = mcPlayers.at(mCurrentPlayerIndex).makeMove(pcMove, getFaceUpCards());
    pcMove->execute(*mpcDeck, mcPlayers.at(mCurrentPlayerIndex));
  }
  return;
}

bool BlackjackModel::split(){
  bool bSuccess = false;
  if(true){
    std::shared_ptr<IMove> pcMove = std::make_shared<Split>();
    bSuccess = mcPlayers.at(mCurrentPlayerIndex).makeMove(pcMove, getFaceUpCards());
    pcMove->execute(*mpcDeck, mcPlayers.at(mCurrentPlayerIndex));
  }
  return bSuccess;
}

void BlackjackModel::drawCard(){
  bool bSuccess = false;
  if(true){
    std::shared_ptr<IMove> pcMove = std::make_shared<Draw>();
    bSuccess = mcPlayers.at(mCurrentPlayerIndex).makeMove(pcMove, getFaceUpCards());
    pcMove->execute(*mpcDeck, mcPlayers.at(mCurrentPlayerIndex));
  }
  return;
}

void BlackjackModel::setPlayerName(std::string name){
  setPlayerName(name, mCurrentPlayerIndex);
}

void BlackjackModel::setPlayerName(std::string name, int index){
  mcPlayers.at(index).setName(name);
}

void BlackjackModel::setPlayerType(std::string stratType){
  setPlayerType(stratType, mCurrentPlayerIndex);
}

void BlackjackModel::setPlayerType(std::string stratType, int index){
  MoveStrategyFactory stratMaker;
  std::shared_ptr<IMoveStrategy> moveStrat = stratMaker.makeStrategy(stratType);
  if(moveStrat != nullptr){
    mcPlayers.at(index).changeStrat(moveStrat);
  }
  return;
}

std::vector<std::string> BlackjackModel::getTypeList(){
  return MoveStrategyFactory::listStrats();
}

std::vector<std::string> BlackjackModel::getCurrentPlayerHand(){
  std::vector<std::string> cardStrs;
  std::vector<Card> cCards = mcPlayers.at(mCurrentPlayerIndex).getCurrentHand().getHand();

  for (Card card : cCards)
  {
    cardStrs.push_back(toString(card));
  }

  return cardStrs;
}

std::vector<Card> BlackjackModel::getFaceUpCards(){
  std::vector<Card> cAllFaceUp;
  std::vector<Card> cThisFaceUp;
  for(int i = 0; i < getNumPlayers(); i++){
    cThisFaceUp = mcPlayers.at(i).getFaceUpCards();
    cAllFaceUp.insert(cAllFaceUp.end(), cThisFaceUp.begin(),
                      cThisFaceUp.end());
  }
  return cAllFaceUp;
}

std::string BlackjackModel::getName(){
  return getName(mCurrentPlayerIndex);
}

std::string BlackjackModel::getName(int index){
  return mcPlayers.at(index).getName();
}

int BlackjackModel::getNumPlayers(){
  return mcPlayers.size();
}

long long BlackjackModel::getBalance(){
  return getBalance(mCurrentPlayerIndex);
}

long long BlackjackModel::getBalance(int index){
  return mcPlayers.at(index).getBank().getAmount();
}

long long BlackjackModel::getBet(){
  return getBet(mCurrentPlayerIndex);
}

long long BlackjackModel::getBet(int index){
  return mcPlayers.at(index).getBet().getAmount();
}

std::string BlackjackModel::toString (Card cCard)
{
  std::string cardStr = "";
  auto suit = cCard.getSuit();
  auto rank = cCard.getValue();

  if (!cCard.isFaceUp())
  {
    cardStr = "--";
  }
  else
  {
    // Adds the rank
    switch (rank)
    {
    case Value::Ace:
      cardStr += "A";
      break;

    case Value::Two:
      cardStr += "2";
      break;

    case Value::Three:
      cardStr += "3";
      break;

    case Value::Four:
      cardStr += "4";
      break;

    case Value::Five:
      cardStr += "5";
      break;

    case Value::Six:
      cardStr += "6";
      break;

    case Value::Seven:
      cardStr += "7";
      break;

    case Value::Eight:
      cardStr += "8";
      break;

    case Value::Nine:
      cardStr += "9";
      break;

    case Value::Ten:
      cardStr += "10";
      break; 

    case Value::Jack:
      cardStr += "J";
      break;

    case Value::Queen:
      cardStr += "Q";
      break;

    case Value::King:
      cardStr += "K";
      break;
    }

    // Adds the suit
    switch (suit)
    {
    case Suit::Clubs:
      cardStr += "C";
      break;

    case Suit::Diamonds:
      cardStr += "D";
      break;

    case Suit::Hearts:
      cardStr += "H";
      break;

    case Suit::Spades:
      cardStr += "S";
      break;
    }
  }

  return cardStr;
}

bool BlackjackModel::canSplit()
{
  //Only the first hand may be split
  return mcPlayers[mCurrentPlayerIndex].getHands().at(0).canSplit() == 
         mcPlayers[mCurrentPlayerIndex].canSplit();
}

std::vector<std::string> BlackjackModel::getDealerCards()
{
  std::vector <std::string> stringArry;
  
  for (int i = 0; i < mcDealerHand.getHand().size(); i++)
  {
    stringArry.push_back(toString(mcDealerHand.getHand().at(i)));
  }
  return stringArry;
}

Status BlackjackModel::resultCurrentPlayer()
{
  Status eStatus;
  int sum = mcPlayers[mCurrentPlayerIndex].getCurrentHand().getHandValue();
  int dealerSum = mcDealerHand.getHandValue();

  if (sum == (int) Status::Blackjack)
  {
    eStatus = Status::Blackjack;
  }
  else if (sum > dealerSum && sum < (int) Status::Blackjack)
  {
    eStatus = Status::Win;
  }
  else if (sum > (int) Status::Blackjack)
  {
    eStatus = Status::Bust;
  }
  else
  {
    eStatus = Status::Lose;
  }

  return eStatus;
}
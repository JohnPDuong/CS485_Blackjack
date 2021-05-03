//***************************************************************************
// File name:  
// Author:     
// Date:       5/7/2021
// Class:      CS485
// Assignment: Blackjack
// Purpose:    
//***************************************************************************

#include "BlackjackModel.h"

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

bool BlackjackModel::isHuman(){
  return isHuman(mCurrentPlayerIndex);
}

bool BlackjackModel::isHuman(int index){
  return mcPlayers.at(index).isHuman();
}

bool BlackjackModel::isBetTime(){
  
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

bool BlackjackModel::makeBet(Money cBet){
  return mcPlayers.at(mCurrentPlayerIndex).makeBet(cBet);
}

void BlackjackModel::stand(){
  bool bSuccess = false;
  if(isHuman()){
    std::shared_ptr<IMove> pcMove = std::make_shared<Stand>();
    bSuccess = mcPlayers.at(mCurrentPlayerIndex).makeMove(pcMove, getFaceUpCards());
    pcMove->execute(*mpcDeck, mcPlayers.at(mCurrentPlayerIndex));
  }
  return;
}

bool BlackjackModel::split(){
  bool bSuccess = false;
  if(isHuman()){
    std::shared_ptr<IMove> pcMove = std::make_shared<Split>();
    bSuccess = mcPlayers.at(mCurrentPlayerIndex).makeMove(pcMove, getFaceUpCards());
    pcMove->execute(*mpcDeck, mcPlayers.at(mCurrentPlayerIndex));
  }
  return bSuccess;
}

void BlackjackModel::drawCard(){
  bool bSuccess = false;
  if(isHuman()){
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

Hand BlackjackModel::getCurrentPlayerHand(){
  mcPlayers.at(mCurrentPlayerIndex).getCurrentHand();
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
  getName(mCurrentPlayerIndex);
}

std::string BlackjackModel::getName(int index){
  return mcPlayers.at(index).getName();
}

int BlackjackModel::getNumPlayers(){
  return mcPlayers.size();
}

Money BlackjackModel::getBalance(){
  return getBalance(mCurrentPlayerIndex);
}

Money BlackjackModel::getBalance(int index){
  return mcPlayers.at(index).getBank();
}

Money BlackjackModel::getBet(){
  return getBet(mCurrentPlayerIndex);
}

Money BlackjackModel::getBet(int index){
  return mcPlayers.at(index).getBet();
}

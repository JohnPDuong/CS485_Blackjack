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
  mCurrentPlayerIndex = 0;
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
  mpcDeck->fillShuffle();
  return true;
}

bool BlackjackModel::newGame(int numPlayers){
  mcPlayers = std::vector<Player>(numPlayers);
  return newGame();
}

bool BlackjackModel::newGame(int numPlayers, int numDecks){
  mpcDeck.reset();
  mpcDeck = std::make_shared<Deck>(numDecks);
  return newGame(numPlayers);
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
  return isHuman(mCurrentPlayerIndex); //INFINITE RECURSION
}

bool BlackjackModel::isHuman(int index){
  return mcPlayers.at(index).isHuman();
}

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
  incrementPlayer();
}

void BlackjackModel::nextRound() // Julian made this
{

}

Status BlackjackModel::result() // Julian
{
  return Status::Blackjack;
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
  incrementPlayer();
  return;
}

bool BlackjackModel::split(){
  bool bSuccess = false;
  if(true){
    std::shared_ptr<IMove> pcMove = std::make_shared<Split>();
    bSuccess = mcPlayers.at(mCurrentPlayerIndex).makeMove(pcMove, getFaceUpCards());
    pcMove->execute(*mpcDeck, mcPlayers.at(mCurrentPlayerIndex));
  }
  incrementPlayer();
  return bSuccess;
}

void BlackjackModel::drawCard(){
  bool bSuccess = false;
  if(true){
    std::shared_ptr<IMove> pcMove = std::make_shared<Draw>();
    bSuccess = mcPlayers.at(mCurrentPlayerIndex).makeMove(pcMove, getFaceUpCards());
    pcMove->execute(*mpcDeck, mcPlayers.at(mCurrentPlayerIndex));
  }
  incrementPlayer();
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
  return mcPlayers.at(mCurrentPlayerIndex).getCurrentHand();
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

void BlackjackModel::incrementPlayer() {
  mCurrentPlayerIndex++;
  if (mCurrentPlayerIndex >= mcPlayers.size()) {
      moveDealer();
      mCurrentPlayerIndex = 0;
  }
}
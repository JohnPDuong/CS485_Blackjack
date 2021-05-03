//***************************************************************************
// File name:  
// Author:     
// Date:       5/7/2021
// Class:      CS485
// Assignment: Blackjack
// Purpose:    
//***************************************************************************

#include "BlackjackModel.h"

BlackjackModel::BlackjackModel(int numDecks){
  
}

BlackjackModel::~BlackjackModel(){
  
}

void BlackjackModel::newGame(){
  
}

void BlackjackModel::newGame(int numDecks){
  
}

bool BlackjackModel::isBust(){
  return isBust(mCurrentPlayerIndex);
}

bool BlackjackModel::isBust(int playerIndex){
  return mcPlayers.at(playerIndex).isFullyBust();
}

void BlackjackModel::initialDeal(){
  
}

bool BlackjackModel::isHuman(){
  
}

bool BlackjackModel::isHuman(int index){
  
}

bool BlackjackModel::isBetTime(){
  
}

void BlackjackModel::moveDealer(){
  
}

void BlackjackModel::makeMove(){
  
}

bool BlackjackModel::makeBet(Money bet){
  
}

void BlackjackModel::stand(){
  
}

bool BlackjackModel::split(){
  
}

void BlackjackModel::drawCard(){
  
}

void BlackjackModel::setPlayerName(std::string name){
  
}

void BlackjackModel::setPlayerName(std::string name, int index){
  
}

void BlackjackModel::setPlayerType(std::string stratType){
  
}

void BlackjackModel::setPlayerType(std::string stratType, int index){
  
}

std::vector<std::string> BlackjackModel::getTypeList(){
  
}

Hand BlackjackModel::getCurrentPlayerHand(){
  
}

std::vector<Card> BlackjackModel::getFaceUpCards(){
  
}

std::string BlackjackModel::getName(){
  
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

//***************************************************************************
// File name:  
// Author:     
// Date:       5/7/2021
// Class:      CS485
// Assignment: Blackjack
// Purpose:    
//***************************************************************************
#pragma once

#include "Deck.h"
#include "Player.h"
#include "MoveStrategyFactory.h"
#include "Hand.h"
#include "Money.h"
#include "Stand.h"
#include "Split.h"
#include "Draw.h"
#include <vector>

class BlackjackModel{
public:
  BlackjackModel(int numPlayers, int numDecks = 1);
  ~BlackjackModel();
  
  bool newGame();
  bool newGame(int numDecks);
  
  bool isBust();
  bool isBust(int playerIndex);
  void initialDeal();
  bool isHuman();
  bool isHuman(int index);
  bool isBetTime();
  
  void moveDealer();
  void makeMove();
  
  bool makeBet(Money cBet);
  void stand();
  bool split();
  void drawCard();
  
  void setPlayerName(std::string name);
  void setPlayerName(std::string name, int index);
  void setPlayerType(std::string stratType);
  void setPlayerType(std::string stratType, int index);
  
  std::vector<std::string> getTypeList();
  
  Hand getCurrentPlayerHand();
  std::vector<Card> getFaceUpCards();
  
  std::string getName();
  std::string getName(int index);
  int getNumPlayers();
  Money getBalance();
  Money getBalance(int index);
  Money getBet();
  Money getBet(int index);
  
private:
  
  
  std::shared_ptr<Deck> mpcDeck;
  std::vector<Player> mcPlayers;
  int mCurrentPlayerIndex;
  Hand mcDealerHand;
  DealerAI mcDealerBrain;
};

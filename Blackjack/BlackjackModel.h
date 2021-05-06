//***************************************************************************
// File name:  
// Author:     
// Date:       5/7/2021
// Class:      CS485
// Assignment: Blackjack
// Purpose:    
//***************************************************************************
#pragma once

#include <iostream>
#include "Deck.h"
#include "Player.h"
#include "MoveStrategyFactory.h"
#include "Hand.h"
#include "Money.h"
#include "Stand.h"
#include "Split.h"
#include "Draw.h"
#include "Status.h"
#include <vector>

class BlackjackModel {
public:
  BlackjackModel ();
  BlackjackModel(int numPlayers, int numDecks = 1);
  ~BlackjackModel();

  
  bool newGame();
  bool newGame(int numPlayers);
  bool newGame(int numPlayers, int numDecks);
  
  bool isBust();
  bool isBust(int playerIndex);
  void initialDeal();
  //bool isHuman();
  //bool isHuman(int index);
  bool isBetTime();
  
  void moveDealer();
  void makeMove();
  void nextRound(); // Dear Kitt, I added this for the presenter. Sincerely, Julian
  
  bool makeBet(Money cBet);
  void stand();
  bool split();
  void drawCard();
  
  void setPlayerName(std::string name);
  void setPlayerName(std::string name, int index);
  void setPlayerType(std::string stratType);
  void setPlayerType(std::string stratType, int index);
  
  std::vector<std::string> getTypeList();
  
  std::vector<std::string> getCurrentPlayerHand();
  std::vector<Card> getFaceUpCards();
  
  std::string getName();
  std::string getName(int index);
  int getNumPlayers();
  long long getBalance();
  long long getBalance(int index);
  long long getBet();
  long long getBet(int index);

  bool canSplit ();
  std::vector<std::string> getDealerCards();
  Status resultCurrentPlayer ();

private:
  
  std::string toString(Card cCard); // Julian
  std::shared_ptr<Deck> mpcDeck;
  std::vector<Player> mcPlayers;
  int mCurrentPlayerIndex;
  Hand mcDealerHand;
  DealerAI mcDealerBrain;
};

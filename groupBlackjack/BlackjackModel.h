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
#include <vector>

class BlackjackModel
{
  public:
    BlackjackModel(int numDecks = 1);
    ~BlackjackModel();
  
    void newGame();
    void newGame(int numDecks);
  
    bool isBust();
    bool isBust(int playerIndex);
    void initialDeal();
    bool isHuman();
    bool isHuman(int index);
    bool isBetTime();
  
    void moveDealer();
    void makeMove();
  
    bool makeBet(Money bet);
    void stand();
    bool split();
    void drawCard();
  
    void setPlayerName(std::string name);
    void setPlayerName(std::string name, int index);
    void setPlayerType(std::string stratType);
    void setPlayerType(std::string stratType, int index);
  
    Hand getCurrentPlayerHand();
    std::vector<Card> getFaceUpCards();
  
    std::string getName();
    std::string getName(int index);
    int getNumPlayers();
    Money getBalance();
    Money getBalance(int index);
  
  private:
    Deck mcDeck;
    std::vector<Player> players;
    int mCurrentPlayerIndex;
    Hand mcDealerHand;
    DealerAI mcDealerBrain;
};

//***************************************************************************
// File name:  
// Author:     
// Date:       5/7/2021
// Class:      CS485
// Assignment: Blackjack
// Purpose:    
//***************************************************************************
#pragma once
#include "BlackjackModel.h"
#include "Status.h"
#include <iostream>

class IBlackjackPresenter {
public:
	virtual void newGame(int players) = 0;
	virtual void newGame() = 0;

	virtual void nextRound() = 0;
	virtual void endGame() = 0;
	virtual Status result() = 0;
	//virtual void addBalance(long long amount) = 0;
	virtual long long getBalance() = 0;
	virtual std::vector<std::string> getCurrentPlayerHand() = 0;
	virtual std::vector<std::vector<std::string>> getOpponentCards() = 0;
	virtual std::vector<std::string> getDealerCards() = 0;
	virtual int getNumPlayers() = 0;
	virtual std::string getName() = 0;
	virtual void setName(std::string name, int index) = 0;
	virtual void setPlayerType(std::string stratType, int index) = 0;

	virtual void stand() = 0;
	virtual bool bet(long long amount) = 0;
	virtual void split() = 0;
	virtual void draw() = 0;

	virtual void makeMove() = 0;
	virtual bool isHuman() = 0;
	virtual bool canSplit() = 0;
	virtual bool isBetTime() = 0;

	virtual void updateView() = 0;
	virtual void doCPUMoves() = 0;
	virtual void doCPUBets() = 0;

};

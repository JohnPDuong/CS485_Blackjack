//***************************************************************************
// File name:  IBlackjackPresenter.h
// Author:     John, Julian, Kitt, Erin
// Date:       5/7/2021
// Class:      CS485
// Assignment: Blackjack
// Purpose:    Declares the class from which all presenters inherit
//***************************************************************************
#pragma once
#include "BlackjackModel.h"
#include "Status.h"
#include <iostream>

class IBlackjackPresenter {
public:
	virtual bool newGame(int players) = 0;
	virtual bool newGame() = 0;

	virtual void nextRound() = 0;
  virtual std::vector<Status> endRound() = 0;
  virtual bool roundOngoing() = 0;
	virtual Status result() = 0;
	//virtual void addBalance(long long amount) = 0;
	virtual long long getBalance() = 0;
	virtual std::vector<std::string> getCurrentPlayerHand() = 0;
	virtual std::vector<std::vector<std::string>> getAllCards() = 0;
	virtual std::vector<std::string> getDealerCards() = 0;
  virtual std::vector<std::string> getAllCurrentPlayerHands() = 0;
	virtual int getNumPlayers() = 0;
	virtual std::string getName() = 0;
	virtual void setName(std::string name, int index) = 0;
	virtual void setPlayerType(std::string stratType, int index) = 0;
  virtual std::vector<std::string> listMoveStratTypes() = 0;

	virtual std::string getName(int index) = 0;
	virtual long long getBalance (int index) = 0;
  virtual void setBalance(long long amount, int index) = 0;

	virtual void setBet (long long amount, int index) = 0;
	virtual long long getBet (int index) = 0;

	virtual void stand() = 0;
	virtual bool bet(long long amount) = 0;
	virtual void split() = 0;
	virtual void draw() = 0;

	virtual void makeMove() = 0;
	virtual bool isHuman() = 0;
	virtual bool isHuman(int index) = 0;
	virtual bool canSplit() = 0;
	virtual bool isBetTime() = 0;

	virtual void updateView() = 0;
	virtual void doCPUMoves() = 0;
	virtual void doCPUBets() = 0;

	virtual int getCurrentPlayer () = 0;
};

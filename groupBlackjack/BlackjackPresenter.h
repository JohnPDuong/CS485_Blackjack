//***************************************************************************
// File name:  
// Author:     
// Date:       5/7/2021
// Class:      CS485
// Assignment: Blackjack
// Purpose:    
//***************************************************************************
#pragma once

#include "IBlackjackPresenter.h"
#include "BlackjackModel.h"

class BlackjackPresenter : public IBlackjackPresenter {
public:
	virtual void newGame(int players);

	virtual void nextRound();
	virtual void endGame();
	virtual void result();
	//virtual void addBalance(long long amount) = 0;
	virtual long long getBalance();
	virtual void getNumPlayers();
	virtual std::string getName();
	virtual void setName(std::string name);

	virtual void stand();
	virtual void bet(long long amount);
	virtual void split();
	virtual void draw();

	virtual void makeMove();
	virtual void updateView();

private:
	Blackjack mcGame;


};
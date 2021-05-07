//***************************************************************************
// File name:  BlackjackPresenterSDL.h
// Author:     Erin Melia
// Date:       5/6/2021
// Class:      CS485
// Assignment: Blackjack
// Purpose:    The presenter for the sdl view
//***************************************************************************
#pragma once

#include "IBlackjackPresenter.h"
#include "IBlackjackView.h"
#include "BlackjackModel.h"

class BlackjackPresenterSDL : public IBlackjackPresenter
{
public:
	BlackjackPresenterSDL ();
	BlackjackPresenterSDL (IBlackjackView* pcView);
	BlackjackPresenterSDL (IBlackjackView* pcView, int numPlayers, int numDecks);
	virtual ~BlackjackPresenterSDL ();

	virtual bool newGame (int players) override;
	virtual bool newGame () override;

	virtual void nextRound () override;
	virtual void endGame () override;
	virtual std::vector<Status> endRound() override;
	virtual bool roundOngoing() override;
	virtual Status result () override;
	//virtual void addBalance(long long amount) = 0;
	virtual long long getBalance () override;
	virtual std::vector<std::string> getCurrentPlayerHand () override;
	virtual std::vector<std::vector<std::string>> getAllCards () override;
	virtual std::vector<std::string> getDealerCards () override;
	virtual std::vector<std::string> getAllCurrentPlayerHands() override;
	virtual int getNumPlayers () override;
	virtual std::string getName () override;
	virtual void setName (std::string name, int index) override;
	virtual void setPlayerType (std::string stratType, int index) override;
	virtual std::vector<std::string> listMoveStratTypes() override;

	virtual std::string getName(int index) override;
	virtual long long getBalance(int index) override;

	virtual void setBet(long long amount, int index) override;
	virtual long long getBet(int index) override;

	virtual void stand () override;
	virtual bool bet (long long amount) override;
	virtual void setBalance(long long amount, int index) override;

	virtual void split () override;
	virtual void draw () override;

	virtual void makeMove () override;
	virtual bool isHuman () override;
	virtual bool isHuman(int index) override;
	virtual bool canSplit () override;
	virtual bool isBetTime() override;

	virtual void updateView () override;
	virtual void doCPUMoves() override;
	virtual void doCPUBets() override;

	virtual int getCurrentPlayer() override;

private:
	BlackjackModel mcModel;
	IBlackjackView* mpcView;
};

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

	virtual void newGame (int players);

	virtual void nextRound ();
	virtual void endGame ();
	virtual Status result ();
	//virtual void addBalance(long long amount) = 0;
	virtual long long getBalance ();
	virtual std::vector<std::string> getCurrentPlayerHand ();
	virtual std::vector<std::vector<std::string>> getOpponentCards ();
	virtual std::vector<std::string> getDealerCards ();
	virtual int getNumPlayers ();
	virtual std::string getName ();
	virtual void setName (std::string name);
	virtual void setPlayerType (std::string stratType, int index);

	virtual void stand ();
	virtual void bet (long long amount);
	virtual void split ();
	virtual void draw ();

	virtual void makeMove ();
	virtual bool isHuman ();
	virtual bool canSplit ();

	virtual void updateView ();

private:
	BlackjackModel mcModel;
	IBlackjackView* mpcView;
};
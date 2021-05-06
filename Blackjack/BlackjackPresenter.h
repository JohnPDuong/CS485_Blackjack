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
#include "IBlackjackView.h"
#include "BlackjackModel.h"

class BlackjackPresenter : public IBlackjackPresenter 
{
	public:
		BlackjackPresenter ();
		BlackjackPresenter(IBlackjackView* pcView);
		BlackjackPresenter(IBlackjackView* pcView, int numPlayers, int numDecks);
		virtual ~BlackjackPresenter();

		virtual void newGame(int players);
		virtual void newGame() override;

		virtual void nextRound();
		virtual void endGame();
		virtual Status result();
		//virtual void addBalance(long long amount) = 0;
		virtual long long getBalance();
		virtual std::vector<std::string> getCurrentPlayerHand();
		virtual std::vector<std::vector<std::string>> getOpponentCards();
		virtual std::vector<std::string> getDealerCards();
		virtual int getNumPlayers();
		virtual std::string getName();
		virtual void setName(std::string name, int index);
		virtual void setPlayerType(std::string stratType, int index);

		virtual void stand();
		virtual bool bet(long long amount);
		virtual void split();
		virtual void draw();

		virtual void makeMove();
		virtual bool isHuman();
		virtual bool canSplit();
		virtual bool isBetTime();

		virtual void updateView();
		virtual void doCPUMoves();
		virtual void doCPUBets();

	private:
		BlackjackModel mcModel;
		IBlackjackView *mpcView;
};

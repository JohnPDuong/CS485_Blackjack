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

		virtual void newGame(int players) override;
		virtual void newGame() override;

		virtual void nextRound() override;
		virtual void endGame() override;
    virtual std::vector<Status> endRound() override;
    virtual bool roundOngoing() override;
		virtual Status result() override;
		//virtual void addBalance(long long amount) = 0;
		virtual long long getBalance() override;
		virtual std::vector<std::string> getCurrentPlayerHand() override;
		virtual std::vector<std::vector<std::string>> getOpponentCards() override;
		virtual std::vector<std::string> getDealerCards() override;
		virtual int getNumPlayers() override;
		virtual std::string getName() override;
		virtual void setName(std::string name, int index) override;
		virtual void setPlayerType(std::string stratType, int index) override;

		virtual std::string getName(int index);
		virtual long long getBalance(int index);

		virtual void stand() override;
		virtual bool bet(long long amount) override;
		virtual void split() override;
		virtual void draw() override;

		virtual void makeMove() override;
		virtual bool isHuman() override;
		virtual bool canSplit() override;
		virtual bool isBetTime() override;

		virtual void updateView() override;
		virtual void doCPUMoves() override;
		virtual void doCPUBets() override;

		virtual int getCurrentPlayer();

	private:
		BlackjackModel mcModel;
		IBlackjackView *mpcView;
};

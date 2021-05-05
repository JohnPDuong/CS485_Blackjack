//***************************************************************************
// File name:  
// Author:     
// Date:       5/7/2021
// Class:      CS485
// Assignment: Blackjack
// Purpose:    
//***************************************************************************

#include "BlackjackPresenter.h"
#include "Status.h"


BlackjackPresenter::BlackjackPresenter(IBlackjackView* pcView)
{
	mpcView = pcView;
}

BlackjackPresenter::BlackjackPresenter(IBlackjackView* pcView, int numPlayers, int numDecks)
	: mcModel (numPlayers, numDecks)
{
	mpcView = pcView;
}

BlackjackPresenter::~BlackjackPresenter()
{
	delete mpcView;
}

void BlackjackPresenter::newGame(int players)
{
	mcModel.newGame(players);
}

void BlackjackPresenter::nextRound()
{
	mcModel.nextRound();
}

void BlackjackPresenter::endGame()
{
	// Do we need this?
}

Status BlackjackPresenter::result()
{
	return mcModel.result();
}

long long BlackjackPresenter::getBalance()
{
	return mcModel.getBalance();
}

int BlackjackPresenter::getNumPlayers()
{
	return mcModel.getNumPlayers();
}

std::string BlackjackPresenter::getName()
{
	return mcModel.getName();
}

void BlackjackPresenter::setName(std::string name)
{
	mcModel.setPlayerName(name);
}

void BlackjackPresenter::stand()
{
	mcModel.stand();
}

void BlackjackPresenter::bet(long long amount)
{
	mcModel.makeBet(amount);
}

void BlackjackPresenter::split()
{
	mcModel.split();
}

void BlackjackPresenter::draw()
{
	mcModel.drawCard();
}

void BlackjackPresenter::makeMove()
{
	mcModel.makeMove();
}

void BlackjackPresenter::updateView()
{
	mpcView->render();
}
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


BlackjackPresenter::BlackjackPresenter()
{
	std::cout << "ctor" << std::endl;
}

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

std::vector<std::string> BlackjackPresenter::getCurrentPlayerHand()
{
	return mcModel.getCurrentPlayerHand();
}

std::vector<std::vector<std::string>> BlackjackPresenter::getOpponentCards()
{
	std::vector<std::vector<std::string>> cards; // TEMPORARY

	//return mcModel.getOpponentCards();
	return cards; // TEMPORARY
}

std::vector<std::string> BlackjackPresenter::getDealerCards()
{
	std::vector<std::string> cards; // TEMPORARY

	// return mcModel.getDealerCards();
	return cards;// TEMPORARY
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
	mcModel.makeBet(Money (amount, Currency::USD));
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

bool BlackjackPresenter::isHuman()
{
	// return mcModel.isHuman();
	return true;
}

bool BlackjackPresenter::canSplit()
{
	return mcModel.canSplit();
}

void BlackjackPresenter::updateView()
{
	mpcView->render();
}
//***************************************************************************
// File name:  
// Author:     
// Date:       5/7/2021
// Class:      CS485
// Assignment: Blackjack
// Purpose:    
//***************************************************************************

#include "BlackjackPresenterSDL.h"
#include "Status.h"


BlackjackPresenterSDL::BlackjackPresenterSDL ()
{
	std::cout << "ctor" << std::endl;
}

BlackjackPresenterSDL::BlackjackPresenterSDL (IBlackjackView* pcView)
{
	mpcView = pcView;
}

BlackjackPresenterSDL::BlackjackPresenterSDL (IBlackjackView* pcView, int numPlayers, int numDecks)
	: mcModel (numPlayers, numDecks)
{
	mpcView = pcView;
}

BlackjackPresenterSDL::~BlackjackPresenterSDL ()
{
	delete mpcView;
}

void BlackjackPresenterSDL::newGame (int players)
{
	mcModel.newGame (players);
	//mpcView->newGame(players);
}

void BlackjackPresenterSDL::nextRound ()
{
	mcModel.nextRound ();
}

void BlackjackPresenterSDL::endGame ()
{
	// Do we need this?
}

Status BlackjackPresenterSDL::result ()
{
	return mcModel.resultCurrentPlayer ();
}

long long BlackjackPresenterSDL::getBalance ()
{
	return mcModel.getBalance ();
}

std::vector<std::string> BlackjackPresenterSDL::getCurrentPlayerHand ()
{
	return mcModel.getCurrentPlayerHand ();
}

std::vector<std::vector<std::string>> BlackjackPresenterSDL::getOpponentCards ()
{
	std::vector<std::vector<std::string>> cards; // TEMPORARY

	//return mcModel.getOpponentCards();
	return cards; // TEMPORARY
}

std::vector<std::string> BlackjackPresenterSDL::getDealerCards ()
{
	return mcModel.getDealerCards ();
}

int BlackjackPresenterSDL::getNumPlayers ()
{
	return mcModel.getNumPlayers ();
}

std::string BlackjackPresenterSDL::getName ()
{
	return mcModel.getName ();
}

void BlackjackPresenterSDL::setName (std::string name)
{
	mcModel.setPlayerName (name);
}

void BlackjackPresenterSDL::setPlayerType (std::string stratType, int index)
{
	mcModel.setPlayerType (stratType, index);
}

void BlackjackPresenterSDL::stand ()
{
	mcModel.stand ();
}

void BlackjackPresenterSDL::bet (long long amount)
{
	mcModel.makeBet (Money (amount, Currency::USD));
}

void BlackjackPresenterSDL::split ()
{
	mcModel.split ();
}

void BlackjackPresenterSDL::draw ()
{
	mcModel.drawCard ();
}

void BlackjackPresenterSDL::makeMove ()
{
	mcModel.makeMove ();
}

bool BlackjackPresenterSDL::isHuman ()
{
	// return mcModel.isHuman();
	return true;
}

bool BlackjackPresenterSDL::canSplit ()
{
	return mcModel.canSplit ();
}

void BlackjackPresenterSDL::updateView ()
{
	mpcView->render ();
}
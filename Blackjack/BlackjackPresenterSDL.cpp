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

void BlackjackPresenterSDL::newGame()
{
	mcModel.newGame();
}

void BlackjackPresenterSDL::nextRound ()
{
	mcModel.nextRound ();
}

void BlackjackPresenterSDL::endGame ()
{
	// Do we need this?
}

std::vector<Status> BlackjackPresenterSDL::endRound()
{
	return mcModel.result();
}


bool BlackjackPresenterSDL::roundOngoing()
{
	return !mcModel.roundDone();
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

void BlackjackPresenterSDL::setName (std::string name, int index)
{
	mcModel.setPlayerName (name, index);
}

void BlackjackPresenterSDL::setPlayerType (std::string stratType, int index)
{
	mcModel.setPlayerType (stratType, index);
}

std::string BlackjackPresenterSDL::getName(int index)
{
	return mcModel.getName(index);
}

long long BlackjackPresenterSDL::getBalance(int index)
{
	return mcModel.getBalance(index);
}

void BlackjackPresenterSDL::stand ()
{
	mcModel.stand ();
}

bool BlackjackPresenterSDL::bet (long long amount)
{
	return mcModel.makeBet(Money(amount, Currency::USD));;
}

void BlackjackPresenterSDL::setBalance(long long amount, int index)
{
	mcModel.setPlayerBalance(amount, index);
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

bool BlackjackPresenterSDL::isBetTime()
{
	return mcModel.isBetTime();
}

void BlackjackPresenterSDL::updateView ()
{
	mpcView->render ();
}

void BlackjackPresenterSDL::doCPUMoves()
{
	mcModel.doCPUMoves();
}

void BlackjackPresenterSDL::doCPUBets()
{
	mcModel.doCPUBets();
}

int BlackjackPresenterSDL::getCurrentPlayer()
{
	return mcModel.getCurrentPlayer();
}


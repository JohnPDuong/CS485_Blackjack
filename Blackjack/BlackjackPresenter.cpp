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

//***************************************************************************
// Function:		BlackjackPresenter
//
// Description: None
//
// Parameters:  None
//
// Return:			None
//***************************************************************************
BlackjackPresenter::BlackjackPresenter()
{
}
//***************************************************************************
// Function:		BlackjackPresenter
//
// Description: Assigns pcView to mpcView
//
// Parameters:  pcView - pointer to view
//
// Return:			None
//***************************************************************************
BlackjackPresenter::BlackjackPresenter(IBlackjackView* pcView)
{
	mpcView = pcView;
}
//***************************************************************************
// Function:		BlackjackPresenter
//
// Description: Assigns pcView to mpcView and passes in parameters for model
//
// Parameters:  pcView		 - pointer to view
//							numPlayers - number of players
//							numDecks	 - number of decks
//
// Return:			None		
//***************************************************************************
BlackjackPresenter::BlackjackPresenter(IBlackjackView* pcView, int numPlayers, int numDecks)
	: mcModel (numPlayers, numDecks)
{
	mpcView = pcView;
}
//***************************************************************************
// Function:		BlackjackPresenter
//
// Description: Deletes the view
//
// Parameters:  None
//
// Return:			None
//***************************************************************************
BlackjackPresenter::~BlackjackPresenter()
{
	delete mpcView;
}
//***************************************************************************
// Function:		newGame
//
// Description: calls new game
//
// Parameters:  players - number of players
//
// Return:			None
//***************************************************************************
void BlackjackPresenter::newGame(int players)
{
	mcModel.newGame(players);
	//mpcView->newGame(players);
}
//***************************************************************************
// Function:		newGame
//
// Description: calls new game
//
// Parameters:  None
//
// Return:			None
//***************************************************************************
void BlackjackPresenter::newGame()
{
	mcModel.newGame();
}
//***************************************************************************
// Function:		nextRound
//
// Description: calls next round
//
// Parameters:  none
//
// Return:			none
//***************************************************************************
void BlackjackPresenter::nextRound()
{
	mcModel.nextRound();
}
//***************************************************************************
// Function:		end
//
// Description: 
//
// Parameters:  
//
// Return:			
//***************************************************************************
void BlackjackPresenter::endGame()
{
	// Do we need this?
}

std::vector<Status> BlackjackPresenter::endRound(){
  return mcModel.nextRound();
}

bool BlackjackPresenter::roundOngoing(){
  return !mcModel.roundDone();
}

//***************************************************************************
// Function:
//
// Description: 
//
// Parameters:  
//
// Return:			
//***************************************************************************
Status BlackjackPresenter::result()
{
	return mcModel.resultCurrentPlayer();
}
//***************************************************************************
// Function:
//
// Description: 
//
// Parameters:  
//
// Return:			
//***************************************************************************
long long BlackjackPresenter::getBalance()
{
	return mcModel.getBalance();
}
//***************************************************************************
// Function:
//
// Description: 
//
// Parameters:  
//
// Return:			
//***************************************************************************
std::vector<std::string> BlackjackPresenter::getCurrentPlayerHand()
{
	return mcModel.getCurrentPlayerHand();
}
//***************************************************************************
// Function:
//
// Description: 
//
// Parameters:  
//
// Return:			
//***************************************************************************
std::vector<std::vector<std::string>> BlackjackPresenter::getOpponentCards()
{
	return mcModel.getOpponentCards();
}
//***************************************************************************
// Function:
//
// Description: 
//
// Parameters:  
//
// Return:			
//***************************************************************************
std::vector<std::string> BlackjackPresenter::getDealerCards()
{
	return mcModel.getDealerCards();
}
//***************************************************************************
// Function:
//
// Description: 
//
// Parameters:  
//
// Return:			
//***************************************************************************
int BlackjackPresenter::getNumPlayers()
{
	return mcModel.getNumPlayers();
}
//***************************************************************************
// Function:
//
// Description: 
//
// Parameters:  
//
// Return:			
//***************************************************************************
std::string BlackjackPresenter::getName()
{
	return mcModel.getName();
}
//***************************************************************************
// Function:
//
// Description: 
//
// Parameters:  
//
// Return:			
//***************************************************************************
void BlackjackPresenter::setName(std::string name, int index)
{
	mcModel.setPlayerName(name, index);
}
//***************************************************************************
// Function:
//
// Description: 
//
// Parameters:  
//
// Return:			
//***************************************************************************
void BlackjackPresenter::setPlayerType(std::string stratType, int index)
{
	mcModel.setPlayerType(stratType, index);
}
//***************************************************************************
// Function:
//
// Description: 
//
// Parameters:  
//
// Return:			
//***************************************************************************
void BlackjackPresenter::stand()
{
	mcModel.stand();
}
//***************************************************************************
// Function:
//
// Description: 
//
// Parameters:  
//
// Return:			
//***************************************************************************
bool BlackjackPresenter::bet(long long amount)
{
	return mcModel.makeBet(Money (amount, Currency::USD));
}
//***************************************************************************
// Function:
//
// Description: 
//
// Parameters:  
//
// Return:			
//***************************************************************************
void BlackjackPresenter::split()
{
	mcModel.split();
}
//***************************************************************************
// Function:
//
// Description: 
//
// Parameters:  
//
// Return:			
//***************************************************************************
void BlackjackPresenter::draw()
{
	mcModel.drawCard();
}
//***************************************************************************
// Function:
//
// Description: 
//
// Parameters:  
//
// Return:			
//***************************************************************************
void BlackjackPresenter::makeMove()
{
	mcModel.makeMove();
}
//***************************************************************************
// Function:
//
// Description: 
//
// Parameters:  
//
// Return:			
//***************************************************************************
bool BlackjackPresenter::isHuman()
{
	return mcModel.isHuman();
}
//***************************************************************************
// Function:
//
// Description: 
//
// Parameters:  
//
// Return:			
//***************************************************************************
bool BlackjackPresenter::canSplit()
{
	return mcModel.canSplit();
}
//***************************************************************************
// Function:
//
// Description: 
//
// Parameters:  
//
// Return:			
//***************************************************************************
bool BlackjackPresenter::isBetTime()
{
	return mcModel.isBetTime();
}

//***************************************************************************
// Function:
//
// Description: 
//
// Parameters:  
//
// Return:			
//***************************************************************************
bool BlackjackPresenter::lastUnder()
{
	return mcModel.lastUnder();
}
//***************************************************************************
// Function:
//
// Description: 
//
// Parameters:  
//
// Return:			
//***************************************************************************
void BlackjackPresenter::updateView()
{
	mpcView->render();
}
//***************************************************************************
// Function:
//
// Description: 
//
// Parameters:  
//
// Return:			
//***************************************************************************
void BlackjackPresenter::doCPUMoves()
{
	mcModel.doCPUMoves();
}
//***************************************************************************
// Function:
//
// Description: 
//
// Parameters:  
//
// Return:			
//***************************************************************************
void BlackjackPresenter::doCPUBets()
{
	mcModel.doCPUBets();
}
//***************************************************************************
// Function:
//
// Description: 
//
// Parameters:  
//
// Return:			
//***************************************************************************
std::string BlackjackPresenter::getName(int index)
{
	return mcModel.getName(index);
}

long long BlackjackPresenter::getBalance(int index)
{
	return mcModel.getBalance(index);
}

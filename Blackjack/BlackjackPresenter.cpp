//***************************************************************************
// File name:  BlackjackPresenter.cpp
// Author:     John, Julian, Kitt, Erin
// Date:       5/7/2021
// Class:      CS485
// Assignment: Blackjack
// Purpose:    Defines the class declared in BlackjackPresenther.h
//***************************************************************************

#include "BlackjackPresenter.h"
#include "Status.h"

//***************************************************************************
// Function:		BlackjackPresenter
//
// Description: The default constructor for BlackjackPresenter
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
BlackjackPresenter::BlackjackPresenter(IBlackjackView* pcView, int numPlayers, 
	int numDecks) : mcModel (numPlayers, numDecks)
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
bool BlackjackPresenter::newGame(int players)
{
	return mcModel.newGame(players);
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
bool BlackjackPresenter::newGame()
{
	return mcModel.newGame();
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
// Function:		endRound
//
// Description: calls next round
//
// Parameters:  none
//
// Return:			none
//***************************************************************************
std::vector<Status> BlackjackPresenter::endRound(){
  return mcModel.nextRound();
}

//***************************************************************************
// Function:		roundOngoing
//
// Description: Determines whether the current round is still in progress
//
// Parameters:  none
//
// Return:			true if the current round is still in progress, otherwise false
//***************************************************************************
bool BlackjackPresenter::roundOngoing(){
  return !mcModel.roundDone();
}

//***************************************************************************
// Function:    result
//
// Description: returns the result of the current player's turn
//
// Parameters:  None
//
// Return:			the status of the current player
//***************************************************************************
Status BlackjackPresenter::result()
{
	return mcModel.resultCurrentPlayer();
}

//***************************************************************************
// Function:    getBalance
//
// Description: gets the balance of the current player's bank
//
// Parameters:  none
//
// Return:			the balance in the current player's bank
//***************************************************************************
long long BlackjackPresenter::getBalance()
{
	return mcModel.getBalance();
}

//***************************************************************************
// Function:    getCurrentPlayerHand
//
// Description: returns a vector of strings representing the cards in the 
//              current player's hand
//
// Parameters:  None
//
// Return:			a vector of strings representing the cards in the current
//              player's hand
//***************************************************************************
std::vector<std::string> BlackjackPresenter::getCurrentPlayerHand()
{
	return mcModel.getCurrentPlayerHand();
}

//***************************************************************************
// Function:    getAllCards
//
// Description: returns a vector of vectors of strings representing all the 
//              cards in all the player's hands
//
// Parameters:  None
//
// Return:			a vector of vectors of strings representing all the cards in all
//              the player's hands
//***************************************************************************
std::vector<std::vector<std::string>> BlackjackPresenter::getAllCards()
{
	return mcModel.getAllCards();
}

//***************************************************************************
// Function:    getDealerCards
//
// Description: returns a vector of strings representing the cards in the 
//              dealer's hand
//
// Parameters:  None
//
// Return:			a vector of strings representing the cards in the dealer's hand
//***************************************************************************
std::vector<std::string> BlackjackPresenter::getDealerCards()
{
	return mcModel.getDealerCards();
}

//***************************************************************************
// Function:    getAllCurrentPlayerHands
//
// Description: returns a vector of strings representing all the cards in all
//              of the current player's hands
//
// Parameters:  None
//
// Return:			a vector of strings representing all the cards in all of the 
//              current player's hands
//***************************************************************************
std::vector<std::string> BlackjackPresenter::getAllCurrentPlayerHands(){
  return mcModel.getAllCurrentPlayerHands();
}

//***************************************************************************
// Function:    getNumPlayers
//
// Description: returns the number of players
//
// Parameters:  None
//
// Return:			the number of players
//***************************************************************************
int BlackjackPresenter::getNumPlayers()
{
	return mcModel.getNumPlayers();
}

//***************************************************************************
// Function:    getName
//
// Description: returns the current player's name
//
// Parameters:  None
//
// Return:			the current player's name
//***************************************************************************
std::string BlackjackPresenter::getName()
{
	return mcModel.getName();
}

//***************************************************************************
// Function:    setName
//
// Description: sets the name of the player at the specified index to the
//              specified string
//
// Parameters:  name  - the name to which the player's name is to be set
//              index - the index of the player whose name is to be set
//
// Return:			Noen
//***************************************************************************
void BlackjackPresenter::setName(std::string name, int index)
{
	mcModel.setPlayerName(name, index);
}

//***************************************************************************
// Function:    setPlayerType
//
// Description: sets the strategy of the player at the specified index to the 
//              specified type
//
// Parameters:  stratType - the type of strategy that the player's strategy is
//                          to be set to
//              index     - the index of the player whose strategy is to be set
//
// Return:			None
//***************************************************************************
void BlackjackPresenter::setPlayerType(std::string stratType, int index)
{
	mcModel.setPlayerType(stratType, index);
}

//***************************************************************************
// Function:    listMoveStratTypes 
//
// Description: returns a vector of strings representing the possible move 
//              strategies
//
// Parameters:  None
//
// Return:			a vector of strings representing the possible move strategies
//***************************************************************************
std::vector<std::string> BlackjackPresenter::listMoveStratTypes(){
  return mcModel.getTypeList();
}

//***************************************************************************
// Function:    stand    
//
// Description: called when the current player stands
//
// Parameters:  None
//
// Return:			None
//***************************************************************************
void BlackjackPresenter::stand()
{
	mcModel.stand();
}

//***************************************************************************
// Function:    bet
//
// Description: called when the current player bets
//
// Parameters:  amount - the amount of money the player bet
//
// Return:			true if the player's bet was valid, otherwise false
//***************************************************************************
bool BlackjackPresenter::bet(long long amount)
{
	return mcModel.makeBet(Money (amount, Currency::USD));
}

//***************************************************************************
// Function:    split
//
// Description: called when the current player splits
//
// Parameters:  None
//
// Return:			None
//***************************************************************************
void BlackjackPresenter::split()
{
	mcModel.split();
}

//***************************************************************************
// Function:    draw
//
// Description: called when the current player draws a card
//
// Parameters:  None
//
// Return:			None
//***************************************************************************
void BlackjackPresenter::draw()
{
	mcModel.drawCard();
}

//***************************************************************************
// Function:    makeMove
//
// Description: determines the current player's move
//
// Parameters:  None
//
// Return:			None
//***************************************************************************
void BlackjackPresenter::makeMove()
{
	mcModel.makeMove();
}

//***************************************************************************
// Function:    isHuman
//
// Description: returns true if the current player is human, othwerise false
//
// Parameters:  None
//
// Return:			true if the current player is human, otherwise false
//***************************************************************************
bool BlackjackPresenter::isHuman()
{
	return mcModel.isHuman();
}
//***************************************************************************
// Function:    isHuman
//
// Description: determines if the player at the specified index is human
//
// Parameters:  index - the index of the player in question
//
// Return:			true if the player at the specified index is human, otherwise
//              false
//***************************************************************************
bool BlackjackPresenter::isHuman(int index)
{
	return mcModel.isHuman(index);
}

//***************************************************************************
// Function:    canSplit
//
// Description: returns true if the current player can split their hand
//
// Parameters:  None
//
// Return:			true if the current player can split their hand, otherwise false
//***************************************************************************
bool BlackjackPresenter::canSplit()
{
	return mcModel.canSplit();
}

//***************************************************************************
// Function:    isBetTime
//
// Description: returns true if the current player is able to make a bet at 
//              this time
//
// Parameters:  None
//
// Return:			true if the current player is able to make a bet at this time, 
//              otherwise false
//***************************************************************************
bool BlackjackPresenter::isBetTime()
{
	return mcModel.isBetTime();
}

//***************************************************************************
// Function:    updateView
//
// Description: rerenders the view
//
// Parameters:  None
//
// Return:			None
//***************************************************************************
void BlackjackPresenter::updateView()
{
	mpcView->render();
}

//***************************************************************************
// Function:    doCPUMoves
//
// Description: forces all of the AI players to make their moves
//
// Parameters:  None
//
// Return:			None
//***************************************************************************
void BlackjackPresenter::doCPUMoves()
{
	mcModel.doCPUMoves();
}

//***************************************************************************
// Function:    DoCPUBets
//
// Description: all the cpu players place their bets
//
// Parameters:  None  
//
// Return:			None
//***************************************************************************
void BlackjackPresenter::doCPUBets()
{
	mcModel.doCPUBets();
}

//***************************************************************************
// Function:    getCurrentPlayer
//
// Description: returns the index of the current player
//
// Parameters:  None
//
// Return:			The index of the current player
//***************************************************************************
int BlackjackPresenter::getCurrentPlayer()
{
	return mcModel.getCurrentPlayer();
}

//***************************************************************************
// Function:    getName
//
// Description: gets the name of the player at the specified index
//
// Parameters:  index - the index of the player whose name is to be retrieved
//
// Return:			the name of the player at the specified index
//***************************************************************************
std::string BlackjackPresenter::getName(int index)
{
	return mcModel.getName(index);
}

//***************************************************************************
// Function:    getBalance
//
// Description: returns the bank balance of the player at the specified index
//
// Parameters:  index - the index of the player whose balance is to be 
//                      retrieved
//
// Return:			the balance of the player at the specified index
//***************************************************************************
long long BlackjackPresenter::getBalance(int index)
{
	return mcModel.getBalance(index);
}

//***************************************************************************
// Function:    setBalance
//
// Description: sets the balance of the player at the specified index to the 
//              specified amount
//
// Parameters:  amount - the new balance of the player
//              index  - the index of the player whose balance is to be set
//
// Return:			None
//***************************************************************************
void BlackjackPresenter::setBalance(long long amount, int index)
{
	mcModel.setPlayerBalance (amount, index);
}

//***************************************************************************
// Function:    setBet
//
// Description: sets the bet of the player at the specified index to the 
//              specified amount
//
// Parameters:  amount - the new bet of the player
//              index  - the index of the player whose bet is to be set
//
// Return:			None
//***************************************************************************
void BlackjackPresenter::setBet(long long amount, int index)
{
	mcModel.setPlayerBet(amount, index);
}

//***************************************************************************
// Function:    getBet
//
// Description: returns the bet of the player at the specified index
//
// Parameters:  index - the index of the player whose bet is to be retrieved
//
// Return:			the bet of the player at the specified index
//***************************************************************************
long long BlackjackPresenter::getBet(int index)
{
	return mcModel.getPlayerBet(index);
}

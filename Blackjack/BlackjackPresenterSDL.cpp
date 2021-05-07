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

//***************************************************************************
// Function:		BlackjackPresenterSDL
//
// Description: The default constructor for BlackjackPresenterSDL
//
// Parameters:  None
//
// Return:			None
//***************************************************************************
BlackjackPresenterSDL::BlackjackPresenterSDL ()
{

}

//***************************************************************************
// Function:		BlackjackPresenterSDL
//
// Description: Assigns pcView to mpcView
//
// Parameters:  pcView - pointer to view
//
// Return:			None
//***************************************************************************
BlackjackPresenterSDL::BlackjackPresenterSDL (IBlackjackView* pcView)
{
	mpcView = pcView;
}

//***************************************************************************
// Function:		BlackjackPresenterSDL
//
// Description: Assigns pcView to mpcView and passes in parameters for model
//
// Parameters:  pcView		 - pointer to view
//							numPlayers - number of players
//							numDecks	 - number of decks
//
// Return:			None		
//***************************************************************************
BlackjackPresenterSDL::BlackjackPresenterSDL (IBlackjackView* pcView, int numPlayers, int numDecks)
	: mcModel (numPlayers, numDecks)
{
	mpcView = pcView;
}

//***************************************************************************
// Function:		BlackjackPresenterSDL
//
// Description: Deletes the view
//
// Parameters:  None
//
// Return:			None
//***************************************************************************
BlackjackPresenterSDL::~BlackjackPresenterSDL ()
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
bool BlackjackPresenterSDL::newGame (int players)
{
	mcModel.newGame (players);
	
	return true;
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
bool BlackjackPresenterSDL::newGame()
{
	mcModel.newGame();

	return true;
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
void BlackjackPresenterSDL::nextRound ()
{
	mcModel.nextRound ();
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
std::vector<Status> BlackjackPresenterSDL::endRound()
{
	return mcModel.result();
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
bool BlackjackPresenterSDL::roundOngoing()
{
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
Status BlackjackPresenterSDL::result ()
{
	return mcModel.resultCurrentPlayer ();
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
long long BlackjackPresenterSDL::getBalance ()
{
	return mcModel.getBalance ();
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
std::vector<std::string> BlackjackPresenterSDL::getCurrentPlayerHand ()
{
	return mcModel.getCurrentPlayerHand ();
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
std::vector<std::vector<std::string>> BlackjackPresenterSDL::getAllCards ()
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
std::vector<std::string> BlackjackPresenterSDL::getDealerCards ()
{
	return mcModel.getDealerCards ();
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
std::vector<std::string> BlackjackPresenterSDL::getAllCurrentPlayerHands()
{
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
int BlackjackPresenterSDL::getNumPlayers ()
{
	return mcModel.getNumPlayers ();
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
std::string BlackjackPresenterSDL::getName ()
{
	return mcModel.getName ();
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
void BlackjackPresenterSDL::setName (std::string name, int index)
{
	mcModel.setPlayerName (name, index);
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
void BlackjackPresenterSDL::setPlayerType (std::string stratType, int index)
{
	mcModel.setPlayerType (stratType, index);
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
std::vector<std::string> BlackjackPresenterSDL::listMoveStratTypes()
{
	return std::vector<std::string>();
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
std::string BlackjackPresenterSDL::getName(int index)
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
long long BlackjackPresenterSDL::getBalance(int index)
{
	return mcModel.getBalance(index);
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
void BlackjackPresenterSDL::setBet(long long amount, int index)
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
long long BlackjackPresenterSDL::getBet(int index)
{
	return mcModel.getPlayerBet(index);
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
void BlackjackPresenterSDL::stand ()
{
	mcModel.stand ();
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
bool BlackjackPresenterSDL::bet (long long amount)
{
	return mcModel.makeBet(Money(amount, Currency::USD));;
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
void BlackjackPresenterSDL::setBalance(long long amount, int index)
{
	mcModel.setPlayerBalance(amount, index);
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
void BlackjackPresenterSDL::split ()
{
	mcModel.split ();
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
void BlackjackPresenterSDL::draw ()
{
	mcModel.drawCard ();
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
void BlackjackPresenterSDL::makeMove ()
{
	mcModel.makeMove ();
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
bool BlackjackPresenterSDL::isHuman ()
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
bool BlackjackPresenterSDL::isHuman(int index)
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
bool BlackjackPresenterSDL::canSplit ()
{
	return mcModel.canSplit ();
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
bool BlackjackPresenterSDL::isBetTime()
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
void BlackjackPresenterSDL::updateView ()
{
	mpcView->render ();
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
void BlackjackPresenterSDL::doCPUMoves()
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
void BlackjackPresenterSDL::doCPUBets()
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
int BlackjackPresenterSDL::getCurrentPlayer()
{
	return mcModel.getCurrentPlayer();
}


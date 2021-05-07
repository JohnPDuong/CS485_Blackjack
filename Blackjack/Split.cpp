//***************************************************************************
// File name:  Split.cpp
// Author:     Kitt Oster
// Date:       5/2/2021
// Class:      CS485
// Assignment: Blackjack
// Purpose:    implement split command
//***************************************************************************

#include "Split.h"

//***************************************************************************
// Function:    execute
//
// Description: splits the player's hand into two
//
// Parameters:  cTableDeck - the deck on the table
//              cPlayer    - the player that is attempting to split
//
// Return:			true if the player can split, otherwise false
//***************************************************************************
bool Split::execute(Deck& cTableDeck, Player& cPlayer){
  return cPlayer.trySplit();
}

//***************************************************************************
// Function:    execute
//
// Description: splits the player's hand into two
//
// Parameters:  cTableDeck  - the deck the card is to be pulled from
//              cPlayerHand - the hand to be split
//
// Return:			true
//***************************************************************************
bool Split::execute(Deck& cTableDeck, Hand& cPlayerHand){
  return true;//this should never be used really but we need the function in hand.
}

//***************************************************************************
// Function:    moveName
//
// Description: returns a string representing the name of the move 
//
// Parameters:  None
//
// Return:			"Split"
//***************************************************************************
std::string Split::moveName(){
  return "Split";
}

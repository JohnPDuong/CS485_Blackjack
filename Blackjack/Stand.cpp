//***************************************************************************
// File name:  Stand.cpp
// Author:     Kitt Oster
// Date:       5/2/2021
// Class:      CS485
// Assignment: Blackjack
// Purpose:    implement stand command
//***************************************************************************

#include "Stand.h"

//***************************************************************************
// Function:    execute
//
// Description: Allows the player to stop drawing cards
//
// Parameters:  cTableDeck - the deck on the table
//              cPlayer    - the player that is standing
//
// Return:			true
//***************************************************************************
bool Stand::execute(Deck& cTableDeck, Player& cPlayer){
  return true;
}
//***************************************************************************
// Function:    execute
//
// Description: Allows the player to stop drawing cards
//
// Parameters:  cTableDeck  - the deck on the table
//              cPlayerHand - the current hand of the player that is standing
//
// Return:			true
//***************************************************************************
bool Stand::execute(Deck& cTableDeck, Hand& cPlayerHand){
  return true;
}

//***************************************************************************
// Function:    moveName
//
// Description: returns a string representing the name of the move 
//
// Parameters:  None
//
// Return:			"Stand"
//***************************************************************************
std::string Stand::moveName(){
  return "Stand";
}

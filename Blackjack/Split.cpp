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
// Function:
//
// Description: 
//
// Parameters:  
//
// Return:			
//***************************************************************************
bool Split::execute(Deck& cTableDeck, Player& cPlayer){
  return cPlayer.trySplit();
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
bool Split::execute(Deck& cTableDeck, Hand& cPlayerHand){
  return true;//this should never be used really but we need the function in hand.
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
std::string Split::moveName(){
  return "Split";
}

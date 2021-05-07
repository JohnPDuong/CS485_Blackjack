//***************************************************************************
// File name:  Draw.cpp
// Author:     Kitt Oster
// Date:       5/2/2021
// Class:      CS485
// Assignment: Blackjack
// Purpose:    implement draw command
//***************************************************************************

#include "Draw.h"

//***************************************************************************
// Function:    execute
//
// Description: draws a card 
//
// Parameters:  cTableDeck - the deck the card is to be pulled from
//              cPlayer    - the player that is drawing the card
//
// Return:			true
//***************************************************************************
bool Draw::execute(Deck& cTableDeck, Player& cPlayer){
  Card cTemp = cTableDeck.draw();
  cTemp.flip();
  cPlayer.receiveCard(cTemp);
  return true;
}

//***************************************************************************
// Function:    execute
//
// Description: draws a card 
//
// Parameters:  cTableDeck  - the deck the card is to be pulled from
//              cPlayerHAnd - the hand that the card is being placed into
//
// Return:			true
//***************************************************************************
bool Draw::execute(Deck& cTableDeck, Hand& cPlayerHand){
  Card cTemp = cTableDeck.draw();
  cTemp.flip();
  cPlayerHand.addCard(cTemp);
  return true;
}

//***************************************************************************
// Function:    moveName
//
// Description: returns a string representing the name of the move 
//
// Parameters:  None
//
// Return:			"Draw"
//***************************************************************************
std::string Draw::moveName(){
  return "Draw";
}

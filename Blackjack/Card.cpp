//***************************************************************************
// File name:  Card.cpp
// Author:     John Duong
// Date:       5/7/2021
// Class:      CS485
// Assignment: Blackjack
// Purpose:    Function implementations for Card class
//***************************************************************************

#include "Card.h"

//***************************************************************************
// Constructor:	Card
//
// Description: Initializes member variables
//
// Parameters:  eSuit						 - enum for suit of card
//							eValue					 - enum for value of card
//							mbIsGlobalFaceUp - whether the values of the card is shown
//
// Return:			None
//***************************************************************************
Card::Card (Suit eSuit, Value eValue)
{
	const bool FACE_DOWN = false;

	meSuit = eSuit;
	meValue = eValue;
	mbIsGlobalFaceUp = FACE_DOWN;
}
//***************************************************************************
// Function:		isFaceUp
//
// Description: Returns true if card is face up, false otherwise
//
// Parameters:  None
//
// Return:			True if face up, false otherwise
//***************************************************************************
bool Card::isFaceUp ()
{
	return mbIsGlobalFaceUp;
}
//***************************************************************************
// Function:		flip
//
// Description: Toggle mbIsGlobalFaceUp
//
// Parameters:  None
//
// Return:			None
//***************************************************************************
void Card::flip ()
{
	mbIsGlobalFaceUp = !mbIsGlobalFaceUp;
}
//***************************************************************************
// Function:		getSuit
//
// Description: returns suit of card
//
// Parameters:  None
//
// Return:			enum suit of card
//***************************************************************************
Suit Card::getSuit ()
{
	return meSuit;
}
//***************************************************************************
// Function:		getValue
//
// Description: return value of card
//
// Parameters:  None
//
// Return:			enum value of card
//***************************************************************************
Value Card::getValue ()
{
	return meValue;
}
int Card::getInt()
{

	return 0;
}
//***************************************************************************
// Function:		getValue
//
// Description: return value of card
//
// Parameters:  None
//
// Return:			enum value of card
//***************************************************************************
Value Card::getValue()
{
	return meValue;
}
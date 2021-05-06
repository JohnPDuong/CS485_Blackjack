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
// Destructor:  Card
//
// Description: None
//
// Parameters:  None
//
// Return:			None
//***************************************************************************
Card::~Card()
{
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
//***************************************************************************
// Function:		getInt
//
// Description: return value of card
//
// Parameters:  None
//
// Return:			int value of card
//***************************************************************************
int Card::getInt()
{
	int retVal;

	switch (meValue)
	{
		case Value::Ace:
			retVal = 11;
			break;
		case Value::Two:
			retVal = 2;
			break;
		case Value::Three:
			retVal = 3;
			break;
		case Value::Four:
			retVal = 4;
			break;
		case Value::Five:
			retVal = 5;
			break;
		case Value::Six:
			retVal = 6;
			break;
		case Value::Seven:
			retVal = 7;
			break;
		case Value::Eight:
			retVal = 8;
			break;
		case Value::Nine:
			retVal = 9;
			break;
		default: //10, Jack, Queen, King all have same value
			retVal = 10;
			break;
	}

	return retVal;
}
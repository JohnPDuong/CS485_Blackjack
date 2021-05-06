//***************************************************************************
// File name:  
// Author:     
// Date:       5/7/2021
// Class:      CS485
// Assignment: Blackjack
// Purpose:    
//***************************************************************************

#include "Hand.h"

//***************************************************************************
// Constructor: Hand
//
// Description: None
//
// Parameters:  None
//
// Return:			None
//***************************************************************************
Hand::Hand ()
{
}
//***************************************************************************
// Destructor:  Hand
//
// Description: None
//
// Parameters:  None
//
// Return:			None
//***************************************************************************
Hand::~Hand()
{
}
//***************************************************************************
// Function:		addCard
//
// Description: Adds a card to the hand
//
// Parameters:  cCard - card class object
//
// Return:			None
//***************************************************************************
void Hand::addCard (Card cCard)
{
	mcCards.push_back (cCard);
}
//***************************************************************************
// Function:		getHandValue
//
// Description: returns the hand value, subtracts 10 if there is an Ace and
//							sum is greater than 21
//
// Parameters:  None
//
// Return:			Sum of the hand
//***************************************************************************
int Hand::getHandValue ()
{
	const int ACE_BUST_DEDUCTION = 10;

	int sum = 0;

	for (int i = 0; i < mcCards.size (); i++)
	{
		sum += (int) mcCards[i].getInt ();
	}

	if (sum > (int) Status::Blackjack)
	{
		for (int i = 0; i < mcCards.size (); i++)
		{
			if (Value::Ace == mcCards[i].getValue () &&
					sum > (int) Status::Blackjack)
			{
				//If given 2 or more aces, subtract 10 
				//as long as sum is over 21

				sum -= ACE_BUST_DEDUCTION;
			}
		}
	}

	return sum;
}
//***************************************************************************
// Function:		getFaceUpValue
//
// Description: returns the hand value of all cards that are face up
//
// Parameters:  None
//
// Return:			the sum of all face up cards
//***************************************************************************
int Hand::getFaceUpValue ()
{
	int sum = 0;

	for (int i = 0; i < mcCards.size (); i++)
	{
		if (mcCards[i].isFaceUp ())
		{
			sum += (int) mcCards[i].getValue ();
		}
	}

	return sum;
}
//***************************************************************************
// Function:		getFaceDownValue
//
// Description: returns the sum of all face down cards
//
// Parameters:  None
//
// Return:			the sum of all face down cards
//***************************************************************************
int Hand::getFaceDownValue ()
{
	int sum = 0;

	for (int i = 0; i < mcCards.size (); i++)
	{
		if (!mcCards[i].isFaceUp ())
		{
			sum += (int) mcCards[i].getValue ();
		}
	}

	return sum;
}
//***************************************************************************
// Function:		getFaceUpCards
//
// Description: Returns a vector of face up cards in hand
//
// Parameters:  None
//
// Return:			a vector of face up cards in hand
//***************************************************************************
std::vector<Card> Hand::getFaceUpCards ()
{
	std::vector<Card> cRetVal;

	for (int i = 0; i < mcCards.size (); i++)
	{
		if (mcCards[i].isFaceUp ())
		{
			cRetVal.push_back (mcCards[i]);
		}
	}

	return cRetVal;
}
//***************************************************************************
// Function:		getFaceDownCards
//
// Description: Returns a vector of face down cards in hand
//
// Parameters:  None
//
// Return:			a vector of face down cards in hand
//***************************************************************************
std::vector<Card> Hand::getFaceDownCards()
{
	std::vector<Card> cRetVal;

	for (int i = 0; i < mcCards.size(); i++)
	{
		if (!mcCards[i].isFaceUp())
		{
			cRetVal.push_back(mcCards[i]);
		}
	}

	return cRetVal;
}
//***************************************************************************
// Function:		getHand
//
// Description: returns the hand
//
// Parameters:  None
//
// Return:			vector of cards in hand
//***************************************************************************
std::vector<Card> Hand::getHand ()
{
	return mcCards;
}
//***************************************************************************
// Function:		canSplit
//
// Description: Checks to see if the two cards in hand have the same
//							denomination
//
// Parameters:  None
//
// Return:			True if same card denomination, false otherwise
//***************************************************************************
bool Hand::canSplit()
{
	return mcCards[0].getValue() == mcCards[1].getValue();
}
//***************************************************************************
// Function:		split
//
// Description: Returns the second card in hand
//
// Parameters:  None
//
// Return:			Card object
//***************************************************************************
Card Hand::split()
{
	Card cCard = mcCards[1];

	mcCards.pop_back();

	return cCard;
}

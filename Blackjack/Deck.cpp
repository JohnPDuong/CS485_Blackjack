//***************************************************************************
// File name:  
// Author:     
// Date:       5/7/2021
// Class:      CS485
// Assignment: Blackjack
// Purpose:    
//***************************************************************************

#include "Deck.h"

//***************************************************************************
// Constructor: Deck
//
// Description: Initializes mNumDecks to 0
//
// Parameters:  None
//
// Return:			None
//***************************************************************************
Deck::Deck ()
{
	mNumDecks = 0;
}
//***************************************************************************
// Function:		Deck
//
// Description: Initializes mNumDecks to numDecks
//
// Parameters:  None
//
// Return:			None
//***************************************************************************
Deck::Deck (int numDecks)
{
	mNumDecks = numDecks;
}
//***************************************************************************
// Function:		shuffle
//
// Description: Shuffles mcCards
//
// Parameters:  None
//
// Return:			None
//***************************************************************************
void Deck::shuffle ()
{
	unsigned int seed = (unsigned int)std::chrono::system_clock::
											now ().time_since_epoch ().count ();

	std::shuffle (macCards.begin (), macCards.end (), 
								std::default_random_engine (seed));
}
//***************************************************************************
// Function:		fillShuffle
//
// Description: Clears the deck, repopulates and shuffles the deck
//
// Parameters:  None
//
// Return:			None
//***************************************************************************
void Deck::fillShuffle()
{
	while(macCards.size() > 0)
	{
		macCards.pop_back ();
	}

	populate ();
	shuffle ();
}

int Deck::numCardsRemaining(){
  return macCards.size();
}

//***************************************************************************
// Function:		draw
//
// Description: Returns a card object from the top of the deck
//
// Parameters:  None
//
// Return:			A card object from the top of the dock
//***************************************************************************
Card Deck::draw ()
{
	Card cRetVal = macCards.front ();

	macCards.erase (macCards.begin ());

	return cRetVal;
}
//***************************************************************************
// Function:		populate
//
// Description: Generates all suits and values of the cards multiplied by
//							the number of decks
//
// Parameters:  None
//
// Return:			None
//***************************************************************************
void Deck::populate ()
{
	for (int deck = 0; deck < mNumDecks; deck++)
	{
		for (int suit = 0; suit < (int) Suit::Count; suit++)
		{
			for (int value = 0; value < (int) Value::Count; value++)
			{
				macCards.push_back (Card ((Suit) suit, (Value) value));
			}
		}
	}
}

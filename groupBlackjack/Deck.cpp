#include "Deck.h"
//***************************************************************************
// File name:  
// Author:     
// Date:       5/7/2021
// Class:      CS485
// Assignment: Blackjack
// Purpose:    
//***************************************************************************

Deck::Deck()
{
	mNumDecks = 0;
}

Deck::Deck(int numDecks)
{
	mNumDecks = numDecks;
}

void Deck::shuffle()
{
	unsigned int seed = std::chrono::system_clock::
											now().time_since_epoch().count();

	std::shuffle (mCards.begin(), mCards.end(), 
								std::default_random_engine(seed));
}

void Deck::fillShuffle()
{
	for (int i = 0; i < mCards.size(); i++)
	{
		mCards.pop_back();
	}

	populate();
	shuffle();
}

Card Deck::draw()
{
	Card cRetVal = mCards.front();

	mCards.erase (mCards.begin());

	return cRetVal;
}

void Deck::populate()
{
	for (int deck = 0; deck < mNumDecks; deck++)
	{
		for (int suit = 0; suit < (int)Suit::Count; suit++)
		{
			for (int value = 0; value < (int)Value::Count; value++)
			{
				mCards.push_back (Card ((Suit) suit, (Value) value));
			}
		}
	}
}

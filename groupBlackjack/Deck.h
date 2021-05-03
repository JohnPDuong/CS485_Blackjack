//***************************************************************************
// File name:  
// Author:     
// Date:       5/7/2021
// Class:      CS485
// Assignment: Blackjack
// Purpose:    
//***************************************************************************
#pragma once
#include <vector>
#include "Card.h"

#include <algorithm>
#include <random>
#include <chrono>

class Deck
{
	public:
		Deck ();
		Deck (int numDecks);

		void shuffle ();
		void fillShuffle ();

		Card draw ();
//		Card draw ();

	private:
		int mNumDecks;
		std::vector <Card> mCards;

		void populate();
};

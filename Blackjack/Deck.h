//***************************************************************************
// File name:  Deck.h
// Author:     John, Julian, Kitt, Erin
// Date:       5/7/2021
// Class:      CS485
// Assignment: Blackjack
// Purpose:    Declares a class to represent a deck of cards
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
  int numCardsRemaining ();

		Card draw ();

	private:
		int mNumDecks;
		std::vector <Card> macCards;

		void populate ();
};

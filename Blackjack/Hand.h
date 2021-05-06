//***************************************************************************
// File name:  Hand.h
// Author:     John Duong
// Date:       5/7/2021
// Class:      CS485
// Assignment: Blackjack
// Purpose:    Function prototypes and member variables for Hand class
//***************************************************************************
#pragma once

#include "Card.h"
#include <vector>
#include "Suit.h"
#include "Value.h"
#include "Status.h"

class Hand
{
	public:
		Hand ();

		void addCard (Card cCard);

		int getHandValue ();
		int getFaceUpValue ();
		int getFaceDownValue ();

		std::vector<Card> getFaceUpCards ();
		std::vector<Card> getFaceDownCards();
		std::vector<Card> getHand ();

		bool canSplit ();
		Card split ();

	private:
		std::vector<Card> mcCards;

};
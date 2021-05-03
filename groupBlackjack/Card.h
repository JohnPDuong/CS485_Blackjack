//***************************************************************************
// File name:  Card.h
// Author:     John Duong
// Date:       5/7/2021
// Class:      CS485
// Assignment: Blackjack
// Purpose:    Function prototypes and member variables for Card class
//***************************************************************************
#pragma once
#include "Suit.h"
#include "Value.h"

class Card
{
	public:
		Card (Suit eSuit, Value eValue);

		bool isFaceUp ();
		void flip ();

		Suit getSuit ();
		Value getValue ();

	private:
		Suit meSuit;
		Value meValue;
		bool mbIsGlobalFaceUp;
};
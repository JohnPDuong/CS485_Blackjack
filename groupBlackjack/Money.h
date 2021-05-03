//***************************************************************************
// File name:  Money.h
// Author:     John Duong, Julian Bunch
// Date:       5/7/2021
// Class:      CS485
// Assignment: Blackjack
// Purpose:    Function prototypes and member variables for Money class
//***************************************************************************
#pragma once

#include <istream>

class Money {
	public:
		Money ();
		Money (long long amount);
		Money (const Money &rcCurrency);
		virtual ~Money ();

		Money &operator= (const Money &rcCurrency);

		void setAmount (long long amount);
		long long getAmount ();

		void operator= (long long amount);

		friend Money operator* (const Money &rcCurrency, double fAmount);
		friend Money operator+ (const Money &rcCurrency, const Money &rcOtherCurrency);
		friend Money operator- (const Money &rcCurrency, const Money &rcOtherCurrency);

		friend Money operator+= (const Money &rcCurrency, const Money &rcOtherCurrency);
		friend Money operator-= (const Money &rcCurrency, const Money &rcOtherCurrency);

		friend bool operator< (const Money &rcCurrency, const Money &rcOtherCurrency);
		friend bool operator> (const Money &rcCurrency, const Money &rcOtherCurrency);

	private:
		long long mAmount;
};

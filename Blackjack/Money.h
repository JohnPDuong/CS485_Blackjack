//***************************************************************************
// File name:  Money.h
// Author:     John Duong, Julian Bunch
// Date:       5/7/2021
// Class:      CS485
// Assignment: Blackjack
// Purpose:    Function prototypes and member variables for Money class
//***************************************************************************
#pragma once

#include <iostream>
#include "Currency.h"
#include "CurrencyMismatchException.h"

class Money {
	public:
		Money ();
		Money (long long amount, Currency type);
		Money (const Money &rcCurrency);
		virtual ~Money ();

		Money &operator= (const Money &rcCurrency);

		void setAmount (long long amount);
		long long getAmount ();

		void operator= (long long amount);

		Currency getCurrency();
		static Currency strToType(std::string type);
		std::string typeToStr(Currency eType);

		friend Money operator* (const Money &rcCurrency, double fAmount);
		friend Money operator+ (const Money &rcCurrency, const Money &rcOtherCurrency);
		friend Money operator- (const Money &rcCurrency, const Money &rcOtherCurrency);

		friend Money operator+= (const Money &rcCurrency, const Money &rcOtherCurrency);
		friend Money operator-= (const Money &rcCurrency, const Money &rcOtherCurrency);

		friend bool operator< (const Money &rcCurrency, const Money &rcOtherCurrency);
		friend bool operator> (const Money &rcCurrency, const Money &rcOtherCurrency);

		void throwMismatchException(const Money &rcMoney) const;

	private:
		long long mAmount;
		Currency meCurrency;
};

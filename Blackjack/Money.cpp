//***************************************************************************
// File name:  Money.cpp
// Author:     John Duong, Julian Bunch
// Date:       5/7/2021
// Class:      CS485
// Assignment: Blackjack
// Purpose:    Function implementations for Money class
//***************************************************************************

#include "Money.h"

//****************************************************************************
// Constructor: Currency
// 
// Description: Initializes mAmount to 0
//
// Paramaters:	None
//
// Returns:			None
//****************************************************************************
Money::Money ()
{
	mAmount = 0;
}
//****************************************************************************
// Constructor: Currency
// 
// Description: Initializes mAmount to amount
//
// Paramaters:	amount - the amount
//
// Returns:			None
//****************************************************************************
Money::Money (long long amount, Currency type)
{
	mAmount = amount;
}
//****************************************************************************
// Copy Constructor: Currency
// 
// Description:			 Copies rcMoney to this Currency object
//
// Paramaters:			 rcMoney - reference to class object Currency
//
// Returns:					 None
//****************************************************************************
Money::Money (const Money &rcMoney)
{
	mAmount = rcMoney.mAmount;
}
//****************************************************************************
// Destructor:	~Currency
// 
// Description:	Deletes Currency object contents
//
// Paramaters:	None
//
// Returns:			None
//****************************************************************************
Money::~Money ()
{
}
//****************************************************************************
// Function:		operator=
// 
// Description: Assigns rcMoney.mAmount to this mAmount
//
// Paramaters:	rcMoney - reference to class object Currency
//
// Returns:			this object
//****************************************************************************
Money &Money::operator= (const Money &rcMoney)
{
	mAmount = rcMoney.mAmount;

	return *this;
}
//****************************************************************************
// Function:		setAmount
// 
// Description: Sets mAmount to amount
//
// Paramaters:	amount - the amount
//
// Returns:			None
//****************************************************************************
void Money::setAmount (long long amount)
{
	mAmount = amount;
}
//****************************************************************************
// Function:		getAmount
// 
// Description: Returns mAmount
//
// Paramaters:	None
//
// Returns:			mAmount - the amount
//****************************************************************************
long long Money::getAmount ()
{
	return mAmount;
}
//****************************************************************************
// Function:		operator=
// 
// Description: Assigns amount to mAmount
//
// Paramaters:	amount	  - the amount
//
// Returns:			None
//****************************************************************************
void Money::operator= (long long amount)
{
	mAmount = amount;
}
//****************************************************************************
// Function:		getCurrency
// 
// Description: Returns meCurrency
//
// Paramaters:	None
//
// Returns:			meCurrency
//****************************************************************************
Currency Money::getCurrency ()
{
	return meCurrency;
}
//****************************************************************************
// Function:		strToType
// 
// Description: Converts a string to currency type and returns the type
//
// Paramaters:	type - the currency type
//
// Returns:			Currency type enum
//****************************************************************************
Currency Money::strToType (std::string type)
{
	Currency eType = static_cast<Currency> (-1);

	if (type == "USD")
	{
		eType = Currency::USD;
	}
	else if (type == "GBP")
	{
		eType = Currency::GBP;
	}
	else if (type == "EUR")
	{
		eType = Currency::EUR;
	}
	else if (type == "YEN")
	{
		eType = Currency::YEN;
	}
	else
	{
		std::cerr << "ERROR IN Currency::strToType ()\n";
	}

	return eType;
}
//****************************************************************************
// Function:		typeToStr
// 
// Description: Converts currency type enum to string
//
// Paramaters:	eType - class enum type
//
// Returns:			string of currency type
//****************************************************************************
std::string Money::typeToStr (Currency eType)
{
	std::string type;

	switch (eType)
	{
		case Currency::USD:
			type = "USD";
			break;
		case Currency::GBP:
			type = "GBP";
			break;
		case Currency::EUR:
			type = "EUR";
			break;
		case Currency::YEN:
			type = "YEN";
			break;
		default:
			std::cerr << "ERROR IN Currency::typeToStr ()\n";
	}

	return type;
}
//****************************************************************************
// Function:		operator*
// 
// Description: Multiplies rcMoney.mAmount by amount
//
// Paramaters:	rcMoney		 - reference to class object Currency
//							amount		 - the amount
//
// Returns:			new Currency object
//****************************************************************************
Money operator* (const Money &rcMoney, double fAmount)
{
	return Money (rcMoney.mAmount * fAmount, rcMoney.meCurrency);
}
//****************************************************************************
// Function:		operator+
// 
// Description: Add rcMoney.mAmount and rcOtherMoney.mAmount
//
// Paramaters:	rcMoney			 - reference to class object Currency
//							rcOtherMoney - reference to other class object Currency
//
// Returns:			new Currency object
//****************************************************************************
Money operator+ (const Money &rcMoney, const Money &rcOtherMoney)
{
	try
	{
		rcMoney.throwMismatchException (rcOtherMoney);
	}
	catch (const std::exception &rcException)
	{
		std::cout << rcException.what () << std::endl;
	}

	return Money (rcMoney.mAmount + rcOtherMoney.mAmount, rcMoney.meCurrency);
}
//****************************************************************************
// Function:		operator-
// 
// Description: Subtract rcMoney.mAmount and rcOtherMoney.mAmount
//
// Paramaters:	rcMoney			 - reference to class object Currency
//							rcOtherMoney - reference to other class object Currency
//
// Returns:			new Currency object
//****************************************************************************
Money operator- (const Money &rcMoney, const Money &rcOtherMoney)
{
	try
	{
		rcMoney.throwMismatchException (rcOtherMoney);
	}
	catch (const std::exception &rcException)
	{
		std::cout << rcException.what () << std::endl;
	}

	return Money (rcMoney.mAmount - rcOtherMoney.mAmount, rcMoney.meCurrency);
}
//****************************************************************************
// Function:		operator+=
// 
// Description: Add rcMoney.mAmount and rcOtherMoney.mAmount
//
// Paramaters:	rcMoney		   - reference to class object Currency
//							rcOtherMoney - reference to other class object Currency
//
// Returns:			new Currency object
//****************************************************************************
Money operator+= (const Money &rcMoney, const Money &rcOtherMoney)
{
	try
	{
		rcMoney.throwMismatchException (rcOtherMoney);
	}
	catch (const std::exception &rcException)
	{
		std::cout << rcException.what () << std::endl;
	}

	return Money (rcMoney.mAmount + rcOtherMoney.mAmount, rcMoney.meCurrency);
}
//****************************************************************************
// Function:		operator-=
// 
// Description: Subtract rcMoney.mAmount and rcOtherMoney.mAmount
//
// Paramaters:	rcMoney			 - reference to class object Currency
//							rcOtherMoney - reference to other class object Currency
//
// Returns:			new Currency object
//****************************************************************************
Money operator-= (const Money &rcMoney, const Money &rcOtherMoney)
{
	try
	{
		rcMoney.throwMismatchException (rcOtherMoney);
	}
	catch (const std::exception &rcException)
	{
		std::cout << rcException.what () << std::endl;
	}

	return Money (rcMoney.mAmount - rcOtherMoney.mAmount, rcMoney.meCurrency);
}
//****************************************************************************
// Function:		operator<
// 
// Description: Compares rcMoney and rcOtherMoney
//
// Paramaters:	rcMoney			 - reference to class Currency object
//							rcOtherMoney - reference to other class Currency object
//
// Returns:			true if cOtherCurrency, false otherwise
//****************************************************************************
bool operator< (const Money &rcMoney, const Money &rcOtherMoney)
{
	try
	{
		rcMoney.throwMismatchException (rcOtherMoney);
	}
	catch (const std::exception &rcException)
	{
		std::cout << rcException.what () << std::endl;
	}

	return rcMoney.mAmount < rcOtherMoney.mAmount;
}
//****************************************************************************
// Function:		operator>
// 
// Description: Compares rcMoney and rcOtherMoney
//
// Paramaters:	rcMoney			 - reference to class Currency object
//							rcOtherMoney - reference to other class Currency object
//
// Returns:			true if cOtherCurrency, false otherwise
//****************************************************************************
bool operator> (const Money &rcMoney, const Money &rcOtherMoney)
{
	try
	{
		rcMoney.throwMismatchException (rcOtherMoney);
	}
	catch (const std::exception &rcException)
	{
		std::cout << rcException.what () << std::endl;
	}

	return rcMoney.mAmount > rcOtherMoney.mAmount;
}
//****************************************************************************
// Function:		throwMismatchException
// 
// Description: throws a currency mismatch error if currencies don't match
//
// Paramaters:	rcMoney - reference to class Money object
//
// Returns:			None
//****************************************************************************
void Money::throwMismatchException (const Money &rcMoney) const
{
	if (rcMoney.meCurrency != meCurrency)
	{
		throw CurrencyMismatchException ();
	}
}
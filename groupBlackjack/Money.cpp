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
Money::Money (long long amount)
{
	mAmount = amount;
}
//****************************************************************************
// Copy Constructor: Currency
// 
// Description:			 Copies rcCurrency to this Currency object
//
// Paramaters:			 rcCurrency - reference to class object Currency
//
// Returns:					 None
//****************************************************************************
Money::Money (const Money &rcCurrency)
{
	mAmount = rcCurrency.mAmount;
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
// Description: Assigns rcCurrency.mAmount to this mAmount
//
// Paramaters:	rcCurrency - reference to class object Currency
//
// Returns:			this object
//****************************************************************************
Money &Money::operator= (const Money &rcCurrency)
{
	mAmount = rcCurrency.mAmount;

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
// Function:		operator*
// 
// Description: Multiplies rcCurrency.mAmount by amount
//
// Paramaters:	rcCurrency - reference to class object Currency
//							amount		 - the amount
//
// Returns:			new Currency object
//****************************************************************************
Money operator* (const Money &rcCurrency, double fAmount)
{
	return Money (rcCurrency.mAmount * fAmount);
}
//****************************************************************************
// Function:		operator+
// 
// Description: Add rcCurrency.mAmount and rcOtherCurrency.mAmount
//
// Paramaters:	rcCurrency		  - reference to class object Currency
//							rcOtherCurrency - reference to other class object Currency
//
// Returns:			new Currency object
//****************************************************************************
Money operator+ (const Money &rcCurrency, const Money &rcOtherCurrency)
{
	return Money (rcCurrency.mAmount * rcOtherCurrency.mAmount);
}
//****************************************************************************
// Function:		operator-
// 
// Description: Subtract rcCurrency.mAmount and rcOtherCurrency.mAmount
//
// Paramaters:	rcCurrency			- reference to class object Currency
//							rcOtherCurrency - reference to other class object Currency
//
// Returns:			new Currency object
//****************************************************************************
Money operator- (const Money &rcCurrency, const Money &rcOtherCurrency)
{
	return Money (rcCurrency.mAmount - rcOtherCurrency.mAmount);
}
//****************************************************************************
// Function:		operator+=
// 
// Description: Add rcCurrency.mAmount and rcOtherCurrency.mAmount
//
// Paramaters:	rcCurrency		  - reference to class object Currency
//							rcOtherCurrency - reference to other class object Currency
//
// Returns:			new Currency object
//****************************************************************************
Money operator+= (const Money &rcCurrency, const Money &rcOtherCurrency)
{
	return Money (rcCurrency.mAmount + rcOtherCurrency.mAmount);
}
//****************************************************************************
// Function:		operator-=
// 
// Description: Subtract rcCurrency.mAmount and rcOtherCurrency.mAmount
//
// Paramaters:	rcCurrency			- reference to class object Currency
//							rcOtherCurrency - reference to other class object Currency
//
// Returns:			new Currency object
//****************************************************************************
Money operator-= (const Money &rcCurrency, const Money &rcOtherCurrency)
{
	return Money (rcCurrency.mAmount - rcOtherCurrency.mAmount);
}
//****************************************************************************
// Function:		operator<
// 
// Description: Compares rcCurrency and rcOtherCurrency
//
// Paramaters:	rcCurrency			- reference to class Currency object
//							rcOtherCurrency - reference to other class Currency object
//
// Returns:			true if cOtherCurrency, false otherwise
//****************************************************************************
bool operator< (const Money &rcCurrency, const Money &rcOtherCurrency)
{
	return rcCurrency.mAmount < rcOtherCurrency.mAmount;
}
//****************************************************************************
// Function:		operator>
// 
// Description: Compares rcCurrency and rcOtherCurrency
//
// Paramaters:	rcCurrency			- reference to class Currency object
//							rcOtherCurrency - reference to other class Currency object
//
// Returns:			true if cOtherCurrency, false otherwise
//****************************************************************************
bool operator> (const Money &rcCurrency, const Money &rcOtherCurrency)
{
	return rcCurrency.mAmount > rcOtherCurrency.mAmount;
}

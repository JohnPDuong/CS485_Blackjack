//****************************************************************************
// File name:	 CurrencyMismatchException.cpp
// Author:		 John Duong and Julian Bunch
// Date:		   04/08/2021
// Class:		   CS 485 - Advanced Object Oriented Programming
// Assignment: 4 - Bank
// Purpose:		 Function definitions for CurrencyMismatchException class
//****************************************************************************
#pragma once

#include <exception>
#include "Money.h"

class CurrencyMismatchException : public std::exception
{
	public:
	CurrencyMismatchException();
	CurrencyMismatchException(const CurrencyMismatchException &rcOther);
	virtual ~CurrencyMismatchException();

	CurrencyMismatchException &operator= (CurrencyMismatchException cOther);

	virtual const char *what() const override;


	private:
	char *mpszMessage = nullptr;
};
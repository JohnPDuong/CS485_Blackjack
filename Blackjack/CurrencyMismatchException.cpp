//****************************************************************************
// File name:	 CurrencyMismatchException.cpp
// Author:		 John Duong and Julian Bunch
// Date:		   04/08/2021
// Class:		   CS 485 - Advanced Object Oriented Programming
// Assignment: 4 - Bank
// Purpose:		 Function definitions for CurrencyMismatchException class
//****************************************************************************
#include "CurrencyMismatchException.h"
#include <iostream>

//****************************************************************************
// Constructor: CurrencyMismatchException
// 
// Description: Initializes the exception
//
// Paramaters:	None
//
// Returns:			None
//****************************************************************************
CurrencyMismatchException::CurrencyMismatchException()
{
  std::string errMessage = "ERROR: Currencies don't match";

  mpszMessage = new char[errMessage.size() + 1];

  strncpy_s(mpszMessage, errMessage.size() + 1, errMessage.c_str(),
    errMessage.size() + 1);
}
//****************************************************************************
// Constructor: CurrencyMismatchException
// 
// Description: Copy constructor
//
// Paramaters:	rcOther - the object to copy
//
// Returns:			None
//****************************************************************************
CurrencyMismatchException::CurrencyMismatchException
(const CurrencyMismatchException &rcOther)
{
  int size;

  if (nullptr != rcOther.mpszMessage)
  {
    size = strlen(rcOther.mpszMessage) + 1;
    mpszMessage = new char[size];

    strncpy_s(mpszMessage, size, rcOther.mpszMessage, size);
  }
}
//****************************************************************************
// Destructor:  CurrencyMismatchException
// 
// Description: Deallocate the what string
//
// Paramaters:	None
//
// Returns:			None
//****************************************************************************
CurrencyMismatchException::~CurrencyMismatchException()
{
  if (nullptr != mpszMessage)
  {
    std::cout << "dtor ";
    std::cout << mpszMessage;
    delete mpszMessage;
    mpszMessage = nullptr;
  }
  std::cout << std::endl;
}
//***************************************************************************
// Function:    operator=
//
// Description: Copy assignment operator
//
// Parameters:  rcOther - the object to copy
//
// Returned:    the updated object
//***************************************************************************
CurrencyMismatchException
&CurrencyMismatchException::operator= (CurrencyMismatchException cOther)
{
  using std::swap;

  std::swap(this->mpszMessage, cOther.mpszMessage);

  return *this;
}
//****************************************************************************
// Function:    what
// 
// Description: Returns the error message
//
// Paramaters:	None
//
// Returns:			Error message
//****************************************************************************
const char *CurrencyMismatchException::what() const
{
  return mpszMessage;
}
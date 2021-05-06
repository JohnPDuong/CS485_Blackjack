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
#include <cstring>
#include <stdlib.h>

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

#ifdef _WIN32
  //the *_s functions are a windows only implementation. Microsoft claims some
  //standard functions are insecure to shackle you to their OS. You can get
  //this preprocessor macro method should make the code portable but you can
  //also get around them entirely with
  //Configuration Properties>>C/C++>>Preprocessor>>Preprocessor Definitions
  //>> _CRT_SECURE_NO_WARNINGS
  strncpy_s(mpszMessage, errMessage.size() + 1, errMessage.c_str(),
    errMessage.size() + 1);
#else
  strncpy(mpszMessage, errMessage.c_str(), errMessage.size() + 1);
#endif
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
    size = (int)strlen(rcOther.mpszMessage) + 1;
    mpszMessage = new char[size];

#ifdef _WIN32
    strncpy_s(mpszMessage, size, rcOther.mpszMessage, size);
#else
    strncpy(mpszMessage, rcOther.mpszMessage, size);
#endif
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
const char *CurrencyMismatchException::what() const noexcept
{
  return mpszMessage;
}

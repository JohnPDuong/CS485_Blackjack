//****************************************************************************
// File name:	 ISDLWidgetClickable.h
// Author:     Chadd Williams
// Date:       3/30/2017
// Class:      CS 485
// Assignment: SDLApp2
// Purpose:    Provider wrapper for SDL
//****************************************************************************
#pragma once
#include "SDLApp.h"
#include <functional>

class ISDLWidgetClickable
{
public:

  // must return true or false to determine
  // if the widget was clicked
  // may optionally call clickEventHandler()
  virtual bool clicked (int x, int y) = 0;
  
  virtual void registerClickEventHandler (
    std::function<void (void)> cFunction)
  { mcClickHandler = cFunction;}

  virtual void clickEventHandler()
  {
    if (nullptr!=mcClickHandler)
    { 
      mcClickHandler ();
    }
  }

private:
  std::function<void (void)>
    mcClickHandler = nullptr;
};
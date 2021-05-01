//****************************************************************************
// File name:	 ButtonViewSDL.cpp
// Author:     Erin Melia
// Date:       5/1/2021
// Class:      CS 485
// Assignment: Blackjack
// Purpose:    Define class to represent a button
//****************************************************************************
#pragma once

#include <functional>

#include "SDLTextWidget.h"
#include "SDLApp.h"
#include "ISDLWidgetTextable.h"

class ButtonViewSDL : SDLTextWidget {
  public:
    ButtonViewSDL(std::string text, int x, int y, 
      std::function<void (void)> function): 
      SDLTextWidget("", text, x, y, 1, { 255, 255, 255, 255 }) 
      { registerClickEventHandler(function); };
};

//****************************************************************************
// File name:	 ISDLWidget.h
// Author:     Chadd Williams
// Date:       3/30/2017
// Class:      CS 485
// Assignment: SDLApp2
// Purpose:    Provider wrapper for SDL
//****************************************************************************
#pragma once
#include <string>
#include "SDLApp.h"

class ISDLWidget
{
public:

  virtual ~ISDLWidget () = default;

  virtual void draw (SDLApp &rcApp) = 0;

  virtual bool isVisible () { return mbVisible; };

  virtual void setVisible (bool bVisible) { mbVisible = bVisible; };

private:
  bool mbVisible = true;
};

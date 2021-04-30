//****************************************************************************
// File name:	 SDLTextWidget.h
// Author:     Chadd Williams
// Date:       3/30/2017
// Class:      CS 485
// Assignment: SDLApp2
// Purpose:    Provider wrapper for SDL
//****************************************************************************
#pragma once
#include "ISDLWidget.h"
#include <functional>
#include "ISDLWidget.h"
#include "ISDLWidgetClickable.h"
#include "ISDLWidgetTextable.h"

class SDLTextWidget : public ISDLWidget, public ISDLWidgetTextable
{

public:

  SDLTextWidget (std::string label, std::string data, int x, int y,
    int font, Color cColor);

  virtual ~SDLTextWidget () = default;

  void draw (SDLApp &rcApp) ;

  int getLength () const;

  bool clicked (int x, int y);

  int getWidth () const;
  int getHeight () const;

  void setColor (Color cColor);


private:

  int mX;
  int mY;
  int mH=0;
  int mW=0;
  int mFont;
  Color mcColor;

};
//****************************************************************************
// File name:	 Color.h
// Author:     Chadd Williams
// Date:       3/30/2017
// Class:      CS 485
// Assignment: SDLApp2
// Purpose:    Provider wrapper for SDL
//****************************************************************************
#pragma once

#include "SDL.h"
#include <iostream>

class Color
{
public:

  Color ();
  Color (Uint8 r, Uint8 g, Uint8 b, Uint8 a=0);

  Uint8 getR () const;
  Uint8 getG () const;
  Uint8 getB () const;
  Uint8 getA () const;

  void setOpacity (float opacity);

  friend std::istream& operator >> (std::istream &in, Color &rcColor);

private:
  Uint8 mR, mG, mB, mA;
};
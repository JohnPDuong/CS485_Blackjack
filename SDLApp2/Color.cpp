//****************************************************************************
// File name:	 Color.cpp
// Author:     Chadd Williams
// Date:       3/30/2017
// Class:      CS 485
// Assignment: SDLApp2
// Purpose:    Provider wrapper for SDL
//****************************************************************************
#include "Color.h"

Color::Color () : Color(0,0,0,0)
{
}

//***************************************************************************
// Constructor: Color
//
// Description: Initialize rgba
//
// Parameters:  r - red
//              g - green
//              b - blue 
//              a - alpha, all parameter are in the range 0-255
//
// Returned:    None
//***************************************************************************
Color::Color (Uint8 r, Uint8 g, Uint8 b, Uint8 a)
{
  mR = r;
  mG = g;
  mB = b;
  mA = a;
}

//***************************************************************************
// Function:    getR
//
// Description: Get the red component
//
// Parameters:  none
//
// Returned:    Uint8 - the red component
//***************************************************************************
Uint8 Color::getR () const
{
  return mR;
}

//***************************************************************************
// Function:    getG
//
// Description: Get the green component
//
// Parameters:  none
//
// Returned:    Uint8 - the green component
//***************************************************************************
Uint8 Color::getG () const
{
  return mG;
}

//***************************************************************************
// Function:    getB
//
// Description: Get the blue component
//
// Parameters:  none
//
// Returned:    Uint8 - the blue component
//***************************************************************************
Uint8 Color::getB () const
{
  return mB;
}

//***************************************************************************
// Function:    getA
//
// Description: Get the alpha component
//
// Parameters:  none
//
// Returned:    Uint8 - the alpha component
//***************************************************************************
Uint8 Color::getA () const
{
  return mA;
}

//***************************************************************************
// Function:    setOpacity
//
// Description: set the alpha component (Opacity). 0=transparent, 1= opaque
//
// Parameters:  opacity - value from 0.0 to 1.0 to determine Opacity
//
// Returned:    none
//***************************************************************************
void Color::setOpacity (float opacity)
{
  if (opacity >= 0.0 && opacity <= 1.0)
  {
    mA = static_cast<Uint8>(opacity * 255);
  }
}

//***************************************************************************
// Function:    operator>>
//
// Description: Read in the Color from a stream
//
// Parameters:  in - the stream to read
//              rcColor - the Color to read into
//
// Returned:    the stream
//***************************************************************************
std::istream& operator >> (std::istream &in, Color &rcColor)
{
  int r, g, b, a;

  in >> r >> g >> b >> a;

  rcColor.mR = static_cast<Uint8>(r);
  rcColor.mG = static_cast<Uint8>(g);
  rcColor.mB = static_cast<Uint8>(b);
  rcColor.mA = static_cast<Uint8>(a);

  return in;
}

//****************************************************************************
// File name:	 SDLTextWidget.cpp
// Author:     Chadd Williams
// Date:       3/30/2017
// Class:      CS 485
// Assignment: SDLApp2
// Purpose:    Provider wrapper for SDL
//****************************************************************************
#include "SDLTextWidget.h"


//***************************************************************************
// Constructor: SDLTextWidget
//
// Description: Set label, data, screen position, font and color
//
// Parameters:  label - the widget's label
//              data - the widget's data
//              x - x coordinate on screen
//              y - y coordinate on screen
//              font - font to use
//              cColor - color to use
//
// Returned:    None
//***************************************************************************
SDLTextWidget::SDLTextWidget (std::string label, std::string data, int x, 
  int y, int font, Color cColor) :
  mX(x), mY(y), mFont(font), mcColor(cColor)
{
  setLabel (label);
  setData (data);
}


//***************************************************************************
// Function:    draw
//
// Description: Draw the widget to the screen
//
// Parameters:  rcApp - the SDLApp to use
//
// Returned:    None
//***************************************************************************
void SDLTextWidget::draw (SDLApp &rcApp)
{
  std::string msg = "";
  Color cSaveColor;

  if (getLabel().length () > 0)
  {
    msg = getLabel () + ": ";
  }
  msg += getData();

  rcApp.displayTextClickable (mX, mY, msg, mcColor, mFont, mW, mH);

  if (hasFocus())
  {
    cSaveColor = rcApp.getColor ();
    rcApp.setColor ({ 255,0,0,255 });
    rcApp.drawLine (mX, mY+ mH, mX+ mW, mY+mH);
    rcApp.setColor (cSaveColor);
  }
}


//***************************************************************************
// Function:    getLength
//
// Description: Get the number of characters in the widget
//
// Parameters:  None
//
// Returned:    number of text characters in widget
//***************************************************************************
int SDLTextWidget::getLength () const
{

  int len = 0;

  if (getLabel().length () > 0)
  {
    len = getLabel ().length() + 2;
  }
  len += getData().length();
  return len;
}

//***************************************************************************
// Function:    clicked
//
// Description: determine if the widget has been clicked
//
// Parameters:  x - x coordinate of mouse click on screen
//              y - y coordinate of mouse click on screen
//
// Returned:    true if the x,y falls inside the widget
//***************************************************************************
bool SDLTextWidget::clicked (int x, int y) 
{
  bool bRetVal = false;
  if (x >= mX && x <= mX + mW &&
    y >= mY && y <= mY + mH)
  {
    bRetVal = true;
  }

  return bRetVal;
}

int SDLTextWidget::getWidth () const
{
  return mW;
}

int SDLTextWidget::getHeight () const
{
  return mH;
}

void SDLTextWidget::setColor (Color cColor)
{
  mcColor = cColor;
}




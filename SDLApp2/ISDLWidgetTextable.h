//****************************************************************************
// File name:	 ISDLWidgetTextable.h
// Author:     Chadd Williams
// Date:       3/30/2017
// Class:      CS 485
// Assignment: SDLApp2
// Purpose:    Provider wrapper for SDL
//****************************************************************************
#pragma once
#include <string>
#include "SDLApp.h"
#include <functional>

#include "ISDLWidgetClickable.h"

class ISDLWidgetTextable : public ISDLWidgetClickable
{
public:

  virtual ~ISDLWidgetTextable () = default;
  virtual void setData (std::string cData) { mData = cData;}

  virtual std::string getData () const {return mData;}
  virtual void setLabel (std::string cLab) { mLabel = cLab; }
  virtual std::string getLabel () const { return mLabel; }
  virtual int getLength () const = 0;

  virtual void setEditable (bool bEditable) { mbEditable = bEditable; };
  virtual bool isEditable () const { return mbEditable; };
  virtual void setFocus (bool bFocus) { mbHasFocus = bFocus; };
  virtual bool hasFocus () const {return mbHasFocus;};

  virtual void stateChangeEvent () {
    if (nullptr != mcStateChangeHandler)
    {
      mcStateChangeHandler ();
    }
  };

  virtual void registerStateChangeEventHandler (
    std::function<void (void)> cFunction)
  {
    mcStateChangeHandler = cFunction;
  };


private:
  std::string mData;
  std::string mLabel;

  bool mbEditable = true;
  bool mbHasFocus = false;

  std::function<void (void)>
    mcStateChangeHandler = nullptr;


};
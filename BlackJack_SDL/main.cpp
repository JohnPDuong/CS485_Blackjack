//***************************************************************************
// File name:  main.cpp
// Author:     Erin Melia
// Date:       4/30/2021
// Class:      CS485
// Assignment: Blackjack
// Purpose:    Runs the SDL version of the program
//***************************************************************************
#include "vld.h"
#include "BlackjackViewSDL.h"

int main (int argc, char* args[]) {
  BlackjackViewSDL cDisplay;
  
  cDisplay.createWindow("Blackjack");

  cDisplay.setWindowBackgroundColor({0, 0, 0, 255});

  cDisplay.gameLoop();

  cDisplay.cleanup();
  return 0;
}
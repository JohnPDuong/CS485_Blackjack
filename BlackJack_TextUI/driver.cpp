//***************************************************************************
// File name:  main.cpp
// Author:     John, Julian, Kitt, Erin
// Date:       5/7/2021
// Class:      CS485
// Assignment: Blackjack
// Purpose:    Runs the TextUI version of blackjack
//***************************************************************************

#include <iostream>
#include "BlackjackTextUI.h"
#include "../Blackjack/BlackjackModel.h"

using namespace std;

int main()
{	
	BlackjackTextUI cGame;
	
	system("cls");
	cGame.printWelcome();
	cGame.onGameStartup();
	cGame.playGame();

	return EXIT_SUCCESS;
}

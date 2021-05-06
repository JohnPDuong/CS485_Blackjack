#include <iostream>
#include "BlackjackTextUI.h"
#include "../Blackjack/BlackjackModel.h"

using namespace std;

int main()
{	
	/*
	BlackjackModel cModel;

	cModel.newGame(3); for (int i = 0; i < 3 - 1; i++)
	{
		cModel.setPlayerType("Card Counter", i);
	}
	cModel.setPlayerType("Human", 3 - 1);
	cout << "cool";

	while (!cModel.isHuman())
	{
		cModel.makeMove();
	}
	cout << "moces done";*/

	BlackjackTextUI cGame;
	
	system("cls");
	cGame.printWelcome();
	cGame.onGameStartup();
	cGame.playGame();


	return EXIT_SUCCESS;
}

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


	return EXIT_SUCCESS;
}

#include "BlackjackTextUI.h"


BlackjackTextUI::BlackjackTextUI()
{
	mpcPresenter = new BlackjackPresenter(this);
}

BlackjackTextUI::BlackjackTextUI(int numPlayers)
{
	mpcPresenter = new BlackjackPresenter(this, numPlayers, 1);
}

BlackjackPresenter::~BlackjackPresenter()
{
	delete mpcView;
}

void BlackjackTextUI::newGame(int numPlayers)
{
	mpcPresenter->newGame(numPlayers);
}

void BlackjackTextUI::nextRound()
{
	mpcPresenter->nextRound();
}

void BlackjackTextUI::stand()
{
	mpcPresenter->stand();
}

void BlackjackTextUI::drawCard()
{
	mpcPresenter->draw();
}

void BlackjackTextUI::split()
{
	mpcPresenter->split();
}

void BlackjackTextUI::bet(long long amount)
{
	mpcPresenter->bet(amount);
}

void BlackjackTextUI::onStand()
{
	
}

void BlackjackTextUI::onDrawCard()
{

}

void BlackjackTextUI::onSplit()
{

}

void BlackjackTextUI::onBet(long long amount)
{

}

void BlackjackTextUI::render()
{

}


/****************  TextUI specific functions  ********************/

void BlackjackTextUI::printWelcome()
{
	std::cout << "***********************************\n";
	std::cout << "***    WELCOME TO BLACKJACK!    ***\n";
	std::cout << "***********************************\n";
}

void BlackjackTextUI::printHeader()
{
	std::cout << "***********************************\n";
	std::cout << "***          BLACKJACK          ***\n";
	std::cout << "***********************************\n";
}

void BlackjackTextUI::printGameState()
{
	// Print your cards
	std::cout << "Your cards: ";
	for (std::string str : mpcPresenter->getCurrentPlayerHand())
	{
		std::cout << str << " ";
	}
	std::cout << std::endl;



}

void BlackjackTextUI::onGameStartup()
{
	const int MAX = 5, MIN = 1;
	int numPlayers = -1;

	std::cout << "Enter number of players (1-5): ";
	do
	{
		std::cin >> numPlayers;
	} while (numPlayers > MAX || numPlayers < MIN);
}

void BlackjackTextUI::playGame()
{
	const char BET = '0';
	const char STAND = '1';
	const char SPLIT = '2';
	const char DRAW = '3';

	bool bKeepPlaying = true;
	long long betAmount = -1;


	while (bKeepPlaying)
	{
		// Do CPU Moves
		while (!mpcPresenter->isHuman())
		{
			mpcPresenter->makeMove();
		}

		// Print state of the game and options
		system("cls");
		printHeader();



	}



}
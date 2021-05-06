#include "BlackjackTextUI.h"


BlackjackTextUI::BlackjackTextUI()
{
	mpcPresenter = new BlackjackPresenter(this);
}

BlackjackTextUI::BlackjackTextUI(int numPlayers)
{
	mpcPresenter = new BlackjackPresenter(this, numPlayers, 1);
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
	std::vector<std::vector<std::string>> cards = mpcPresenter->getOpponentCards();

	// Print your bank
	std::cout << "Chips available: " << mpcPresenter->getBalance() << std::endl;

	// Print your cards
	std::cout << "Your cards: ";
	for (std::string str : mpcPresenter->getCurrentPlayerHand())
	{
		std::cout << str << " ";
	}
	std::cout << std::endl;

	// print opponents cards
	for (int i = 0; i < mpcPresenter->getNumPlayers(); i++)
	{
		std::cout << "Opponent " << i + 1 << "cards: ";
		for (std::string card : cards[i])
		{
			std::cout << card << " ";
		}
		std::cout << std::endl;
	}
}

void BlackjackTextUI::printPlayerCards()
{
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
	mpcPresenter->newGame(numPlayers);

	for (int i = 0; i < numPlayers - 1; i++)
	{
		mpcPresenter->setPlayerType("Card Counter", i);
	}
	mpcPresenter->setPlayerType("Human", numPlayers - 1);

	mpcPresenter->newGame();
}

void BlackjackTextUI::playGame()
{
	const int STAND = 1;
	const int DRAW = 2;
	const int SPLIT = 3;
	const int QUIT = 4;

	const bool STOP_PLAYING = false;

	bool bKeepPlaying = true;
	long long betAmount = -1;
	int turns = 0;
	int move = 0;

	while (bKeepPlaying)
	{
		// Do CPU Moves
		/*
		while (!mpcPresenter->isHuman())
		{
			mpcPresenter->makeMove();
		}*/
		mpcPresenter->doCPUMoves();

		// Print state of the game and options
		system("cls");
		printHeader();

		// Do betting
		mpcPresenter->doCPUBets();
		std::cout << "Current balance: " << mpcPresenter->getBalance();
		std::cout << "\nHow much would you like to bet? ";
		do
		{
			//mpcPresenter->doCPUBets();
			std::cin >> betAmount;

		} while (!mpcPresenter->bet(betAmount));
		mpcPresenter->doCPUBets();

		printGameState();

		// Prints the move options if the human's turn is still going
		while (move != STAND && mpcPresenter->result() != Status::Bust && move != QUIT)
		{
			move = SPLIT;
			std::cout << "OPTIONS: \n(1) Stand \n(2) Draw\n";
			if (mpcPresenter->canSplit())
			{
				std::cout << "(3) Split\n";
			}
			std::cout << "(4) Quit\n";

			do
			{
				std::cout << "Enter your move: ";
				std::cin >> move;
			} while ((move == SPLIT && !mpcPresenter->canSplit()) || (move > QUIT || move < STAND));

			// Executes selected move
			switch (move)
			{
			case STAND:
				mpcPresenter->stand();
				break;

			case DRAW:
				mpcPresenter->draw();
				break;

			case SPLIT:
				mpcPresenter->split();
				break;
			case QUIT:
				bKeepPlaying = STOP_PLAYING;
				break;
			}
		}


		turns++;
	}
}

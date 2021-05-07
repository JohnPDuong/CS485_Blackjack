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
	std::vector<std::vector<std::string>> cards = mpcPresenter->getAllCards();
	std::vector<std::string> dealerCards = mpcPresenter->getDealerCards();
	std::cout << std::endl;

	// print opponents cards
  for (int i = 0; i < mpcPresenter->getNumPlayers(); i++)
  {
    if(i != mpcPresenter->getCurrentPlayer()){
      std::cout << mpcPresenter->getName(i) << " cards: ";
      for (std::string card : cards[i])
      {
        std::cout << card << " ";
      }
      std::cout << std::endl;
    }
  }
  std::cout << std::endl;

	// Print Dealer cards
	std::cout << "Dealer cards: ";
	for (std::string card : dealerCards)
	{
		std::cout << card << " ";
	}
	std::cout << std::endl << std::endl;

	// Print your bank
	std::cout << "Chips available: " << mpcPresenter->getBalance() << std::endl;
}

void BlackjackTextUI::printPlayerCards()
{
	std::cout << "Your cards: ";
	for (std::string str : mpcPresenter->getCurrentPlayerHand())
	{
		std::cout << str << " ";
	}
	std::cout << std::endl << std::endl;
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
  
  do{
  for(int i = 0; i < numPlayers; i++){
    std::string name;
    std::cout << "Please name the player in the " << i << " position.\n";
    std::cin >> name;
    mpcPresenter->setName(name, i);
  }

  std::vector<std::string> moveStratList = mpcPresenter->listMoveStratTypes();
	for (int i = 0; i < numPlayers; i++)
	{
    int selection;
    do{
      std::cout << "Please select a moveStrategy for "
                << mpcPresenter->getName(i)
                << " from one of the following by inputting the corresponding"
                << " number:\n";
      for(int i = 0; i < moveStratList.size(); i++){
        std::cout << i + 1 << " " << moveStratList[i] << "\n";
      }
      std::cin >> selection;
    }while(selection < 0 || selection > moveStratList.size() + 1);
    mpcPresenter->setPlayerType(moveStratList[selection - 1], i);
	}
  }while(!mpcPresenter->newGame());
}

void BlackjackTextUI::playGame()
{
	const int STAND = 1;
	const int DRAW = 2;
	const int SPLIT = 3;
	const int QUIT = 4;
	const bool STOP_PLAYING = false;
	const std::vector<std::string> EMPTY_HAND;

	bool bKeepPlaying = true;
	long long betAmount = -1;
	int turns = 0;
	int move;

	while (bKeepPlaying)
	{
		move = -1;
		mcHand = EMPTY_HAND;		

		// Print state of the game and options
		system("cls");
		printHeader();

		// Do betting
		mpcPresenter->doCPUBets();
		std::cout << "\nCurrent balance: " << mpcPresenter->getBalance();

		if (!(0 >= mpcPresenter->getBalance()))
		{
			std::cout << "\nHow much would you like to bet? ";
			do
			{
				//mpcPresenter->doCPUBets();
				std::cin >> betAmount;

			} while (!mpcPresenter->bet(betAmount));
			mpcPresenter->doCPUBets();

			

			// Prints the move options if the human's turn is still going
			while (/*move != STAND &&*/ mpcPresenter->roundOngoing() && move != QUIT)
			{
				mpcPresenter->doCPUMoves();
        system("cls");
        printHeader();
        printGameState();
				printPlayerCards();

				// Sets the move to stand automatically if bust
				if (Status::Bust == mpcPresenter->result())
				{
					move = STAND;
				}

				if (move != STAND)
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
					std::cout << std::endl;
				}

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
					//mcHand.push_back(mpcPresenter->getCurrentPlayerHand()[1]);// TODO
					mpcPresenter->split();
					break;
				case QUIT:
					bKeepPlaying = STOP_PLAYING;
					break;
				}
        
				turns++;
			}

			//mcHand = mpcPresenter->getCurrentPlayerHand();
			mpcPresenter->doCPUMoves();
			printEndRoundScreen();
			mpcPresenter->nextRound();
		}

		else
		{
			std::cout << "\nWow, you lost. Hope that wasn't your life's savings!\n\n";
			bKeepPlaying = false;
		}
	}
}


void BlackjackTextUI::printEndRoundScreen(){
	std::string something = "";
	std::vector<std::string> hand = mpcPresenter->getAllCurrentPlayerHands();
  std::vector<std::vector<std::string>> cards = mpcPresenter->getAllCards();
	int numPlayers = mpcPresenter->getNumPlayers();
	std::vector<std::string> dealerCards = mpcPresenter->getDealerCards();

  std::vector<Status> endStatuses = mpcPresenter->endRound();

	long long balance = mpcPresenter->getBalance();

	system("cls");
	printHeader();
	std::cout << "\nRound results:\n\n";

  // Print your bank
  std::cout << "Chips: " << balance << std::endl;

  // Print your cards
  std::cout << "Your cards: ";
  for (std::string str : hand)
  {
    std::cout << str << " ";
  }
	for (std::string str : mcHand)
	{
		std::cout << str << " ";
	}
  std::cout << std::endl << std::endl;

  // print opponents cards
  for (int i = 0; i < numPlayers; i++)
  {
    if(i != mpcPresenter->getCurrentPlayer()){
      std::cout << mpcPresenter->getName(i) << " cards: ";
      for (std::string card : cards[i])
      {
        std::cout << card << " ";
      }
      std::cout << std::endl;
    }
  }
	std::cout << std::endl;

	// Print Dealer cards
	std::cout << "Dealer cards: ";
	for (std::string card : dealerCards)
	{
		std::cout << card << " ";
	}
	std::cout << std::endl;

	system("PAUSE");
}

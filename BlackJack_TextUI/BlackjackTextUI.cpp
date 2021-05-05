#include "BlackjackTextUI.h"

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

}

void BlackjackTextUI::stand()
{

}

void BlackjackTextUI::drawCard()
{

}

void BlackjackTextUI::split()
{

}

void BlackjackTextUI::bet(long long amount)
{

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
//***************************************************************************
// File name:  BlackjackViewSDL.cpp
// Author:     Erin Melia
// Date:       5/5/2021
// Class:      CS485
// Assignment: Blackjack
// Purpose:    Defines the UI functionality for the SDL version of the game
//***************************************************************************
#include "BlackjackViewSDL.h"

//***************************************************************************
// Constructor: BlackjackViewSDL
//
// Description: Initialize the on-screen widgets, hookup event handlders,
//              load fonts, register widgets with SDLApp
//
// Parameters:  None
//
// Returned:    None
//***************************************************************************
BlackjackViewSDL::BlackjackViewSDL () :
mcBetButton("Bet", "", 10, 10, 1, { 255,255,255,255 }),
mcStandButton("Stand", "", 100, 10, 1, { 255,255,255,255 }),
mcSplitButton("Split", "", 200, 10, 1, { 255,255,255,255 }),
mcDrawButton("Draw", "", 300, 10, 1, { 255,255,255,255 }),
mcNumPlayersInput("Enter number of Players", "", 10, 50, 1, { 255,255,255,255 }),
mcEndGameButton("New Game", "", 500, 650, 1, { 255,255,255,255 }),
mcNextRound("Next Round", "", 400, 10, 1, {255, 255, 255, 255}),
mcPlayerNameInput("Player 1 Name", "", 10, 50, 1, { 255, 255, 255, 255 }),
mcPlayerTypeInput("Player 1 Type", "", 10, 140, 1, { 255, 255, 255, 255 }),
mcSetPlayer("Set Player", "", 10, 200, 1, {255, 255, 255, 255}),
mcPlayerBalanceInput("Player 1 Balance", "", 10, 110, 1, {255, 255, 255, 255}),
mcConfirmBets("Confirm Bets", "", 10, 10, 1, {255, 255, 255, 255})
{
  mpcPresenter = new BlackjackPresenterSDL ((IBlackjackView*)this);
  loadFont ("c:/Windows/Fonts/Cour.ttf", 20);

  //set event handlers
  mcBetButton.registerStateChangeEventHandler 
    (std::bind
    (&BlackjackViewSDL::onBetWidget, this, &mcBetButton));
  mcNumPlayersInput.registerStateChangeEventHandler
    (std::bind
    (&BlackjackViewSDL::onNumPlayersWidget, this, &mcNumPlayersInput));
  mcStandButton.registerClickEventHandler
    (std::bind(&BlackjackViewSDL::onStand, this));
  mcSplitButton.registerClickEventHandler
    (std::bind (&BlackjackViewSDL::onSplit, this));
  mcDrawButton.registerClickEventHandler
    (std::bind(&BlackjackViewSDL::onDrawCard, this));
  mcEndGameButton.registerClickEventHandler
    (std::bind(&BlackjackViewSDL::onEndGame, this));
  mcNextRound.registerClickEventHandler
    (std::bind(&BlackjackViewSDL::onNextRound, this));
  mcSetPlayer.registerClickEventHandler 
    (std::bind
    (&BlackjackViewSDL::onSetPlayerWidget, this, &mcPlayerNameInput, &mcPlayerTypeInput, &mcPlayerBalanceInput));

  //set non-editable text objects
  mcStandButton.setEditable(false);
  mcSplitButton.setEditable(false);
  mcDrawButton.setEditable(false);
  mcEndGameButton.setEditable(false);
  mcNextRound.setEditable(false);
  mcSetPlayer.setEditable(false);
  mcConfirmBets.setVisible(false);

  enableTextInput();

  registerTextWidget((ISDLWidgetTextable*)&mcBetButton);
  registerTextWidget((ISDLWidgetTextable*)&mcNumPlayersInput);
  registerTextWidget((ISDLWidgetTextable*)&mcPlayerNameInput);
  registerTextWidget((ISDLWidgetTextable*)&mcPlayerTypeInput);
  registerTextWidget((ISDLWidgetTextable*)&mcPlayerBalanceInput);
  registerClickableWidget((ISDLWidgetClickable*)&mcStandButton);
  registerClickableWidget((ISDLWidgetClickable*)&mcSplitButton);
  registerClickableWidget((ISDLWidgetClickable*)&mcDrawButton);
  registerClickableWidget((ISDLWidgetClickable*)&mcEndGameButton);
  registerClickableWidget((ISDLWidgetClickable*)&mcNextRound);
  registerClickableWidget((ISDLWidgetClickable*)&mcSetPlayer);
  registerClickableWidget((ISDLWidgetClickable*)&mcConfirmBets);

  mcDrawableWidget.push_back(&mcBetButton);
  mcDrawableWidget.push_back(&mcNumPlayersInput);
  mcDrawableWidget.push_back(&mcStandButton);
  mcDrawableWidget.push_back(&mcDrawButton);
  mcDrawableWidget.push_back(&mcEndGameButton);
  mcDrawableWidget.push_back(&mcNextRound);
  mcDrawableWidget.push_back(&mcPlayerNameInput);
  mcDrawableWidget.push_back(&mcPlayerTypeInput);
  mcDrawableWidget.push_back(&mcSetPlayer);
  mcDrawableWidget.push_back(&mcSplitButton);
  mcDrawableWidget.push_back(&mcPlayerBalanceInput);
  mcDrawableWidget.push_back(&mcConfirmBets);
}

//***************************************************************************
// Destructor:  ~BlackjackViewSDL
//
// Description: Delete the presenter
//
// Parameters:  None
//
// Returned:    None
//***************************************************************************
BlackjackViewSDL::~BlackjackViewSDL ()
{
  delete mpcPresenter;
  for(auto it = mcPlayers.begin(); it != mcPlayers.end(); it++)
    delete *it;
  mcPlayers.clear();
}

//***************************************************************************
// Function:    newGame
//
// Description: From Presenter: create PlayerViews for the specified number of
//              players
//
// Parameters:  numPlayers - the number of views to create
//
// Returned:    None
//***************************************************************************
void BlackjackViewSDL::newGame (int numPlayers)
{
  //create player views
  for (int i = 0; i < numPlayers; i++) {
    PlayerView* pcCreated = new PlayerView(10, 150 + 100 * i, *this);
    pcCreated->setName(mpcPresenter->getName(i));
    pcCreated->setMoney(std::to_string(mpcPresenter->getBalance(i)));
    mcPlayers.push_back(pcCreated);
    mcDrawableWidget.push_back((ISDLWidget*)pcCreated);
  }

  PlayerView* pcDealer = new PlayerView(10, 50, *this);
  pcDealer->makeDealer();
  mcPlayers.push_back(pcDealer);
  mcDrawableWidget.push_back (pcDealer);

  //mcStandButton.setVisible (true);
  //mcSplitButton.setVisible (true);
  //mcDrawButton.setVisible (true);
  //mcEndGameButton.setVisible (true);
  //mcBetButton.setVisible (true);
  mcNumPlayersInput.setVisible (false);
  mcPlayerNameInput.setVisible (false);
  mcPlayerTypeInput.setVisible (false);
  mcSetPlayer.setVisible (false);
  mcPlayerBalanceInput.setVisible (false);
  mcSetPlayer.registerClickEventHandler (std::bind
    (&BlackjackViewSDL::doNothing, this));

  mpcPresenter->newGame();

  betScreen();
}

//***************************************************************************
// Function:    stand
//
// Description: From Presenter:  advance to the next player
//
// Parameters:  None
//
// Returned:    None
//***************************************************************************
void BlackjackViewSDL::stand ()
{
  if(mpcPresenter->roundOngoing())
    mcNextRound.setVisible(true);
  else
    mcPlayers[mpcPresenter->getCurrentPlayer()]->showCards();
}
//***************************************************************************
// Function:    drawCard
//
// Description: From Presenter: add card to the current player's hand
//
// Parameters:  card     - a string representing which card should be added
//              isFaceUp - whether the card should be dealt face up or face
//                         down
//
// Returned:    None
//***************************************************************************
void BlackjackViewSDL::drawCard (std::string card, bool isFaceUp, 
  bool inMainHand)
{
  mcPlayers[mpcPresenter->getCurrentPlayer()]->addCard(this, card, isFaceUp, inMainHand);
}

//***************************************************************************
// Function:    split
//
// Description: From Presenter:  split the current player's hand
//
// Parameters:  None
//
// Returned:    None
//***************************************************************************
void BlackjackViewSDL::split ()
{
  mcPlayers[mpcPresenter->getCurrentPlayer()]->splitHand();
}

//***************************************************************************
// Function:    bet
//
// Description: From Presenter:  update the displayed amount of the player's
//              money
//
// Parameters:  amount - the current player's bank balance
//
// Returned:    None
//***************************************************************************
void BlackjackViewSDL::bet (long long amount) //set money bc Chadd
{
  mcPlayers[mpcPresenter->getCurrentPlayer()]->setMoney(std::to_string(amount));
}

//***************************************************************************
// Function:    nextRound
//
// Description: From Presenter: reset the UI so the player can begin the next
//              round
//
// Parameters:  None
//
// Returned:    None
//***************************************************************************
void BlackjackViewSDL::nextRound ()
{
  for (auto it = mcPlayers.begin (); it != mcPlayers.end (); it++)
    (*it)->discardHand ();
}

//***************************************************************************
// Function:    endGame
//
// Description: From Presenter: reset the UI to the beginning screen
//
// Parameters:  None
//
// Returned:    None
//***************************************************************************
void BlackjackViewSDL::endGame ()
{
  mcStandButton.setVisible (false);
  mcSplitButton.setVisible (false);
  mcDrawButton.setVisible (false);
  mcEndGameButton.setVisible (false);
  mcBetButton.setVisible (false);
  mcNumPlayersInput.setVisible (true);
}

//***************************************************************************
// Function:    setPlayer
//
// Description: Sets the type of the current player
//
// Parameters:  None
//
// Returned:    None
//***************************************************************************
void BlackjackViewSDL::setPlayer ()
{
  if (mPlayersSet < mpcPresenter->getNumPlayers ()) {
    mcPlayerNameInput.setLabel ("Player " + std::to_string (mPlayersSet + 1) + " name");
    mcPlayerNameInput.setData ("");
    mcPlayerTypeInput.setLabel ("Player " + std::to_string (mPlayersSet + 1) + " type");
    mcPlayerTypeInput.setData ("");
    mcPlayerBalanceInput.setLabel("Player " + std::to_string(mPlayersSet + 1) + " balance");
    mcPlayerBalanceInput.setData("");
  }
  else
  {
    newGame(mpcPresenter->getNumPlayers());
  }
}

//***************************************************************************
// Function:    setNumPlayers
//
// Description: Runs after the number of players has been set. Inititalizes
//              the UI to allow user to specify types of players
//
// Parameters:  None
//
// Returned:    None
//***************************************************************************
void BlackjackViewSDL::setNumPlayers ()
{
  mcNumPlayersInput.setVisible(false);
  mcPlayerNameInput.setVisible(true);
  mcPlayerTypeInput.setVisible(true);
  mcPlayerBalanceInput.setVisible(true);
  mcSetPlayer.setVisible(true);
}

//***************************************************************************
// Function:    betScreen
//
// Description: Displays the UI to allow users to place their bets
//
// Parameters:  None
//
// Returned:    None
//***************************************************************************
void BlackjackViewSDL::betScreen ()
{
  mcConfirmBets.registerClickEventHandler
    (std::bind
    (&BlackjackViewSDL::onConfirmBets, this));
  mcConfirmBets.setVisible(true);
}
//***************************************************************************
// Function:    onStand
//
// Description: UI Event handler: call presenter
//
// Parameters:  None
//
// Returned:    None
//***************************************************************************
void BlackjackViewSDL::onStand ()
{
  mpcPresenter->stand();
  updateCards();

  if (!mpcPresenter->roundOngoing())
  {
    mcNextRound.setVisible(true);
    mcNextRound.setEditable(true);
  }
}

//***************************************************************************
// Function:    onDrawCard
//
// Description: UI Event handler: call presenter
//
// Parameters:  None
//
// Returned:    None
//***************************************************************************
void BlackjackViewSDL::onDrawCard ()
{
  if (Status::Bust != mpcPresenter->result() && 
    Status::Blackjack != mpcPresenter->result() && mpcPresenter->roundOngoing())
  {
    mpcPresenter->draw();
    std::vector<std::string> cards = mpcPresenter->getCurrentPlayerHand();
    mcPlayers.at(mpcPresenter->getCurrentPlayer())->addCard(this, 
      cards.at(cards.size()-1), true, true);
    updateCards();
  }

  if ((Status::Bust == mpcPresenter->result() || 
    Status::Blackjack == mpcPresenter->result()) && mpcPresenter->roundOngoing())
  {
    onStand();
  }
}

//***************************************************************************
// Function:    updateCards
//
// Description: Updates cards so that they render correctly
//
// Parameters:  None
//
// Returned:    None
//***************************************************************************
void BlackjackViewSDL::updateCards()
{
  std::vector<std::string> currCards = mpcPresenter->getCurrentPlayerHand();
  std::vector<std::vector<std::string>> allCards = mpcPresenter->getAllCards();
  std::vector<std::string> dealerCards = mpcPresenter->getDealerCards();
  int currInd = mpcPresenter->getCurrentPlayer();

  discardHands();

  for (int i = 0; i < currCards.size(); i++)
  {
    mcPlayers.at(currInd)->addCard (this, currCards.at(i), true, true);
  }

  for (int i = 0; i < mpcPresenter->getNumPlayers(); i++)
  {
    if (i != currInd)
    {
      for (int j = 0; j < allCards.at(i).size(); j++)
      {
        mcPlayers.at(i)->addCard(this, allCards.at(i).at(j), true, true);
      }
    }
  }

  for (int i = 0; i < dealerCards.size(); i++)
  {
    mcPlayers.at(mcPlayers.size() - 1)->addCard(this, dealerCards.at(i), true, true);
  }
}

//***************************************************************************
// Function:    toggleButtonOff
//
// Description: Hides the buttons at the top of the screen
//
// Parameters:  None
//
// Returned:    None
//***************************************************************************
void BlackjackViewSDL::toggleButtonsOff()
{
  mcDrawButton.setVisible(false);
  mcDrawButton.setEditable(false);
  mcSplitButton.setVisible(false);
  mcSplitButton.setEditable (false);
  mcStandButton.setVisible(false);
  mcStandButton.setEditable (false);
}

//***************************************************************************
// Function:    toggleButtonOn
//
// Description: displays the buttons at the top of the screen
//
// Parameters:  None
//
// Returned:    None
//***************************************************************************
void BlackjackViewSDL::toggleButtonsOn()
{
  mcDrawButton.setVisible(true);
  mcDrawButton.setEditable(true);
  mcSplitButton.setVisible(true);
  mcSplitButton.setEditable(true);
  mcStandButton.setVisible(true);
  mcStandButton.setEditable(true);
}

//***************************************************************************
// Function:    discardHands
//
// Description: removes all CardViewSDLs from the PlayerView's hands
//
// Parameters:  None
//
// Returned:    None
//***************************************************************************
void BlackjackViewSDL::discardHands()
{
  for (int i = 0; i < mcPlayers.size(); i++)
  {
    mcPlayers.at(i)->discardHand();
  }
}

//***************************************************************************
// Function:    onSplit
//
// Description: UI Event handler: call presenter
//
// Parameters:  None
//
// Returned:    None
//***************************************************************************
void BlackjackViewSDL::onSplit ()
{
  if (mpcPresenter->canSplit())
  {
    mpcPresenter->split();
  }
  else
  {
    mcSplitButton.setVisible (false);
  }
}

//***************************************************************************
// Function:    onBet
//
// Description: UI Event handler: call presenter
//
// Parameters:  amount - the amount of money the player bet
//
// Returned:    None
//***************************************************************************
void BlackjackViewSDL::onBet (long long amount)
{
  mpcPresenter->bet(amount);
  bet(mpcPresenter->getBalance());
}

//***************************************************************************
// Function:    onNewGame
//
// Description: UI Event handler: call presenter
//
// Parameters:  None
//
// Returned:    None
//***************************************************************************
void BlackjackViewSDL::onEndGame ()
{
  //note: at some point in here, new game needs to be
                            //called
}

//***************************************************************************
// Function:    onNextRound
//
// Description: UI Event handler: call presenter
//
// Parameters:  None
//
// Returned:    None
//***************************************************************************
void BlackjackViewSDL::onNextRound ()
{
  mcNextRound.setVisible(false);
  mcNextRound.setEditable(false);

  mpcPresenter->nextRound();

  discardHands();

  for (int i = 0; i < mpcPresenter->getNumPlayers(); i++)
  {
    mcPlayers.at(i)->setBetVisible(true);
    mcPlayers.at(i)->setMoney((std::to_string(mpcPresenter->getBalance(i))));
  }

  mcPlayers.at(mcPlayers.size()-1)->setBetVisible (false);
 
  toggleButtonsOff();

  betScreen();
}

//***************************************************************************
// Function:    onSetNumPlayers
//
// Description: UI Event handler: call presenter
//
// Parameters:  None
//
// Returned:    None
//***************************************************************************
void BlackjackViewSDL::onSetNumPlayers (int number)
{
  mpcPresenter->newGame(number);
  setNumPlayers();
}

//***************************************************************************
// Function:    onSetPlayer
//
// Description: Runs when the user has input the correct parameters to set
//              the name and type of a player, as well as their starting bank
//              balance
//
// Parameters:  name    - the name of the player
//              type    - the type of the player
//              balance - the player's starting bank balance
//
// Returned:    None
//***************************************************************************
void BlackjackViewSDL::onSetPlayer (std::string name, std::string type, 
  long long balance)
{
  mpcPresenter->setName(name, mPlayersSet);
  mpcPresenter->setPlayerType(type, mPlayersSet);
  mpcPresenter->setBalance(balance, mPlayersSet);
  mPlayersSet++;
  setPlayer();
}

//***************************************************************************
// Function:    onConfirmBets
//
// Description: Runs when the player has input all of the bets. Begins a new
//              round
//
// Parameters:  None
//
// Returned:    None
//***************************************************************************
void BlackjackViewSDL::onConfirmBets ()
{
  bool bGoodBets = true;
  std::string str;
  int size;

  for (int i = 0; i < mpcPresenter->getNumPlayers(); i++)
  {
    str = mcPlayers.at(i)->getBet();
    size = str.size();

    if (size != 0)
    {
      if (std::any_of(str.begin(), str.end(), std::isdigit))
      {
        if (mpcPresenter->getBalance(i) >= stoll(str) && stoll(str) > 0)
        {
          mpcPresenter->setBet(stoll(str), i);
        }
        else
        {
          bGoodBets = false;
        }
      }
      else
      {
        bGoodBets = false;
      }
    }
    else
    {
      bGoodBets = false;
    }
  }

  if (bGoodBets)
  {
    int count = -1;

    mpcPresenter->doCPUBets();
    mpcPresenter->doCPUMoves();

    toggleButtonsOn();

    discardHands();

    mcEndGameButton.setVisible(true);
    mcConfirmBets.setVisible(false);
    mcConfirmBets.registerClickEventHandler
    (std::bind
    (&BlackjackViewSDL::doNothing, this));

    updateCards();

    if (Status::Bust == mpcPresenter->result() || Status::Blackjack == mpcPresenter->result())
    {
      onStand();
    }

    mpcPresenter->doCPUMoves();
  }
}
//***************************************************************************
// Function:    onBetWidget
//
// Description: UI Event handler: call presenter
//
// Parameters:  string - the data from the UI widget
//
// Returned:    None
//***************************************************************************
void BlackjackViewSDL::onBetWidget (SDLTextWidget* widget)
{
  std::string str = widget->getData();
  int size = str.size();

  if (size != 0)
  {
    if (std::any_of(str.begin(), str.end(), std::isdigit))
    {
      onBet(stoll(str));

      mcBetButton.setEditable (false);
    }
  }
}
//***************************************************************************
// Function:    onNumPlayersWidget
//
// Description: UI Event handler: call presenter
//
// Parameters:  int - the number of players
//
// Returned:    None
//***************************************************************************
void BlackjackViewSDL::onNumPlayersWidget (SDLTextWidget* widget)
{
  std::string str = widget->getData();
  int size = str.size();
  int number;

  if (size != 0)
  {
    if (std::any_of(str.begin(), str.end(), std::isdigit))
    {
      number = (stoi(str));

      if (number <= 5 && number >= 1)
      {
        onSetNumPlayers(number);
      }
    }
  }
}

//***************************************************************************
// Function:    onSetPlayerWidget
//
// Description: validates input and passes it to onSetPlayer
//
// Parameters:  string    - the name of the player
//              string    - the type of the player
//              long long - the player's starting bank balance
//
// Returned:    None
//***************************************************************************
void BlackjackViewSDL::onSetPlayerWidget (SDLTextWidget* name, 
  SDLTextWidget* type, SDLTextWidget* balance)
{
  if (name->getData () != "" && (type->getData () == "Card Counter" || 
    type->getData () == "Human") && std::stoll(balance->getData()) > 0)
  {
    onSetPlayer(name->getData(), type->getData(), std::stoll(balance->getData()));
  }
}

//***************************************************************************
// Function:    initGame
//
// Description: Initializes the UI elements
//
// Parameters:  None
//
// Returned:    None
//***************************************************************************
void BlackjackViewSDL::initGame ()
{
  mcStandButton.setVisible (false);
  mcSplitButton.setVisible (false);
  mcDrawButton.setVisible (false);
  mcEndGameButton.setVisible (false);
  mcBetButton.setVisible (false);
  mcNextRound.setVisible (false);
  mcSetPlayer.setVisible(false);
  mcPlayerNameInput.setVisible(false);
  mcPlayerTypeInput.setVisible(false);
  mcNumPlayersInput.setVisible (true);
  mcPlayerBalanceInput.setVisible(false);
}

//***************************************************************************
// Function:    render
//
// Description: Displays UI to the screen
//
// Parameters:  None
//
// Returned:    None
//***************************************************************************
void BlackjackViewSDL::render ()
{
  for (auto value : mcDrawableWidget) {
    if(value->isVisible())
      value->draw(*this);
  }
}

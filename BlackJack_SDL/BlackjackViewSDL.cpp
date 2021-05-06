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
mcStandButton("Stand", "", 10, 20, 1, { 255,255,255,255 }),
mcSplitButton("Split", "", 10, 30, 1, { 255,255,255,255 }),
mcDrawButton("Draw", "", 10, 40, 1, { 255,255,255,255 }),
mcNumPlayersInput("Enter number of Players (1-5)", "", 10, 50, 1, { 255,255,255,255 }),
mcEndGameButton("New Game", "", 10, 60, 1, { 255,255,255,255 }),
mcNextRound("Next Round", "", 10, 70, 1, {255, 255, 255, 255})
{
  mpcPresenter = new BlackjackPresenter();
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

  //set non-editable text objects
  mcStandButton.setEditable(false);
  mcSplitButton.setEditable(false);
  mcDrawButton.setEditable(false);
  mcEndGameButton.setEditable(false);
  mcNextRound.setEditable(false);

  enableTextInput();

  registerTextWidget((ISDLWidgetTextable*)&mcBetButton);
  registerTextWidget((ISDLWidgetTextable*)&mcNumPlayersInput);
  registerClickableWidget((ISDLWidgetClickable*)&mcStandButton);
  registerClickableWidget((ISDLWidgetClickable*)&mcSplitButton);
  registerClickableWidget((ISDLWidgetClickable*)&mcDrawButton);
  registerClickableWidget((ISDLWidgetClickable*)&mcEndGameButton);
  registerClickableWidget((ISDLWidgetClickable*)&mcNextRound);

  mcDrawableWidget.push_back(&mcBetButton);
  mcDrawableWidget.push_back(&mcNumPlayersInput);
  mcDrawableWidget.push_back(&mcStandButton);
  mcDrawableWidget.push_back(&mcDrawButton);
  mcDrawableWidget.push_back(&mcEndGameButton);
  mcDrawableWidget.push_back(&mcNextRound);
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
    PlayerView cCreated(10, 100 + 10 * i);
    mcPlayers.push_back(cCreated);
    mcDrawableWidget.push_back(&cCreated);
  }
  PlayerView cDealer(10, 90);
  cDealer.makeDealer();
  mcPlayers.push_back(cDealer);
  mcDrawableWidget.push_back (&cDealer);

  mcCurrentPlayer = mcPlayers.begin();

  //initialize game UI
  mcStandButton.setVisible (true);
  mcSplitButton.setVisible (true);
  mcDrawButton.setVisible (true);
  mcEndGameButton.setVisible (true);
  mcBetButton.setVisible (true);
  mcNumPlayersInput.setVisible(false);
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
  mcCurrentPlayer++;

  if(mcCurrentPlayer == mcPlayers.end())
    mcNextRound.setVisible(true);
  else
    mcCurrentPlayer->showCards();
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
  mcCurrentPlayer->addCard(this, card, isFaceUp, inMainHand);
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
  mcCurrentPlayer->splitHand();
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
void BlackjackViewSDL::bet (long long amount)
{
  mcCurrentPlayer->setMoney(std::to_string(amount));
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
  mcCurrentPlayer = mcPlayers.begin ();

  for (auto it = mcPlayers.begin (); it != mcPlayers.end (); it++)
    it->discardHand ();
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
  mpcPresenter->draw();
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
  mpcPresenter->split();
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
  mpcPresenter->endGame (); //note: at some point in here, new game needs to be
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
  mpcPresenter->nextRound();
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
  onBet(stoll(widget->getData()));
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
  int numPlayers = stoi(widget->getData());

  if (numPlayers <= 5 && numPlayers >= 1)
  {
    onSetNumPlayers(stoi(widget->getData()));
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
  mcNumPlayersInput.setVisible (true);
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

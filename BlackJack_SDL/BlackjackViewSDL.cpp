//***************************************************************************
// File name:  BlackjackView.cpp
// Author:     Erin Melia
// Date:       5/1/2021
// Class:      CS485
// Assignment: Blackjack
// Purpose:    Define the primary view used in the SDL app
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
mcStandButton("Stand", "", 10, 10, 1, { 255,255,255,255 }),
mcBetButton("Bet", "", 10, 20, 1, { 255,255,255,255 }),
mcSplitButton("Split", "", 10, 30, 1, { 255,255,255,255 }),
mcDrawButton("Draw", "", 10, 40, 1, { 255,255,255,255 }),
mcNumPlayersInput("Number of Players", "", 10, 60, 1, { 255,255,255,255 }),
mcPlayerTypeInput("Input Player Type", "", 10, 70, 1, { 255,255,255,255 }),
mcNewGame("New Game", "", 10, 80, 1, { 255,255,255,255 }),
mcNameInput("Name", "", 10, 100, 1, { 255,255,255,255 }),
mcCreatePlayer("Create Player", "", 10, 110, 1, { 255,255,255,255 })
{
  mpcPresenter = new BlackjackPresenter();
  loadFont ("c:/Windows/Fonts/Cour.ttf", 20);

  mcNumPlayersInput.registerStateChangeEventHandler 
    (std::bind
    (&BlackjackViewSDL::onSetNumPlayersWidget, this, &mcNumPlayersInput));
  mcBetButton.registerStateChangeEventHandler
    (std::bind
    (&BlackjackViewSDL::onBetWidget,this, &mcBetButton));
  mcNewGame.registerClickEventHandler
    (std::bind(&BlackjackViewSDL::onNewGame, this));
  mcCreatePlayer.registerClickEventHandler
    (std::bind
    (&BlackjackViewSDL::onCreatePlayerWidget, this, &mcNameInput, 
    &mcPlayerTypeInput));
  mcStandButton.registerClickEventHandler
    (std::bind (&BlackjackViewSDL::onStand, this));
  mcDrawButton.registerClickEventHandler
    (std::bind(&BlackjackViewSDL::onDrawCard, this));
  mcSplitButton.registerClickEventHandler
    (std::bind(&BlackjackViewSDL::onSplit, this));

  enableTextInput();

  mcBetButton.setVisible(false);
  mcStandButton.setVisible(false);
  mcSplitButton.setVisible(false);
  mcDrawButton.setVisible(false);
  mcPlayerTypeInput.setVisible(false);
  mcNewGame.setVisible(false);
  mcNameInput.setVisible(false);
  mcCreatePlayer.setVisible(false);

  mcStandButton.setEditable(false);
  mcSplitButton.setEditable(false);
  mcDrawButton.setEditable(false);
  mcNewGame.setEditable(false);
  mcCreatePlayer.setEditable(false);

  mcDrawableWidget.push_back(&mcBetButton);
  mcDrawableWidget.push_back(&mcDrawButton);
  mcDrawableWidget.push_back(&mcNumPlayersInput);
  mcDrawableWidget.push_back(&mcSplitButton);
  mcDrawableWidget.push_back(&mcStandButton);
  mcDrawableWidget.push_back(&mcPlayerTypeInput);
  mcDrawableWidget.push_back(&mcNewGame);
  mcDrawableWidget.push_back(&mcCreatePlayer);
  mcDrawableWidget.push_back(&mcNameInput);
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
// Function:    nextRound
//
// Description: removes all the cards from the players' current hands
//
// Parameters:  None
//
// Returned:    None
//***************************************************************************
void BlackjackViewSDL::nextRound ()
{
  for(auto it = mcPlayers.begin(); it != mcPlayers.end(); it++)
    it->discardHand();
}

//***************************************************************************
// Function:    stand
//
// Description: advances to the next player
//
// Parameters:  None
//
// Returned:    None
//***************************************************************************
void BlackjackViewSDL::stand ()
{
  advancePlayer();
}

//***************************************************************************
// Function:    drawCard
//
// Description: updates the player's hand to reflect their new card
//
// Parameters:  card - the card that the player has drawn
//
// Returned:    None
//***************************************************************************
void BlackjackViewSDL::drawCard (std::string card)
{
  mcCurrentPlayer->addCard(this, card, true);
}

//***************************************************************************
// Function:    setNumPlayers
//
// Description: hide the UI to set the number of players and display the UI to
//              set the type of players
//
// Parameters:  None
//
// Returned:    None
//***************************************************************************
void BlackjackViewSDL::setNumPlayers ()
{
  mcNumPlayersInput.setVisible(false);
  mcPlayerTypeInput.setVisible(true);
  mcNameInput.setVisible(true);
  mcCreatePlayer.setVisible(true);
}

//***************************************************************************
// Function:    createPlayer
//
// Description: creates a PlayerView for the newly created player and adds it
//              to the object's data
//
// Parameters:  name - the name of the player
//
// Returned:    None
//***************************************************************************
void BlackjackViewSDL::createPlayer (std::string name)
{
  PlayerView cCreated;
  cCreated.setName(name);
  mcPlayers.push_back(cCreated);
  mcDrawableWidget.push_back((ISDLWidget*)&cCreated);
}

//***************************************************************************
// Function:    setPlayerType
//
// Description: Creates the UI for the newly added player and resets the data
//              in mcPlayerTypeInput
//
// Parameters:  None
//
// Returned:    None
//***************************************************************************
/*void BlackjackViewSDL::setPlayerType ()
{
  PlayerView cCreated;

  mcPlayers.push_back(cCreated);
  mcDrawableWidget.push_back((ISDLWidget*)&cCreated);

  mcPlayerTypeInput.setData("");
}*/

//***************************************************************************
// Function:    onStand
//
// Description: calls the stand function in the presenter
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
// Description: calls the draw function in the presenter
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
// Description: calls the split function in the presenter
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
// Function:    onSetNumPlayers
//
// Description: UI Event handler: call presenter
//
// Parameters:  number - the number of players being passed to the presenter
//
// Returned:    None
//***************************************************************************
void BlackjackViewSDL::onSetNumPlayers (int number)
{
  //we need to set the number of players in the presenter here
}

//***************************************************************************
// Function:    onSetPlayerType
//
// Description: UI Event handler: call presenter
//
// Parameters:  number - the number of players being passed to the presenter
//
// Returned:    None
//***************************************************************************
/*void BlackjackViewSDL::onSetPlayerType (std::string type)
{
  //set the type of the current player
}*/

//***************************************************************************
// Function:    onNewGame
//
// Description: UI Event handler: call presenter
//
// Parameters:  None
//
// Returned:    None
//***************************************************************************
void BlackjackViewSDL::onNewGame ()
{
  //mpcPresenter->newGame(); //I don't think this should take an int since we
  //dont know how many players there are yet?
}

//***************************************************************************
// Function:    onCreatePlayer
//
// Description: UI Event handler: call presenter
//
// Parameters:  name - the name of the player to be created
//              type - the type of player to be created
//
// Returned:    None
//***************************************************************************
void BlackjackViewSDL::onCreatePlayer (std::string name, std::string type)
{
  //so as I'm writing this the model doesn't seem to have a function to create
  //a new player. So this function is blank for now
}

//***************************************************************************
// Function:    onSetNumPlayersWidget
//
// Description: UI Event handler: call presenter
//
// Parameters:  string - the data from the UI widget
//
// Returned:    None
//***************************************************************************
void BlackjackViewSDL::onSetNumPlayersWidget (SDLTextWidget* widget)
{
  std::stringstream test(widget->getData());
  int val = -1;
  test >> val;

  if(val > 0 && val <= 4)
    onSetNumPlayers(val);
}

//***************************************************************************
// Function:    onBetWidget
//
// Description: UI Event handler: call presenter
//
// Parameters:  string - the data from the ui widget
//
// Returned:    None
//***************************************************************************
void BlackjackViewSDL::onBetWidget (SDLTextWidget* widget)
{
  std::stringstream test(widget->getData());
  int val = 0;
  test >> val;

  if(val > 0)
    onBet(val);
}

//***************************************************************************
// Function:    onSetPlayerTypeWidget
//
// Description: UI Event handler: call presenter
//
// Parameters:  string - the data from the UI widget
//
// Returned:    None
//***************************************************************************
/*void BlackjackViewSDL::onSetPlayerTypeWidget (SDLTextWidget* widget)
{
  //BIG PROBLEM
  //as it stands, we don't know when to hide mcPlayerTypeInput, since this
  //function has no way of knowing how many times it needs to run

  if(widget->getData() == "HUMAN" || widget->getData() == "COMPUTER" || 
    widget->getData() == "CARD COUNTER")
    onSetPlayerType(widget->getData());
}*/

//***************************************************************************
// Function:    onCreatePlayerWidget
//
// Description: UI Event handler: call presenter
//
// Parameters:  string - the data from the UI widget
//
// Returned:    None
//***************************************************************************
void BlackjackViewSDL::onCreatePlayerWidget (SDLTextWidget* name, SDLTextWidget* type)
{
  if (name->getData () != "")
  {
    if (type->getData () == "HUMAN" || type->getData () == "COMPUTER" ||
      type->getData () == "CARD COUNTER")
      onCreatePlayer(name->getData(), type->getData());
  }
}

//***************************************************************************
// Function:    render
//
// Description: draw all the widgets to the screen
//
// Parameters:  None
//
// Returned:    None
//***************************************************************************
void BlackjackViewSDL::render ()
{
  for (auto value : mcDrawableWidget)
  {
    if (value->isVisible ())
    {
      value->draw (*this);
    }
  }
}


//***************************************************************************
// Function:    advancePlayer
//
// Description: advances to the next player
//
// Parameters:  None
//
// Returned:    None
//***************************************************************************
void BlackjackViewSDL::advancePlayer ()
{
  mcCurrentPlayer++;
  if (mcCurrentPlayer == mcPlayers.end ())
    mcCurrentPlayer = mcPlayers.begin ();
}

//***************************************************************************
// File name:  
// Author:     
// Date:       5/7/2021
// Class:      CS485
// Assignment: Blackjack
// Purpose:    
//***************************************************************************

#include "BlackjackModel.h"
//***************************************************************************
// Constructor: BlackjackModel
//
// Description: Initializes member variables
//
// Parameters:  numPlayers - number of players
//              numDecks   - number of decks
//
// Return:			None
//***************************************************************************
BlackjackModel::BlackjackModel(int numPlayers, int numDecks){
  mCurrentPlayerIndex = 0;
  mcPlayers = std::vector<Player>(numPlayers);
  mpcDeck = std::make_shared<Deck>(numDecks);
  mpcDeck->fillShuffle();
  mbRoundDone = false;
}
//***************************************************************************
// Destructor:  BlackjackModel
//
// Description: resets deck
//
// Parameters:  None
//
// Return:			None
//***************************************************************************
BlackjackModel::~BlackjackModel(){
  mpcDeck.reset();
}
//***************************************************************************
// Function:    newGame
//
// Description: Checks to see if a new game can be started, if true, shuffles
//              deck
//
// Parameters:  None
//
// Return:			true if start game, false otherwise
//***************************************************************************
bool BlackjackModel::newGame(){
  if(getNumPlayers() == 0){
    return false;
  }
  for(int i = 0; i < getNumPlayers(); i++){
    if(!mcPlayers.at(i).readyToStart()){
      return false;
    }
  }
  mbRoundDone = false;
  mpcDeck->fillShuffle();
  initialDeal();
  return true;
}
//***************************************************************************
// Function:    newGame
//
// Description: Creates a new vector with number of players
//
// Parameters:  numPlayers - number of players
//
// Return:			function call to newGame
//***************************************************************************
bool BlackjackModel::newGame(int numPlayers){
  mcPlayers = std::vector<Player>(numPlayers);
  return newGame();
}
//***************************************************************************
// Function:    newGame
//
// Description: starts a new game with new player and new decks
//
// Parameters:  numPlayers - number of players
//              numDecks   - number of decks
//
// Return:			function call to new game
//***************************************************************************
bool BlackjackModel::newGame(int numPlayers, int numDecks){
  mpcDeck.reset();
  mpcDeck = std::make_shared<Deck>(numDecks);
  mpcDeck->fillShuffle();
  return newGame(numPlayers);
}
//***************************************************************************
// Function:    isBust
//
// Description: Checks to see if player is bust
//
// Parameters:  None
//
// Return:			True if bust, false otherwise
//***************************************************************************
bool BlackjackModel::isBust(){
  return isBust(mCurrentPlayerIndex);
}
//***************************************************************************
// Function:    isBust
//
// Description: checks to see if player is bust at index
//
// Parameters:  playerIndex - the player index
//
// Return:			true if bust, false otherwise
//***************************************************************************
bool BlackjackModel::isBust(int playerIndex){
  return mcPlayers.at(playerIndex).isFullyBust();
}
//***************************************************************************
// Function:    initialDeal
//
// Description: deals out cards
//
// Parameters:  none
//
// Return:			None
//***************************************************************************
void BlackjackModel::initialDeal(){
  mpcDeck->shuffle();
  for(int i = 0; i < getNumPlayers(); i++){
    mcPlayers.at(i).receiveCard(mpcDeck->draw());
  }
  mcDealerHand.addCard(mpcDeck->draw());
  Card cTemp = mpcDeck->draw();
  for(int i = 0; i < getNumPlayers(); i++){
    cTemp.flip();
    mcPlayers.at(i).receiveCard(cTemp);
    cTemp = mpcDeck->draw();
  }
  cTemp.flip();
  mcDealerHand.addCard(cTemp);
}
//***************************************************************************
// Function:    isHuman
//
// Description: Checks to see if player is human
//
// Parameters:  None
//
// Return:			true if human, false otherwise
//***************************************************************************
bool BlackjackModel::isHuman(){
  return isHuman(mCurrentPlayerIndex);
}
//***************************************************************************
// Function:    isHuman
//
// Description: checks to see if player is human
//
// Parameters:  index - the index in the player array
//
// Return:			true if human, false otherwise
//***************************************************************************
bool BlackjackModel::isHuman(int index){
  return mcPlayers.at(index).isHuman();
}
//***************************************************************************
// Function:    isBetTime
//
// Description: Checks to see if players are still betting
//
// Parameters:  None
//
// Return:			True if still betting, false otherwise
//***************************************************************************
bool BlackjackModel::isBetTime(){
  for(int i = 0; i < getNumPlayers(); i++){
    if(mcPlayers.at(i).getBet().getAmount() == -1){
      return true;
    }
  }
  return false;
}
//***************************************************************************
// Function:    moveDealer
//
// Description: Dealers makes a move through strategy
//
// Parameters:  None
//
// Return:			None
//***************************************************************************
void BlackjackModel::moveDealer(){
  std::shared_ptr<IMove> cDealerMove;
  std::vector<Card> cFaceUpCards = getFaceUpCards(); //Dealer doesn't use these
  //so could be an empty vector. Populating it correctly anyway but if worried
  //about run time minor efficiency opportunity here.
  mcDealerBrain.determineMove(mcDealerHand, cDealerMove, cFaceUpCards);
  cDealerMove->execute(*mpcDeck, mcDealerHand);
  if(cDealerMove->moveName() == "Stand"){
    mbRoundDone = true;
  }
}
//***************************************************************************
// Function:    makeMove
//
// Description: Current player makes move
//
// Parameters:  None
//
// Return:			None
//***************************************************************************
void BlackjackModel::makeMove(){
  std::shared_ptr<IMove> cCompMove;
  mcPlayers.at(mCurrentPlayerIndex).makeMove(cCompMove, getFaceUpCards());
  cCompMove->execute(*mpcDeck,
                     mcPlayers.at(mCurrentPlayerIndex));
  incrementPlayer();
}
//***************************************************************************
// Function:    nextRound
//
// Description: Adds a status of all players to vector and returns it
//
// Parameters:  None
//
// Return:			vector of Status enums
//***************************************************************************
std::vector<Status> BlackjackModel::nextRound()
{
  std::vector<Status> results;
  
  if(!mbRoundDone){
    return results;
  }
  
  results = result();
  
  for(int i = 0; i < getNumPlayers(); i++){
    mcPlayers.at(i).endRound();
  }
  mbRoundDone = false;
  mbBetReady = true;

  mpcDeck.get()->fillShuffle();
  
  initialDeal();
  
  return results;
}
//***************************************************************************
// Function:    result
//
// Description: Adds a status of all players to vector and returns it
//
// Parameters:  None
//
// Return:			vector of Status enums		
//***************************************************************************
std::vector<Status> BlackjackModel::result(){
  std::vector<Status> results;
  
  for(int i = 0; i < getNumPlayers(); i++){
    results.push_back(resultCurrentPlayer());
    mCurrentPlayerIndex = getNextPlayer();
  }
  
  return results;
}
//***************************************************************************
// Function:    makeBet
//
// Description: Takes a bet from the player
//
// Parameters:  cBet - a money object with the amount
//
// Return:			true if bet is made, false otherwise
//***************************************************************************
bool BlackjackModel::makeBet(Money cBet){
  return mcPlayers.at(mCurrentPlayerIndex).makeBet(cBet);
}
//***************************************************************************
// Function:    stand
//
// Description: makes a player stand
//
// Parameters:  None
//
// Return:			None
//***************************************************************************
void BlackjackModel::stand(){
  bool bSuccess = false;
  if(isHuman()){
    std::shared_ptr<IMove> pcMove = std::make_shared<Stand>();
    bSuccess = mcPlayers.at(mCurrentPlayerIndex).makeMove(pcMove, getFaceUpCards());
    pcMove->execute(*mpcDeck, mcPlayers.at(mCurrentPlayerIndex));
    incrementPlayer();
  }
}
//***************************************************************************
// Function:    split
//
// Description: checks to see if player can split
//
// Parameters:  None
//
// Return:			True if can split, false otherwise
//***************************************************************************
bool BlackjackModel::split(){
  bool bSuccess = false;
  if(isHuman()){
    std::shared_ptr<IMove> pcMove = std::make_shared<Split>();
    bSuccess = mcPlayers.at(mCurrentPlayerIndex).makeMove(pcMove, getFaceUpCards());
    pcMove->execute(*mpcDeck, mcPlayers.at(mCurrentPlayerIndex));
    incrementPlayer();
  }
  return bSuccess;
}
//***************************************************************************
// Function:    drawCard
//
// Description: Current player draws card
//
// Parameters:  None
//
// Return:			None
//***************************************************************************
void BlackjackModel::drawCard(){
  bool bSuccess = false;
  if(isHuman()){
    std::shared_ptr<IMove> pcMove = std::make_shared<Draw>();
    bSuccess = mcPlayers.at(mCurrentPlayerIndex).makeMove(pcMove, getFaceUpCards());
    pcMove->execute(*mpcDeck, mcPlayers.at(mCurrentPlayerIndex));
    incrementPlayer();
  }
}
//***************************************************************************
// Function:    setPlayerName
//
// Description: Sets the players name at the current index
//
// Parameters:  name - name of player
//
// Return:			None
//***************************************************************************
void BlackjackModel::setPlayerName(std::string name){
  setPlayerName(name, mCurrentPlayerIndex);
}
//***************************************************************************
// Function:    setPlayerName
//
// Description: Sets the player name at the index
//
// Parameters:  name  - name of player
//              index - index of player
//
// Return:			None
//***************************************************************************
void BlackjackModel::setPlayerName(std::string name, int index){
  mcPlayers.at(index).setName(name);
}
//***************************************************************************
// Function:    setPlayerType
//
// Description: Sets the type of player for current player
//
// Parameters:  stratType - the player type
//
// Return:			None
//***************************************************************************
void BlackjackModel::setPlayerType(std::string stratType){
  setPlayerType(stratType, mCurrentPlayerIndex);
}
//***************************************************************************
// Function:    setPlayerType
//
// Description: Sets the player type at the index
//
// Parameters:  stratType - player type
//              index     - index of the player
//
// Return:			None
//***************************************************************************
void BlackjackModel::setPlayerType(std::string stratType, int index){
  MoveStrategyFactory stratMaker;
  std::shared_ptr<IMoveStrategy> moveStrat = stratMaker.makeStrategy(stratType);
  if(moveStrat != nullptr){
    mcPlayers.at(index).changeStrat(moveStrat);
  }
  return;
}
//***************************************************************************
// Function:    getTypeList
//
// Description: Returns the list of strategies
//
// Parameters:  None
//
// Return:			Returns the list of strategies
//***************************************************************************
std::vector<std::string> BlackjackModel::getTypeList(){
  return MoveStrategyFactory::listStrats();
}
//***************************************************************************
// Function:    getCurrentPlayerHand
//
// Description: returns the current player's hand to display in string form
//
// Parameters:  None
//
// Return:			vector of strings of card values and ranks
//***************************************************************************
std::vector<std::string> BlackjackModel::getCurrentPlayerHand(){
  std::vector<std::string> cardStrs;
  std::vector<Card> cCards = mcPlayers.at(mCurrentPlayerIndex).getCurrentHand().getHand();

  for (Card card : cCards)
  {
    if(!card.isFaceUp()){
      card.flip();
      cardStrs.push_back(toString(card));
      card.flip();
    }
    else{
      cardStrs.push_back(toString(card));
    }
  }

  return cardStrs;
}
//***************************************************************************
// Function:    getOpponentCards
//
// Description: returns the opponents' cards
//
// Parameters:  None
//
// Return:			2d vector of strings of opponent's cards
//***************************************************************************
std::vector<std::vector<std::string>> BlackjackModel::getOpponentCards(){
  std::vector<std::vector<std::string>> stringHands(getNumPlayers());
  std::vector<std::vector<Card>> cCardHands;
  
  //get hands
  for(int i = getNextPlayer(mCurrentPlayerIndex); i != mCurrentPlayerIndex;
      i = getNextPlayer(i)){
    std::vector<Card> cThisPlayerCards;
    for(int j = 0; j < mcPlayers.at(i).getNumHands(); j++){
      std::vector<Card> cCurrentHand = mcPlayers.at(i).getHands().at(j).getHand();
      cThisPlayerCards.insert(cThisPlayerCards.end(), cCurrentHand.begin(),
                              cCurrentHand.end());
    }
    cCardHands.push_back(cThisPlayerCards);
  }
  
  //stringify hands
  for(int i = 0; i < cCardHands.size(); i++){
    for(int j = 0; j < cCardHands.at(i).size(); j++){
      stringHands.at(i).push_back(toString(cCardHands.at(i).at(j)));
    }
  }
  
  return stringHands;
}
//***************************************************************************
// Function:    getFaceUpCards
//
// Description: returns all face up cards
//
// Parameters:  None
//
// Return:			vector of face up cards
//***************************************************************************
std::vector<Card> BlackjackModel::getFaceUpCards(){
  std::vector<Card> cAllFaceUp;
  std::vector<Card> cThisFaceUp;
  for(int i = 0; i < getNumPlayers(); i++){
    cThisFaceUp = mcPlayers.at(i).getFaceUpCards();
    cAllFaceUp.insert(cAllFaceUp.end(), cThisFaceUp.begin(),
                      cThisFaceUp.end());
  }
  return cAllFaceUp;
}
//***************************************************************************
// Function:    getName
//
// Description: get name of current player
//
// Parameters:  None
//
// Return:			current player name
//***************************************************************************
std::string BlackjackModel::getName(){
  return getName(mCurrentPlayerIndex);
}
//***************************************************************************
// Function:    getName
//
// Description: get name of player at index
//
// Parameters:  index - index of player
//
// Return:			the name of player at index
//***************************************************************************
std::string BlackjackModel::getName(int index){
  return mcPlayers.at(index).getName();
}
//***************************************************************************
// Function:    getNumPlayers
//
// Description: return the number of players
//
// Parameters:  None
//
// Return:			number of players
//***************************************************************************
int BlackjackModel::getNumPlayers(){
  return (int)mcPlayers.size();
}
//***************************************************************************
// Function:    getBalance
//
// Description: get balance of current player
//
// Parameters:  none
//
// Return:			the balance in long long
//***************************************************************************
long long BlackjackModel::getBalance(){
  return getBalance(mCurrentPlayerIndex);
}
//***************************************************************************
// Function:    getBalance
//
// Description: get balance of player at index
//
// Parameters:  index - index of player
//
// Return:			the balance in long long
//***************************************************************************
long long BlackjackModel::getBalance(int index){
  return mcPlayers.at(index).getBank().getAmount();
}
//***************************************************************************
// Function:    getBet
//
// Description: get bet of player at current player
//
// Parameters:  none
//
// Return:			bet of current player
//***************************************************************************
long long BlackjackModel::getBet(){
  return getBet(mCurrentPlayerIndex);
}
//***************************************************************************
// Function:    getBet
//
// Description: get bet of player at index
//
// Parameters:  index - index of player
//
// Return:			bet of player at index
//***************************************************************************
long long BlackjackModel::getBet(int index){
  return mcPlayers.at(index).getBet().getAmount();
}
//***************************************************************************
// Function:    toString
//
// Description: return the card value and suit in form of string
//
// Parameters:  cCard - the card object
//
// Return:			a string of card value and suit
//***************************************************************************
std::string BlackjackModel::toString (Card cCard)
{
  std::string cardStr = "";
  auto suit = cCard.getSuit();
  auto rank = cCard.getValue();

  if (!cCard.isFaceUp() && !mbRoundDone)
  {
    cardStr = "--";
  }
  else
  {
    // Adds the rank
    switch (rank)
    {
    case Value::Ace:
      cardStr += "A";
      break;

    case Value::Two:
      cardStr += "2";
      break;

    case Value::Three:
      cardStr += "3";
      break;

    case Value::Four:
      cardStr += "4";
      break;

    case Value::Five:
      cardStr += "5";
      break;

    case Value::Six:
      cardStr += "6";
      break;

    case Value::Seven:
      cardStr += "7";
      break;

    case Value::Eight:
      cardStr += "8";
      break;

    case Value::Nine:
      cardStr += "9";
      break;

    case Value::Ten:
      cardStr += "10";
      break; 

    case Value::Jack:
      cardStr += "J";
      break;

    case Value::Queen:
      cardStr += "Q";
      break;

    case Value::King:
      cardStr += "K";
      break;
        
    case Value::Count:
      break;
    }

    // Adds the suit
    switch (suit)
    {
    case Suit::Clubs:
      cardStr += "C";
      break;

    case Suit::Diamonds:
      cardStr += "D";
      break;

    case Suit::Hearts:
      cardStr += "H";
      break;

    case Suit::Spades:
      cardStr += "S";
      break;
        
    case Suit::Count:
      break;
    }
  }

  return cardStr;
}
//***************************************************************************
// Function:    canSplit
//
// Description: checks to see if player can split
//
// Parameters:  none
//
// Return:			true if can split, false otherwise
//***************************************************************************
bool BlackjackModel::canSplit()
{
  //Only the first hand may be split
  return mcPlayers[mCurrentPlayerIndex].getHands().at(0).canSplit() && 
         mcPlayers[mCurrentPlayerIndex].canSplit();
}
//***************************************************************************
// Function:    getDealerCards
//
// Description: returns the hand of the dealer
//
// Parameters:  None
//
// Return:			returns a string of card values and suits
//***************************************************************************
std::vector<std::string> BlackjackModel::getDealerCards()
{
  std::vector <std::string> stringArry;
  
  for (int i = 0; i < mcDealerHand.getHand().size(); i++)
  {
    stringArry.push_back(toString(mcDealerHand.getHand().at(i)));
  }
  return stringArry;
}
//***************************************************************************
// Function:    roundDone
//
// Description: return mbRoundDone
//
// Parameters:  None
//
// Return:			mbRoundDone
//***************************************************************************
bool BlackjackModel::roundDone(){
  return mbRoundDone;
}


bool BlackjackModel::lastUnder() // Author: Julian Bunch
{
  return mcPlayers[mcPlayers.size() - 1].getCurrentHand().getHandValue() < 21;
}

//***************************************************************************
// Function:    doCPUMoves
//
// Description: the AI make their move
//
// Parameters:  None
//
// Return:			None
//***************************************************************************
void BlackjackModel::doCPUMoves(){
  while(!isHuman()){
    makeMove();
  }
}
//***************************************************************************
// Function:    doCPUBets
//
// Description: AI make their bets
//
// Parameters:  None
//
// Return:			None
//***************************************************************************
void BlackjackModel::doCPUBets(){
  while(!isHuman() && isBetTime()){
    if(mcPlayers.at(mCurrentPlayerIndex).getBet().getAmount() == -1){
      makeBet();
    }
    else{
      incrementPlayer();
    }
  }
}
int BlackjackModel::getCurrentPlayer()
{
  return mCurrentPlayerIndex;
}
//***************************************************************************
// Function:    resultCurrentPlayer
//
// Description: checks the result of the current player to see their status
//
// Parameters:  None
//
// Return:			return the status of the player
//***************************************************************************
Status BlackjackModel::resultCurrentPlayer()
{
  Status eStatus;
  int sum = mcPlayers[mCurrentPlayerIndex].getCurrentHand().getHandValue();
  int dealerSum = mcDealerHand.getHandValue();

  if (sum == (int) Status::Blackjack)
  {
    eStatus = Status::Blackjack;
  }
  else if (sum > dealerSum && sum < (int) Status::Blackjack)
  {
    eStatus = Status::Win;
  }
  else if (sum > (int) Status::Blackjack)
  {
    eStatus = Status::Bust;
  }
  else
  {
    eStatus = Status::Lose;
  }

  return eStatus;
}
//***************************************************************************
// Function:    incrementPlayer
//
// Description: Moves the player index to the next
//
// Parameters:  None
//
// Return:			None
//***************************************************************************
void BlackjackModel::incrementPlayer() {
  mCurrentPlayerIndex = getNextPlayer();
  if (mCurrentPlayerIndex == 0) {
      moveDealer();
  }
}
//***************************************************************************
// Function:    getNextPlayer
//
// Description: Calls getNextPlayer
//
// Parameters:  none
//
// Return:			return the int of the next player
//***************************************************************************
int BlackjackModel::getNextPlayer(){
  return getNextPlayer(mCurrentPlayerIndex);
}
//***************************************************************************
// Function:    getNextPlayer
//
// Description: return the int of the next player
//
// Parameters:  currentPlayer - index of current player
//
// Return:			current player index
//***************************************************************************
int BlackjackModel::getNextPlayer(int currentPlayer){
  if(++currentPlayer >= getNumPlayers()){
    return 0;
  }
  else{
    return currentPlayer;
  }
}

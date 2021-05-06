//This is just so it will actually build (otherwise the project gives an unresolved external linker error because nomain.

#include "BlackjackModel.h"
int main() {
  BlackjackModel test;
  
  test.newGame(5);
  for(int i = 0; i < 4; i++){
    test.setPlayerType("Card Counter", i);
  }
  test.setPlayerType("Human", 4);
  
  test.newGame();
  while(test.isBetTime()){
    if(!test.isHuman()){
      test.makeBet();
    }
    else{
      test.makeBet(Money(10,Currency::USD));
    }
  }
  
  while(!test.isHuman()){
    test.makeMove();
  }
  test.stand();
	return 0;
}

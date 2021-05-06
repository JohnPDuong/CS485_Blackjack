//This is just so it will actually build (otherwise the project gives an unresolved external linker error because nomain.

#include "BlackjackModel.h"
int main() {
	BlackjackModel cGame;

	cGame.newGame(5);

	return 0;
}

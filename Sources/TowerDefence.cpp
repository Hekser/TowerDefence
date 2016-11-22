#include "Game.h"

int main()
{
	Game *game = new Game;

	game->startMenu();
	game->play();

	delete game;
	game = NULL;

	return 0;
}
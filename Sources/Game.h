#pragma once

#include "MenuTextures.h"
#include "Map.h"

class Game
{
public:
	Game();
	~Game();
	void startMenu();
	void play();
private:
	MenuTextures *menuTextures;
	Player *player;
	Map *map;
};
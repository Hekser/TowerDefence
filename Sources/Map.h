#pragma once

#include "GameTextures.h"
#include "Sorcerer.h"
#include "Paladin.h"
#include "Warior.h"
#include "Archer.h"

class Map
{
public:
	Map(Player);
	~Map();
	void start();
private:
	GameTextures *gameTextures;
	Champion *champion;
	LevelCreator *levelCreator;
	int level;
	int numberOfMonsters;
	String string;

	double getTime();
	void endGame(RenderWindow &, bool);
};
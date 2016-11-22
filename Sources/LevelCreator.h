#pragma once

#include "NormalMonster.h"
#include "FlyingMonster.h"
#include "BossMonster.h"
#include <ctime>
#include <cstdlib>

class LevelCreator
{
public:
	LevelCreator(Vector2f);
	~LevelCreator();
	Monster & getMonster(int, int);
	int getCountOfMonsters(int);
	int getNumberOfLevels();
private:
	vector<vector<Monster *>> monsters;

	void setVectorToNULL(vector<Monster *> &);
};
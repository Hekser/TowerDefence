#include "LevelCreator.h"

LevelCreator::LevelCreator(Vector2f screenBoxSize)
{
	srand((unsigned int)time(NULL));

	vector<Monster *> tmp;

	tmp.push_back(new NormalMonster(screenBoxSize));
	tmp.push_back(new NormalMonster(screenBoxSize));
	tmp.push_back(new NormalMonster(screenBoxSize));
	tmp.push_back(new FlyingMonster(screenBoxSize));
	tmp.push_back(new FlyingMonster(screenBoxSize));
	tmp.push_back(new NormalMonster(screenBoxSize));
	tmp.push_back(new FlyingMonster(screenBoxSize));
	tmp.push_back(new NormalMonster(screenBoxSize));
	tmp.push_back(new FlyingMonster(screenBoxSize));
	tmp.push_back(new BossMonster(screenBoxSize));

	this->monsters.push_back(tmp);

	setVectorToNULL(tmp);
	tmp.clear();

	tmp.push_back(new NormalMonster(screenBoxSize));
	tmp.push_back(new NormalMonster(screenBoxSize));
	tmp.push_back(new NormalMonster(screenBoxSize));
	tmp.push_back(new FlyingMonster(screenBoxSize));
	tmp.push_back(new FlyingMonster(screenBoxSize));
	tmp.push_back(new NormalMonster(screenBoxSize));
	tmp.push_back(new FlyingMonster(screenBoxSize));
	tmp.push_back(new NormalMonster(screenBoxSize));
	tmp.push_back(new FlyingMonster(screenBoxSize));
	tmp.push_back(new NormalMonster(screenBoxSize));
	tmp.push_back(new FlyingMonster(screenBoxSize));
	tmp.push_back(new NormalMonster(screenBoxSize));
	tmp.push_back(new FlyingMonster(screenBoxSize));
	tmp.push_back(new BossMonster(screenBoxSize));
	tmp.push_back(new BossMonster(screenBoxSize));

	this->monsters.push_back(tmp);

	setVectorToNULL(tmp);
	tmp.clear();

	tmp.push_back(new BossMonster(screenBoxSize));
	tmp.push_back(new NormalMonster(screenBoxSize));
	tmp.push_back(new FlyingMonster(screenBoxSize));
	tmp.push_back(new FlyingMonster(screenBoxSize));
	tmp.push_back(new NormalMonster(screenBoxSize));
	tmp.push_back(new FlyingMonster(screenBoxSize));
	tmp.push_back(new NormalMonster(screenBoxSize));
	tmp.push_back(new FlyingMonster(screenBoxSize));
	tmp.push_back(new NormalMonster(screenBoxSize));
	tmp.push_back(new NormalMonster(screenBoxSize));
	tmp.push_back(new NormalMonster(screenBoxSize));
	tmp.push_back(new FlyingMonster(screenBoxSize));
	tmp.push_back(new FlyingMonster(screenBoxSize));
	tmp.push_back(new NormalMonster(screenBoxSize));
	tmp.push_back(new FlyingMonster(screenBoxSize));
	tmp.push_back(new NormalMonster(screenBoxSize));
	tmp.push_back(new FlyingMonster(screenBoxSize));
	tmp.push_back(new BossMonster(screenBoxSize));
	tmp.push_back(new BossMonster(screenBoxSize));
	tmp.push_back(new BossMonster(screenBoxSize));

	this->monsters.push_back(tmp);

	setVectorToNULL(tmp);
	tmp.clear();
}

LevelCreator::~LevelCreator()
{
	for (int i = 0; i < monsters.size(); ++i)
	{
		for (int j = 0; j < monsters[i].size(); ++j)
		{
			delete monsters[i][j];
			monsters[i][j] = NULL;
		}

		monsters[i].clear();
	}

	monsters.clear();
}

Monster & LevelCreator::getMonster(int level, int i)
{
	return *(monsters[level - 1][i]);
}

int LevelCreator::getCountOfMonsters(int level)
{
	return (int)(this->monsters[level - 1].size());
}

int LevelCreator::getNumberOfLevels()
{
	return (int)(monsters.size());
}

void LevelCreator::setVectorToNULL(vector<Monster*> &vector)
{
	for (int i = 0; i < vector.size(); ++i)
	{
		vector[i] = NULL;
	}
}
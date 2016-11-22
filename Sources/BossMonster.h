#pragma once

#include "Monster.h"

class BossMonster : public Monster
{
public:
	BossMonster(Vector2f);
	~BossMonster();
	void move(vector<Missile *> &);
private:
	int missileDamage;

	float targetPosition;
	float maxAttackHeight;
	float minAttackHeight;
	float attackSize;

	bool allowReaction;
	bool allowMove;
	double startReactionTime;
	double endReactionTime;
	double timeToNextMissile;
};
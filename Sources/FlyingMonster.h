#pragma once

#include "Monster.h"

class FlyingMonster : public Monster
{
public:
	FlyingMonster(Vector2f);
	~FlyingMonster();
	void move(vector<Missile *> &);
private:
	float maxHeight;
	float minHeight;
	float verticalSpeed;

	bool upFlying;
	bool allowReaction;
	float distanceToReaction;
};
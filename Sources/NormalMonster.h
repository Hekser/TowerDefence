#pragma once

#include "Monster.h"

class NormalMonster : public Monster
{
public:
	NormalMonster(Vector2f);
	~NormalMonster();
	void move(vector<Missile *> &);
private:
	float baseMovementSpeed;

	Vector2f reactionRangeStart;
	Vector2f reactionRangeEnd;

	bool allowReaction;
	bool forwardMovement;
	float dodgeDistance;
	float distanceToDodge;

	void setReactionRange();
};
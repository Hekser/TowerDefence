#pragma once

#include "Missile.h"
#include <vector>

using namespace std;

class Monster
{
public:
	Monster(Vector2f, Vector2f);
	virtual ~Monster();
	RectangleShape & getRectangleShape();
	RectangleShape & getRectangleHP();
	float getPosition();
	int getAttackDamage();
	int getHP();
	void dealDamage(int);
	virtual void move(vector<Missile *> &) = 0;
protected:
	Vector2f monsterBoxSize;
	Vector2f monsterBoxPosition;

	RectangleShape monsterBox;
	RectangleShape monsterBoxHP;

	void setHPPosition();

	int attackDamage;
	int HP;
	int baseHP;
	float movementSpeed;
};
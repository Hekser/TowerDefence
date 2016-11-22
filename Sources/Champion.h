#pragma once

#include "GameTextures.h"

class Champion
{
public:
	Champion(string);
	virtual ~Champion();
	string getName();
	int getHP();
	void heal(int);
	void dealDamage(int);
	double getHPProportion();
	int getAttackDamage();
	void upgradeAttackDamage(int);
	int getMoney();
	void addMoney(int);
	void takeMoney(int);
protected:
	const string name;
	int HP;
	int baseHP;
	int attackDamage;
	int money;
};
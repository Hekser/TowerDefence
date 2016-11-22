#include "Champion.h"

Champion::Champion(string name) :
	name(name), HP(0), baseHP(0), attackDamage(0), money(0)
{
}

Champion::~Champion()
{
}

string Champion::getName()
{
	return this->name;
}

int Champion::getHP()
{
	return this->HP;
}

void Champion::heal(int HP)
{
	this->HP += HP;
	
	if (this->HP > 10000)
	{
		this->HP = 10000;
	}

	if (this->HP > baseHP)
	{
		baseHP = this->HP;
	}
}

void Champion::dealDamage(int damage)
{
	this->HP -= damage;

	if (this->HP < 0)
	{
		this->HP = 0;
	}
}

double Champion::getHPProportion()
{
	return ((double)HP / (double)baseHP);
}

int Champion::getAttackDamage()
{
	return this->attackDamage;
}

void Champion::upgradeAttackDamage(int attackDamage)
{
	this->attackDamage += attackDamage;

	if (this->attackDamage > 999)
	{
		this->attackDamage = 999;
	}
}

int Champion::getMoney()
{
	return this->money;
}

void Champion::addMoney(int money)
{
	this->money += money;

	if (this->money > 9999)
	{
		this->money = 9999;
	}
}

void Champion::takeMoney(int money)
{
	this->money -= money;

	if (this->money < 0)
	{
		this->money = 0;
	}
}
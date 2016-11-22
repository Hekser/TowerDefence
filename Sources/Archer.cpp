#include "Archer.h"

Archer::Archer(string name) :
	Champion(name)
{
	this->HP = 175;
	this->baseHP = HP;
	this->attackDamage = 15;
}

Archer::~Archer()
{
}
#include "Paladin.h"

Paladin::Paladin(string name) :
	Champion(name)
{
	this->HP = 250;
	this->baseHP = HP;
	this->attackDamage = 20;
}

Paladin::~Paladin()
{
}
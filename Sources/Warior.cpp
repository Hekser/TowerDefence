#include "Warior.h"

Warior::Warior(string name) :
	Champion(name)
{
	this->HP = 300;
	this->baseHP = HP;
	this->attackDamage = 10;
}

Warior::~Warior()
{
}
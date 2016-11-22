#include "Sorcerer.h"

Sorcerer::Sorcerer(string name) :
	Champion(name)
{
	this->HP = 75;
	this->baseHP = HP;
	this->attackDamage = 25;
}

Sorcerer::~Sorcerer()
{
}
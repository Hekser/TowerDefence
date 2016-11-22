#include "Monster.h"

Monster::Monster(Vector2f monsterBoxSize, Vector2f monsterBoxPosition) :
	monsterBoxSize(monsterBoxSize), monsterBoxPosition(monsterBoxPosition), HP(0), baseHP(0), attackDamage(0), movementSpeed(0)
{
	monsterBox.setSize(monsterBoxSize);
	monsterBox.setOrigin(0, monsterBoxSize.y);
	monsterBox.setPosition(monsterBoxPosition);

	monsterBoxHP.setSize(Vector2f(monsterBoxSize.x, monsterBoxPosition.x * 0.0024305f));
	monsterBoxHP.setFillColor(Color::Red);
	setHPPosition();
}

Monster::~Monster()
{
}

RectangleShape & Monster::getRectangleShape()
{
	return this->monsterBox;
}

RectangleShape & Monster::getRectangleHP()
{
	return this->monsterBoxHP;
}

float Monster::getPosition()
{
	return monsterBox.getPosition().x;
}

int Monster::getAttackDamage()
{
	return this->attackDamage;
}

int Monster::getHP()
{
	return this->HP;
}

void Monster::dealDamage(int damage)
{
	this->HP -= damage;

	monsterBoxHP.setSize(Vector2f(monsterBox.getSize().x * ((float)HP / (float)baseHP), monsterBoxHP.getSize().y));
}

void Monster::setHPPosition()
{
	Vector2f newPosition(this->monsterBox.getPosition().x, this->monsterBox.getPosition().y - this->monsterBoxSize.y - (this->monsterBoxPosition.x * 0.01388f));
	this->monsterBoxHP.setPosition(newPosition);
}
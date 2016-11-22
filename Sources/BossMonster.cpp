#include "BossMonster.h"

BossMonster::BossMonster(Vector2f screenBoxSize) :
	Monster(Vector2f(screenBoxSize.x * 0.06f, screenBoxSize.y * 0.16f), Vector2f(screenBoxSize.x, screenBoxSize.y * 0.975f))
{
	this->attackDamage = 35;
	this->HP = 500;
	this->baseHP = HP;
	this->movementSpeed = screenBoxSize.x * 0.00052083f;

	this->missileDamage = 15;

	this->targetPosition = screenBoxSize.x * 0.177f;
	this->maxAttackHeight = screenBoxSize.y * 0.3703f;
	this->minAttackHeight = screenBoxSize.y * 0.8641f;
	this->attackSize = this->monsterBoxSize.y * 0.15f;

	this->allowReaction = true;
	this->allowMove = true;
	this->startReactionTime = 0;
	this->endReactionTime = 0;
	this->timeToNextMissile = 0;
}

BossMonster::~BossMonster()
{
}

void BossMonster::move(vector<Missile *> &missiles)
{
	if (rand() % 500 == 0 && allowReaction && this->getRectangleShape().getPosition().x > this->targetPosition * 1.5)
	{
		this->startReactionTime = (clock() / CLOCKS_PER_SEC) + 1;
		this->endReactionTime = this->startReactionTime + rand() % (5 - 3 + 1) + 3;
		this->timeToNextMissile = this->startReactionTime;

		this->allowReaction = false;
		this->allowMove = false;
	}

	if ((clock() / CLOCKS_PER_SEC) >= timeToNextMissile && !allowReaction)
	{
		if (timeToNextMissile < this->endReactionTime)
		{
			++timeToNextMissile;

			Vector2f startAttackPosition(this->monsterBox.getPosition().x - this->attackSize - 1.0f, this->monsterBox.getPosition().y - this->monsterBoxSize.y * 0.5f);
			Vector2i endAttackPosition((int)this->targetPosition, (rand() % (int)(minAttackHeight - maxAttackHeight)) + (int)maxAttackHeight);

			missiles.push_back(new Missile(startAttackPosition, endAttackPosition, this->attackSize, this->missileDamage, false));
			missiles[missiles.size() - 1]->getCircleShape().setTexture(this->monsterBox.getTexture());
			missiles[missiles.size() - 1]->getCircleShape().setFillColor(Color::Black);
		}
		else
		{
			this->allowReaction = true;
			this->allowMove = true;
		}
	}

	if (allowMove)
	{
		this->monsterBox.move(Vector2f(-movementSpeed, 0.0f));
	}

	setHPPosition();
}
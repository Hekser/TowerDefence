#include "FlyingMonster.h"
#include <math.h>
FlyingMonster::FlyingMonster(Vector2f screenBoxSize) :
	Monster(Vector2f(screenBoxSize.x * 0.03f, screenBoxSize.y * 0.08f), Vector2f(screenBoxSize.x, screenBoxSize.y * (float)(((rand() % (6419 - 4133)) + 4133) / 10000.0)))
{
	this->attackDamage = 10;
	this->HP = 75;
	this->baseHP = HP;
	this->movementSpeed = screenBoxSize.x * 0.00086805f;

	this->maxHeight = screenBoxSize.y * 0.4133f;
	this->minHeight = screenBoxSize.y * 0.6419f;
	this->verticalSpeed = this->movementSpeed * 0.5f;

	this->upFlying = (bool)(rand() % 2);
	this->allowReaction = true;
	this->distanceToReaction = 0;
}

FlyingMonster::~FlyingMonster()
{
}

void FlyingMonster::move(vector<Missile *> &missiles)
{
	if (distanceToReaction > this->monsterBox.getPosition().x)
	{
		allowReaction = true;
	}

	for (int i = 0; i < missiles.size(); ++i)
	{
		if (missiles[i]->isPositiveEffect() && allowReaction)
		{
			Vector2f missilePosition(missiles[i]->getPosition());

			if (missilePosition.x >= (this->monsterBox.getPosition().x - this->monsterBoxSize.x * 3) && missilePosition.x <= (this->monsterBox.getPosition().x + this->monsterBoxSize.x))
			{
				if ((missilePosition.y >= (this->monsterBox.getPosition().y - this->monsterBoxSize.y * 2.5) && missilePosition.y <= (this->monsterBox.getPosition().y - this->monsterBoxSize.y * 0.5) && upFlying) ||
					(missilePosition.y >(this->monsterBox.getPosition().y - this->monsterBoxSize.y * 0.5) && missilePosition.y <= (this->monsterBox.getPosition().y + this->monsterBoxSize.y * 1.5) && !upFlying))
				{
					this->upFlying = !upFlying;
					this->allowReaction = false;
					this->distanceToReaction = this->monsterBox.getPosition().x - this->monsterBoxSize.x * 6;
				}
			}
		}
	}

	if (upFlying)
	{
		this->monsterBox.move(Vector2f(-movementSpeed, -verticalSpeed));

		if (this->monsterBox.getPosition().y < maxHeight)
		{
			this->upFlying = false;
		}
	}
	else
	{
		this->monsterBox.move(Vector2f(-movementSpeed, verticalSpeed));

		if (this->monsterBox.getPosition().y > minHeight)
		{
			this->upFlying = true;
		}
	}

	setHPPosition();
}
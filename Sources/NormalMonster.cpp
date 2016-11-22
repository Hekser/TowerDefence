#include "NormalMonster.h"

NormalMonster::NormalMonster(Vector2f screenBoxSize) :
	Monster(Vector2f(screenBoxSize.x * 0.03f, screenBoxSize.y * 0.08f), Vector2f(screenBoxSize.x, screenBoxSize.y * 0.975f))
{
	this->attackDamage = 15;
	this->HP = 100;
	this->baseHP = HP;
	this->movementSpeed = screenBoxSize.x * 0.00052083f;

	this->baseMovementSpeed = this->movementSpeed;
	this->allowReaction = true;
	this->forwardMovement = true;
	this->dodgeDistance = 0;
	this->distanceToDodge = 0;

	setReactionRange();
}

NormalMonster::~NormalMonster()
{
}

void NormalMonster::move(vector<Missile *> &missiles)
{
	if (distanceToDodge > this->monsterBox.getPosition().x)
	{
		allowReaction = true;
	}

	if (forwardMovement && dodgeDistance > this->monsterBox.getPosition().x)
	{
		this->movementSpeed = this->baseMovementSpeed;
	}
	else if ((!forwardMovement) && dodgeDistance < this->monsterBox.getPosition().x)
	{
		this->movementSpeed = this->baseMovementSpeed;
		this->forwardMovement = true;
	}

	for (int i = 0; i < missiles.size(); ++i)
	{
		if (missiles[i]->isPositiveEffect() && allowReaction)
		{
			Vector2f missilePosition(missiles[i]->getPosition());

			if (missilePosition.x >= (reactionRangeStart.x + monsterBoxSize.x * 2) && missilePosition.x <= reactionRangeEnd.x && missilePosition.y >= reactionRangeStart.y && missilePosition.y <= (reactionRangeEnd.y - monsterBoxSize.y * 2.0))
			{
				this->allowReaction = false;
				this->movementSpeed = this->movementSpeed * 5;
				this->dodgeDistance = this->monsterBox.getPosition().x - this->monsterBoxSize.x * 3;
				this->distanceToDodge = this->monsterBox.getPosition().x - this->monsterBoxSize.x * 9;
			}
			else if (missilePosition.x >= reactionRangeStart.x && missilePosition.x <= reactionRangeEnd.x && missilePosition.y >= reactionRangeStart.y && missilePosition.y <= reactionRangeEnd.y)
			{
				this->allowReaction = false;
				this->forwardMovement = false;
				this->movementSpeed = -(this->movementSpeed * 5);
				this->dodgeDistance = this->monsterBox.getPosition().x + this->monsterBoxSize.x * 3;
				this->distanceToDodge = this->monsterBox.getPosition().x - this->monsterBoxSize.x * 6;
			}
		}
	}
	
	this->monsterBox.move(Vector2f(-movementSpeed, 0.0f));

	setHPPosition();
	setReactionRange();
}

void NormalMonster::setReactionRange()
{
	this->reactionRangeStart = Vector2f(this->monsterBox.getPosition().x - this->monsterBoxSize.x * 3, this->monsterBox.getPosition().y - this->monsterBoxSize.y * 2.5f);
	this->reactionRangeEnd = Vector2f(this->monsterBox.getPosition().x + this->monsterBoxSize.x, this->monsterBox.getPosition().y);
}
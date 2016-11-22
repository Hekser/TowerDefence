#include "Missile.h"

Missile::Missile(Vector2f startPosition, Vector2i mousePosition, float missileSize, int damage, bool positiveEffect) :
	horizontalProjection(mousePosition.x - startPosition.x),
	verticalProjection(mousePosition.y - startPosition.y),
	length(sqrt(horizontalProjection * horizontalProjection + verticalProjection * verticalProjection)),
	circleShape(missileSize),

	damage(damage),
	positiveEffect(positiveEffect)
{
	circleShape.setPosition(startPosition);
	circleShape.setOrigin(circleShape.getRadius(), circleShape.getRadius());
	this->speed = setSpeed(missileSize);
}

Missile::~Missile()
{
}

CircleShape & Missile::getCircleShape()
{
	return this->circleShape;
}

Vector2f Missile::getPosition()
{
	return this->circleShape.getPosition();
}

void Missile::move()
{
	this->circleShape.move(this->speed);
}

int Missile::getDamage()
{
	return this->damage;
}

bool Missile::isPositiveEffect()
{
	return this->positiveEffect;
}

Vector2f Missile::setSpeed(float missileSize)
{
	return Vector2f(horizontalProjection / length * missileSize * 0.25f, verticalProjection / length * missileSize * 0.25f);
}
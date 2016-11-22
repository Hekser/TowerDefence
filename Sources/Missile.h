#pragma once

#include "Textures.h"

class Missile
{
public:
	Missile(Vector2f, Vector2i, float, int, bool);
	~Missile();
	CircleShape & getCircleShape();
	Vector2f getPosition();
	void move();
	int getDamage();
	bool isPositiveEffect();
private:
	int damage;
	bool positiveEffect;

	Vector2f speed;

	float verticalProjection;
	float horizontalProjection;
	float length;

	CircleShape circleShape;

	Vector2f setSpeed(float);
};
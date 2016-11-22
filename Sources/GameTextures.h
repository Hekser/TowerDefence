#pragma once

#include "LevelCreator.h"
#include <typeinfo>

class GameTextures : public Textures
{
public:

	enum Collision
	{
		MonsterToTower,
		MissileToMonster,
		MonstersDeath,
		NONE
	};

	GameTextures();
	~GameTextures();
	void setString(String &);
	void draw(RenderWindow &);
	void addMissile(Vector2i, int);
	void addMonster(Monster &);
	void setMissileColor(Color);
	void setChampionHPProportion(double);
	bool isLevelClear();
	Collision checkCollision();
	int getDamageGivenToTower();
	void setActionAccessHP(bool);
	void setActionAccessDamage(bool);
	void clearMap();
	void centerString();
private:
	vector<Missile *> missilesToDraw;
	vector<Monster *> monstersToDraw;

	template <typename T>
	void deleteObject(vector<T *> &, int);

	int monsterDamageGivenToTower;

	const Vector2f textPosition;

	const Vector2f startMissilePosition;
	const float missileSize;
	const float towerPosition;

	const Vector2f championBoxSizeHP;
	const Vector2f championBoxPositionHP;

	const Vector2f actionBoxSize;
	const Vector2f actionPositionHP;
	const Vector2f actionPositionDamage;

	RectangleShape championBoxHP;
	CircleShape startAttackBox;
	RectangleShape actionBoxHP;
	RectangleShape actionBoxDamage;

	Color missileColor;

	Texture missileBoxTexture;
	Texture startAttackBoxTexture;
	Texture normalMonsterTexture;
	Texture flyingMonsterTexture;
	Texture bossMonsterTexture;
	Texture greenHPTexture;
	Texture redHPTexture;
	Texture actionHPTexture;
	Texture actionDamageTexture;
};

template<typename T>
inline void GameTextures::deleteObject(vector<T *> &vector, int index)
{
	delete vector[index];
	vector[index] = NULL;
	vector.erase(vector.begin() + index);
}
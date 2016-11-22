#include "GameTextures.h"

GameTextures::GameTextures() :
	Textures(),

	textPosition(screenSize.x * 0.95f, screenSize.y * 0.05f),
	startMissilePosition(screenSize.x * 0.1597f, screenSize.y * 0.1521f),
	missileSize(screenSize.y * 0.02469f),
	towerPosition(screenBoxSize.x * 0.177f),
	championBoxSizeHP(screenSize.x * 0.243f, screenSize.y * 0.004938f),
	championBoxPositionHP(screenSize.x * 0.0353f, startMissilePosition.y / 2.0f),
	actionBoxSize(screenSize.x * 0.0694f, screenSize.y * 0.1234f),
	actionPositionHP(screenSize.x * 0.0277f, screenSize.y * 0.1728f),
	actionPositionDamage(screenSize.x * 0.0277f, screenSize.y * 0.3271f),

	championBoxHP(championBoxSizeHP),
	startAttackBox(missileSize),
	actionBoxHP(actionBoxSize),
	actionBoxDamage(actionBoxSize)
{
	text.setPosition(textPosition);

	championBoxHP.setPosition(championBoxPositionHP);

	startAttackBox.setPosition(startMissilePosition);
	startAttackBox.setOrigin(startAttackBox.getRadius(), startAttackBox.getRadius());

	actionBoxHP.setPosition(actionPositionHP);
	actionBoxHP.setOutlineThickness(screenSize.y * 0.0037037f);

	actionBoxDamage.setPosition(actionPositionDamage);
	actionBoxDamage.setOutlineThickness(screenSize.y * 0.0037037f);

	setActionAccessHP(false);
	setActionAccessDamage(false);

	missileColor = Color::White;

	if (!screenBoxTexture.loadFromFile("textures\\gameBackground.png"))
	{
		throw GameExceptions("Nie mozna zaladowac tekstury: gameBackground.png");
	}

	if (!missileBoxTexture.loadFromFile("textures\\missile.png"))
	{
		throw GameExceptions("Nie mozna zaladowac tekstury: missile.png");
	}

	if (!startAttackBoxTexture.loadFromFile("textures\\startMissile.png"))
	{
		throw GameExceptions("Nie mozna zaladowac tekstury: startMissile.png");
	}

	if (!normalMonsterTexture.loadFromFile("textures\\monster.png"))
	{
		throw GameExceptions("Nie mozna zaladowac tekstury: monster.png");
	}

	if (!flyingMonsterTexture.loadFromFile("textures\\flyingMonster.png"))
	{
		throw GameExceptions("Nie mozna zaladowac tekstury: flyingMonster.png");
	}

	if (!bossMonsterTexture.loadFromFile("textures\\bossMonster.png"))
	{
		throw GameExceptions("Nie mozna zaladowac tekstury: bossMonster.png");
	}

	if (!greenHPTexture.loadFromFile("textures\\greenHP.png"))
	{
		throw GameExceptions("Nie mozna zaladowac tekstury: greenHP.png");
	}

	if (!redHPTexture.loadFromFile("textures\\redHP.png"))
	{
		throw GameExceptions("Nie mozna zaladowac tekstury: redHP.png");
	}

	if (!actionHPTexture.loadFromFile("textures\\actionHP.png"))
	{
		throw GameExceptions("Nie mozna zaladowac tekstury: actionHP.png");
	}

	if (!actionDamageTexture.loadFromFile("textures\\actionDamage.png"))
	{
		throw GameExceptions("Nie mozna zaladowac tekstury: actionDamage.png");
	}

	screenBox.setTexture(&screenBoxTexture);
	startAttackBox.setTexture(&startAttackBoxTexture);
	championBoxHP.setTexture(&greenHPTexture);
	actionBoxHP.setTexture(&actionHPTexture);
	actionBoxDamage.setTexture(&actionDamageTexture);

	this->monsterDamageGivenToTower = 0;
}

GameTextures::~GameTextures()
{
	clearMap();
}

void GameTextures::setString(String &string)
{
	Textures::setString(string);
	text.setOrigin(text.getLocalBounds().width, 0);
}

void GameTextures::draw(RenderWindow &renderWindow)
{
	renderWindow.clear();

	renderWindow.draw(screenBox);
	renderWindow.draw(championBoxHP);
	renderWindow.draw(startAttackBox);

	this->startAttackBox.rotate(25);

	renderWindow.draw(actionBoxHP);
	renderWindow.draw(actionBoxDamage);

	for (auto missile_itr = missilesToDraw.begin(), missile_end = missilesToDraw.end(); missile_itr != missile_end; ++missile_itr)
	{
		renderWindow.draw((*missile_itr)->getCircleShape());
		(*missile_itr)->move();
	}

	for (auto monster_itr = monstersToDraw.begin(), monster_end = monstersToDraw.end(); monster_itr != monster_end; ++monster_itr)
	{
		renderWindow.draw((*monster_itr)->getRectangleShape());
		renderWindow.draw((*monster_itr)->getRectangleHP());
		(*monster_itr)->move(this->missilesToDraw);
	}

	renderWindow.draw(text);

	renderWindow.display();
}

void GameTextures::addMissile(Vector2i mousePosition, int damage)
{
	this->missilesToDraw.push_back(new Missile(startMissilePosition, mousePosition, missileSize, damage, true));
	this->missilesToDraw[missilesToDraw.size() - 1]->getCircleShape().setTexture(&missileBoxTexture);
	this->missilesToDraw[missilesToDraw.size() - 1]->getCircleShape().setFillColor(missileColor);
}

void GameTextures::addMonster(Monster &monster)
{
	this->monstersToDraw.push_back(&monster);

	if (typeid(monster) == typeid(NormalMonster))
	{
		this->monstersToDraw[monstersToDraw.size() - 1]->getRectangleShape().setTexture(&normalMonsterTexture);
	}
	else if (typeid(monster) == typeid(FlyingMonster))
	{
		this->monstersToDraw[monstersToDraw.size() - 1]->getRectangleShape().setTexture(&flyingMonsterTexture);
	}
	else if (typeid(monster) == typeid(BossMonster))
	{
		this->monstersToDraw[monstersToDraw.size() - 1]->getRectangleShape().setTexture(&bossMonsterTexture);
	}

	this->monstersToDraw[monstersToDraw.size() - 1]->getRectangleHP().setTexture(&redHPTexture);
}

void GameTextures::setMissileColor(Color color)
{
	this->missileColor = color;
	this->startAttackBox.setFillColor(color);
}

void GameTextures::setChampionHPProportion(double proportion)
{
	if (proportion >= 0)
	{
		this->championBoxHP.setSize(Vector2f(championBoxSizeHP.x * (float)proportion, championBoxSizeHP.y));
	}
	else
	{
		this->championBoxHP.setSize(Vector2f(0.0f, 0.0f));
	}
}

bool GameTextures::isLevelClear()
{
	if (monstersToDraw.size() == 0)
	{
		return true;
	}
	
	return false;
}

GameTextures::Collision GameTextures::checkCollision()
{
	for (int i = 0; i < missilesToDraw.size(); ++i)
	{
		Vector2f missilePosition(missilesToDraw[i]->getPosition());

		if (missilePosition.x >= screenBoxSize.x || missilePosition.y >= screenBoxSize.y || missilePosition.x <= 0 || missilePosition.y <= 0)
		{
			deleteObject(this->missilesToDraw, i--);
		}
		else if (!missilesToDraw[i]->isPositiveEffect() && missilePosition.x <= this->towerPosition)
		{
			monsterDamageGivenToTower = missilesToDraw[i]->getDamage();

			deleteObject(this->missilesToDraw, i);

			return GameTextures::Collision::MonsterToTower;
		}
		else
		{
			for (int j = 0; j < missilesToDraw.size(); ++j)
			{
				if (i == j)
				{
					continue;
				}

				if (missilesToDraw[i]->getCircleShape().getGlobalBounds().intersects(missilesToDraw[j]->getCircleShape().getGlobalBounds()))
				{
					if (missilesToDraw[i]->isPositiveEffect() != missilesToDraw[j]->isPositiveEffect())
					{
						if (missilesToDraw[i]->isPositiveEffect())
						{
							deleteObject(this->missilesToDraw, j);
						}
						else
						{
							deleteObject(this->missilesToDraw, i);
						}

						return GameTextures::Collision::MissileToMonster;
					}
				}
			}
		}
	}

	for (int i = 0; i < monstersToDraw.size(); ++i)
	{
		if (monstersToDraw[i]->getPosition() <= this->towerPosition)
		{
			monsterDamageGivenToTower = monstersToDraw[i]->getAttackDamage();

			deleteObject(this->monstersToDraw, i);

			return GameTextures::Collision::MonsterToTower;
		}
		else
		{
			for (int j = 0; j < missilesToDraw.size(); ++j)
			{
				if (monstersToDraw[i]->getRectangleShape().getGlobalBounds().intersects(missilesToDraw[j]->getCircleShape().getGlobalBounds()))
				{
					if (missilesToDraw[j]->isPositiveEffect())
					{
						monstersToDraw[i]->dealDamage(missilesToDraw[j]->getDamage());

						deleteObject(this->missilesToDraw, j);

						if (monstersToDraw[i]->getHP() > 0)
						{
							return GameTextures::Collision::MissileToMonster;
						}
						else
						{
							deleteObject(this->monstersToDraw, i);

							return GameTextures::Collision::MonstersDeath;
						}
					}
				}
			}
		}
	}

	return GameTextures::Collision::NONE;
}

int GameTextures::getDamageGivenToTower()
{
	return this->monsterDamageGivenToTower;
}

void GameTextures::setActionAccessHP(bool available)
{
	if (available)
	{
		this->actionBoxHP.setOutlineColor(Color::Green);
	}
	else
	{
		this->actionBoxHP.setOutlineColor(Color::Red);
	}
}

void GameTextures::setActionAccessDamage(bool available)
{
	if (available)
	{
		this->actionBoxDamage.setOutlineColor(Color::Green);
	}
	else
	{
		this->actionBoxDamage.setOutlineColor(Color::Red);
	}
}

void GameTextures::clearMap()
{
	for (int i = 0; i < missilesToDraw.size(); ++i)
	{
		deleteObject(this->missilesToDraw, i);
	}
	missilesToDraw.clear();

	for (int i = 0; i < monstersToDraw.size(); ++i)
	{
		deleteObject(this->monstersToDraw, i);
	}
	monstersToDraw.clear();
}

void GameTextures::centerString()
{
	text.setOrigin(text.getGlobalBounds().width / 2.0f, text.getGlobalBounds().height / 2.0f);
	text.setPosition(screenSize.x / 2.0f, screenSize.y / 2.0f);
}
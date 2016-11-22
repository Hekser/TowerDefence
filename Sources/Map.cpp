#include "Map.h"

Map::Map(Player player)
{
	try
	{
		this->gameTextures = new GameTextures();

		if (player.getProfession() == Player::Profession::SORCERER)
		{
			this->champion = new Sorcerer(player.getPlayerName());
			this->gameTextures->setMissileColor(Color::Blue);
		}
		else if (player.getProfession() == Player::Profession::PALADIN)
		{
			this->champion = new Paladin(player.getPlayerName());
			this->gameTextures->setMissileColor(Color::Yellow);
		}
		else if (player.getProfession() == Player::Profession::WARRIOR)
		{
			this->champion = new Warior(player.getPlayerName());
			this->gameTextures->setMissileColor(Color::Red);
		}
		else if (player.getProfession() == Player::Profession::ARCHER)
		{
			this->champion = new Archer(player.getPlayerName());
			this->gameTextures->setMissileColor(Color::Green);
		}
		else if (player.getProfession() == Player::Profession::DEFAULT)
		{
			throw GameExceptions("Nie wybrano bohatera!");
		}
	}
	catch (GameExceptions & ex)
	{
		ex.getInfo();
		exit(1);
	}

	this->levelCreator = new LevelCreator(this->gameTextures->screenBoxSize);

	this->level = 1;
	this->numberOfMonsters = 0;
	this->string = "";
}

Map::~Map()
{
	delete this->gameTextures;
	this->gameTextures = NULL;
	delete this->champion;
	this->champion = NULL;
	delete this->levelCreator;
	this->levelCreator = NULL;
}

void Map::start()
{
	GameTextures::Collision collisionType = GameTextures::Collision::NONE;

	double timeToNextLevel = getTime() + 5;
	double timeToNextMonster = timeToNextLevel;

	bool allowActionHP = false;
	bool allowActionDamage = false;

	RenderWindow gameWindow(VideoMode(gameTextures->screenSize.x, gameTextures->screenSize.y, 32), "Tower Defence", Style::Close);
	gameWindow.setPosition(gameTextures->screenPosition);

	Event event;

	while (gameWindow.isOpen())
	{
		while (gameWindow.pollEvent(event))
		{
			if (event.type == Event::Closed)
			{
				gameWindow.close();
				exit(1);
			}

			if (event.type == Event::MouseButtonPressed)
			{
				if (event.mouseButton.button == Mouse::Left)
				{
					gameTextures->addMissile(Mouse::getPosition(gameWindow), champion->getAttackDamage());
				}
			}

			if (event.type == Event::TextEntered && event.text.unicode == 49 && allowActionHP)
			{
				champion->takeMoney(100);
				champion->heal(75);
				gameTextures->setChampionHPProportion(champion->getHPProportion());
			}

			if (event.type == Event::TextEntered && event.text.unicode == 50 && allowActionDamage)
			{
				champion->takeMoney(175);
				champion->upgradeAttackDamage(10);
			}
		}

		if (getTime() >= timeToNextLevel)
		{
			if (numberOfMonsters < levelCreator->getCountOfMonsters(level))
			{
				if (getTime() >= timeToNextMonster)
				{
					gameTextures->addMonster(this->levelCreator->getMonster(level, numberOfMonsters));
					++timeToNextMonster;
					++numberOfMonsters;
				}
			}
			else if (gameTextures->isLevelClear())
			{
				timeToNextLevel = getTime() + 5;
				timeToNextMonster = timeToNextLevel;
				numberOfMonsters = 0;
				++level;

				if (level > levelCreator->getNumberOfLevels())
				{
					endGame(gameWindow, true);
				}
			}
		}

		string = "Level " + to_string(level) + " | HP " + to_string(champion->getHP()) + " | Money " + to_string(champion->getMoney());
		gameTextures->setString(string);

		collisionType = gameTextures->checkCollision();
		if (collisionType == GameTextures::Collision::MonsterToTower)
		{
			champion->dealDamage(gameTextures->getDamageGivenToTower());
			gameTextures->setChampionHPProportion(champion->getHPProportion());

			if (champion->getHP() <= 0)
			{
				endGame(gameWindow, false);
			}
		}
		else if (collisionType == GameTextures::Collision::MissileToMonster)
		{
			champion->addMoney(1);
		}
		else if (collisionType == GameTextures::Collision::MonstersDeath)
		{
			champion->addMoney(10);
		}

		if (champion->getMoney() >= 100)
		{
			gameTextures->setActionAccessHP(true);
			allowActionHP = true;
		}
		else
		{
			gameTextures->setActionAccessHP(false);
			allowActionHP = false;
		}

		if (champion->getMoney() >= 175)
		{
			gameTextures->setActionAccessDamage(true);
			allowActionDamage = true;
		}
		else
		{
			gameTextures->setActionAccessDamage(false);
			allowActionDamage = false;
		}

		gameTextures->draw(gameWindow);

		sleep(milliseconds(5));
	}
}

double Map::getTime()
{
	return (double)(clock() / CLOCKS_PER_SEC);
}

void Map::endGame(RenderWindow &renderWindow, bool success)
{
	if (success)
	{
		string = "Wygrana! Gratulacje " + champion->getName();
	}
	else
	{
		string = "Przegrana! Sprobuj jeszcze raz " + champion->getName();
	}

	gameTextures->clearMap();
	gameTextures->setString(string);
	gameTextures->centerString();
	gameTextures->draw(renderWindow);
	sleep(milliseconds(3000));
	exit(1);
}
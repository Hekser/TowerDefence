#include "Game.h"

Game::Game()
{
	try
	{
		this->menuTextures = new MenuTextures();
	}
	catch (GameExceptions & ex)
	{
		ex.getInfo();
		exit(1);
	}

	this->player = new Player;
	this->map = NULL;
}

Game::~Game()
{
	delete this->menuTextures;
	this->menuTextures = NULL;
	delete this->player;
	this->player = NULL;
	delete this->map;
	this->map = NULL;
}

void Game::startMenu()
{
	String string;

	bool mouseReleased;
	Vector2i mousePosition;
	Player::Profession chosenProfession = Player::Profession::DEFAULT;

	RenderWindow startWindow(VideoMode(menuTextures->screenSize.x, menuTextures->screenSize.y, 32), "Tower Defence", Style::Close);
	startWindow.setPosition(menuTextures->screenPosition);

	Event event;

	while (startWindow.isOpen())
	{
		mouseReleased = false;
		mousePosition = Mouse::getPosition(startWindow);

		while (startWindow.pollEvent(event))
		{
			if (event.type == Event::Closed)
			{
				startWindow.close();
				exit(1);
			}
			else if (event.type == Event::TextEntered)
			{
				if (event.text.unicode == 8 && string.getSize() > 0)
				{
					string.erase(string.getSize() - 1, string.getSize());
				}
				else if (event.text.unicode >= 32 && event.text.unicode < 128)
				{
					if (string.getSize() <= 30)
					{
						string += static_cast<char>(event.text.unicode);
					}
				}

				menuTextures->setString(string);
				menuTextures->setFontSize();
			}
			else if (event.type == Event::MouseButtonReleased)
			{
				if (event.mouseButton.button == Mouse::Left)
				{
					mouseReleased = true;
				}
			}
		}

		chosenProfession = menuTextures->choseProfessionBox(mousePosition, mouseReleased);

		if (chosenProfession != Player::Profession::DEFAULT)
		{
			this->player->setProfession(chosenProfession);
		}

		if (menuTextures->isPlayBoxAction(mousePosition, mouseReleased, false))
		{
			if (menuTextures->getString() != "" && this->player->getProfession() != Player::Profession::DEFAULT)
			{
				this->player->setPlayerName(menuTextures->getString());
				menuTextures->isPlayBoxAction(mousePosition, mouseReleased, true);
				menuTextures->draw(startWindow);
				sleep(milliseconds(300));
				startWindow.close();
			}
		}

		menuTextures->draw(startWindow);
	}
}

void Game::play()
{
	this->map = new Map(*this->player);
	this->map->start();
}
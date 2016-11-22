#include "MenuTextures.h"

MenuTextures::MenuTextures() :
	Textures(),

	gameNameSize(screenSize.x / 2 * 0.8f, screenSize.y * 0.3f),
	gameNamePosition(screenSize.x / 2 * 0.1f, screenSize.y * 0.1f),

	entryNameSize(screenSize.x / 2 * 0.7f, screenSize.y * 0.15f),
	entryNamePosition(screenSize.x / 2 * 0.15f, screenSize.y * 0.5f),

	nameBoxSize(screenSize.x / 2 * 0.8f, screenSize.y * 0.15f),
	nameBoxPosition(screenSize.x / 2 * 0.1f, screenSize.y * 0.75f),

	professionBoxSize(screenSize.x / 2 * 0.8f, screenSize.y * 0.1f),
	professionBoxPosition(screenSize.x / 2 * 1.1f, screenSize.y * 0.05f),

	sorcererBoxSize(screenSize.x / 2 * 0.4f, screenSize.y * 0.25f),
	sorcererBoxPosition(screenSize.x / 2 * 1.05f, screenSize.y * 0.225f),

	paladinBoxSize(screenSize.x / 2 * 0.4f, screenSize.y * 0.25f),
	paladinBoxPosition(screenSize.x / 2 * 1.55f, screenSize.y * 0.225f),

	warriorBoxSize(screenSize.x / 2 * 0.4f, screenSize.y * 0.25f),
	warriorBoxPosition(screenSize.x / 2 * 1.05f, screenSize.y * 0.55f),

	archerBoxSize(screenSize.x / 2 * 0.4f, screenSize.y * 0.25f),
	archerBoxPosition(screenSize.x / 2 * 1.55f, screenSize.y * 0.55f),

	playBoxSize(screenSize.x / 2 * 0.5f, screenSize.y * 0.075f),
	playBoxPosition(screenSize.x / 2 * 1.25f, screenSize.y * 0.87f),

	textNameBoxPosition(nameBoxPosition.x + (nameBoxSize.x / 2.0f), nameBoxPosition.y + (nameBoxSize.y / 2.0f)),

	gameName(gameNameSize),
	entryName(entryNameSize),
	nameBox(nameBoxSize),
	professionBox(professionBoxSize),
	sorcererBox(sorcererBoxSize),
	paladinBox(paladinBoxSize),
	warriorBox(warriorBoxSize),
	archerBox(archerBoxSize),
	playBox(playBoxSize)
{
	text.setPosition(textNameBoxPosition);

	gameName.setPosition(gameNamePosition);
	entryName.setPosition(entryNamePosition);
	nameBox.setPosition(nameBoxPosition);
	professionBox.setPosition(professionBoxPosition);
	sorcererBox.setPosition(sorcererBoxPosition);
	paladinBox.setPosition(paladinBoxPosition);
	warriorBox.setPosition(warriorBoxPosition);
	archerBox.setPosition(archerBoxPosition);
	playBox.setPosition(playBoxPosition);

	if (!screenBoxTexture.loadFromFile("textures\\screenBox.png"))
	{
		throw GameExceptions("Nie mozna zaladowac tekstury: screenBox.png");
	}

	if (!gameNameTexture.loadFromFile("textures\\gameName.png"))
	{
		throw GameExceptions("Nie mozna zaladowac tekstury: gameName.png");
	}

	if (!entryNameTexture.loadFromFile("textures\\entryName.png"))
	{
		throw GameExceptions("Nie mozna zaladowac tekstury: entryName.png");
	}

	if (!professionBoxTexture.loadFromFile("textures\\professionBox.png"))
	{
		throw GameExceptions("Nie mozna zaladowac tekstury: professionBox.png");
	}

	if (!sorcererBoxTexture.loadFromFile("textures\\sorcererBox.png"))
	{
		throw GameExceptions("Nie mozna zaladowac tekstury: sorcererBox.png");
	}

	if (!onSorcererBoxTexture.loadFromFile("textures\\onSorcererBox.png"))
	{
		throw GameExceptions("Nie mozna zaladowac tekstury: onSorcererBox.png");
	}

	if (!paladinBoxTexture.loadFromFile("textures\\paladinBox.png"))
	{
		throw GameExceptions("Nie mozna zaladowac tekstury: paladinBox.png");
	}

	if (!onPaladinBoxTexture.loadFromFile("textures\\onPaladinBox.png"))
	{
		throw GameExceptions("Nie mozna zaladowac tekstury: onPaladinBox.png");
	}

	if (!warriorBoxTexture.loadFromFile("textures\\warriorBox.png"))
	{
		throw GameExceptions("Nie mozna zaladowac tekstury: warriorBox.png");
	}

	if (!onWarriorBoxTexture.loadFromFile("textures\\onWarriorBox.png"))
	{
		throw GameExceptions("Nie mozna zaladowac tekstury: onWarriorBox.png");
	}

	if (!archerBoxTexture.loadFromFile("textures\\archerBox.png"))
	{
		throw GameExceptions("Nie mozna zaladowac tekstury: archerBox.png");
	}

	if (!onArcherBoxTexture.loadFromFile("textures\\onArcherBox.png"))
	{
		throw GameExceptions("Nie mozna zaladowac tekstury: onArcherBox.png");
	}

	if (!playBoxTexture.loadFromFile("textures\\playBox.png"))
	{
		throw GameExceptions("Nie mozna zaladowac tekstury: playBox.png");
	}

	if (!playPressedBoxTexture.loadFromFile("textures\\playBoxPressed.png"))
	{
		throw GameExceptions("Nie mozna zaladowac tekstury: playBoxPressed.png");
	}

	screenBox.setTexture(&screenBoxTexture);

	gameName.setTexture(&gameNameTexture);

	entryName.setTexture(&entryNameTexture);

	nameBox.setFillColor(Color(255, 255, 255, 65));
	nameBox.setOutlineColor(Color(50, 50, 50));
	nameBox.setOutlineThickness(screenSize.y * 0.006172f);

	professionBox.setTexture(&professionBoxTexture);

	sorcererBox.setTexture(&sorcererBoxTexture);
	sorcererBox.setOutlineColor(Color(100, 100, 100));
	sorcererBox.setOutlineThickness(screenSize.y * 0.006172f);

	paladinBox.setTexture(&paladinBoxTexture);
	paladinBox.setOutlineColor(Color(100, 100, 100));
	paladinBox.setOutlineThickness(screenSize.y * 0.006172f);

	warriorBox.setTexture(&warriorBoxTexture);
	warriorBox.setOutlineColor(Color(100, 100, 100));
	warriorBox.setOutlineThickness(screenSize.y * 0.006172f);

	archerBox.setTexture(&archerBoxTexture);
	archerBox.setOutlineColor(Color(100, 100, 100));
	archerBox.setOutlineThickness(screenSize.y * 0.006172f);

	playBox.setTexture(&playBoxTexture);
}

MenuTextures::~MenuTextures()
{
}

Player::Profession MenuTextures::choseProfessionBox(const Vector2i &point, bool mouseReleased)
{
	if (point.x >= sorcererBoxPosition.x && point.y >= sorcererBoxPosition.y && point.x <= (sorcererBoxPosition.x + sorcererBoxSize.x) && point.y <= (sorcererBoxPosition.y + sorcererBoxSize.y))
	{
		if (mouseReleased)
		{
			sorcererBox.setOutlineColor(Color::Red);
			paladinBox.setOutlineColor(Color(100, 100, 100));
			warriorBox.setOutlineColor(Color(100, 100, 100));
			archerBox.setOutlineColor(Color(100, 100, 100));

			return Player::Profession::SORCERER;
		}
		else
		{
			sorcererBox.setTexture(&onSorcererBoxTexture);
		}
	}
	else if (point.x >= paladinBoxPosition.x && point.y >= paladinBoxPosition.y && point.x <= (paladinBoxPosition.x + paladinBoxSize.x) && point.y <= (paladinBoxPosition.y + paladinBoxSize.y))
	{
		if (mouseReleased)
		{
			sorcererBox.setOutlineColor(Color(100, 100, 100));
			paladinBox.setOutlineColor(Color::Red);
			warriorBox.setOutlineColor(Color(100, 100, 100));
			archerBox.setOutlineColor(Color(100, 100, 100));

			return Player::Profession::PALADIN;
		}
		else
		{
			paladinBox.setTexture(&onPaladinBoxTexture);
		}
	}
	else if (point.x >= warriorBoxPosition.x && point.y >= warriorBoxPosition.y && point.x <= (warriorBoxPosition.x + warriorBoxSize.x) && point.y <= (warriorBoxPosition.y + warriorBoxSize.y))
	{
		if (mouseReleased)
		{
			sorcererBox.setOutlineColor(Color(100, 100, 100));
			paladinBox.setOutlineColor(Color(100, 100, 100));
			warriorBox.setOutlineColor(Color::Red);
			archerBox.setOutlineColor(Color(100, 100, 100));

			return Player::Profession::WARRIOR;
		}
		else
		{
			warriorBox.setTexture(&onWarriorBoxTexture);
		}
	}
	else if (point.x >= archerBoxPosition.x && point.y >= archerBoxPosition.y && point.x <= (archerBoxPosition.x + archerBoxSize.x) && point.y <= (archerBoxPosition.y + archerBoxSize.y))
	{
		if (mouseReleased)
		{
			sorcererBox.setOutlineColor(Color(100, 100, 100));
			paladinBox.setOutlineColor(Color(100, 100, 100));
			warriorBox.setOutlineColor(Color(100, 100, 100));
			archerBox.setOutlineColor(Color::Red);

			return Player::Profession::ARCHER;
		}
		else
		{
			archerBox.setTexture(&onArcherBoxTexture);
		}
	}
	else
	{
		sorcererBox.setTexture(&sorcererBoxTexture);
		paladinBox.setTexture(&paladinBoxTexture);
		warriorBox.setTexture(&warriorBoxTexture);
		archerBox.setTexture(&archerBoxTexture);
	}

	return Player::Profession::DEFAULT;
}

bool MenuTextures::isPlayBoxAction(const Vector2i &point, bool mouseReleased, bool setChosenBox)
{
	if (setChosenBox)
	{
		playBox.setFillColor(Color::Blue);
	}

	if (point.x >= playBoxPosition.x && point.y >= playBoxPosition.y && point.x <= (playBoxPosition.x + playBoxSize.x) && point.y <= (playBoxPosition.y + playBoxSize.y))
	{
		playBox.setTexture(&playPressedBoxTexture);

		if (mouseReleased)
		{
			return true;
		}
	}
	else
	{
		playBox.setTexture(&playBoxTexture);
	}

	return false;
}

void MenuTextures::setFontSize()
{
	int fontSize = 1;

	text.setCharacterSize(fontSize);

	if (text.getString() != "")
	{
		while (text.getLocalBounds().width < nameBoxSize.x * 0.8 && text.getLocalBounds().height < nameBoxSize.y * 0.8 && fontSize <= 60)
		{
			fontSize += 3;
			text.setCharacterSize(fontSize);
		}
	}

	text.setOrigin(text.getLocalBounds().width * 0.5f, text.getLocalBounds().height * 0.75f);
}

void MenuTextures::draw(RenderWindow &renderWindow)
{
	renderWindow.clear();

	renderWindow.draw(screenBox);
	renderWindow.draw(gameName);
	renderWindow.draw(entryName);
	renderWindow.draw(nameBox);
	renderWindow.draw(professionBox);
	renderWindow.draw(sorcererBox);
	renderWindow.draw(paladinBox);
	renderWindow.draw(warriorBox);
	renderWindow.draw(archerBox);
	renderWindow.draw(playBox);

	renderWindow.draw(text);

	renderWindow.display();
}
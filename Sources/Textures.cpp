#include "Textures.h"

Textures::Textures() :
	screenWidth(VideoMode::getDesktopMode().width),
	screenHeight(VideoMode::getDesktopMode().height),

	screenSize((unsigned int)(screenWidth * 0.75f), (unsigned int)(screenHeight * 0.75f)),
	screenPosition(screenWidth / 8, screenHeight / 8),
	screenBoxSize((float)screenSize.x, (float)screenSize.y),

	screenBox(screenBoxSize)
{
	if (!font.loadFromFile("sansation.ttf"))
	{
		throw GameExceptions("Nie mozna zaladowac czcionki: sansation.ttf");
	}

	text.setFont(font);
}

Textures::~Textures()
{
}

void Textures::setString(String &string)
{
	this->text.setString(string);
}

String Textures::getString()
{
	return this->text.getString();
}
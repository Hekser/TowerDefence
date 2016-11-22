#pragma once

#include "SFML\Graphics.hpp"
#include "GameExceptions.h"
#include "Player.h"

using namespace sf;

class Textures
{
public:
	Textures();
	virtual ~Textures();
	virtual void setString(String &);
	String getString();
	virtual void draw(RenderWindow &) = 0;

	unsigned int screenWidth;
	unsigned int screenHeight;
	const Vector2u screenSize;
	const Vector2i screenPosition;
	const Vector2f screenBoxSize;
protected:
	Font font;
	Text text;

	RectangleShape screenBox;
	Texture screenBoxTexture;
};
#pragma once

#include "Textures.h"

class MenuTextures : public Textures
{
public:
	MenuTextures();
	~MenuTextures();
	Player::Profession choseProfessionBox(const Vector2i &, bool);
	bool isPlayBoxAction(const Vector2i &, bool, bool);
	void setFontSize();
	void draw(RenderWindow &);
private:
	const Vector2f gameNameSize;
	const Vector2f gameNamePosition;

	const Vector2f entryNameSize;
	const Vector2f entryNamePosition;

	const Vector2f nameBoxSize;
	const Vector2f nameBoxPosition;

	const Vector2f professionBoxSize;
	const Vector2f professionBoxPosition;

	const Vector2f sorcererBoxSize;
	const Vector2f sorcererBoxPosition;

	const Vector2f paladinBoxSize;
	const Vector2f paladinBoxPosition;

	const Vector2f warriorBoxSize;
	const Vector2f warriorBoxPosition;

	const Vector2f archerBoxSize;
	const Vector2f archerBoxPosition;

	const Vector2f playBoxSize;
	const Vector2f playBoxPosition;

	const Vector2f textNameBoxPosition;

	RectangleShape gameName;
	RectangleShape entryName;
	RectangleShape nameBox;
	RectangleShape professionBox;
	RectangleShape sorcererBox;
	RectangleShape paladinBox;
	RectangleShape warriorBox;
	RectangleShape archerBox;
	RectangleShape playBox;

	Texture gameNameTexture;
	Texture entryNameTexture;
	Texture professionBoxTexture;
	Texture sorcererBoxTexture;
	Texture onSorcererBoxTexture;
	Texture paladinBoxTexture;
	Texture onPaladinBoxTexture;
	Texture warriorBoxTexture;
	Texture onWarriorBoxTexture;
	Texture archerBoxTexture;
	Texture onArcherBoxTexture;
	Texture playBoxTexture;
	Texture playPressedBoxTexture;
};
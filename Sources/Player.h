#pragma once

#include <string>

class Player
{
public:

	enum Profession
	{
		SORCERER,
		PALADIN,
		WARRIOR,
		ARCHER,
		DEFAULT
	};

	Player(std::string playerName = "Player", Profession profession = Profession::DEFAULT);
	~Player();
	void setProfession(Profession);
	Profession getProfession();
	void setPlayerName(std::string);
	std::string getPlayerName();
private:
	std::string playerName;
	Profession profession;
};
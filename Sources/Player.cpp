#include "Player.h"

Player::Player(std::string playerName, Profession profession)
{
	this->playerName = playerName;
	this->profession = profession;
}

Player::~Player()
{
}

void Player::setProfession(Profession profession)
{
	this->profession = profession;
}

Player::Profession Player::getProfession()
{
	return this->profession;
}

void Player::setPlayerName(std::string playerName)
{
	this->playerName = playerName;
}

std::string Player::getPlayerName()
{
	return this->playerName;
}
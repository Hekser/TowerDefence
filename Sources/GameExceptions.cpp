#include "GameExceptions.h"

GameExceptions::GameExceptions(std::string info) :
	info(info)
{
}

GameExceptions::~GameExceptions()
{
}

std::string GameExceptions::getInfo()
{
	return this->info;
}
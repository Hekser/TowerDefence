#pragma once

#include <string>

class GameExceptions
{
public:
	GameExceptions(std::string);
	~GameExceptions();
	std::string getInfo();
private:
	std::string info;
};
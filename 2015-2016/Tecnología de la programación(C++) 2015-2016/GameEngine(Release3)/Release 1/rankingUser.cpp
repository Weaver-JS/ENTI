#include "rankingUser.h"



rankingUser::rankingUser()
{
	std::string nameString;
	nameString = "default";
	strncpy_s(_name, nameString.c_str(), sizeof(_name));
	_name[sizeof(_name) - 1] = 0;
	score = 0;
}

rankingUser::rankingUser(std::string name, int Score)
{
	std::string nameString;
	nameString = name;
	strncpy_s(_name, nameString.c_str(), sizeof(_name));
	_name[sizeof(_name) - 1] = 0;
	score = Score;
}

rankingUser::rankingUser(rankingUser & user)
{
	for (int i = 0; i < 50;i++)
	{
		_name[i] = user._name[i];
	}
	score = user.score;
}




rankingUser::~rankingUser()
{
}



std::string rankingUser::getName()
{
	return _name;
}

int rankingUser::getScore()
{
	return score;
}

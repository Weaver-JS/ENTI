#pragma once
#include <iostream>
class rankingUser
{
private:
	char _name[50];
	int score;
public:
	rankingUser();
	rankingUser(std::string name, int Score);
	rankingUser(rankingUser &user);

	~rankingUser();
	std::string getName();
	int getScore();
};


#pragma once
#include "rankingUser.h"
#include "Array.h"
#include <fstream>
#include <string>
#define userRankingLength 10
class Ranking
{
private:
	rankingUser ranking[userRankingLength];
public:
	Ranking();
	~Ranking();
	void saveRanking();
	void loadRanking();
	void AddnsortRanking(rankingUser &user);
	void fillRanking();
	rankingUser & getRankingUser(int i);
	rankingUser* getRanking();
};


#include "Ranking.h"



Ranking::Ranking()
{
}


Ranking::~Ranking()
{
}

void Ranking::saveRanking()
{
	std::ofstream rankingFile;
	rankingFile.open("ranking.bin", std::ios::out | std::ios::binary | std::ios::trunc);
	for (int i = 0; i < userRankingLength;i++)
	{
		rankingFile.write((char*)&ranking[i], sizeof(rankingUser));
	}
	rankingFile.close();
	
}

void Ranking::loadRanking()
{
	std::ifstream rankingFile;
	rankingFile.open("ranking.bin", std::ios::in | std::ios::binary);
	for (int i = 0;i < userRankingLength;i++)
	{
		rankingFile.read((char*)&ranking[i], sizeof(rankingUser));
	}
	for (int i = 0; i < userRankingLength;i++)
	{
		std::cout << ranking[i].getName() << " " << ranking[i].getScore() << std::endl;
	}
	rankingFile.close();


}

void Ranking::AddnsortRanking(rankingUser & user)
{
	for (int i = userRankingLength - 1; i > 0;i--)
	{ 
		if (user.getScore() > ranking[0].getScore())
		{
			ranking[0] = user;
			for (int j = 1; j < userRankingLength;j++)
			{
				if (j + 1 < userRankingLength)
				ranking[j] = ranking[j + 1];
			}
			
			break;
		}
		if (user.getScore() > ranking[i].getScore() && user.getScore() <= ranking[i - 1].getScore())
		{
			ranking[i] = user;
			for (int j = i + 1 ; j < userRankingLength;j++)
			{
				if(j + 1 < userRankingLength)
				ranking[j] = ranking[j+1];
			}
			break;
		}
		
	}
}

void Ranking::fillRanking()
{
	for (int i = 0; i < userRankingLength;i++)
	{
		rankingUser user("default", userRankingLength - i);
		ranking[i] = user;

	}
}

rankingUser & Ranking::getRankingUser(int i)
{
	return ranking[i];
	// TODO: insert return statement here
}


rankingUser* Ranking::getRanking()
{

	return ranking;
	// TODO: insert return statement here
}

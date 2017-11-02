#pragma once
#include "Tile.h"
#include "Vector.h"
#define GOAL 5
#define preGoal 4
#define ENEMY 2
#define mainCharacter 3
#define NPC 1
#define WATER 8
#define EMPTY 0
class AImap
{

private:
	int actualPositionX;
	int actualPositionY;
	int goalPositionX;
	int goalPosiitonY;
	Tile** mapPointer;
	bool gotGoal;
public:
	AImap();
	AImap(Tile** map, int actualX, int actualY);
	~AImap();
	void setGoal(int x, int y);
	void setMap(Tile** map);
	void setActualPosition(int x,int  y);
	bool & getGoalBool();
	Coord<int> getBestPlace();

};


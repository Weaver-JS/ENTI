#include "AImap.h"



AImap::AImap()
{
	gotGoal = false;
}

AImap::AImap(Tile** map, int actualX, int actualY)
{
	mapPointer = map;
	actualPositionX = actualX;
	actualPositionY = actualY;
	gotGoal = false;
}


AImap::~AImap()
{
}

void AImap::setGoal(int x, int y)
{
	goalPositionX = x / SPRITE_DEFAULT_WIDTH;
	goalPosiitonY = y / SPRITE_DEFAULT_HEIGHT;
}

void AImap::setMap(Tile ** map)
{
	mapPointer = map;
}

void AImap::setActualPosition(int x, int y)
{
	actualPositionX = x / SPRITE_DEFAULT_WIDTH;
	actualPositionY = y / SPRITE_DEFAULT_HEIGHT;
}

bool & AImap::getGoalBool()
{
	return gotGoal;
}

Coord<int> AImap::getBestPlace()
{
	int minimValue = 8000;
	int selectedX = 0;
	int selectedY = 0;
	int value = 0;
	int repeatedNum = 0;
	/*for (int i = 0; i < LAYERLENGTH;i++)
	{
		
		for (int j = 0; j < LAYERLENGTH; j++)
		{
			std::cout << mapPointer[j][i].getLayer().dataArray[2];
		}
		std::cout << std::endl;
	}*/

	std::cout << std::endl;
 	for (int i = actualPositionX - 1; i <= actualPositionX + 1; i++)
	{
		for (int j = actualPositionY- 1; j <= actualPositionY+ 1; j++)
		{
			
			if (i >=  0 && i<LAYERLENGTH && j>= 0 && j< LAYERLENGTH)
			{
				
				 value = sqrt(abs((goalPositionX - i) * (goalPositionX - i) + (goalPosiitonY - j) * (goalPosiitonY - j)))  + mapPointer[i][j].getLayer().dataArray[2]; // sacamos distancias y sumamos el valor de la casilla, para ver si es el correcto.
				if (value < minimValue && mapPointer[i][j].getLayer().dataArray[2] == EMPTY)
				{

					minimValue = value;
					selectedX = i;
					selectedY = j;
				}
				if (mapPointer[i][j].getLayer().dataArray[2] == preGoal)
				{
					gotGoal = true;
					mapPointer[actualPositionX][actualPositionY].getLayer().dataArray[2] = EMPTY;
				}

			}
		}
	}
	mapPointer[actualPositionX][actualPositionY].getLayer().dataArray[2] = EMPTY;
	mapPointer[selectedX][selectedY].getLayer().dataArray[2] = ENEMY;
	if (mapPointer[selectedX][selectedY].getLayer().dataArray[2] == preGoal)
	{
		mapPointer[selectedX][selectedY].getLayer().dataArray[2] = EMPTY;
	}
	actualPositionX = selectedX;
	actualPositionY = selectedY;
	Coord<int> selectedPos(selectedX, selectedY);
	return selectedPos;
}

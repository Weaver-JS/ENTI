#include "Tile.h"



Tile::Tile()
{
	
	layer0 = SPRITE_TERRAIN_1;
	layer1 = SPRITE_TERRAIN_2;
	objectIn = false;
}
int Tile::getLayer0()
{
	return layer0;
}

int Tile::getLayer1()
{
	return layer1;
}
/*void Tile::placeTile0(int x, int y)
{
	layer0.setPositionAtWorld(x, y);
	
}*/

/*void Tile::placeTile1(int x, int y)
{
	layer1.setPositionAtWorld(x, y);
}*/


Tile::~Tile()
{
}

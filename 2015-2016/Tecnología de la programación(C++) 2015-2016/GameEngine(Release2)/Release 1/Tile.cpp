#include "Tile.h"



Tile::Tile()
{
	layer.setActualPosition(0);
	layer.addData(SPRITE_TERRAIN_1);
	layer.addData(SPRITE_TERRAIN_2);
	objectIn = false;
}


void Tile::changeLayerSprite(int numLayer,int numSprite)
{
	layer.dataArray[numLayer] = numSprite;
}
Array<int> Tile::getLayer()
{
	return layer;
}




Tile::~Tile()
{
	
}

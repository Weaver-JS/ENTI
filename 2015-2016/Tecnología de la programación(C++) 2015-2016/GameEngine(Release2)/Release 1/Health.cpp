#include "Health.h"



Health::Health()
{
	hCoords.setVector(0, 0);
	heart.setInitialValues(hCoords.getVectorX(), hCoords.getVectorY(), SPRITE_HEART, 63, 53, 0, 1);
}

void Health::placeHeart(Coord<int> v)
{
	hCoords = v;
	heart.setPositionAtWorld(hCoords.getVectorX(),hCoords.getVectorY());
}
Sprite Health::getSprite()
{
	return heart;
}
Coord<int> Health::getCoords()

{
	return hCoords;
}


void Health::sumPosition(Coord<int> sumVector)
{
	hCoords += sumVector;

}
Health::~Health()
{
}

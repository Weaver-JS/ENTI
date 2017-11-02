#include "Health.h"



Health::Health()
{
	_x = 0;
	_y = 0;
	heart.setInitialValues(_x, _y, SPRITE_HEART, 63, 53, 0, 1);
}

void Health::placeHeart(int x, int y)
{
	_x = x;
	_y = y;
	heart.setPositionAtWorld(_x, _y);
}
Sprite Health::getSprite()
{
	return heart;
}
int Health::getX()

{
	return _x;
}
int Health::getY()
{
	return _y;
}

void Health::sumPosition(int x, int y)
{
	_x += x;
	_y += y;

}
Health::~Health()
{
}

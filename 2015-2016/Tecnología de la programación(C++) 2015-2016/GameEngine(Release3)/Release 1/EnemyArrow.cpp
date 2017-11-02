#include "EnemyArrow.h"



EnemyArrow::EnemyArrow()
{
	_sprite.setInitialValues(LIMITX, LIMITY, SPRITE_HEART, SPRITE_DEFAULT_WIDTH, SPRITE_DEFAULT_HEIGHT, 0, 1);
}


EnemyArrow::~EnemyArrow()
{
}

int EnemyArrow::calculateRect(int pointA_x, int pointA_y, int pointB_x, int pointB_y)
{
  //	Coord<int> centro(pointA_x, pointA_y);
	float y = 0;
	float x;
	int radius = 50;
	/*
		x - pointA_x / pointB_x - pointA_x   = y - PointA_y / pointB_y - pointA_y;

		x- pointA_x = (y - pointA_y / pointB_y - pointA_y) * (pointB_x -pointA_x);
		x =(y - pointA_y / pointB_y - pointA_y) * (pointB_x -pointA_x) + pointA_x;
		
		(x - pointA_x / pointB_x - pointA_x)* (pointB_y - pointA_y) = y - PointA_y;

		(x - pointA_x / pointB_x - pointA_x)* (pointB_y - pointA_y)  + pointA_y = y;

		Círculo
		(x

	*/
	float vectorX, vectorY;
	vectorX =pointA_x- pointB_x;
	vectorY =pointA_y -pointB_y;

	//x = pointB_x + ((vectorX / (vectorX * 1.1)) ) * (vectorX);
	//y = pointB_y + (vectorY/(vectorY * 1.1 )) * (vectorY);
	x = pointB_x + (0.75 ) * (vectorX);
	y = pointB_y + (0.75) * (vectorY);
		
		

		_sprite.setPositionAtWorld(x, y);
		return y;
	
}

Sprite EnemyArrow::getSprite()
{
	return _sprite;
}

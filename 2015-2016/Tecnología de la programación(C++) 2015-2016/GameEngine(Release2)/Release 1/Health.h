#pragma once
#include "Sprite.h"
#include "Vector.h"
class Health
{
private:
	Coord<int> hCoords;
	/*int _x;
	int _y;*/
	Sprite heart;

public:
	Health();
	~Health();

	void placeHeart(Coord<int> v);
	Sprite getSprite();
	Coord<int> getCoords();
	void sumPosition(Coord<int> sumVector);
};


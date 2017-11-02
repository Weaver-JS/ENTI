#pragma once
#include "Sprite.h"
class Health
{
private:
	int _x;
	int _y;
	Sprite heart;

public:
	Health();
	~Health();

	void placeHeart(int x, int y);
	Sprite getSprite();
	int getX();
	int getY();
	void sumPosition(int x, int y);
};


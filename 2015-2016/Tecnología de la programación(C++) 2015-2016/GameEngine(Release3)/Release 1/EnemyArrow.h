#pragma once
#include "Sprite.h"
#include <iostream>
class EnemyArrow 
{
private:
	Sprite _sprite;

public:
	EnemyArrow();
	~EnemyArrow();
	int calculateRect(int pointA_x, int pointA_y, int pointB_x, int pointB_y);
	Sprite getSprite();
};


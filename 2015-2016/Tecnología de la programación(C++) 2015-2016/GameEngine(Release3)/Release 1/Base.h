#pragma once
#include "Sprite.h"
#include "Vector.h"
#include <Windows.h>
class Base
{
#define interval 100;
private:
	
	int dangerZonedist;
	int _life;
	bool beingAttacked;
	int receiveAttacks;
	Coord<int> _coords;
	int timerWithInterval;
	Sprite _sprite;

	
public:
	Base();
	~Base();
	void calculateDangerZone(Coord<int> pos);
	void moveBase(Coord<int> pos);
	Sprite getSprite();
	void baseCheck(int actualTick);
	int getBaseLive();
	Coord<int> & getCoords();
	void getAttacked();
	void setLife(int n);
};


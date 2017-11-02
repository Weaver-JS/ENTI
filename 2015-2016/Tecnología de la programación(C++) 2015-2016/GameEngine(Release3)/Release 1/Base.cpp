#include "Base.h"



Base::Base()
{
	dangerZonedist = 100;
	_life = 2000;
	beingAttacked = false;
	receiveAttacks = 0;
	_coords.setVector(LAYERLENGTH*SPRITE_DEFAULT_WIDTH  /2 - BASE_WIDTH/2 + 50 , LAYERLENGTH * SPRITE_DEFAULT_HEIGHT / 2 - Base_Height/2);
	_sprite.setInitialValues(_coords.getVectorX(), _coords.getVectorY(), SPRITE_BASE, BASE_WIDTH, Base_Height, 0, 1);
}


Base::~Base()
{
}

void Base::calculateDangerZone(Coord<int> pos)
{
	if (_coords.getVectorX() + dangerZonedist < pos.getVectorX() && _coords.getVectorY() + dangerZonedist < pos.getVectorY())
	{
		beingAttacked = true;
	}
}

Sprite Base::getSprite()
{
	return _sprite;
}

void Base::baseCheck(int actualTick)
{
	if (beingAttacked == true)
	{
		receiveAttacks += 1;
	}
	if (actualTick > timerWithInterval)
	{
		_life -= receiveAttacks;
		timerWithInterval = GetTickCount() + interval;
	}
}

int Base::getBaseLive()
{
	return _life;
}

Coord<int>& Base::getCoords()
{
	return _coords;
	// TODO: insert return statement here
}

void Base::getAttacked()
{
	_life -= 10;
}

void Base::setLife(int n)
{
	_life = n;
}

void Base::moveBase(Coord<int> pos)
{
	_coords += pos;
	_sprite.setPositionAtWorld(_coords.getVectorX(), _coords.getVectorY());
}
#include "Bullet.h"



Bullet::Bullet()
{
}

Bullet::Bullet(Coord<int> pos, Coord<int> velocity, int bullet)
{
	this->pos = pos;
	this->velocity = velocity;
	this->distance = 200;
	this->_bullet.setInitialValues(pos.getVectorX(), pos.getVectorY(), bullet, SPRITE_DEFAULT_WIDTH, SPRITE_DEFAULT_HEIGHT, 0, 1);// = bullet;
		firstPos = pos;
}

Bullet::Bullet(Bullet & b)
{
	pos = b.pos;
	velocity = b.pos;
	 distance = b.distance;
	 _bullet = b._bullet;

}


Bullet::~Bullet()
{
}

bool Bullet::checkHit(Collider c)
{
	if (c.onColisionEnter(pos.getVectorX(), pos.getVectorY()))
	{

		return true;
	}
	return false;
}

void Bullet::moveBullet()
{
	pos += velocity;
	_bullet.setPositionAtWorld(pos.getVectorX(), pos.getVectorY());
}

Sprite Bullet::getSprite()
{
	return _bullet;
}

int Bullet::getDistance()
{
	return distance;
}

Coord<int> Bullet::getFirstPos()
{
	return firstPos;
}

Coord<int> Bullet::getPos()
{
	return pos;
}

Coord<int>& Bullet::getVelocity()
{
	return velocity;
}

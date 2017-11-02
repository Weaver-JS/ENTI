#include "BulletList.h"






BulletList::~BulletList()
{
}

void BulletList::addBullet(Coord<int> pos, Coord<int> velocity)
{
	b = new Bullet(pos,velocity,BULLET_SPRITE);
	addCharacter(b);
	std::cout << getLength() << std::endl;
}

void BulletList::moveBullets()
{
	for (int i = 0; i < getLength(); i++)
	{
		getCharacter(i)->moveBullet();
		if (abs(getCharacter(i)->getPos().getVectorX()) >= abs(getCharacter(i)->getFirstPos().getVectorX() + getCharacter(i)->getDistance()) || abs(getCharacter(i)->getPos().getVectorY()) >= abs(getCharacter(i)->getFirstPos().getVectorY() + getCharacter(i)->getDistance()))
		{
			removeCharacter();
		}
	}
}

bool BulletList::checkHit(Collider col)
{
	for (int i = 0; i < getLength(); i++)
	{
		if (getCharacter(i)->checkHit(col))
		{
			return true;
		}
	}
	return false;
}

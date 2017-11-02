#include "BulletList.h"






BulletList::~BulletList()
{
}

void BulletList::addBullet(Coord<int> pos, Coord<int> velocity)
{
	b = new Bullet(pos,velocity,BULLET_SPRITE);
	addCharacter(b);

}

void BulletList::moveBullets()
{
	int length = getLength();
	for (int i = 0; i < length; i++)
	{
		getCharacter(i)->moveBullet();
		if (getCharacter(i) != NULL &&  abs(getCharacter(i)->getPos().getVectorX()) >= abs(getCharacter(i)->getFirstPos().getVectorX() + getCharacter(i)->getDistance()) || abs(getCharacter(i)->getPos().getVectorY()) >= abs(getCharacter(i)->getFirstPos().getVectorY() + getCharacter(i)->getDistance()))
		{
			removeCharacter(i);
			
			length = getLength();
			
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

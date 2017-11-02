#include "objectList.h"



objectList::objectList()
{
	 numEnvironment = ENVIRONMENT_OBJECT_NUM;
	 numPowerUp = POWER_UP_NUM;
	 numHealthObject = HEALTH_OBJECT_NUM;
}

Sprite objectList::getSpriteID(int id)
{
	return getCharacter(id)->getSprite();
}

int objectList::getObjectID(int id)
{
	return getCharacter(id)->getObjectID();
}

void objectList::init() {
	Coord<int> pos(50, 50);
	srand(time(NULL));

 	for (int i = 0; i < ENVIRONMENT_OBJECT_NUM; i++) {
		pos.setVector(rand() % WIDTH, rand() % HEIGHT);
		polymorphisticObject = new Environment(pos, std::rand() % 3 + SPRITE_TREE_ENVIRONMENT);
		addCharacter(polymorphisticObject);
	}

	for (int i = 0; i < POWER_UP_NUM; i++) {
		pos.setVector(rand() % WIDTH, rand() % HEIGHT);
		polymorphisticObject = new PowerUp(pos, std::rand() % 3 + SPRITE_SPEED_POWERUP);
		addCharacter(polymorphisticObject);
	}

	for (int i = 0; i < HEALTH_OBJECT_NUM; i++) {
		pos.setVector(rand() % WIDTH, rand() % HEIGHT);
		polymorphisticObject = new healthObject(pos, SPRITE_HEALTHOBJECT);
		addCharacter(polymorphisticObject);
	}
}

void objectList::powerUpsubtract()
{
	numPowerUp--;
}

int objectList::getNumPowerUp()
{
	return numPowerUp;
}



objectList::~objectList()
{
}

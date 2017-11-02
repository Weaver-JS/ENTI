#include "healthObject.h"



healthObject::healthObject()
{
}


healthObject::~healthObject()
{
}


void healthObject::moveCharacter(Coord<int> pos)
{
	_position += pos;
	_sprite.setPositionAtWorld(_position.getVectorX() + SPRITE_DEFAULT_WIDTH / 2, _position.getVectorY() - SPRITE_DEFAULT_HEIGHT / 2);
	_col.setCoordsAndDist(_position.getVectorX() + SPRITE_DEFAULT_WIDTH/2, _position.getVectorY()-SPRITE_DEFAULT_HEIGHT /2, SPRITE_DEFAULT_WIDTH / 2);
}

int healthObject::getID() {
	return objectID;
}

int healthObject::getSpriteID()
{
	return _sprite.getSpriteId();
}

void healthObject::setHealthObjectCoord(Coord<int> powerUpCoords) {
	_position = powerUpCoords;
}




Coord<int> healthObject::getCoord() {
	return _position;
}


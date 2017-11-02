#include "Environment.h"



Environment::Environment(){
}


Environment::~Environment(){
}

void Environment::moveCharacter(Coord<int> pos)
{
	_position += pos;
	_sprite.setPositionAtWorld(pos.getVectorX() + SPRITE_DEFAULT_WIDTH /2, pos.getVectorY()- SPRITE_DEFAULT_HEIGHT /2);

}

int Environment::getID() {
	return objectID;
}

int Environment::getSpriteID()
{
	return _sprite.getSpriteId();
}



void Environment::setEnvironmentCoords(Coord<int> environmentCoords) {
	_position = environmentCoords;
}

Coord<int> Environment::getCoord() {
	return _position;
}


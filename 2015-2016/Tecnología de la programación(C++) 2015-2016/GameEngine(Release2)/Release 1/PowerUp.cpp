#include "PowerUp.h"



PowerUp::PowerUp(){
	}

PowerUp::~PowerUp(){
}




int PowerUp::getID() {
	return objectID;
}

int PowerUp::getSpriteID()
{
	return _sprite.getSpriteId();
}

void PowerUp::moveCharacter(Coord<int> pos)
{
	_position += pos;
	_sprite.setPositionAtWorld(_position.getVectorX() + INVENTORY_WIDTH/2, _position.getVectorY()-INVENTORY_HEIGHT/2);
	_col.setCoordsAndDist(_position.getVectorX() + INVENTORY_WIDTH/2, _position.getVectorY()-INVENTORY_HEIGHT/2, INVENTORY_WIDTH / 2);
}

void PowerUp::setPowerUpCoord(Coord<int> powerUpCoords) {
	_position = powerUpCoords;
}



Coord<int> PowerUp::getCoord() {
	return _position;
}



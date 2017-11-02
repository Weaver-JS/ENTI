#pragma once
#include "Object.h"

/*
	Clase Power-up
*/
class PowerUp : 
	public Object
{

public:
	PowerUp();
	~PowerUp();
	
	PowerUp(Coord<int> pos, int spriteID) : Object(pos, spriteID){
		_position = pos;
		_col.setCoordsAndDist(pos.getVectorX() + INVENTORY_WIDTH / 2,pos.getVectorY() - INVENTORY_HEIGHT / 2, INVENTORY_WIDTH / 2);
		_sprite.setInitialValues(pos.getVectorX() + INVENTORY_WIDTH / 2, pos.getVectorY() - INVENTORY_HEIGHT / 2, spriteID, INVENTORY_WIDTH, INVENTORY_HEIGHT, 0, 1);
		objectID = rand() % 3;
	};
	PowerUp(Coord<int> pos, int spriteID,int ObjectID) : Object(pos, spriteID) {
		_position = pos;
		_col.setCoordsAndDist(pos.getVectorX() + INVENTORY_WIDTH / 2, pos.getVectorY() - INVENTORY_HEIGHT / 2, INVENTORY_WIDTH / 2);
		_sprite.setInitialValues(pos.getVectorX() + INVENTORY_WIDTH / 2, pos.getVectorY() - INVENTORY_HEIGHT / 2, spriteID, INVENTORY_WIDTH, INVENTORY_HEIGHT, 0, 1);
		objectID = ObjectID;
	};
	int getID();
	int getSpriteID();
	void moveCharacter(Coord<int> pos);
	void setPowerUpCoord(Coord<int> powerUpCoords);
	Coord<int> getCoord();
	
};


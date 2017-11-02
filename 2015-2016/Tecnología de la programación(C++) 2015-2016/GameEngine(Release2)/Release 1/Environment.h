#pragma once
#include "Object.h"
class Environment :
	public Object
{
	/*
	Clase hija de objeto,
	se encarga de decorar el mapa.
	*/

public:
	Environment();
	~Environment();

	Environment(Coord<int> pos, int spriteID) : Object(pos, spriteID) {
		_position = pos;
		_col.setCoordsAndDist(pos.getVectorX(), pos.getVectorY(), SPRITE_DEFAULT_WIDTH / 2);
		_sprite.setInitialValues(pos.getVectorX(), pos.getVectorY(), spriteID, ENVIRONMENT_WIDTH, ENVIRONMENT_WIDTH, 0, 1); 

		switch (spriteID) {
		case SPRITE_TREE_ENVIRONMENT: _sprite.setInitialValues(pos.getVectorX(), pos.getVectorY(), spriteID, TREE_WIDTH, TREE_HEIGHT, 0, 1); break;
		default: 	_sprite.setInitialValues(pos.getVectorX(), pos.getVectorY(), spriteID, ENVIRONMENT_WIDTH, ENVIRONMENT_WIDTH, 0, 1); break;
		}
	};
	void moveCharacter(Coord<int> pos);
	int getID();
	int getSpriteID();
	void setEnvironmentCoords(Coord<int> environmentCoords);
	Coord<int> getCoord();



};


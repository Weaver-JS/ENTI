#pragma once
#include "Object.h"
class healthObject :
	public Object
{
	/*
	Clase hija de objeto,
	por ahora no sirve para nada.
	se puede recoger y se pone en el inventario.
	*/

public:
	healthObject();
	~healthObject();

	healthObject(Coord<int> pos, int spriteID) : Object(pos, spriteID) {
		_position = pos;
		_col.setCoordsAndDist(pos.getVectorX() + SPRITE_DEFAULT_WIDTH / 2, pos.getVectorY() - SPRITE_DEFAULT_HEIGHT / 2, SPRITE_DEFAULT_WIDTH / 2);
		_sprite.setInitialValues(pos.getVectorX() + SPRITE_DEFAULT_WIDTH/2, pos.getVectorY()- SPRITE_DEFAULT_HEIGHT /2, SPRITE_HEALTHOBJECT, SPRITE_DEFAULT_WIDTH, SPRITE_DEFAULT_HEIGHT, 0, 1);

	};
	void moveCharacter(Coord<int> pos);
	int getID();
	int getSpriteID();
	void setHealthObjectCoord(Coord<int> powerUpCoords);
	Coord<int> getCoord();

};


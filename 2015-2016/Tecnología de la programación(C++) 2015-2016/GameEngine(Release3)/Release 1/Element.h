#pragma once
#include "Vector.h"
#include "Sprite.h"
#include"GameConstants.h"
#include "Collider.h"

/*
Clase padre de todo objeto/Character
*/
class Element
{

protected:
	Coord<int> _position;
	Sprite _sprite;
	Collider _col;
public:
	Element();
	Element(Element &c);
	~Element();
};


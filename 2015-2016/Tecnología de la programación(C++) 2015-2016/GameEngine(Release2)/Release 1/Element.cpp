#include "Element.h"



	Element::Element()
	{
		_position.setVector(0, 0);
		_sprite.setInitialValues(0, 0, SPRITE_ANIM, 0, 0, 0, 1);
		_col.setCoordsAndDist(_position.getVectorX(), _position.getVectorY(), 5);
	}

	Element::Element(Element & c)
	{
		_position = c._position;
		_sprite = c._sprite;
		_col = c._col;

	}


	Element::~Element()
	{
	}

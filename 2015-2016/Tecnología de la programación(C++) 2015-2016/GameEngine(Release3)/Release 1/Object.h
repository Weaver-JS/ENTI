#pragma once
#include <time.h>
#include "Element.h"

//Abstract class of Objects
class Object : public Element
{
	/* 
	Clase abstracta objeto
	encargada de compartir metodos y atributos con sus clases hijas:
	Environment
	Power up
	HealthObject
	*/
protected:
	int objectID;
	
public:
	
	Object();
	Object(Coord<int> pos, int spriteID);
	Object(Object &o);

	//Virtual methods
	virtual int getID() = 0;
	virtual int getSpriteID() = 0;
	virtual void moveCharacter(Coord<int> pos) = 0;
	//Shared Methods
	Coord<int> getPosition();
	Sprite getSprite();
	Collider getCollider();
	int getObjectID();
	~Object();
};


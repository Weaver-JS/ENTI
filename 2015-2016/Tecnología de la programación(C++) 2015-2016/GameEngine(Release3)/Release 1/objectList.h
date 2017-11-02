#pragma once
#include "LinkedListPointer.h"
#include "PowerUp.h"
#include "Environment.h"
#include "healthObject.h"
/*
	Lista de objetos, se encarga de gestionar y organizar los objetos de la partida-
*/
class objectList :
	public LinkedListPointer<Object*>
{
private:
	Object* polymorphisticObject;
	int numEnvironment;
	int numPowerUp;
	int numHealthObject;
public:
	objectList();
	~objectList();

	Sprite getSpriteID(int id);
	int getObjectID(int id);
	void init();
	void powerUpsubtract();
	int getNumPowerUp();

	
	

};


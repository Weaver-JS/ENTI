#pragma once
#include "Array.h"
#include "Sprite.h"

class Inventory
{
	
	/*
	Clase inventario.
	Se encarga de gestionar y enseñar los objetos que vamos cogiendo del suelo.
	*/
private:
	//Creation of an Array of Sprites with 10 positions
	Array<Sprite>inventorySlots = Array<Sprite>(10);
public:
	Inventory();
	~Inventory();
	//Initialization
	//Print information
	//Deleting an object from the inventory
	void deleteObject(int spriteID);
	//Change the sprite
	void changeSpriteID(int spriteID);
	Array<Sprite> & getSpriteArray();
	
};


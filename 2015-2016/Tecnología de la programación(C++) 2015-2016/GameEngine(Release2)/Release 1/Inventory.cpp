#include "Inventory.h"



Inventory::Inventory()
{
	for (int i = 0; i < inventorySlots.getLenght(); i++) {
		if (i == 0) {
		inventorySlots.dataArray[i].setInitialValues(INVENTORY_X_POSITION, INVENTORY_Y_POSITION, SPRITE_EMTPY_OBJECT, INVENTORY_WIDTH, INVENTORY_HEIGHT, 0, 1);
		}
		else
			inventorySlots.dataArray[i].setInitialValues(INVENTORY_X_POSITION + INVENTORY_WIDTH * i, INVENTORY_Y_POSITION, SPRITE_EMTPY_OBJECT, INVENTORY_WIDTH, INVENTORY_HEIGHT, 0, 1);
	}
}



void Inventory::changeSpriteID(int spriteID) {
	//In the case that the position has an empty object, we fill it with the new object, in this situation, we avoid deleting objects that we have
	for (int i = 0; i < inventorySlots.getLenght(); i++) {
		if (inventorySlots.dataArray[i].getSpriteId() == SPRITE_EMTPY_OBJECT) {
			inventorySlots.dataArray[i].setSpriteID(spriteID);
			break;
		}

	}
}

Array<Sprite> & Inventory::getSpriteArray()
{
	return inventorySlots;
}

//Deleting an object from the inventory
void Inventory::deleteObject(int spriteID) {
	//We search the object that we want to destroy and we make that position an empty position
	for (int i = 0; i < inventorySlots.getLenght(); i++) {
		if (inventorySlots.dataArray[i].getSpriteId() == spriteID) {
			inventorySlots.dataArray[i].setSpriteID(SPRITE_EMTPY_OBJECT);
			break;
		}
	}
	//After that, we move all the positions to send the empty space to the end of the array
	for (int j = 0; j < inventorySlots.getLenght(); j++) {
		if (inventorySlots.dataArray[j].getSpriteId() == SPRITE_EMTPY_OBJECT && inventorySlots.dataArray[j + 1].getSpriteId() != SPRITE_EMTPY_OBJECT && j + 1 != inventorySlots.getLenght()) {
			inventorySlots.dataArray[j].setSpriteID(inventorySlots.dataArray[j+1].getSpriteId());
			inventorySlots.dataArray[j + 1].setSpriteID(SPRITE_EMTPY_OBJECT);
		}
	}
}




Inventory::~Inventory(){
}

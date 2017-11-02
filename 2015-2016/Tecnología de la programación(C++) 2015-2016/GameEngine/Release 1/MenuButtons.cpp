#include "MenuButtons.h"




MenuButtons::MenuButtons()
{
	
}

MenuButtons::MenuButtons(int numColliders)
{
	this->numColliders = numColliders;
	buttons = new Collider[numColliders];
}

void MenuButtons::setColliders(int x, int y, int dist, int coordArray)
{
	buttons[coordArray].setCoordsAndDist(x, y, dist);
}

Sprite MenuButtons::getSprite() {
	return sprite;
}

void MenuButtons::setSprite(Sprite newSprite) {
	sprite = newSprite;
}


MenuButtons::~MenuButtons()
{
	delete[] buttons;
}



#include "MenuButtons.h"




MenuButtons::MenuButtons()
{
	buttons = NULL;
}

MenuButtons::MenuButtons(MenuButtons & mb)
{
	numColliders = mb.numColliders;
	sprite = mb.sprite;
}

MenuButtons::MenuButtons(int numColliders)
{
	buttons = NULL;
	this->numColliders = numColliders;
	buttons = new Collider[numColliders];
	//buttons = new Collider[numColliders];
}

void MenuButtons::setColliders(int x, int y, int dist, int coordArray)
{

	buttons[coordArray].setCoordsAndDist(x, y, dist);
}

void MenuButtons::setNumColliders(int numColliders)
{
	this->numColliders = numColliders;
}

Sprite MenuButtons::getSprite() {
	return sprite;
}

void MenuButtons::setSprite(Sprite newSprite) {
	sprite = newSprite;
}


MenuButtons::~MenuButtons()
{

}



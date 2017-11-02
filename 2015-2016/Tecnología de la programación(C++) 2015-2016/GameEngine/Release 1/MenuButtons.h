#include "Sprite.h"
#include "Collider.h"

#pragma once
class MenuButtons
{

private:
	int numColliders;
	Sprite sprite;

public:
	Collider* buttons; //Hacerlo dinámico después

	MenuButtons();
	MenuButtons(int numColliders);
	Sprite getSprite();
	void setSprite(Sprite newSprite);
	void setColliders(int x, int y, int dist, int coordArray);
	~MenuButtons();
};


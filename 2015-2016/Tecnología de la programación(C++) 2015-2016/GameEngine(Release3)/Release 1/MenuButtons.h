#include "Sprite.h"
#include "Collider.h"

#pragma once
class MenuButtons
{

	/*
		Clase MenuButtons
		se encarga de organizar las escenas del juego.
	*/
private:
	int numColliders;
	Sprite sprite;

public:
	Collider* buttons; 

	MenuButtons();
	MenuButtons(MenuButtons &mb);
	MenuButtons(int numColliders);
	Sprite getSprite();
	void setSprite(Sprite newSprite);
	void setColliders(int x, int y, int dist, int coordArray);
	void setNumColliders(int numColliders);
	~MenuButtons();
};


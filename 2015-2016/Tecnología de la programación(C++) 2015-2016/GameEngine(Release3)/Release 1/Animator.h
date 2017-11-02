#pragma once
#include "Sprite.h"
#include "SDLInterface.h"

class Animator :
	public Sprite
{
	int rowHeight;
	/*
	Animator class, se encarga de permitir animar objetos con spritesheets que posean altura.
	*/
public:
	Animator();
	void drawSprite(Sprite &sprite, SDLInterface &_graphics);
	void setRowHeight(int newRowHeight);
	~Animator();
};


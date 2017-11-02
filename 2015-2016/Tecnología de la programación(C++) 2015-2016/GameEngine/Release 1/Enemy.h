#include "Sprite.h"
#include "GameConstants.h"

#pragma once

class Enemy
{
private:
	
	int _Xposition;
	int _Yposition;
	int velocity;
	bool dead;
	Sprite sprite;


	
public:
	//Constructores
	Enemy();
	Enemy(int xpos, int ypos, Sprite sprite);
	Enemy(Enemy &enemy);
	//DESTRUCTOR
	~Enemy();

	//Methods
	int getXposition();
	int getYposition();
	int getVelocity();
	Sprite getSprite();
	void spriteAnimation();
	void setNewPosition(int x, int y);
	void init(int x, int y);
	void changeVelocity();

	
	


};


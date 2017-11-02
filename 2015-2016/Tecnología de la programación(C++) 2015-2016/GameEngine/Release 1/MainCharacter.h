#pragma once
#include "Sprite.h"
#include "Health.h"
class MainCharacter
{
private:
	int _Xcoord; //Coordenada X del personaje.
	int _Ycoord; // Coordenada Y del personaje.

	// coordenadas entre los límites de la cámara.
	int _XcoordCamera;  
	int _YcoordCamera; 

	//Velocidad del personaje.
	int velocity;

	Sprite _mainCharacter;
	//La vida será un objeto aparte
	int numLife;
	Health* heartArray;

public:
	//Constructor
	MainCharacter();
	~MainCharacter();
	
	//Methods
	void moveCharacter(int x,int y);
	void setCharacterCoords(int x, int y);
	void nextAnimationframe(int tick);
	void changeVelocity(int newVel);
	//Getters
	int getXcoordCamera();
	int getYcoordCamera();
	int getVelocity();
	int getXcoord();
	int getYcoord();
	int getNumLife();
	Sprite getSprite();
	Health* getHealth();


};


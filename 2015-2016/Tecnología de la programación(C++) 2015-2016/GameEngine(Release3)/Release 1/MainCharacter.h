#pragma once
#include "Health.h"
#include "Array.h"
#include "Animator.h"
#include "Character.h"

class MainCharacter : public Character
{
	
	/*
	Clase MainCharacter hija de Character.
	Se encarga de gestionar el personaje que utiliza el jugador.
	*/
private:
	
	
	Coord<int> _cameraPosition;
	
	



public:
	//Constructor
	MainCharacter();
	 void setGoal(int x, int y) {};
	 void sendMap(Tile** _map) {};
	

	MainCharacter(Coord<int> position, int characterVelocity, int attackPower, int mainC, int characterHealth) : Character(position, mainC, attackPower, characterVelocity, characterHealth)
	{
		
		_sprite.setInitialValues(position.getVectorX(), position.getVectorY(), mainC, MainCharacter_WIDTH, MainCharacter_HEIGHT, 0, 9);
		//_col.setCoordsAndDist(position.getVectorX(), position.getVectorY(), 23);
		_cameraPosition = position;
		_sprite.setPositionAtWorld(position.getVectorX() + MainCharacter_WIDTH / 2, position.getVectorY() + MainCharacter_HEIGHT / 2);

		_col.setCoordsAndDist(position.getVectorX() + MainCharacter_WIDTH / 2, position.getVectorY() + MainCharacter_HEIGHT / 2, MainCharacter_HEIGHT);
		characterMaxHeight = 4;

		
	}
	~MainCharacter();

	//Methods
	void moveCharacter(Coord<int> pos);

	//Virtuals
	void moveCharacter();
	void drawLoop();
	void attack();
	//Virtuals
	void moveCharacterPrivate(Coord<int> characterMove);
	void animation();
	void setCharacterCoords(Coord<int> characterCoords);
	void nextAnimationframe(int tick);
	void changeVelocity(int newVel);
	//Getters
	Coord<int> getCameraPosition();
	int getVelocity();
	Coord<int> getCoord();
	
	void attack(Collider col);
    void drawLoop(SDLInterface* graphic);
	void drawSprite(Sprite &sprite, SDLInterface* graphic);
	
	void attackBase(Base &b) {};
	void addHeart();
	void removeHeart();
	Sprite getSprite();
	Array<Health> getHealth();

	int getArrowY(Coord<int> pos) {
		return 0;
	};
	Sprite getArrowSprite() { return _sprite; };
	//POWER UPS
	bool getPowerUp(Collider &col,int id);

};


#pragma once
#include "Character.h"

class Enemy : public Character
{
private:
	/*
	Clase enemigo hija de la clase abstracta Character.
	Se encarga de perseguir al personaje cuando este se acerca lo suficiente.
	si toca al personaje este pierde vida.
	*/
	
public:
	void attack(Collider col);
	void moveCharacter();
	void moveCharacter(Coord<int> pos);
	bool getPowerUp(Collider &col, int id) { return false; };
	void drawLoop(SDLInterface * s) {};
	Enemy();
	Enemy(Enemy &c);
	Enemy(Coord<int> pos, int sprite, int attackPower, int velocity, int characterHealth) : Character(pos, sprite, attackPower, velocity,characterHealth)
	{
		combatActivated = false;
		_sprite.setInitialValues(pos.getVectorX(), pos.getVectorY(), SPRITE_FIRE, ENEMY_WIDTH , ENEMY_HEIGHT, 0, 3);
		//_col.setCoordsAndDist(pos.getVectorX(), pos.getVectorY(), 23);
		
	}

	~Enemy();
};


#pragma once
#include "Character.h"
#include "EnemyArrow.h"
#include "AImap.h"

class Enemy : public Character
{
private:
	/*
	Clase enemigo hija de la clase abstracta Character.
	Se encarga de perseguir al personaje cuando este se acerca lo suficiente.
	si toca al personaje este pierde vida.
	*/ 
	enemyState _state;
	EnemyArrow arrow;
	AImap enemyMap;
	Coord<int> cameraPosition;
	
public:
	void attack(Collider col);
	void moveCharacter();
	void moveCharacter(Coord<int> pos);
	bool getPowerUp(Collider &col, int id) { return enemyMap.getGoalBool(); };
	void drawLoop(SDLInterface * s) {};
	int getArrowY(Coord<int> pos);
	Coord<int> getCameraPosition() { return  cameraPosition; };
	Sprite getArrowSprite();
	Enemy();
	Enemy(Enemy &c);
	Enemy(Coord<int> pos, int sprite, int attackPower, int velocity, int characterHealth) : Character(pos, sprite, attackPower, velocity,characterHealth)
	{
		combatActivated = false;
		_sprite.setInitialValues(pos.getVectorX() + (ENEMY_WIDTH/2), pos.getVectorY() +  (ENEMY_HEIGHT / 2), SPRITE_FIRE, ENEMY_WIDTH , ENEMY_HEIGHT, 0, 6);
		//_col.setCoordsAndDist(pos.getVectorX(), pos.getVectorY(), 23);
		characterMaxHeight = 0;
		_state = enemyState::WALK;
		cameraPosition = _position;
	}
	 void setGoal(int x, int y);
	 void sendMap(Tile** _map);
	 void attackBase(Base &b);
	~Enemy();
};


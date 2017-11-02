#pragma once

#include "Element.h"
#include "SDLInterface.h"
class Character : public Element
{
	/*
	Clase abstracta encargada de compartir atributos y metodos con las clases:
	MainCharacter
	Enemy
	NPC
	*/
protected:
	int attackPower;
	int velocity;
	int characterHealth;
	int defense;
	bool combatActivated = false;
public:
	Character();
	Character(Coord<int> pos, int spriteid,int attackPower,int velocity,int characterHealth);
	Character(Character &c);
	virtual void attack(Collider col) = 0;
	virtual void moveCharacter() = 0;
	virtual void moveCharacter(Coord<int> pos) = 0;
	virtual void drawLoop(SDLInterface * s) = 0;
	virtual bool getPowerUp(Collider &col, int id)=  0;
	//virtual void 
	Coord<int> getPosition();
	Sprite  getSprite();
	Collider getCollider();
	int getCharacterHealth();
	int getVelocity();
	int getAttackPower();
	void setCombat(bool &p);
	void lowCharacterLife();
	bool getCombatActivated();
	
	~Character();
};


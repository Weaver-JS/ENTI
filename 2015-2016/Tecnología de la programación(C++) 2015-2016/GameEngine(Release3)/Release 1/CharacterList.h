#pragma once
#include "LinkedListPointer.h"
#include "Enemy.h"
#include "Npc.h"
#include "MainCharacter.h"
class CharacterList :
	public LinkedListPointer<Character*>
	/*
	Clase encargada de gestionar la lista de personajes.
	En ella se encuentran todos los personajes del juego.
	por ahora el juego es muy básico y hay un número limitado de enemigos y Npcs.
	*/
{
private:
	Character* polymorphistiCharacter;
	int enemyNumber;
	int npcNumber;
	int scorecopy;
public:
	CharacterList();
	~CharacterList();

	void init();

	void move();
	void attack();
	void sortList();

	void drawLoop();
	void createEnemies();
	int & getEnemyNumber();
	int & getNpcNumber();
	void removeActualCharacter(int i);
	void setNpcNumber(int n);
	void setEnemyNumber(int n);
	void lowEnemyNumber();
};


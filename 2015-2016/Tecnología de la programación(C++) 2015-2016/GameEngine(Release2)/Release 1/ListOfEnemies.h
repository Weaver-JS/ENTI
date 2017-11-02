#pragma once
#include "Enemy.h"
class ListOfEnemies
{
private:
	int _enemySize;
	int _actualEnemy;
	Enemy* enemyArray;
	
		
public:
	ListOfEnemies();
	~ListOfEnemies();
	void resize();
	void moveEnemies();
	void init();
	void loop();
	void addEnemy();

};


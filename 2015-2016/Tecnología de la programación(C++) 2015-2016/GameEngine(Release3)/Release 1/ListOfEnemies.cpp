#include "ListOfEnemies.h"
#include <random>


ListOfEnemies::ListOfEnemies()
{
	 _enemySize = 10;
	 _actualEnemy = 0;
	 enemyArray = new Enemy[_enemySize];
	 init();
}


ListOfEnemies::~ListOfEnemies()
{
	delete[] enemyArray;
}

void ListOfEnemies::resize()
{

}

void ListOfEnemies::moveEnemies()
{
	for (int i = 0; i < _enemySize;i++)
	{
		if (enemyArray[i].getXposition()>= WIDTH || enemyArray[i].getXposition() <= 10)
		{
			enemyArray[i].changeVelocity();
		}
		
		enemyArray[i].setNewPosition(enemyArray[i].getXposition(), enemyArray[i].getYposition() + enemyArray[i].getVelocity() );

	}
}

void ListOfEnemies::init()
{
	for (int i = 0; i < _enemySize; i++)
	{

		
		for (int j = 0; j < _enemySize;j++) // Se asegura de que los enemigos aparezcan con una separación establecida.
		{
			if (i != _enemySize - 1 && i != j)
			{
				int difference = 50;
				if (enemyArray[i].getXposition() > enemyArray[j].getXposition() - difference && enemyArray[i].getXposition() < enemyArray[j].getXposition() + difference &&
					enemyArray[i].getYposition() > enemyArray[j].getYposition() - difference && enemyArray[i].getYposition() < enemyArray[j].getYposition() + difference)
				{
					enemyArray[i].setNewPosition(rand() % WIDTH, rand() % LENGHT);
					i--;
				}
			}

		}
		enemyArray[i].init(enemyArray[i].getXposition(),enemyArray[i].getYposition());

	}
}
void ListOfEnemies::addEnemy()
{
	
}
void ListOfEnemies::loop()
{
	moveEnemies();
}
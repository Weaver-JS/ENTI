#include "CharacterList.h"



CharacterList::CharacterList()
{
	scorecopy = 0;
}


CharacterList::~CharacterList()
{
}

 void CharacterList::init()
{
	Coord<int> posit(50, 50);
	polymorphistiCharacter = new MainCharacter(posit, 5, 5, SPRITE_ANIM, 5);
	addCharacter(polymorphistiCharacter);
	
	for (int i = 0; i < NPC_NUMBER; i++)
	{
		posit.setVector(WIDTH / 2, 95);
		polymorphistiCharacter = new Npc(posit, 5, 5, SPRITE_NPC, 5);
		addCharacter(polymorphistiCharacter);
	}
	for (int i = 0; i < ENEMY_NUMBER; i++)
	{
		Coord<int> pos(rand() % SPRITE_DEFAULT_WIDTH*LAYERLENGTH, rand() % SPRITE_DEFAULT_HEIGHT * LAYERLENGTH);
		while (pos.getVectorX() <100  && pos.getVectorY() < 100)
		{
			pos.setVector(rand() % SPRITE_DEFAULT_WIDTH*LAYERLENGTH, rand() % SPRITE_DEFAULT_HEIGHT * LAYERLENGTH);
		}
		polymorphistiCharacter = new Enemy(pos, 5, 5, SPRITE_FIRE, 5);
		addCharacter(polymorphistiCharacter);
	}
	enemyNumber = ENEMY_NUMBER;
	npcNumber = ENEMY_NUMBER + NPC_NUMBER;
	 

}

 void CharacterList::move()
 {
	 bool actual = true;
	 for (int i = enemyNumber; i < getLength() - 1 ; i++)
	 {
		 getCharacter(i)->setCombat(actual);
	 }
	 getCharacter(getLength() - 1)->setCombat(actual);
	 if (!getCharacter(getLength()-1 )->getCombatActivated())
	 {

		 actual = false;
		 for (int i = enemyNumber; i < getLength() - 1; i++)
		 {
			 getCharacter(i)->setCombat(actual);
		 }
	 }

	/* for (int i = 0 ; i < enemyNumber; i++)
	 {
		 getCharacter(i)->moveCharacter();
		
		 if (getCharacter(i)->getCombatActivated())
		 {
			 getCharacter(i)->moveCharacter(getCharacter(getLength()-1)->getPosition());
		 }
		 
	 }*/

	 for (int i = enemyNumber; i < getLength() - 1; i++)
	 {
		 if (getCharacter(i)->getCombatActivated())
		 {

			 getCharacter(i)->moveCharacter();
		 }
		
	 }
	 
	 for (int i = 0 ; i <enemyNumber; i++)
	 {
		 if (getCharacter(i)->getCharacterHealth() <= 0)
		 {
			
			 removeCharacter(i);
			 enemyNumber--;
			 npcNumber--;
			 //i--;
			 break;
			 
			
			
		 }
	 }
	
 }

 void CharacterList::attack()
 {
	 for (int i = 0 ; i <enemyNumber ; i++)
	 {
	
		getCharacter(i)->attack(getCharacter(getLength() - 1)->getCollider());
		 getCharacter(getLength() -1  )->attack(getCharacter(i)->getCollider());
		 getCharacter(getLength() - 1)->attack(getCharacter(i)->getCollider());
		 
	 }
	
 }

 void CharacterList::sortList()
 {
	
	 
 }

 void CharacterList::drawLoop()
 {
 }

 void CharacterList::createEnemies()
 { 
	 
	 if (enemyNumber < 50)
	 {
		 Coord<int> pos(rand() % SPRITE_DEFAULT_WIDTH*LAYERLENGTH, rand() % SPRITE_DEFAULT_HEIGHT * LAYERLENGTH);
		 while (pos.getVectorX() < 100 && pos.getVectorY() < 100)
		 {
			 pos.setVector(rand() % SPRITE_DEFAULT_WIDTH*LAYERLENGTH, rand() % SPRITE_DEFAULT_HEIGHT * LAYERLENGTH);
		 }
		 polymorphistiCharacter = new Enemy(pos, 5, 5, SPRITE_FIRE, 5);
		 addCharacter(polymorphistiCharacter);
		 enemyNumber++;
		 npcNumber++;
	 }

 }

 int & CharacterList::getEnemyNumber()
 {
	 return enemyNumber;
 }
 int  & CharacterList::getNpcNumber()
 {
	 return npcNumber;
 }
 void CharacterList::removeActualCharacter(int i)
 {
	 removeCharacter();
	 //delete getCharacter(i);
 }
 void CharacterList::setNpcNumber(int n)
 {
	 npcNumber = n;
 }
 void CharacterList::setEnemyNumber(int n)
 {
	 enemyNumber = n;
 }
 void CharacterList::lowEnemyNumber()
 {
	 enemyNumber--;
 }



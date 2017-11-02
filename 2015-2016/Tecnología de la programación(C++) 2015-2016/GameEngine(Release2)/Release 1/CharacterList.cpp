#include "CharacterList.h"



CharacterList::CharacterList()
{
	
}


CharacterList::~CharacterList()
{
}

 void CharacterList::init()
{
	Coord<int> posit(50, 50);
	polymorphistiCharacter = new MainCharacter(posit, 5, 5, SPRITE_ANIM, 5);
	addCharacter(polymorphistiCharacter);
	for (int i = 0; i < ENEMY_NUMBER; i++)
	{
		Coord<int> pos(rand() % SPRITE_DEFAULT_WIDTH*LAYERLENGTH, rand() % SPRITE_DEFAULT_HEIGHT * LAYERLENGTH);
		polymorphistiCharacter = new Enemy(pos, 5, 5, SPRITE_NPC, 5);
		addCharacter(polymorphistiCharacter);
	}
	for (int i = 0; i < NPC_NUMBER; i++)
	{
		posit.setVector(WIDTH / 2, 120);
		polymorphistiCharacter = new Npc(posit, 5, 5, SPRITE_NPC, 5);
		addCharacter(polymorphistiCharacter);
	}
	enemyNumber = ENEMY_NUMBER;
	npcNumber = NPC_NUMBER;

}

 void CharacterList::move()
 {
	 bool actual = true;
	 for (int i = 0; i < npcNumber; i++)
	 {
		 getCharacter(i)->setCombat(actual);
	 }
	 getCharacter(getLength() - 1)->setCombat(actual);
	 if (!getCharacter(getLength() - 1)->getCombatActivated())
	 {

		 actual = false;
		 for (int i = 0; i < npcNumber; i++)
		 {
			 getCharacter(i)->setCombat(actual);
		 }
	 }

	 for (int i = npcNumber ; i <= enemyNumber; i++)
	 {
		 getCharacter(i)->moveCharacter();
		
		 if (getCharacter(i)->getCombatActivated())
		 {
			 getCharacter(i)->moveCharacter(getCharacter(getLength() - 1)->getPosition());
		 }
		 
	 }
	 for (int i = 0; i < npcNumber; i++)
	 {
		 if (getCharacter(i)->getCombatActivated())
		 {
			 getCharacter(i)->moveCharacter();
		 }
		
	 }
	 
	 for (int i = 0 ; i <getLength() - 1 ; i++)
	 {
		 if (getCharacter(i)->getCharacterHealth() <= 0)
		 {
			 //_list.removeCharacter();
			 //_list.lowEnemyNumber();
			 removeCharacter();
			 enemyNumber--;
		 }
	 }
	
 }

 void CharacterList::attack()
 {
	 for (int i = npcNumber ; i <enemyNumber ; i++)
	 {
		 getCharacter(i)->attack(getCharacter(getLength() - 1)->getCollider());
		 getCharacter(getLength() - 1)->attack(getCharacter(i)->getCollider());
		 //getCharacter(getLength() - 1)->attack(getCharacter(i)->getCollider());
	 }
	
 }

 void CharacterList::drawLoop()
 {
 }

 int CharacterList::getEnemyNumber()
 {
	 return enemyNumber;
 }
 int CharacterList::getNpcNumber()
 {
	 return npcNumber;
 }
 void CharacterList::lowEnemyNumber()
 {
	 enemyNumber--;
 }



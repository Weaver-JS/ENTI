#include "Character.h"



Character::Character()
{
	_position.setVector(0, 0);
	_sprite.setInitialValues(0,0,SPRITE_FIRE,SPRITE_DEFAULT_WIDTH,SPRITE_DEFAULT_HEIGHT,0,1);
	 _col.setCoordsAndDist(_position.getVectorX(),_position.getVectorY(),SPRITE_DEFAULT_WIDTH /2);
	 characterHealth = 3;
	attackPower = 5;
	velocity = 10;
}






Character::Character(Coord<int> pos, int spriteid,int attackPower,int v,int characterHealth)
{
	_position = pos;
	this->attackPower = attackPower;
	velocity = v;
	this->characterHealth = characterHealth;
	
}

Character::Character(Character &c)
{
	_position = c._position;
	_sprite = c._sprite;
	_col = c._col;
	velocity = c.velocity;
	attackPower = c.attackPower;
	characterHealth = c.characterHealth;
	
	
}

//virtual void 
Coord<int> Character::getPosition()
{
	return _position;
}
Sprite Character::getSprite()
{
	return _sprite;
}
Collider Character::getCollider()
{
	return _col;
}
int Character::getCharacterHealth()
{
	return characterHealth;
}
int Character::getVelocity()
{
	return velocity;
}
int Character::getAttackPower()
{
	return attackPower;
}

void Character::setCombat(bool &p)
{
	combatActivated = p;
}

void Character::lowCharacterLife()
{
	characterHealth--;
}

bool Character::getCombatActivated()
{
	return combatActivated;
}



Character::~Character()
{
}

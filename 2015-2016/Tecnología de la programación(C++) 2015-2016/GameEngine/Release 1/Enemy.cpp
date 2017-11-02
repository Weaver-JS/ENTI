#include "Enemy.h"
#include <random>
#include ".h"


Enemy::Enemy()
{
	 _Xposition = 0;
	 _Yposition = 0;
	 dead = false;
	 sprite.setInitialValues(_Xposition,_Yposition, SPRITE_FIRE,0,5);
}

Enemy::Enemy(int xpos, int ypos, Sprite sprite)
{
	_Xposition = xpos;
	_Yposition = ypos;
	this->sprite = sprite;
}

Enemy::Enemy(Enemy &enemy)
{
	_Xposition = enemy._Xposition;
	_Yposition = enemy._Yposition;
	sprite = enemy.sprite;
}

Enemy::~Enemy()
{
}

int Enemy::getVelocity()
{
	return velocity;
}

int Enemy::getXposition()
{
	return _Xposition;
}

int Enemy::getYposition()
{
	return _Yposition;
}

void Enemy::setNewPosition(int x, int y)
{
	_Xposition = x;
	_Yposition = y;
}

void Enemy::init(int x,int y)
{
	sprite.setInitialValues(x, y, SPRITE_FIRE, 0, 5);
}

void Enemy::changeVelocity()
{
	velocity = -velocity;
}

Sprite Enemy::getSprite()
{
	return sprite;
}

void Enemy::spriteAnimation()
{
	//sprite.nextFrame((int)(_graphic.getCurrentTicks() * SPRITE_SPEED));
}
/**/
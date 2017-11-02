#include "Enemy.h"



Enemy::Enemy()
{
}

Enemy::Enemy(Enemy & c)
{
	_position = c._position;
	_sprite = c._sprite;
	_col = c._col;
}

void Enemy::attack(Collider col)
{

	if (_col.onColisionEnter(col.getX() + col.getDist(), col.getY() + col.getDist()))
	{
		
		combatActivated = true;
	}
}
void Enemy::moveCharacter()
{

}
void Enemy::moveCharacter(Coord<int> pos)
{
	if (combatActivated)
	{
		
		if (pos.getVectorX() - 23  <= _position.getVectorX())
		{
			Coord<int> v(-velocity, 0);
			_position += v;
		}

		if (pos.getVectorY()-23  <= _position.getVectorY())
		{
			Coord<int> v(0, -velocity);
			_position += v;
		}

		if (pos.getVectorX()-23 >= _position.getVectorX())
		{
			Coord<int> v(velocity, 0);
			_position += v;
		}

		if (pos.getVectorY()-23 >= _position.getVectorY())
		{
			Coord<int> v(0, velocity);
			_position += v;
		}

	}

	else
	{
		_position += pos;
	}
	_col.setCoordsAndDist(_position.getVectorX() - SPRITE_DEFAULT_WIDTH/2, _position.getVectorY()- SPRITE_DEFAULT_HEIGHT/2, SPRITE_DEFAULT_WIDTH);
	_sprite.setPositionAtWorld(_col.getX(),_col.getY());

}



Enemy::~Enemy()
{
}

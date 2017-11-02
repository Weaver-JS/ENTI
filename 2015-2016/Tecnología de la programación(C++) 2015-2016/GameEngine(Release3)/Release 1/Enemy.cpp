#include "Enemy.h"



int Enemy::getArrowY(Coord<int> pos)
{
	return arrow.calculateRect(pos.getVectorX(), pos.getVectorY(), _col.getX(), _col.getY());
}

Sprite Enemy::getArrowSprite()
{
	return arrow.getSprite();
}

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
	Coord<int> newPosition;
	switch (_state)
	{
	case enemyState::WALK:
		//_position += pos;
		enemyMap.setActualPosition(_position.getVectorX(), _position.getVectorY());
		newPosition = enemyMap.getBestPlace();
		_position.setVector(newPosition.getVectorX()* SPRITE_DEFAULT_WIDTH , newPosition.getVectorY()* SPRITE_DEFAULT_HEIGHT );

		if (enemyMap.getGoalBool())
		{
			_state = enemyState::ATTACKBASE;
		}
		break;
	case enemyState::ATTACKBASE:
		
		/*SHOOT AT THE BASE WITH THE COORD OF THE */
		break;
	/*case enemyState::ATTACKPLAYER:
		characterMaxHeight = 1;
		if (pos.getVectorX() - 23 <= _position.getVectorX())
		{
			Coord<int> v(-velocity, 0);
			_position += v;
		}

		if (pos.getVectorY() - 23 <= _position.getVectorY())
		{
			Coord<int> v(0, -velocity);
			_position += v;
		}

		if (pos.getVectorX() - 23 >= _position.getVectorX())
		{
			Coord<int> v(velocity, 0);
			_position += v;
		}

		if (pos.getVectorY() - 23 >= _position.getVectorY())
		{
			Coord<int> v(0, velocity);
			_position += v;
		}
		break;*/
	}

	if (combatActivated)
	{

		_state = enemyState::ATTACKPLAYER;
	}

	//_position += pos;

// 	_col.setCoordsAndDist(_position.getVectorX() + ENEMY_WIDTH / 2, _position.getVectorY() + ENEMY_HEIGHT / 2, ENEMY_WIDTH);
	//_sprite.setPositionAtWorld(_position.getVectorX(), _position.getVectorY());
	
}
void Enemy::moveCharacter(Coord<int> pos)
{
	if (combatActivated)
	{
		characterMaxHeight = 1;
		if (pos.getVectorX() - 23 <= _position.getVectorX())
		{
			Coord<int> v(-velocity, 0);
			_position += v;
		}

		if (pos.getVectorY() - 23 <= _position.getVectorY())
		{
			Coord<int> v(0, -velocity);
			_position += v;
		}

		if (pos.getVectorX() - 23 >= _position.getVectorX())
		{
			Coord<int> v(velocity, 0);
			_position += v;
		}

		if (pos.getVectorY() - 23 >= _position.getVectorY())
		{
			Coord<int> v(0, velocity);
			_position += v;
		}
		cameraPosition += pos;
		//_position += pos;
		_col.setCoordsAndDist(_position.getVectorX() + ENEMY_WIDTH / 2, _position.getVectorY() + ENEMY_HEIGHT / 2, ENEMY_WIDTH);
		_sprite.setPositionAtWorld(_position.getVectorX(), _position.getVectorY());
	}
	
	std::cout << _position;
	//
//
}



void Enemy::setGoal(int x, int y)
{
	enemyMap.setGoal(x, y);
}

void Enemy::sendMap(Tile ** _map)
{
	enemyMap.setMap(_map);
}

void Enemy::attackBase(Base & b)
{
	b.getAttacked();
}

Enemy::~Enemy()
{
}

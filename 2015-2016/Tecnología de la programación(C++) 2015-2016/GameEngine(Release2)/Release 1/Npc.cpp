#include "Npc.h"



Npc::Npc()
{
}




void Npc::attack(Collider col)
{
	
}

void Npc::moveCharacter()
{
	
		if (_position.getVectorX() >= coordCopy.getVectorX() + _distance)
		{
			v.setVector(-velocity, 0);
		}
		if (_position.getVectorX() <= coordCopy.getVectorX() - _distance)
		{
			v.setVector(velocity, 0);
		}
		_position += v;

	
		_sprite.setPositionAtWorld(_position.getVectorX(), _position.getVectorY());
	
	
}

void Npc::moveCharacter(Coord<int> pos)
{
	//std::cout << "Nothing";
	
	_position += pos;
	coordCopy += pos;

	
	//coordCopy = _position;

	_sprite.setPositionAtWorld(_position.getVectorX(), _position.getVectorY());
}

Npc::~Npc()
{
}

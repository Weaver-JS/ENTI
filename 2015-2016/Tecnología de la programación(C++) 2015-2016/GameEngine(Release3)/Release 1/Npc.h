#pragma once
#include "Character.h"
class Npc :
	public Character
{
	/*
	Clase NPC hija de la clase abstracta Character
	Se encarga de moverse de derecha a izquierda sin parar
	tiene un limite de distancia.
	*/
private:
	int _distance;
	Coord<int> coordCopy;
	int _randNumber;
	Coord<int> v;
	bool move;
	void drawLoop(SDLInterface * s) {};
	bool getPowerUp(Collider &col, int id) { return false; };
public:
	Npc();
	Npc(Coord<int> pos, int sprite, int attackPower, int velocity, int characterHealth) : Character(pos, sprite, attackPower, velocity, characterHealth)
	{
		
		move = false;
		_distance = 100;
		combatActivated = true;
		_randNumber = std::rand() % 2;
		v.setVector(velocity, 0);
		coordCopy = _position;
		_sprite.setInitialValues(_position.getVectorX() + NPC_WIDTH / 2, _position.getVectorY() - NPC_HEIGHT / 2, SPRITE_NPC, NPC_WIDTH, NPC_HEIGHT, 0, 4);
		characterMaxHeight = 1;
		
	};
	 void attack(Collider col);
	 void moveCharacter();
	 void moveCharacter(Coord<int> pos);
	 Coord<int> getCameraPosition() {
		 return _position;
	 };
	 int getArrowY(Coord<int> pos) {
		 return 0;
	 };
	  void setGoal(int x, int y) {};
	  void sendMap(Tile** _map) {};
	  void attackBase(Base &b) {};
	 Sprite getArrowSprite() { return _sprite; };
	~Npc();
};


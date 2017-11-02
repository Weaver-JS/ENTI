#pragma once
#include "LinkedListPointer.h"
#include "Bullet.h"
class BulletList : public LinkedListPointer<Bullet*>
{
	/*
	Clase encargada de gestionar todas las balas que se inicializan por el jugador,
	va destruyendolas de la lista o añadiendolas según el jugador. 
	*/
private:
	Bullet* b;

public:
	BulletList() : LinkedListPointer() {
	
	};
	~BulletList();
	void addBullet(Coord<int> pos, Coord<int> velocity);
	void moveBullets();
	bool checkHit(Collider col);
};


#pragma once
#include "Vector.h"
#include "Collider.h"
#include "Sprite.h"
class Bullet
{
	/*
	Clase bala se encarga de gestionar todo lo referente
	al proyectil del jugador.
	*/
private:
	Coord<int> pos;
	Coord<int> velocity;
	Coord<int> firstPos;
	int distance;
	Sprite _bullet;

public:
	Bullet();
	Bullet(Coord<int> pos, Coord<int> velocity, int bullet);
	Bullet(Bullet &b);
	~Bullet();

	bool checkHit(Collider c);// Mediante este metodo retornaremos true o false según la bala haya chocado con el collider
	void moveBullet();// la bala se moverá a una velocidad constante hasta que llegue a su distancia definitiva, entonces se destruirá.
	Sprite getSprite();
	int getDistance();
	Coord<int> getFirstPos();
	Coord<int> getPos();

};


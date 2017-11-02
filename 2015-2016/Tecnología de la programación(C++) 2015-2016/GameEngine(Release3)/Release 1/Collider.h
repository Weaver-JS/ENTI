#pragma once
#include <iostream>
class Collider
{/*
 Clase encargada de gestionar colisiones.
 */
private: 
	int x;
	int y;
	int dist;

public:
	Collider();
	Collider(int x, int y, int dist);
	Collider(Collider & col);
	void setCoordsAndDist(int newX, int newY, int dist);

	int getX();
	int getY();
	int getDist();

	bool onColisionEnter(int x, int y);

	~Collider();
};


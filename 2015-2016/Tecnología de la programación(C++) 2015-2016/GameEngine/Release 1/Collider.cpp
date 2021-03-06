#include "Collider.h"



Collider::Collider()
{
	x = 0;
	y = 0;
	dist = 0;
}

int Collider::getX() {
	return x;
}

int Collider::getY() {
	return y;
}

int Collider::getDist() {
	return dist;
}

void Collider::setCoordsAndDist(int newX, int newY, int newDist) {
	x = newX;
	y = newY;
	dist = newDist;
}

bool Collider::onColisionEnter(int x, int y) {
	
	if (x <= this->x + dist && x >= this->x - dist && y <= this->y + dist && y >= this->y - dist) {
		return true;
	}

	return false;
}

Collider::~Collider()
{
}

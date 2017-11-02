#pragma once
class Collider
{
private: 
	int x;
	int y;
	int dist;

public:
	Collider();

	void setCoordsAndDist(int newX, int newY, int dist);

	int getX();
	int getY();
	int getDist();

	bool onColisionEnter(int x, int y);

	~Collider();
};


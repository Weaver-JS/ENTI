#pragma once
#include <iostream>
template <class data>
class Coord
{
	/*
	Clase encargada en gestionar coordenadas.
	*/
private:
	data _x;
	data _y;

	
public:
	
	Coord()
	{
		_x = 0;
		_y = 0;
	};
	Coord(data x, data y)
	{
		_x = x;
		_y = y;
	}

	Coord(Coord &v)
	{
		_x = v._x;
		_y = v._y;
	}
	~Coord()
	{

	}
	void setVector(data x, data y)
	{
		_x = x;
		_y = y;

	}
	//Getters
	data getVectorX()
	{
		return _x;
	}
	data getVectorY()
	{
		return _y;
	}
	friend std::ostream& operator <<(std::ostream& os, const Coord& v)
	{
		std::cout << "coordX:" << v._x << std::endl << "coordY:" << v._y << std::endl;
		return os;
	}
	Coord operator-(const Coord &v)
	 {
		 Coord vResult;
		 vResult._x = _x - v._x;
		 vResult._y = _y - v._y;
		 return vResult;
	}
	Coord operator -(const data &i)
	{
		_y -= i;
		return *this;
		
	}
	Coord operator+(const Coord &v)
	{
		Coord vResult;
		vResult._x = _x + v._x;
		vResult._y = _y + v._y;
		
		return vResult;
	}

	Coord operator= ( Coord &v)
	{
		_x = v._x;
		_y = v._y;
		return *this;
	}

	Coord operator+=(Coord &v)
	{
		_x += v._x;
		_y += v._y;
		return *this;
	}

	Coord operator *(const Coord &v)
	{
		_x *= v._x;
		_y *= v._y;
		return *this;
	}
	
	Coord operator *=(const Coord &v)
	{
		_x *= v._x;
		_y *= v._y;
		return *this;
	}
	Coord negative()
	{
		_x = -_x;
		_y = -_y;
		return *this;
	}
	Coord operator /(const Coord &v)
	{
		_x /= v._x;
		_y /= v._y;
		return *this;
	}

	Coord operator +(const data &i)
	 {
		 Coord vResult;
		 vResult._x += i;
		 vResult._y += i;
		 return vResult;
	}

	Coord operator +=(const data &i)
	{
		_x += v._x;
		_y += v._y;
		return *this;

	}

	Coord operator * (const data &i)
	{
		_x *= i;
		_y *= i;
		return *this;
	}
};


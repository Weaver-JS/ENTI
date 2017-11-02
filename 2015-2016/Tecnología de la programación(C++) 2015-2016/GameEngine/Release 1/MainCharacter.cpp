#include "MainCharacter.h"



MainCharacter::MainCharacter()
{
	//centro del personaje.
	_Xcoord = WIDTH/2 ; 
	_Ycoord = HEIGHT / 2 ;
	_XcoordCamera = WIDTH / 2;
	_YcoordCamera = HEIGHT / 2;
	velocity = 5;
	_mainCharacter.setInitialValues(WIDTH / 2, HEIGHT / 2, SPRITE_ANIM, 104, 120, 0, 8); // Personaje y animación temporales.
	numLife = 3;
	heartArray = new Health[numLife * 2];
	int xSep = 10;
	for (int i = 0; i < numLife; i++)
	{
		
		heartArray[i].sumPosition(xSep, 0);
		heartArray[i].placeHeart(xSep,heartArray[i].getY());
		xSep += 40;
	}
	
}

void MainCharacter::nextAnimationframe(int cur)
{
	_mainCharacter.nextFrame((int)(cur * SPRITE_SPEED));
}
void MainCharacter::setCharacterCoords(int x, int y)
{
	_Xcoord = x;
	_Ycoord = y;
}
MainCharacter::~MainCharacter()
{
	delete[] heartArray;
}

int MainCharacter::getXcoordCamera()
{
	return _XcoordCamera;
}

int MainCharacter::getYcoordCamera()
{
	return _YcoordCamera;
}
void MainCharacter::moveCharacter(int x,int y)
{
	_Xcoord += x;
	_Ycoord += y;
	
		
		_XcoordCamera += x;
		_YcoordCamera += y;
		if (_XcoordCamera <= 0)
		{
			_XcoordCamera = 0;
		}
		if (_YcoordCamera <= 0)
		{
			_YcoordCamera = 0;
		}
		if (_XcoordCamera >= LIMITX  )
		{
			_XcoordCamera = LIMITX ;
		}
		if (_YcoordCamera >= LIMITY)
		{
			_YcoordCamera = LIMITY;
		}
		_mainCharacter.setPositionAtWorld(_XcoordCamera, _YcoordCamera);
	}
	


int MainCharacter::getVelocity()
{
	return velocity;
}
void MainCharacter::changeVelocity(int newVel)
{
	velocity = newVel;
}
int MainCharacter::getXcoord()
{
	return _Xcoord;
}
int MainCharacter::getYcoord()
{
	return _Ycoord;
}
Sprite MainCharacter::getSprite()
{
	return _mainCharacter;
}

int MainCharacter::getNumLife()
{
	return numLife;
}



Health* MainCharacter::getHealth()
{
	return heartArray;
}


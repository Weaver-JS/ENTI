#include "Terrain.h"



Terrain::Terrain()
{
	
	numberLayersX = LAYERLENGTH;
	numberLayersY = LAYERLENGTH;

	characterCoord.setVector(WIDTH / 2, HEIGHT / 2);

	cameraCoord.setVector(WIDTH, HEIGHT);

	terrainCoord.setVector(0, 0);

	limitCoords.setVector(cameraCoord.getVectorX() / SPRITE_DEFAULT_WIDTH, cameraCoord.getVectorY() / SPRITE_DEFAULT_HEIGHT);
	 allocateMatrixMemory();
	 
}

Coord<int> Terrain::getCameraVector()
{
	return cameraCoord;
}

void Terrain::placeWater(int initX, int initY, int finalX, int finalY,bool bordes)
{
	if (initX >= 0 && initX < numberLayersX && finalX >0 && finalX < numberLayersX && initY >= 0 && initY < numberLayersY && finalY >0 && finalY < numberLayersY)
	{
		for (int i = initX;i <= finalX;i++)
		{
			for (int j = initY; j <= finalY;j++)
			{
				tileArray[i][j].changeLayerSprite(0, SPRITE_WATER);
			}
		}
	}

	else
	{
		throw std::exception("Terrain.cpp function PlaceRoad:: You've tried to draw a Road out of the map moron");
	}

	if (bordes)
	{
		if (initX - 1 > 0 && initY -1 > 0)
		{
			placebottomTopRoad(initX - 1, initY - 1, 2);
			placeRoad(initX, initY - 1, finalX, initY - 1,0);
			placebottomTopRoad(finalX + 1,initY -1, 3);
			placeRoad(initX, finalY + 1, finalX, finalY + 1, 0);
			placebottomTopRoad(initX - 1, finalY + 1, 0);
			placeRoad(initX - 1, initY , initX -1 , finalY , 1);
			placebottomTopRoad(finalX + 1, finalY + 1, 1);
			placeRoad(finalX + 1, initY, finalX + 1, finalY, 1);

			
		}
	}
}

void Terrain::placebottomTopRoad(int X, int Y, int direction)
{
	switch (direction)
	{
	case 0:
		tileArray[X][Y].changeLayerSprite(0, SPRITE_BOTTOM_LEFT); // ESQUINA INFERIOR IZQUIERDA
		break;

	case 1:
		tileArray[X][Y].changeLayerSprite(0, SPRITE_BOTTOM_RIGHT); //ESQUINA INFERIOR DERECHA
		break;
	case 2:
		tileArray[X][Y].changeLayerSprite(0, SPRITE_ROADLEFT); //ESQUINA SUPERIOR IZQUIERDA
		break;

	case 3:
		tileArray[X][Y].changeLayerSprite(0, SPRITE_ROADDOWN); //ESQUINA SUPERIOR DERECHA
		break;
	}
}

void Terrain::placeRoad(int initX, int initY, int finalX, int finalY, int direction)
{
 
	if (initX >= 0 && initX < numberLayersX && finalX >0 && finalX < numberLayersX && initY >= 0 && initY < numberLayersY && finalY >=0 && finalY < numberLayersY)
	{
		for (int i = initX;i <= finalX;i++)
		{
			for (int j = initY; j <= finalY;j++)
			{
				switch (direction)
				{
					case 0:
					tileArray[i][j].changeLayerSprite(0, SPRITE_ROADRIGHT);
					break;

					case 1:
					tileArray[i][j].changeLayerSprite(0, SPRITE_ROADUP);
					break;

				}
				
			}
		}
	}
	
	else
	{
		throw std::exception("Terrain.cpp function PlaceRoad:: You've tried to draw a Road out of the map moron");
		
	}
}
void Terrain::matrixMap()
{



	int matrix[LAYERLENGTH][LAYERLENGTH] = 
		{
			1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
			0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
			0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
			0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
			1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
			0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
			0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
			0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
			0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
			0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
			1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
			0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
			0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
			0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
			1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
			0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
			0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
			0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
			0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
			0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
		};

}
Terrain::~Terrain()
{
	/*for (int i = 0; i < numberLayersX; i++)
	{
		delete tileArray[i];
	}*/


	delete[] tileArray;
}
int Terrain::getNumberLayersX()
{
	return numberLayersX;
}

int Terrain::getNumberLayersY()
{
	return numberLayersY;
}

Tile  Terrain::getTileArray(int i, int j)
{
	return tileArray[i][j];
}



 void  Terrain::actualCharacterPosition(Coord<int> characterVector)
{
	characterCoord = characterVector;
}

void Terrain::changeCamera(Coord<int> cameraVector)
{
	cameraCoord += cameraVector;

}
void Terrain::changePositionTerrain(Coord<int> terrainVector)
{

	terrainCoord += terrainVector;
	for (int i = _list.getNpcNumber(); i < _list.getEnemyNumber(); i++)
	{
		if (!_list.getCharacter(i)->getCombatActivated())
			_list.getCharacter(i)->moveCharacter(terrainVector);
	}

	for (int i = 0; i < _list.getNpcNumber(); i++)
	{

		_list.getCharacter(i)->moveCharacter(terrainVector);
		//_list.getCharacter(i)->moveCharacter();


	}

	for (int i = 0; i <HEALTH_OBJECT_NUM +  _objectList.getNumPowerUp() + ENVIRONMENT_OBJECT_NUM; i++)
	{
		_objectList.getCharacter(i)->moveCharacter(terrainVector);
	}
	
}

Coord<int> Terrain::getTerrainVector()
{
	return terrainCoord;
}

Coord<int> Terrain::getLimitVector()
{
	return limitCoords;
}

Character* Terrain::getMainCharacter()
{
	return _list.getCharacter(_list.getLength() - 1);
}

CharacterList& Terrain::getList()
{
	return _list;
}

void Terrain::drawCharacterList()
{
	for (int i = 0; i < _list.getLength() ; i++)
	{
	//	drawSpriteWith(_list.getCharacter(i)->getSprite());
		drawCharacterAnimation(_list.getCharacter(i)->getSprite().getSpriteId(), _list.getCharacter(i)->getPosition(), _graphics->getCurrentTicks() * GAME_SPEED, _list.getCharacter(i)->getSprite().getMaxFrames(),_list.getCharacter(i)->getSprite().getSpriteWidth(), _list.getCharacter(i)->getSprite().getSpriteHeight());
		//drawSprite(_list.getCharacter(i)->getSprite().getSpriteId(), _list.getCharacter(i)->getPosition());
	}
	//drawSprite(_list.getCharacter(_list.getLength()-1)->getSprite().getSpriteId(), _list.getCharacter(_list.getLength()-1)->getPosition());
}

void Terrain::moveCharacterList()
{
	_list.move();
	_list.attack();
	getPowerUp();
	
	_bulletList.moveBullets();
	checkBulletCollision();
}

void Terrain::drawObjects()
{
	for (int i = 0; i < HEALTH_OBJECT_NUM + _objectList.getNumPowerUp() + ENVIRONMENT_OBJECT_NUM; i++)
	{
		drawSpriteWith(_objectList.getCharacter(i)->getSprite());
		//drawSprite(_objectList.getSpriteID(i).getSpriteId(), _objectList.getCharacter(i)->getPosition());
	}
}

void Terrain::getPowerUp()
{
	for (int i = HEALTH_OBJECT_NUM; i <_objectList.getNumPowerUp() + HEALTH_OBJECT_NUM  ; i++)
	{
		if (_list.getCharacter(_list.getLength() - 1)->getPowerUp(_objectList.getCharacter(i)->getCollider(), _objectList.getCharacter(i)->getID()))
		{
			_inventory.changeSpriteID(_objectList.getCharacter(i)->getSprite().getSpriteId());
			_objectList.removeCharacter();
			std::cout << "OBJETO COGIDO" << i<<std::endl;
			_objectList.powerUpsubtract();
			i--;
		}
	}
}

void Terrain::drawInventory()
{
	for (int i = 0; i < _inventory.getSpriteArray().getLenght(); i++)
	{
		Coord<int> pos(_inventory.getSpriteArray().dataArray[i].getXAtWorld(), _inventory.getSpriteArray().dataArray[i].getYAtWorld());
			drawSprite(_inventory.getSpriteArray().dataArray[i].getSpriteId(), pos);
	}
}

/*void Terrain::moveMapAccordingMC()
{
	//_list.getCharacter(_list.getLength() - 1)->moveCharacter();
	std::cout << "TERRAIN COORD"  << terrainCoord;
	_list.move();
	_list.attack();
	if (getTerrainVector().getVectorY() <= 0 && getTerrainVector().getVectorY() > -getNumberLayersY() + 1)// Si no nos encontramos en los límites del mapa.
	{
		Coord<int> vectorTemp(0, _list.getCharacter(_list.getLength() - 1)->mainCharacterMove().getVectorY());
		Coord<int> vectorTempN(0, -_list.getCharacter(_list.getLength() - 1)->mainCharacterMove().getVectorY());
		changeCamera(vectorTempN);
		changePositionTerrain(vectorTemp);
	}
	if (getTerrainVector().getVectorX() > -getNumberLayersX() + 1 && getTerrainVector().getVectorX() <= 0)
	{
		Coord<int> vectorTemp(_list.getCharacter(_list.getLength() - 1)->mainCharacterMove().getVectorX(), 0);
		Coord<int> vectorTempN(-_list.getCharacter(_list.getLength() - 1)->mainCharacterMove().getVectorX(), 0);
		changeCamera(vectorTempN);
		changePositionTerrain(vectorTemp);
	}

	actualCharacterPosition(_list.getCharacter(_list.getLength() - 1)->getPosition());
	
}*/

void Terrain::renderTerrain()
{
	
	Coord<int> positionVector = terrainCoord;
	

	limitCoords.setVector((cameraCoord.getVectorX() / SPRITE_DEFAULT_WIDTH) + 1, (cameraCoord.getVectorY() / SPRITE_DEFAULT_HEIGHT)+ 1);

	//PRUEBA
	placeRoad(0, numberLayersY / 2, numberLayersX - 1, numberLayersY / 2, 0);
	placeRoad(numberLayersX / 2, 0, numberLayersX / 2, numberLayersY - 1, 1);
	placeWater(2, 2, 6, 6,true);
	placeWater(2, 13, 6,17, true);
	placeWater(numberLayersX / 2 + 1, 0, numberLayersX - 1, numberLayersY / 2 - 1, false);
	placeRoad(0, 0, numberLayersX - 1, 0, 0);
	//PRUEBA




	
	
		for (int i = 0; i <limitCoords.getVectorX() ;i++)
		{
			positionVector.setVector(positionVector.getVectorX(), terrainCoord.getVectorY());
		
			for (int j = 0; j < limitCoords.getVectorY(); j++)
			{

				
				if (tileArray[i][j].getLayer().dataArray[0] == SPRITE_WATER)// SE ACABARA UTILIZANDO UN SWITCH PROBABLEMENTE
				{
					drawSpriteAnimation(tileArray[i][j].getLayer().dataArray[0], positionVector, _graphics->getCurrentTicks() * GAME_SPEED,10);
				}
				else
				{
					drawSprite(tileArray[i][j].getLayer().dataArray[0], positionVector);
				}
		
				
				Coord<int> v(0, SPRITE_DEFAULT_HEIGHT);
				positionVector += v;
			}

			Coord<int> v2(SPRITE_DEFAULT_WIDTH, 0);
			positionVector += v2;

		}
		printLife();
		drawObjects();
		drawCharacterList();
		drawInventory();
		drawBullets();
	

	
}

void Terrain::init(SDLInterface &graphics)
{
	_graphics = &graphics;
	_list.init();
   _objectList.init();
   _characterLife.setActualPosition(_list.getCharacter(_list.getLength() - 1)->getCharacterHealth());
	//_characterLife = Array<Health>(_list.getLength() - 1);
	
}

void Terrain::allocateMatrixMemory() {
	//Allocate memory
	tileArray = new Tile*[numberLayersX];
	if (tileArray == 0) {
		throw std::exception("System was not able to create the matrix");
	}

	//Initialize the points to null. 
	//It's important for avoiding that the Destructor tries to delete a position that doesn't contain anything
	for (int i = 0; i < numberLayersX; i++) {
		tileArray[i] = 0;
	}

	for (int i = 0; i < numberLayersX; i++) {
		tileArray[i] = new Tile[numberLayersY];
		if (tileArray[i] == 0) {
			throw std::exception("System was not able to create the matrix");
		}
	}
}


void Terrain::drawSprite(int spriteid,Coord<int> positionVector) {
	_graphics->drawTexture(spriteid, 0, 0, SPRITE_DEFAULT_WIDTH, SPRITE_DEFAULT_HEIGHT
		, positionVector.getVectorX(), positionVector.getVectorY(), SPRITE_DEFAULT_WIDTH, SPRITE_DEFAULT_HEIGHT);

}
void Terrain::drawSpriteAnimation(int spriteid, Coord<int> positionVector, int curTicks,int maxFrames)
{
	curTicks = curTicks %  maxFrames;
	_graphics->drawTexture(spriteid, SPRITE_DEFAULT_WIDTH * curTicks, 0, SPRITE_DEFAULT_WIDTH  , SPRITE_DEFAULT_HEIGHT, positionVector.getVectorX(),
		positionVector.getVectorY(), SPRITE_DEFAULT_WIDTH, SPRITE_DEFAULT_HEIGHT);
}

void Terrain::drawSpriteWith(Sprite & sprite) {
	_graphics->drawTexture(sprite.getSpriteId(), sprite.getSpriteWidth()*sprite.getCurrentFrame(), 0, sprite.getSpriteWidth(), sprite.getSpriteHeight()
		, sprite.getXAtWorld(), sprite.getYAtWorld(), sprite.getSpriteWidth(), sprite.getSpriteHeight());
}

void Terrain::drawCharacterAnimation(int spriteid, Coord<int> positionVector, int curTicks, int maxFrames, int width, int height)
{
	curTicks = curTicks %  maxFrames;
	_graphics->drawTexture(spriteid, SPRITE_DEFAULT_WIDTH * curTicks, 0, width, height, positionVector.getVectorX(),
		positionVector.getVectorY(), width, height);
}


void Terrain::checkBulletCollision()
{
	
		for (int j = 0; j < _bulletList.getLength(); j++)
		{
			for (int i = _list.getNpcNumber() ; i<=_list.getEnemyNumber() ; i++)
			{
				if (_bulletList.getCharacter(j) != NULL &&_bulletList.getCharacter(j)->checkHit(_list.getCharacter(i)->getCollider()))
						_list.getCharacter(i)->lowCharacterLife();
					
			}
		}
	
}

void Terrain::drawBullets()
{
	for (int i = 0; i < _bulletList.getLength(); i++)
	{
		drawSpriteWith(_bulletList.getCharacter(i)->getSprite());
	}
}

BulletList & Terrain::getBulletList()
{
	return _bulletList;
}

void Terrain::printLife()
{

	if ((_list.getCharacter(_list.getLength() - 1)->getCharacterHealth() >0 ))
	{
		
	int xSep = 10;
	
	for (int i = 0; i < _list.getCharacter(_list.getLength() - 1)->getCharacterHealth(); i++)
	{

		Coord<int> v(xSep, 0);
		_characterLife.dataArray[i].placeHeart(v);

		//_heartArray.dataArray[i].placeHeart(_heartArray.dataArray[i].getCoords());

		xSep += 40;
		drawSpriteWith(_characterLife.dataArray[i].getSprite());
	}
	}
}

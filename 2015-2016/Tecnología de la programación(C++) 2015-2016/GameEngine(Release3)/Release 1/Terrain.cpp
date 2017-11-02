#include "Terrain.h"



Terrain::Terrain()
{
	

	 
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

void Terrain::destroy()
{

	int numberL = _list.getLength();
	for (int i = 0; i < numberL; i++)
	{

		_list.removeCharacter(i);

	}
	_list.setEnemyNumber(0);
	_list.setNpcNumber(0);
	numberL = _objectList.getLength();
	for (int i = 0; i < numberL; i++)
	{
		_objectList.removeCharacter(i);
	}
	
	_inventory.getSpriteArray().~Array();
	
		

	 _characterLife.~Array();

	 
	mainBase.~Base();
	
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
	int enemyLength = _list.getEnemyNumber();
	

	int npcLength = _list.getNpcNumber();
	for (int i = enemyLength; i < npcLength; i++)
	{

		_list.getCharacter(i)->moveCharacter(terrainVector);
		


	}

	for (int i = 0; i <HEALTH_OBJECT_NUM +  _objectList.getNumPowerUp() + ENVIRONMENT_OBJECT_NUM; i++)
	{
		_objectList.getCharacter(i)->moveCharacter(terrainVector);
	}
	mainBase.moveBase(terrainVector);
	
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
	
	int length = _list.getLength();
	int enemyLength = _list.getEnemyNumber();
	

	for (int i = 0; i < enemyLength;i++)
	{
		if (_list.getCharacter(i)->getCombatActivated())
		{
			drawAnimationwith(_list.getCharacter(i)->getSprite().getSpriteId(), _list.getCharacter(i)->getPosition(), _graphics->getCurrentTicks() * GAME_SPEED, _list.getCharacter(i)->getSprite().getMaxFrames(), _list.getCharacter(i)->getSprite().getSpriteWidth(), _list.getCharacter(i)->getSprite().getSpriteHeight(), _list.getCharacter(i)->getSprite().getSpriteHeight(), _list.getCharacter(i)->getCharacterTick());
		}
	}
		/*for (int i = 0; i < _list.getEnemyNumber(); i++)
		{
			
			//	drawSpriteWith(_list.getCharacter(i)->getSprite());
			if (_list.getCharacter(i)->getPosition().getVectorX() / SPRITE_DEFAULT_WIDTH < limitCoords.getVectorX() && _list.getCharacter(i)->getPosition().getVectorY() / SPRITE_DEFAULT_HEIGHT < limitCoords.getVectorY()
				&& _list.getCharacter(i)->getPosition().getVectorX() / SPRITE_DEFAULT_WIDTH> limitCoords.getVectorX() - WIDTH /SPRITE_DEFAULT_WIDTH &&
				_list.getCharacter(i)->getPosition().getVectorY() / SPRITE_DEFAULT_HEIGHT >limitCoords.getVectorY() - HEIGHT / SPRITE_DEFAULT_HEIGHT)
			{
			 x = -(limitCoords.getVectorX() *SPRITE_DEFAULT_WIDTH -WIDTH)  + _list.getCharacter(i)->getPosition().getVectorX() ; //- WIDTH / SPRITE_DEFAULT_WIDTH;
			 y = -(limitCoords.getVectorY() *SPRITE_DEFAULT_WIDTH - HEIGHT) + _list.getCharacter(i)->getPosition().getVectorY();
			 std::cout << "SHOW CHARACTER POSITION" << std::endl;
			 std::cout << x << " " << y<< std::endl;
			 std::cout << "SHOW CHARACTER POSITION" << std::endl;
				Coord<int> drawVector(x, y );
			//	_list.getCharacter(i)->getPosition().setVector(x*SPRITE_DEFAULT_WIDTH, y*SPRITE_DEFAULT_HEIGHT);
				
				drawAnimationwith(_list.getCharacter(i)->getSprite().getSpriteId(), drawVector, _graphics->getCurrentTicks() * GAME_SPEED, _list.getCharacter(i)->getSprite().getMaxFrames(), _list.getCharacter(i)->getSprite().getSpriteWidth(), _list.getCharacter(i)->getSprite().getSpriteHeight(), _list.getCharacter(i)->getSprite().getSpriteHeight(), _list.getCharacter(i)->getCharacterTick());
			}						//drawCharacterAnimation(_list.getCharacter(i)->getSprite().getSpriteId(), _list.getCharacter(i)->getPosition(), _graphics->getCurrentTicks() * GAME_SPEED, _list.getCharacter(i)->getSprite().getMaxFrames(),_list.getCharacter(i)->getSprite().getSpriteWidth(), _list.getCharacter(i)->getSprite().getSpriteHeight());
									//drawSprite(_list.getCharacter(i)->getSprite().getSpriteId(), _list.getCharacter(i)->getPosition());
		}*/
	

	for (int i = enemyLength; i < length;i++)
	{
		drawAnimationwith(_list.getCharacter(i)->getSprite().getSpriteId(), _list.getCharacter(i)->getPosition(), _graphics->getCurrentTicks() * GAME_SPEED, _list.getCharacter(i)->getSprite().getMaxFrames(), _list.getCharacter(i)->getSprite().getSpriteWidth(), _list.getCharacter(i)->getSprite().getSpriteHeight(), _list.getCharacter(i)->getSprite().getSpriteHeight(), _list.getCharacter(i)->getCharacterTick());
	}
	//drawSprite(_list.getCharacter(_list.getLength()-1)->getSprite().getSpriteId(), _list.getCharacter(_list.getLength()-1)->getPosition());
}

void Terrain::moveCharacterList()
{
	moveEnemies();
	_list.move();
/*	for (int i = 0; i < _list.getEnemyNumber();i++)
	{
		if (_list.getCharacter(i)->getCombatActivated())
		{
			_list.getCharacter(i)->moveCharacter(_list.getCharacter(_list.getLength() - 1)->getPosition());

		}
	}*/
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
			_objectList.removeCharacter(i);
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
				if (tileArray[i][j].getLayer().dataArray[2] == ENEMY)
				{
					for (int i = 0; i < _list.getEnemyNumber(); i++)
					{
						//	drawSpriteWith(_list.getCharacter(i)->getSprite());
						if (_list.getCharacter(i)->getPosition().getVectorX() / SPRITE_DEFAULT_WIDTH < limitCoords.getVectorX() && _list.getCharacter(i)->getPosition().getVectorY() / SPRITE_DEFAULT_HEIGHT < limitCoords.getVectorY()
							&& _list.getCharacter(i)->getPosition().getVectorX() / SPRITE_DEFAULT_WIDTH> limitCoords.getVectorX() - (WIDTH / SPRITE_DEFAULT_WIDTH) &&
							_list.getCharacter(i)->getPosition().getVectorY() / SPRITE_DEFAULT_HEIGHT >limitCoords.getVectorY() - (HEIGHT / SPRITE_DEFAULT_HEIGHT) && positionVector.getVectorX() > 0 && positionVector.getVectorY() > 0)
						{
							_list.getCharacter(i)->getCollider().setCoordsAndDist(positionVector.getVectorX(), positionVector.getVectorY(), ENEMY_WIDTH);
							Coord<int> coords(_list.getCharacter(i)->getCollider().getX(), _list.getCharacter(i)->getCollider().getY());
							//if((!_list.getCharacter(i)->getCombatActivated()))
							drawAnimationwith(_list.getCharacter(i)->getSprite().getSpriteId(), coords, _graphics->getCurrentTicks() * GAME_SPEED, _list.getCharacter(i)->getSprite().getMaxFrames(), _list.getCharacter(i)->getSprite().getSpriteWidth(), _list.getCharacter(i)->getSprite().getSpriteHeight(), _list.getCharacter(i)->getSprite().getSpriteHeight(), _list.getCharacter(i)->getCharacterTick());
							
						}
						
					}
				}
				
				Coord<int> v(0, SPRITE_DEFAULT_HEIGHT);
				positionVector += v;
			}

			Coord<int> v2(SPRITE_DEFAULT_WIDTH, 0);
			positionVector += v2;

		}
		
		drawObjects();
		drawCharacterList();
		
		drawBullets();
		drawEnemyArrow();
		drawSpriteWith(mainBase.getSprite());
		drawInventory();
		printLife();
		drawInterface();
		

	
}
void Terrain::initAfterLoad()
{
	score = 0;
	mainBase.setLife(2000);
	numberLayersX = LAYERLENGTH;
	numberLayersY = LAYERLENGTH;

	characterCoord.setVector(50, 50);

	cameraCoord.setVector(WIDTH, HEIGHT);
	terrainCoord.setVector(0, 0);
	showEnemies = true;
	FixedTime = 0;

	limitCoords.setVector(cameraCoord.getVectorX() / SPRITE_DEFAULT_WIDTH, cameraCoord.getVectorY() / SPRITE_DEFAULT_HEIGHT);
	allocateMatrixMemory();
	placeRoad(0, numberLayersY / 2, numberLayersX - 1, numberLayersY / 2, 0);
	placeRoad(numberLayersX / 2, 0, numberLayersX / 2, numberLayersY - 1, 1);
	placeWater(2, 2, 6, 6, true);
	placeWater(2, 13, 6, 17, true);
	//  placeWater(numberLayersX / 2 + 1, 0, numberLayersX - 1, numberLayersY / 2 - 1, false);
	placeRoad(0, 0, numberLayersX - 1, 0, 0);
	//_characterLife = Array<Health>(_list.getLength() - 1);
	
}
void Terrain::init(SDLInterface &graphics)
{
	_graphics = &graphics;
	score = 0;
	numberLayersX = LAYERLENGTH;
	numberLayersY = LAYERLENGTH;

	characterCoord.setVector(50, 50);

	cameraCoord.setVector(WIDTH, HEIGHT);
	terrainCoord.setVector(0, 0);
	showEnemies = true;
	FixedTime = 0;

	limitCoords.setVector(cameraCoord.getVectorX() / SPRITE_DEFAULT_WIDTH, cameraCoord.getVectorY() / SPRITE_DEFAULT_HEIGHT);
	allocateMatrixMemory();
	_list.init();
   _objectList.init();
   _characterLife.setActualPosition(_list.getCharacter(_list.getLength() - 1)->getCharacterHealth());
   placeRoad(0, numberLayersY / 2, numberLayersX - 1, numberLayersY / 2, 0);
   placeRoad(numberLayersX / 2, 0, numberLayersX / 2, numberLayersY - 1, 1);
   placeWater(2, 2, 6, 6, true);
   placeWater(2, 13, 6, 17, true);
 //  placeWater(numberLayersX / 2 + 1, 0, numberLayersX - 1, numberLayersY / 2 - 1, false);
   placeRoad(0, 0, numberLayersX - 1, 0, 0);
	//_characterLife = Array<Health>(_list.getLength() - 1);
   initAImap();
   for (int i = 0;i < _list.getEnemyNumber();i++)
   {
	   _list.getCharacter(i)->sendMap(tileArray);
   }
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
	_graphics->drawTexture(spriteid, width * curTicks, 0, width, height, positionVector.getVectorX(),
		positionVector.getVectorY(), width, height);
}


void Terrain::checkBulletCollision()
{
	int bulletLength = _bulletList.getLength(), enemyLength = _list.getEnemyNumber();
		for (int j = 0; j < bulletLength; j++)
		{
			bulletLength = _bulletList.getLength();
			for (int i = 0  ; i<enemyLength ; i++)
			{
				if (_bulletList.getCharacter(j) != NULL &&_bulletList.getCharacter(j)->checkHit(_list.getCharacter(i)->getCollider()))
				{
					bool combat = true;
					_bulletList.removeCharacter(j);
					_list.getCharacter(i)->lowCharacterLife();
					_list.getCharacter(i)->setCombat(combat);
					i = enemyLength;
					bulletLength = _bulletList.getLength();
					score += 10;
				}
				enemyLength = _list.getEnemyNumber();
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

void Terrain::changeEnemybool()
{
	showEnemies = !showEnemies;
}

void Terrain::drawEnemyArrow()
{
	int numberL = _list.getEnemyNumber();
	for (int i = 0; i < numberL; i++)
	{
		_list.getCharacter(i)->getArrowY(_list.getCharacter(_list.getLength() -1)->getCameraPosition());
	
				if (abs(_list.getCharacter(i)->getPosition().getVectorX() - _list.getCharacter(_list.getLength() - 1)->getCameraPosition().getVectorX()) > LIMITX - 200 || abs(_list.getCharacter(i)->getPosition().getVectorY() - _list.getCharacter(_list.getLength() - 1)->getCameraPosition().getVectorY()) > LIMITY - 200)
				{
					if (showEnemies == false)
					{

						//drawSpriteWith(_list.getCharacter(i)->getArrowSprite());
						for (int i = 0; i<LAYERLENGTH;i++)
						{
							for (int j = 0; j<LAYERLENGTH;j++)
							{
						if (tileArray[i][j].getLayer().dataArray[2] == ENEMY)
						{
							//_graphics->drawLine(RED, _list.getCharacter(_list.getLength() - 1)->getCameraPosition().getVectorX(), _list.getCharacter(_list.getLength() - 1)->getCameraPosition().getVectorY(),i * SPRITE_DEFAULT_WIDTH,j*SPRITE_DEFAULT_HEIGHT);
							_graphics->drawLine(BLUE, _list.getCharacter(_list.getLength() - 1)->getCameraPosition().getVectorX(), _list.getCharacter(_list.getLength() - 1)->getCameraPosition().getVectorY(), mainBase.getCoords().getVectorX() + mainBase.getSprite().getSpriteWidth() / 2, mainBase.getCoords().getVectorY() + mainBase.getSprite().getSpriteHeight() / 2);
						}
					 }
				}
			}
		}
	}
}

void Terrain::loadMap()
{
/*	_list.restartIterator();
	_objectList.restartIterator();*/
	
	for (int i = 0; i < _list.getLength(); i++)
	{
	
		_list.removeCharacter(i);
		
	}
	_list.setEnemyNumber(0);
	
	for (int i = 0; i < _objectList.getLength(); i++)
	{
		_objectList.removeCharacter(i);
	}
	_list.setNpcNumber(0);
	std::ifstream loadFile;
	int enemyNumber = 0, npcNumber = 0, objectLength = 0;
	loadFile.open("savedFile.bin", std::ios::in | std::ios::binary);
	loadFile.seekg(0, std::ios::beg);

	if (!loadFile.is_open())
	{
		throw std::exception("[LoadMap] System wasn't able to open the file");
	}
	int numberL = _list.getLength();
	numberL = _objectList.getLength();
	int baselife = mainBase.getBaseLive();
	loadFile.read((char*)&numberLayersX, sizeof(int));
	loadFile.read((char*)&numberLayersY, sizeof(int));
	loadFile.read((char*)&score, sizeof(int));
	loadFile.read((char*)&baselife, sizeof(int));
	loadFile.read((char*)&terrainCoord, sizeof(Coord<int>));
	loadFile.read((char*)&cameraCoord, sizeof(Coord<int>));
	loadFile.read((char*)&mainBase, sizeof(Base));
	loadFile.read((char*)&enemyNumber, sizeof(int));
	loadFile.read((char*)&npcNumber, sizeof(int));
	Character *p;
	/* First mainCharacter*/
	mainBase.setLife(baselife);
	p = new MainCharacter();
	loadFile.read((char*)(MainCharacter*)p, sizeof(MainCharacter));
	_list.addCharacter(p);

	/* Next Npc*/
	for (int i = enemyNumber; i < npcNumber; i++)
	{
		p = new Npc();
		loadFile.read((char*)(Npc*)p, sizeof(Npc));
		_list.addCharacter(p);
	}
	_list.setNpcNumber(npcNumber);
	/*At the end of the list we add the enemies*/
	for (int i = 0; i < enemyNumber; i++)
	{
		p = new Enemy();
		loadFile.read((char*)(Enemy*)p, sizeof(Enemy));
		_list.addCharacter(p);
		
	}
	_list.setEnemyNumber(enemyNumber);

	
	

	loadFile.read((char*)&objectLength, sizeof(int));

	Object* o;
	for (int i = 0; i < objectLength; i++)
	{
		o = new PowerUp();
		loadFile.read((char*)(PowerUp*)o, sizeof(Object));
		_objectList.addCharacter(o);
	}
	
	loadFile.close();
	std::ifstream loadFileC;
	loadFileC.open("Map.txt", std::ios::in );
	if (!loadFileC.is_open())
	{
		throw std::exception("[main.cpp] System wasn't able to open the file");
	}
	for (int i = 0; i < numberLayersX; i++)
	{

		for (int j = 0; j < numberLayersY; j++)
		{
			int layerNumber = 0;
		//	loadFileC >> tileArray[i][j].getLayer().dataArray[0];
			//tileArray[i][j].getLayer().dataArray[0] = layerNumber;
			//saveFile.write((char*)&tileArray[i][j].getLayer().dataArray[0], sizeof(tileArray[i][j].getLayer().dataArray[0]));

		}
	}
	
	
	loadFileC.close();
	initAImap();

}

void Terrain::copyMap()
{

	/*
		ENEMIGO 1
		NPC 2
		mainCharacter 3
		Object 4
		Object 5
		Object 6

	*/




	/*
		SAVE OPERATIONS
	*/
	std::ofstream saveFile;
	
	saveFile.open("savedFile.bin", std::ios::out | std::ios::binary| std::ios::trunc);
		if (!saveFile.is_open())
		{
			throw std::exception("[main.cpp] System wasn't able to open the file");
		}
		/*We save map dimensions*/
		int baselife = mainBase.getBaseLive();
		saveFile.write((char*)&numberLayersX, sizeof(int));
		saveFile.write((char*)&numberLayersY, sizeof(int));
		saveFile.write((char*)&score, sizeof(int));
		saveFile.write((char*)&baselife, sizeof(int));
		saveFile.write((char*)&terrainCoord, sizeof(Coord<int>));
		saveFile.write((char*)&cameraCoord, sizeof(Coord<int>));
		saveFile.write((char*)&mainBase, sizeof(Base));
		int enNum = _list.getEnemyNumber();
		int npcNum= _list.getNpcNumber();
		int objectLength = _objectList.getLength();
		/*we save Enemies and Npc numbers*/
		saveFile.write((char*)&enNum, sizeof(int));
		saveFile.write((char*)&npcNum, sizeof(int));
		/*We save the Characters*/
		for (int i = _list.getNpcNumber();i < _list.getLength();i++)
		{
			/* We save the MainCharacter first, because it's in the end of the characterList.*/
			saveFile.write((char*)((MainCharacter*)_list.getCharacter(i)), sizeof(MainCharacter));
		}

		for (int i = _list.getEnemyNumber();i < _list.getNpcNumber();i++)
		{
			/* Next we save Npcs */
			saveFile.write((char*)((Npc*)_list.getCharacter(i)), sizeof(Npc));
		}

		for (int i = 0; i < _list.getEnemyNumber(); i++)
		{
			/*Enemies at last*/
			saveFile.write((char*) ((Enemy *)_list.getCharacter(i)), sizeof(Enemy));
		} 

		
		
		/*We save the number of Objects*/
		saveFile.write((char*)&objectLength,sizeof(int));
		/*We save the objects*/
		for (int i = 0; i < _objectList.getLength(); i++)
		{
			saveFile.write((char*)((PowerUp*)_objectList.getCharacter(i)), sizeof(PowerUp));
		}

/* 
	THIS WAY IS OLD, WE USED TO STORE CHARACTERS IN A LAYER FROM THE MAP
		for (int i = 0; i < numberLayersX; i++)
		{
			
			for (int j = 0; j < numberLayersY; j++)
			{
				
			//	saveFile << tileArray[i][j].getLayer().dataArray[2];
				saveFile.write((char*)&tileArray[i][j].getLayer().dataArray[2],sizeof(tileArray[i][j].getLayer().dataArray[2]));

			}
		}
		*/
	//	saveFile << "terrainMap";
		//FINALLY WE SAVE THE MAP
		
		saveFile.close();
		std::cout << "MAP SAVED"<<std::endl;
		
		saveFile.open("Map.txt", std::ios::out | std::ios::trunc);
		if (!saveFile.is_open())
		{
			throw std::exception("[main.cpp] System wasn't able to open the file");
		}
		for (int i = 0; i < numberLayersX; i++)
		{

			for (int j = 0; j < numberLayersY; j++)
			{

				saveFile<<tileArray[i][j].getLayer().dataArray[0];
				//saveFile.write((char*)&tileArray[i][j].getLayer().dataArray[0], sizeof(tileArray[i][j].getLayer().dataArray[0]));

			}
		}
		saveFile.close();
		/*
		SAVE OPERATIONS
		*/

}

void Terrain::drawInterface()
{
	std::string Score,baselife;
	Score = "Score: " + std::to_string(score);
	baselife = "BaseLife: " + std::to_string(mainBase.getBaseLive());
	_graphics->drawText(Score , RED, WHITE, 50, 50);
	_graphics->drawText(baselife , BLACK, WHITE, 50, 80);
}


void Terrain::drawAnimationwith(int spriteid, Coord<int> positionVector, int curTicks, int maxFrames, int width, int height, int maxFramesHeight,int curTicksHeight)
{
	curTicks = curTicks %  maxFrames;
	curTicksHeight = curTicksHeight % maxFramesHeight;
	_graphics->drawTexture(spriteid, width * curTicks, height * curTicksHeight, width, height, positionVector.getVectorX(),
		positionVector.getVectorY(), width, height);
}

void Terrain::initAImap()
{

	for (int i = 0; i < numberLayersX;i++)
	{
		for (int j = 0;j < numberLayersY;j++)
		{
			tileArray[i][j].getLayer().dataArray[2] = EMPTY;
			if (tileArray[i][j].getLayer().dataArray[0] == SPRITE_WATER)
			{
				tileArray[i][j].getLayer().dataArray[2] = WATER;
			}
		}
	}
	int x, y;
	x = mainBase.getCoords().getVectorX() / SPRITE_DEFAULT_WIDTH;
	y = mainBase.getCoords().getVectorY() / SPRITE_DEFAULT_HEIGHT;
	
	
	for (int i = x - 2; i <= x + 2; i++)
	{
		for (int j = y - 2; j <= y + 2; j++)
		{ 
		
			tileArray[i][j].getLayer().dataArray[2] = preGoal;
		}
	}
	tileArray[x][y].getLayer().dataArray[2] = GOAL;
	for (int i = 0;i < _list.getEnemyNumber();i++)
	{
		x = abs(_list.getCharacter(i)->getPosition().getVectorX() / SPRITE_DEFAULT_WIDTH) ;
		y = abs(_list.getCharacter(i)->getPosition().getVectorY() / SPRITE_DEFAULT_WIDTH) ;
		tileArray[x][y].getLayer().dataArray[2] = ENEMY;
	}

	for (int i = _list.getEnemyNumber(); i < _list.getNpcNumber();i++)
	{
		x = abs( _list.getCharacter(i)->getPosition().getVectorX() / SPRITE_DEFAULT_WIDTH );
		y = abs(_list.getCharacter(i)->getPosition().getVectorY() / SPRITE_DEFAULT_WIDTH) ;
		tileArray[x][y].getLayer().dataArray[2] = NPC;
	}

	x = _list.getCharacter(_list.getLength() - 1)->getPosition().getVectorX() / SPRITE_DEFAULT_WIDTH;
	y = _list.getCharacter(_list.getLength() - 1)->getPosition().getVectorY() / SPRITE_DEFAULT_WIDTH;
	tileArray[x][y].getLayer().dataArray[2] = mainCharacter;
	
	int enemyL = _list.getEnemyNumber();
	for (int i = 0;i < enemyL;i++)
	{
		_list.getCharacter(i)->sendMap(tileArray);
	}
}

void Terrain::moveEnemies()
{
	
		if(timeCount > FixedTime)
	{

	
		//initAImap();

		for (int i = 0; i < _list.getEnemyNumber();i++)
		{

			_list.getCharacter(i)->setGoal(mainBase.getCoords().getVectorX(), mainBase.getCoords().getVectorY());
			_list.getCharacter(i)->sendMap(tileArray);
			_list.getCharacter(i)->moveCharacter();
			if (_list.getCharacter(i)->getPowerUp(_list.getCharacter(i)->getCollider(),0))
			{
				_list.getCharacter(i)->attackBase(mainBase);
			}
		
		}

		/*for (int i = 0; i < LAYERLENGTH;i++)
		{

			for (int j = 0; j < LAYERLENGTH; j++)
			{
				if (tileArray[i][j].getLayer().dataArray[2] == mainCharacter)
				{
					tileArray[i][j].getLayer().dataArray[2] = EMPTY;                QUITAR COMENTARIOS PARA VER LA MATRIZ DE PATHFINDING
				}
				std::cout << tileArray [j][i].getLayer().dataArray[2];
			}
			std::cout << std::endl;
		}*/

		int x = _list.getCharacter(_list.getLength() - 1)->getPosition().getVectorX() / SPRITE_DEFAULT_WIDTH;
		int y = _list.getCharacter(_list.getLength() - 1)->getPosition().getVectorY() / SPRITE_DEFAULT_WIDTH;
		tileArray[x][y].getLayer().dataArray[2] = mainCharacter;
		FixedTime = GetTickCount() + 1000;
		_list.createEnemies();
	}
	
	timeCount = GetTickCount();

		
}

int Terrain::getScore()
{
	return score;
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

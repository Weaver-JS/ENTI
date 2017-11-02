#include "Terrain.h"
#include "GameConstants.h"
#include "ErrorManagement.h"


Terrain::Terrain()
{
	numberLayersX = 200;
	numberLayersY = 200;
	characterX = WIDTH/2;
	characterY = HEIGHT/2;
	cameraWidth = WIDTH;
	cameraHeight = HEIGHT;
	terrainPositionX = 0;
	terrainPositionY = 0;
	 limitX = (cameraWidth / SPRITE_DEFAULT_WIDTH);
	 limitY = (cameraHeight / SPRITE_DEFAULT_HEIGHT);
	allocateMatrixMemory();
}

int Terrain::getCameraWidht()
{
	return cameraWidth;
}
int Terrain::getCameraHeight()
{
	return cameraHeight;
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



void Terrain::actualCharacterPosition(int x, int y)
{
	characterX = x;
	characterY = y;
}

void Terrain::changeCamera(int x, int y)
{
	cameraWidth += x;
	cameraHeight += y;
}
void Terrain::changePositionTerrain(int x, int y)
{
	terrainPositionX += x;
	terrainPositionY += y;
}
int Terrain::getTerrainPositionX()
{
	return terrainPositionX;
}
int Terrain::getTerrainPositionY()
{
	return terrainPositionY;
}

int Terrain::getLimitX()
{
	return  limitX;
}
int Terrain::getLimitY()
{
	return  limitY;
}
void Terrain::renderTerrain()
{
	int posX = terrainPositionX;//otra variable que no sea la camara.
	int posY = terrainPositionY;
	 limitX = (cameraWidth / SPRITE_DEFAULT_WIDTH);
	 limitY = (cameraHeight / SPRITE_DEFAULT_HEIGHT);
	


	
	
		for (int i = 0; i < limitX + 1;i++)
		{
			posY = terrainPositionY;
			
			for (int j = 0; j < limitY + 1; j++)
			{

				Sprite sprite[layerNum];
				sprite[0].setInitialValues(posX, posY, tileArray[i][j].getLayer0(), SPRITE_DEFAULT_WIDTH, SPRITE_DEFAULT_HEIGHT, 0, 1);

				sprite[1].setInitialValues(posX, posY, tileArray[i][j].getLayer1(), SPRITE_DEFAULT_WIDTH, SPRITE_DEFAULT_HEIGHT, 0, 1);

				drawSprite(sprite[0]);
				if (j % 3 == 0 && i % 2 == 0)
				{
					drawSprite(sprite[1]);
				}

				posY += SPRITE_DEFAULT_HEIGHT;

			}

			
			posX += SPRITE_DEFAULT_WIDTH;

		}
	
	


	

	
}

void Terrain::init(SDLInterface &graphics)
{
	_graphics = &graphics;
}

void Terrain::allocateMatrixMemory() {
	//Allocate memory
	tileArray = new Tile*[numberLayersX ];
	if (tileArray == 0) {
		throw exception("System was not able to create the matrix");
	}

	//Initialize the points to null. 
	//It's important for avoiding that the Destructor tries to delete a position that doesn't contain anything
	for (int i = 0; i < numberLayersX; i++) {
		tileArray[i] = 0;
	}

	for (int i = 0; i < numberLayersX; i++) {
		tileArray[i] = new Tile[numberLayersY];
		if (tileArray[i] == 0) {
			throw exception("System was not able to create the matrix");
		}
	}
}

void Terrain::drawSprite(Sprite & sprite) {
	_graphics->drawTexture(sprite.getSpriteId(), sprite.getSpriteWidth()*sprite.getCurrentFrame(), 0, sprite.getSpriteWidth(), sprite.getSpriteHeight()
		, sprite.getXAtWorld(), sprite.getYAtWorld(), sprite.getSpriteWidth(), sprite.getSpriteHeight());
}

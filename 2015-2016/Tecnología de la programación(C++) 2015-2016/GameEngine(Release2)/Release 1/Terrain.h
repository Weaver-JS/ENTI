#pragma once

#include "Tile.h"
#include "CharacterList.h"
#include "objectList.h"
#include "BulletList.h"
#include "Inventory.h"

/*
	Clase Terrain encargada de gestionar tanto el terreno como los objetos que se encuentran dentro de él.

*/
class Terrain
{
private:
	// Tamaño del array
	
	int numberLayersX;
	int numberLayersY;
	//Coordenadas del personaje con respecto al mundo.
	Coord<int> characterCoord;
	
	//Esquina superior derecha de la cámara.
	Coord<int> cameraCoord;
	

	/*Posicion inicial del terreno, cambia según la posición 
	en la que se encuentre el personaje */
	Coord<int> terrainCoord;

	/*
		Limites del mapa
	*/
	Coord<int> limitCoords;

	
	Tile** tileArray; // Array de Sprites 2D
	SDLInterface* _graphics; // puntero que apunta al graphics de la clase Game.
	

	CharacterList _list;
	objectList _objectList;
	Inventory _inventory;
	BulletList _bulletList;
	Array<Health> _characterLife;
	
	


public:
	Terrain();
	~Terrain();
	//Métodos

	void printLife();



	void drawSprite(int spriteid, Coord<int> positionVector); //función que dibuja el mapa.
	void drawSpriteAnimation(int spriteid, Coord<int> positionVector, int curTicks,int maxFrames);
	void init(SDLInterface &graphics);//Inicialización del terreno
	void allocateMatrixMemory();
	void changeCamera(Coord<int> cameraVector);//Movimiento de la cámara.
	void renderTerrain(); // Dibujar el terreno.
	void actualCharacterPosition(Coord<int> characterVector);// adquirir los valores actuales del jugador.
	void changePositionTerrain(Coord<int> terrainVector); // Mover el terreno ajustandolo a los valores del personaje y pintando solo su alrededor.
	void matrixMap();
	//Gets
	int getNumberLayersX(); 
	int getNumberLayersY();
	Tile getTileArray(int i, int j);

	//Metodos para pintar
	void placeRoad(int initX, int initY, int finalX, int finalY,int direction);
	void placeWater(int initX, int initY, int finalX, int finalY,bool bordes);
	void placebottomTopRoad(int X, int Y, int direction);
	//Metodos para pintar "prefabs"
	Coord <int> getTerrainVector();
	
	Coord<int> getCameraVector();
	
	Coord<int> getLimitVector();
	//GESTION DE LISTAS
	//List & characters
	Character* getMainCharacter();
	CharacterList& getList();
	void drawCharacterList();
	void moveCharacterList();
	//List & Objects
	void drawObjects();
	void getPowerUp();
	void drawInventory();
	void drawSpriteWith(Sprite &sprite);
	void drawCharacterAnimation(int spriteid, Coord<int> positionVector, int curTicks, int maxFrames, int width, int height);
	//LIST & BULLETS
	void checkBulletCollision();
	void drawBullets();
	BulletList & getBulletList();
	
};


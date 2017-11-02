#pragma once
#include "Sprite.h"
#include "SDLInterface.h"
#include "Array.h"
class Tile
{
private:
	/*
		Clase que guarda las capas que luego se pintarán en el terreno, cada layer
		guarda la información de una de las capas que se irán pintando una a una
		con la matriz de Tiles. 
	*/
	Array<int> layer = Array<int>(layerNum);
	
	

	//Booleano que utilizaremos para añadir objetos.
	bool objectIn; 
		

public:
	Array<int> getLayer();
	void changeLayerSprite(int numLayer,int numSprite);

	Tile();
	~Tile();
};


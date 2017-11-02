#pragma once
#include "Sprite.h"
#include "SDLInterface.h"
class Tile
{
private:
	/*
		Clase que guarda las capas que luego se pintarán en el terreno, cada layer
		guarda la información de una de las capas que se irán pintando una a una
		con la matriz de Tiles. 
	*/
	int layer0;
	int layer1;

	//Booleano que utilizaremos para añadir objetos.
	bool objectIn; 
		

public:
	int getLayer0();
	int getLayer1();
	
	Tile();
	~Tile();
};


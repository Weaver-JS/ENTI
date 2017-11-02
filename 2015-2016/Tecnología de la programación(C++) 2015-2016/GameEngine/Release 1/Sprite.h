#pragma once
#include "GameConstants.h"
/* 
* The Character class represents a character of the game
*/

class Sprite {
	int _xAtWorld;
	int _yAtWorld;	
	int _textureID;	
	int _currentFrame;
	int _maxFrames;
	int _spriteWidth, _spriteHeight;

public:
	Sprite();
	~Sprite();

		//Getter and setter methods
	void setInitialValues(int x, int y, int textureID,int spriteWidth,int spriteHeight, int currentFrame, int maxFrames);
	void setPositionAtWorld(int newXPosition, int newYPosition);
	int getXAtWorld();
	int getYAtWorld();
	int getSpriteWidth();
	int getSpriteHeight();
	int getSpriteId();
	int getMaxFrames();
	void setCurrentFrame(int newCurrentFrame);
	int getCurrentFrame();
	void nextFrame(int nextValue);
	
	
};


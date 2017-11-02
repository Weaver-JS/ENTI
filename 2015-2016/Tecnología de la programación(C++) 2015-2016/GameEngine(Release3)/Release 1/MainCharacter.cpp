#include "MainCharacter.h"



MainCharacter::MainCharacter()
{
	
	//centro del personaje.
	//_position.setVector(WIDTH / 2, HEIGHT / 2);
	_cameraPosition.setVector(WIDTH / 2, HEIGHT / 2);
	velocity = 5;
	_sprite.setInitialValues(_position.getVectorX(), _position.getVectorY(), SPRITE_ANIM, 23, 23, 0, 8); // Personaje y animación temporales.
	characterMaxHeight = 4;

	

	
}




void MainCharacter::nextAnimationframe(int cur)
{
	_sprite.nextFrame((int)(cur * SPRITE_SPEED));
}
void MainCharacter::setCharacterCoords(Coord<int> characterCoords)
{
	_position =characterCoords;

}
MainCharacter::~MainCharacter()
{
	
}

Coord<int> MainCharacter::getCameraPosition()
{
	return _cameraPosition;
}

void MainCharacter::moveCharacter(Coord<int> pos)
{
	moveCharacterPrivate(pos);
	//nextAnimationframe(_graphics->getCurrentTicks());//
	combatActivated = false;
	
}



void MainCharacter::moveCharacterPrivate(Coord<int> characterMove)
{
	_position += characterMove;


	_cameraPosition += characterMove;

	if (_cameraPosition.getVectorX() <= 0)
	{
		_cameraPosition.setVector(0, _cameraPosition.getVectorY());
	}
	if (_cameraPosition.getVectorY() <= 0)
	{
		_cameraPosition.setVector(_cameraPosition.getVectorX(), 0);
	}
	if (_cameraPosition.getVectorX() >= LIMITX)
	{
		_cameraPosition.setVector(LIMITX, _cameraPosition.getVectorY());
	}
	if (_cameraPosition.getVectorY() >= LIMITY)
	{
		_cameraPosition.setVector(_cameraPosition.getVectorX(), LIMITY);
	}
	_sprite.setPositionAtWorld(_cameraPosition.getVectorX() +MainCharacter_WIDTH /2, _cameraPosition.getVectorY() + MainCharacter_HEIGHT /2);
	
	_col.setCoordsAndDist(_cameraPosition.getVectorX()+ MainCharacter_WIDTH /2, _cameraPosition.getVectorY() +   MainCharacter_HEIGHT /2, MainCharacter_HEIGHT);
	_position = _cameraPosition;
}

void MainCharacter::moveCharacter()
{
	//mainCharacterInput();

	
	}

void MainCharacter::drawLoop()
{
	
}

void MainCharacter::attack()
{
}




	


int MainCharacter::getVelocity()
{
	return velocity;
}
void MainCharacter::changeVelocity(int newVel)
{
	velocity = newVel;
}

Coord<int> MainCharacter::getCoord()
{
	return _position;
}

Sprite MainCharacter::getSprite()
{
	return _sprite;
}



void MainCharacter::attack(Collider col)
{
	if (_col.onColisionEnter(col.getX() + col.getDist(), col.getY() + col.getDist()))
	{
	characterHealth--;
	}
}

void MainCharacter::drawLoop(SDLInterface * graphic)
{
	drawSprite(_sprite, graphic);

}






bool MainCharacter::getPowerUp(Collider &col, int id)
{
	if (col.onColisionEnter(_col.getX(), _col.getY()))
	{
		switch (id)
		{
		case 0 :
			attackPower++;
			break;
		case 1:
			characterHealth++;
		
			break;
		case 2:
			velocity++;
			break;

		}
		
		return true;
	}
	return false;
}
void MainCharacter::drawSprite(Sprite & sprite,SDLInterface* graphic) {
	graphic->drawTexture(sprite.getSpriteId(), sprite.getSpriteWidth()*sprite.getCurrentFrame(), 0, sprite.getSpriteWidth(), sprite.getSpriteHeight()
		, sprite.getXAtWorld(), sprite.getYAtWorld(), sprite.getSpriteWidth(), sprite.getSpriteHeight());
}

#include "Animator.h"



Animator::Animator()
{
}


void Animator::drawSprite(Sprite &sprite, SDLInterface &_graphics) {
	_graphics.drawTexture(sprite.getSpriteId(), sprite.getSpriteWidth()*sprite.getCurrentFrame(), rowHeight, sprite.getSpriteWidth(), sprite.getSpriteHeight()
		, sprite.getXAtWorld(), sprite.getYAtWorld(), sprite.getSpriteWidth(), sprite.getSpriteHeight());
}

void Animator::setRowHeight(int newRowHeight) {
	rowHeight = newRowHeight;
}

Animator::~Animator()
{
}

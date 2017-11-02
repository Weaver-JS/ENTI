#include "Object.h"


Object::Object(){
	/*
	_position.setVector(0, 0);
	_sprite.setInitialValues(0, 0, SPRITE_FIRE, SPRITE_DEFAULT_WIDTH, SPRITE_DEFAULT_HEIGHT, 0, 1);
	_col.setCoordsAndDist(_position.getVectorX(), _position.getVectorY(), SPRITE_DEFAULT_WIDTH / 2);*/
}

Object::Object(Coord<int> pos, int spriteID) {
	_position = pos;
	/*_sprite.setInitialValues(pos.getVectorX() + SPRITE_DEFAULT_WIDTH / 2, pos.getVectorY() - SPRITE_DEFAULT_HEIGHT / 2, spriteID, _sprite.getSpriteWidth(), _sprite.getSpriteHeight(), _sprite.getCurrentFrame(), _sprite.getMaxFrames());
	_col.setCoordsAndDist(pos.getVectorX() + SPRITE_DEFAULT_WIDTH / 2, pos.getVectorY() - SPRITE_DEFAULT_HEIGHT / 2, SPRITE_DEFAULT_WIDTH);*/
}

Object::Object(Object &o) {
	_position = o._position;
	_sprite = o._sprite;
	_col = o._col;
}

Coord<int> Object::getPosition() {
	return _position;
}

Sprite Object::getSprite() {
	return _sprite;
}

Collider Object::getCollider() {
	return _col;
}

int Object::getObjectID()
{
	return objectID;
}

Object::~Object(){

}

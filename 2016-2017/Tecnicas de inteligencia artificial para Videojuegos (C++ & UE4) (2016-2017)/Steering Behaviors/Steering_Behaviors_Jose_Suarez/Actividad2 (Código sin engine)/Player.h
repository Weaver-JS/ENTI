/* ========================================================================
   File: Player.h
   Revision: 0.1
   Creator: David Collado Ochoa
   Notice: (C) Copyright 2016 by David Collado Ochoa. All Rights Reserved.
   ======================================================================== */

#pragma once

#include "Engine/EngineFramework.h"

class Player : public DibSprite
{
public:
	Player(int x, int y, int width, int height) :
		DibSprite(x, y, width, height)
	{
		moves = true;
		isActive = true;
		life = 100;
	};

	virtual void Update(float deltaTime) override;
	virtual void Render() override;
	virtual void Clean() override;
	void damageLife(int damage);
	void setLife(int newLife);
	int getLife();

private:
	// Input flags
	int moveHorizontal;
	int moveVertical;
	int life;
	void HandleInput();
	void UpdateSpeed(float deltaTime);
	void UpdateAngle();
};

#pragma once

#include "Engine/EngineFramework.h"

#include "WarriorPlayer.h"
#include "DragonAgent.h"
#include "Gem.h"

class BTExamState : public BaseState
{
public:
	virtual void Init() override;
	virtual void Clean() override;
	virtual void Update(float deltaTime) override;
	virtual void Render() override;

private:
	// State Data
	
	// Toggle between exercise 1 and 2
	// ONLY AT COMPILE TIME
	bool checkExercise2 = true;

	// Textures
	Texture castleTexture;
	StaticTexture pathTexture;

	// Entities
	WarriorPlayer* kid;
	DragonAgent* dragon;

	// Gems
	static constexpr int K_NUM_GEM = 10;
	int	numGem = K_NUM_GEM;
	Gem* gemArray[K_NUM_GEM];

	// Home
	Path homePath;
	Vector2D homePosition;

	// Fonts and Debug
	FC_Font* fontVerySmall;
	FC_Font* fontSmall;
	FC_Font* fontBig;
	bool isPaused = false;
	bool runOneFrame = false;

	// Private methods
	void HandleInput();
};
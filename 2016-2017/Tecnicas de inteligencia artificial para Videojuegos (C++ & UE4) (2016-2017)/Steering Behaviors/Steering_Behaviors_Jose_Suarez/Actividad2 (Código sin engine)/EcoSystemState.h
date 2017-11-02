/* ========================================================================
   File: EcoSystemState.h
   Revision: 0.1
   Creator: David Collado Ochoa
   Notice: (C) Copyright 2016 by David Collado Ochoa. All Rights Reserved.
   ======================================================================== */

#pragma once
#define PLAYERSNUMBER 3
#define ACTIVE_RADIUS 5
#include "Engine/EngineFramework.h"
#include "Boid.h"
#include "Player.h"
#include "Level.h"
class EcoSystemState : public BaseState
{
public:
	virtual void Init() override;
	virtual void Clean() override;
	virtual void Update(float deltaTime) override;
	virtual void Render() override;

private:
	// State Data
	Behavior currentBehavior;

	//tetures 
	StaticTexture pathTexture;

	//Entities
	static const int BOID_POOL_SIZE = 30;
	GenericPool<Boid>* boidPool;
	Boid* boid;
	
	
	Player* player;
	Level* level;
	
	
	//Trail
	Trail trailPool[BOID_POOL_SIZE];
	int trailPoolOccupation = 0;
	Trail boidTrail;
	float K_TRAIL_UPDATE_THRESHOLD;
	float trailUpdateCounter;
	
	bool playerWins;
	bool redWins;
	bool greenWins;

	bool playerDamaged;
	bool redDamaged;
	bool greenDamaged;

	float playerTime;
	float redTime;
	float greenTime;
	const float timeToWait = 3.0f;

	//Path
	Path path;
	Path path2;
	//Variables for debugging of Path Following
	Vector2D closestPoint;

	//Obstacle Avoidance
	static const int OBSTACLE_POOL_SIZE = 30;
	Obstacle obstaclePool[OBSTACLE_POOL_SIZE];
	int obstaclePoolSize;
	//Variables for debugging of Obstacle Avoidance
	Vector2D raycastStart;
	Vector2D raycastEnd;
	Timer* gameTime;
	bool intersection = false;
	Vector2D intersectionPoint = {};
	Vector2D normalVector = {};
	float normalDistance = 60.0f;

	//Entities for Collisions Avoidance
	static const int ENTITY_POOL_SIZE = 30;
	GenericPool<DibObject>* collisionPool;


	// Fonts and Debug
	FC_Font* fontVerySmall;
	FC_Font* fontSmall;
	FC_Font* fontBig;
	char* title;
	char* theoricUpdateInformation;
	char* theroicAlgorithmInformation;
	char realUpdateInformation[512];
	char realAlgorithmInformation[512];
	char Red_kills_Blue[14];
	char Blue_kills_Green[16];
	char Green_kills_Red[15];
	bool showDebug = false;
	bool smoothAngle = false;

	//Pause Params
	float timeScale = 1.0f;
	bool isPaused = false;
	bool runOneFrame = false;

	// Private functions
	void HandleInput();
	void CreateBoid(int x, int y,Vector2D* position, Vector2D* speed);
	void ChangeBoidsBehavior(Behavior newBehavior);
	void InitCollision(int index, bool movable);
	void ChangeCollisions(bool movable, int collisionNumber);
	void UpdateDebug();
	void RenderDebug();
	void CreateBoid(int x, int y);
	void introGame();
	void calculateCollisions();
	void seeWhoWins();

	void colorInit();

	void stateManager();
	
	
};
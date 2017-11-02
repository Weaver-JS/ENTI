/* ========================================================================
   File: EcoSystemState.cpp
   Revision: 0.1
   Creator: David Collado Ochoa
   Notice: (C) Copyright 2016 by David Collado Ochoa. All Rights Reserved.
   ======================================================================== */

#include "EcoSystemState.h"
static const int LEVEL_WIDTH = 33;
static const int LEVEL_HEIGHT = 22;

static const int mapLevel1[LEVEL_WIDTH][LEVEL_HEIGHT] =
{
	1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
	1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1,
	1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1,
	1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1,
	1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1,
	1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1,
	1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1,
	1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1,
	1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1,
	1, 0, 0, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1,
	1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1,
	1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1,
	1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1,
	1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1,
	0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
	1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1,
	1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1,
	1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,

};

void EcoSystemState::Init()
{
	 playerWins = false;
	 redWins = false;
	 greenWins = false;
	// Seed Random

	srand(5555);
	//CollisionUtils::SDL_CollideBoundingBox(player->GetCollisionBox(), boid->GetCollisionBox());

	title = "Blue";
	// Initialize State
	currentBehavior = Behavior::PATH_FOLLOWING;//WANDER;//PRIORITY_OBSTACLE;
	gameTime = new Timer();
	level = new Level();
	level->LoadFromArray((int*)mapLevel1, { 0.0f,0.0f }, LEVEL_WIDTH, LEVEL_HEIGHT, PathUtils::GetResourcesPath("images/spr_blue_floor_5.png"), "BlueFloor", 32, 32, { GLOBAL_SCALE,GLOBAL_SCALE });
	
	// Initialize Fonts of different sizes
	std::string assetPath = PathUtils::GetResourcesPath("Fonts/nokiafc22.ttf");
	fontVerySmall = FC_CreateFont();
	FC_LoadFont(fontVerySmall, Game::Instance().renderer,
		assetPath.c_str(), 12, FC_MakeColor(255, 255, 255, 255), TTF_STYLE_NORMAL);
	fontSmall = FC_CreateFont();
	FC_LoadFont(fontSmall, Game::Instance().renderer,
		assetPath.c_str(), 22, FC_MakeColor(255, 255, 255, 255), TTF_STYLE_NORMAL);
	fontBig = FC_CreateFont();
	FC_LoadFont(fontBig, Game::Instance().renderer,
		assetPath.c_str(), 30, FC_MakeColor(255, 255, 255, 255), TTF_STYLE_NORMAL);

	// Initialize Entities
	
	// Initialize Player
	assetPath = PathUtils::GetResourcesPath("images/Player.png");
	player = new Player(FIXED_WIDTH - 50, FIXED_HEIGHT-50, 32, 24);
	player->LoadGraphic(assetPath, "Player", 32, 24, false);
	player->SetScale(GLOBAL_SCALE, GLOBAL_SCALE);

	// Boids
	boidPool = new GenericPool<Boid>(BOID_POOL_SIZE);

	int randomX = IntegerUtils::RandomRange(0, FIXED_WIDTH);
	int randomY = IntegerUtils::RandomRange(0, FIXED_HEIGHT);
	boid = new Boid((float)FIXED_WIDTH-1040 , (float)FIXED_HEIGHT-150 , 32, 24);//(float)randomX, (float)randomY, 32, 24);
	assetPath = PathUtils::GetResourcesPath("images/Boid.png");
	boid->LoadGraphic(assetPath, "Boid", 32, 24, false);
	boid->SetScale(GLOBAL_SCALE, GLOBAL_SCALE);
	boid->targetPosition = &player->position;
	boid->targetSpeed = &player->speed;
	boid->SetBehavior(currentBehavior);
	boid->InitDebug(fontVerySmall);


	
	// Initialize Text
	title = (char*)"";
	theroicAlgorithmInformation = (char*)"";
	theoricUpdateInformation = (char*)"";

	// Initialize Trail vars
	boidTrail = {};
	Trail_Initialize(&boidTrail, 80, 4, 4);
	trailUpdateCounter = 0;
	K_TRAIL_UPDATE_THRESHOLD = 0.0225f;

	// Initialize Path
	boid->path = &path;
	//Path_AddPoint(&path, { FIXED_WIDTH - 1050, FIXED_HEIGHT - 100 });
	Path_AddPoint(&path, { FIXED_WIDTH-1000, FIXED_HEIGHT-50 });
	Path_AddPoint(&path, { (float)FIXED_WIDTH-950, (float)FIXED_HEIGHT-50 });
	Path_AddPoint(&path, { FIXED_WIDTH - 900, FIXED_HEIGHT - 50 });
	Path_AddPoint(&path, { FIXED_WIDTH - 800, FIXED_HEIGHT - 50 });
	Path_AddPoint(&path, { FIXED_WIDTH - 500, FIXED_HEIGHT - 50 });
	Path_AddPoint(&path, { FIXED_WIDTH - 500, FIXED_HEIGHT - 400 });
	/*Path_AddPoint(&path, { 100, 100 });
	Path_AddPoint(&path, { 100, 100 });
	Path_AddPoint(&path, { 100, 100 });
	Path_AddPoint(&path, { 100, 100 });*/

	// Draw Path only once
	pathTexture = {};
	StaticTexture_Init(&pathTexture, FIXED_WIDTH, FIXED_HEIGHT, Game::Instance().renderer);
	StaticTexture_StartDrawing(&pathTexture);
	// Render Path
	Path_Render(&path, Game::Instance().renderer, 6, Colors::BELIZE_HOLE);
	StaticTexture_EndDrawing(&pathTexture);

	// Initialize Obstacles
	for (int i = 0; i < 10; ++i)
	{
		obstaclePool[i] = Obstacle_Create({
			(float)IntegerUtils::RandomRange(0, FIXED_WIDTH),
			(float)IntegerUtils::RandomRange(0, FIXED_HEIGHT) }, 100.0f, 5.0f);
		++obstaclePoolSize;
	}
	boid->obstacleArray = (Obstacle*)obstaclePool;
	boid->obstacleArraySize = &obstaclePoolSize;

	// Initialize Priority
	boid->InitPrioritySteering();

	// Initialize Collision Entitites
	collisionPool = new GenericPool<DibObject>(ENTITY_POOL_SIZE);
	for (int i = 0; i < collisionPool->numElements; ++i)
	{
		InitCollision(i, false);
		// Add collisions to boid
		boid->AddTargetForCollisionAvoidance(&collisionPool->pool[i]);
	}

	//Second Boid
	CreateBoid(IntegerUtils::RandomRange(0, FIXED_WIDTH), IntegerUtils::RandomRange(0, FIXED_HEIGHT), &boid->position, &boid->speed);

	player->SetSolidCollisions(level->solids);
	boid->SetSolidCollisions(level->solids);
	boidPool->pool[0].SetSolidCollisions(level->solids);
	Timer_Start(gameTime);

	playerDamaged = false;
	redDamaged = false;
	greenDamaged = false;
	 playerTime = 0.0f;
	 redTime = 0.0f;
	 greenTime = 0.0f;
}

void EcoSystemState::Clean()
{
	// Free fonts
	FC_FreeFont(fontBig);
	FC_FreeFont(fontSmall);
	FC_FreeFont(fontVerySmall);

	// Free textures
	StaticTexture_Free(&pathTexture);

	// Clean Trail
	Trail_Free(&boidTrail);
	// Free Trails in Pool
	for (int i = 0; i < trailPoolOccupation; i++)
	{
		Trail_Free(&trailPool[i]);
	}

	// Clean entities
	player->Clean();
	boid->CleanDebug();
	boid->DeinitPrioritySteering();

	for (int i = 0; i < boidPool->numElements; i++)
	{
		boidPool->pool[i].DeinitPrioritySteering();
	}
	boidPool->Clean();
	collisionPool->Clean();
	level->Clean();
}

void EcoSystemState::Update(float deltaTime)
{
	if (Input::Instance().GetKeyDown(KeyCode::Escape))
	{
		Game::Instance().ChangeState(MENU);
		return;
	}

	HandleInput();

	//Pause management
	if (isPaused == true && runOneFrame == false)
	{
		return;
	}
	runOneFrame = false;

	// Calculate time
	float currentDeltaTime = deltaTime * timeScale;

	// Update Entities
	collisionPool->Update(deltaTime);
	for (int i = 0; i < collisionPool->numElements; ++i)
	{
		// Wrap Collision
		Utils::DoWrap(collisionPool->pool[i].position);
	}
	player->Update(currentDeltaTime);
	boid->Update(currentDeltaTime);

	// Update Trail
	bool updateTrail = false;
	trailUpdateCounter += currentDeltaTime;
	if (trailUpdateCounter > K_TRAIL_UPDATE_THRESHOLD)
	{
		Trail_Update(&boidTrail, boid->position.x, boid->position.y);
		trailUpdateCounter = 0.0f;
		updateTrail = true;
	}

	// Update Boids in Pool and Trail
	for (int i = 0; i < boidPool->numElements; i++)
	{
		Boid* currentBoid = &boidPool->pool[i];
		currentBoid->Update(deltaTime);
		if (currentBoid->GetActive())
		{
			if (updateTrail == true)
			{
				Trail_Update(&trailPool[i],
					currentBoid->position.x,
					currentBoid->position.y);
			}
		}
	}
	stateManager();
	calculateCollisions();
	introGame();
	seeWhoWins();
	
	// Update Debug
	UpdateDebug();
	// Go back to Menu State

	// Update Entities
}

void EcoSystemState::Render()
{
	level->Render();
	SDL_Color white;

	SDL_Color red;

	SDL_Color blue;

	SDL_Color green;

	white.r = 255;
	white.g = 255;
	white.b = 255;
	white.a = 255;

	red.r = 255;
	red.g = 0;
	red.b = 0;

	blue.r = 0;
	blue.g = 0;
	blue.b = 255;

	green.r = 0;
	green.g = 255;
	green.b = 0;
	title = "Blue";
	theoricUpdateInformation = "Green";
	// Render Text
	FC_DrawColor(fontBig, Game::Instance().renderer,
		0,
		FIXED_HEIGHT - 5 * LINE_HEIGHT, blue,
		title);

	FC_DrawColor(fontBig, Game::Instance().renderer,
		85,
		FIXED_HEIGHT - 5 * LINE_HEIGHT, 
		 white,
		"Kills");
	FC_DrawColor(fontBig, Game::Instance().renderer,
		170,
		FIXED_HEIGHT - 5 * LINE_HEIGHT,
		red,
		"Red");

	FC_DrawColor(fontBig, Game::Instance().renderer,
		0,
		FIXED_HEIGHT - 3 * LINE_HEIGHT, green,
		theoricUpdateInformation);

	FC_DrawColor(fontBig, Game::Instance().renderer,
		115,
		FIXED_HEIGHT - 3 * LINE_HEIGHT,
		white,
		"Kills");

	FC_DrawColor(fontBig, Game::Instance().renderer,
		200,
		FIXED_HEIGHT - 3 * LINE_HEIGHT,
		blue,
		"Blue");

	FC_DrawColor(fontBig, Game::Instance().renderer,
		0,
		FIXED_HEIGHT - 1 * LINE_HEIGHT, red,
		"Red");

	FC_DrawColor(fontBig, Game::Instance().renderer,
		80,
		FIXED_HEIGHT - 1 * LINE_HEIGHT,
		white,
		"Kills");

	FC_DrawColor(fontBig, Game::Instance().renderer,
		170,
		FIXED_HEIGHT - 1 * LINE_HEIGHT,
		green,
		"Green");
	char textLife[512];
	sprintf(textLife,"Blue life: %d",player->getLife());

	FC_DrawAlign(fontBig, Game::Instance().renderer,
		0,
		FIXED_HEIGHT - 200,
		FC_ALIGN_LEFT,
		textLife);

	sprintf(textLife, "Red life: %d", boid->life);
	FC_DrawAlign(fontBig, Game::Instance().renderer,
		0,
		FIXED_HEIGHT - 250,
		FC_ALIGN_LEFT,
		textLife);

	sprintf(textLife, "Green life: %d", boidPool->pool[0].life);
	FC_DrawAlign(fontBig, Game::Instance().renderer,
		0,
		FIXED_HEIGHT - 300,
		FC_ALIGN_LEFT,
		textLife);

	
	if (playerWins)
	{
		FC_DrawColor(fontBig, Game::Instance().renderer,
			FIXED_WIDTH / 2 - 100,
			FIXED_HEIGHT / 2, blue,
			title);

		FC_DrawColor(fontBig, Game::Instance().renderer,
			FIXED_WIDTH / 2 + 25,
			FIXED_HEIGHT / 2,
			white,
			"Wins");
	}
	if (greenWins)
	{
		FC_DrawColor(fontBig, Game::Instance().renderer,
			FIXED_WIDTH / 2 - 100,
			FIXED_HEIGHT / 2, green,
			"Green");

		FC_DrawColor(fontBig, Game::Instance().renderer,
			FIXED_WIDTH / 2 + 25,
			FIXED_HEIGHT / 2,
			white,
			"Wins");
	}

	if (redWins)
	{
		FC_DrawColor(fontBig, Game::Instance().renderer,
			FIXED_WIDTH / 2 - 100,
			FIXED_HEIGHT / 2, red,
			"Red");

		FC_DrawColor(fontBig, Game::Instance().renderer,
			FIXED_WIDTH / 2 + 25,
			FIXED_HEIGHT / 2,
			white,
			"Wins");
	}
	/*std::string newP = "Blue life: ";
	FC_DrawColor(fontBig, Game::Instance().renderer,
		200,
		FIXED_HEIGHT -8 * LINE_HEIGHT,
		blue,
		 (char*)std::to_string(player->getLife()));*/
	/*FC_DrawAlign(fontSmall, Game::Instance().renderer,
		FIXED_WIDTH,
		0,
		FC_ALIGN_RIGHT,
		theoricUpdateInformation);
	FC_DrawAlign(fontSmall, Game::Instance().renderer,
		0,
		FIXED_HEIGHT - 3 * LINE_HEIGHT,
		FC_ALIGN_LEFT,
		theroicAlgorithmInformation);

	FC_DrawAlign(fontSmall, Game::Instance().renderer,
		FIXED_WIDTH,
		FIXED_HEIGHT - 2 * LINE_HEIGHT,
		FC_ALIGN_RIGHT,
		(smoothAngle ?
		(char*)"" :
			(char*)""));*/

	if (isPaused == true)
	{
		FC_DrawColor(fontBig, Game::Instance().renderer,
			FIXED_WIDTH / 2 - 200,
			FIXED_HEIGHT / 2 + 50, white,
			"Press 'escape' to leave");
	}
	else
	{
		FC_DrawAlign(fontSmall, Game::Instance().renderer,
			FIXED_WIDTH,
			FIXED_HEIGHT - LINE_HEIGHT,
			FC_ALIGN_RIGHT,
			(char*)"TimeScale = %.2fx", timeScale);
	}

	if (currentBehavior == Behavior::PRIORITY_COLLISION_PATH_FOLLOWING)
	{
		// Render Path
		StaticTexture_Render(&pathTexture, Game::Instance().renderer, 0, 0);
	}

	// Render Trail
	Trail_Render(&boidTrail, Game::Instance().renderer);

	// Render Trails in Pool
	for (int i = 0; i < trailPoolOccupation; i++)
	{
		Trail_Render(&trailPool[i], Game::Instance().renderer);
	}

	// Render Boids in Pool
	boidPool->Render();

	// Render Entities
	player->Render();
	boid->Render();

	// Render Debug
	RenderDebug();

	if (currentBehavior == Behavior::PRIORITY_COLLISION
		|| currentBehavior == Behavior::PRIORITY_COLLISION_PATH_FOLLOWING)
	{
		// Render Entity Collisions
		for (int i = 0; i < collisionPool->numElements; i++)
		{
			filledCircleColor(Game::Instance().renderer,
				collisionPool->pool[i].position.x, collisionPool->pool[i].position.y,
				6, Colors::ORANGE);
		}
	}
}

void EcoSystemState::HandleInput()
{
	if (Input::Instance().GetMouseButtonDown(0))
	{ 
		
		
 
	//	CreateBoid(Input::Instance().mousePosition.x,Input::Instance().mousePosition.y);
	}
	else if (Input::Instance().GetKeyDown(KeyCode::Alpha3))
	{
		ChangeBoidsBehavior(Behavior::PRIORITY_OBSTACLE);
		//ChangeBoidsBehavior(Behavior::PURSUE);
		title = (char*)"Priority Obstacle Avoidance Algorithm";
		theroicAlgorithmInformation = (char*)"Wander + Obstacle Avoidance with Priority.";
		ChangeCollisions(false, 30);
	}
	else if (Input::Instance().GetKeyDown(KeyCode::P))
	{
		isPaused = true;
	}
}

void EcoSystemState::CreateBoid(int x, int y)
{
	Boid* currentBoid = boidPool->GetElement();
	if (currentBoid != nullptr)
	{
		// Prepare Boid
		currentBoid->SetPosition(x, y);
		currentBoid->SetActive(true);
		currentBoid->targetPosition = &player->position;
		currentBoid->targetSpeed = &player->speed;
		currentBoid->SetBehavior(currentBehavior);
		// Configure Path
		currentBoid->path = &path;
		currentBoid->SetScale(GLOBAL_SCALE, GLOBAL_SCALE);

		// Configure Collision Avoidance
		for (int i = 0; i < collisionPool->numElements; ++i)
		{
			currentBoid->AddTargetForCollisionAvoidance(&collisionPool->pool[i]);
		}
		currentBoid->obstacleArray = (Obstacle*)obstaclePool;
		currentBoid->obstacleArraySize = &obstaclePoolSize;

		// Initialize Priority
		currentBoid->InitPrioritySteering();

		// Create Trail
		trailPool[trailPoolOccupation] = {};
		Trail_Initialize(&trailPool[trailPoolOccupation], 80, 4, 4);
		++trailPoolOccupation;
	}
}
void EcoSystemState::CreateBoid(int x, int y, Vector2D* position, Vector2D* speed)
{
	Boid* currentBoid = boidPool->GetElement();
	if (currentBoid != nullptr)
	{
		//Prepare Boid
		currentBoid->SetPosition((float)FIXED_WIDTH - 1000, (float)FIXED_HEIGHT -500);
		currentBoid->SetActive(true);
		currentBoid->targetPosition = &boid->position;
		currentBoid->targetSpeed = &boid->speed;
		currentBoid->SetBehavior(currentBehavior);
		//Configure path
		currentBoid->path = &path2;
		Path_AddPoint(&path2, { FIXED_WIDTH - 1000, FIXED_HEIGHT - 450 });
		Path_AddPoint(&path2, { (float)FIXED_WIDTH - 1000, (float)FIXED_HEIGHT - 300 });
		Path_AddPoint(&path2, { FIXED_WIDTH - 500, FIXED_HEIGHT - 400 });
		Path_AddPoint(&path2, { FIXED_WIDTH - 500, FIXED_HEIGHT - 300 });
		Path_AddPoint(&path2, { FIXED_WIDTH - 500, FIXED_HEIGHT - 250 });

		currentBoid->LoadGraphic(PathUtils::GetResourcesPath("Images/Boid2.png"), "Boid2", 32, 24, false);
		currentBoid->SetScale(GLOBAL_SCALE, GLOBAL_SCALE);
		//Configure Collision Avoidance
		for (int i = 0; i < collisionPool->numElements; i++)
		{
			currentBoid->AddTargetForCollisionAvoidance(&collisionPool->pool[i]);
		}
		currentBoid->obstacleArray = (Obstacle*)obstaclePool;
		currentBoid->obstacleArraySize = &obstaclePoolSize;

		//Initialize Priority
		currentBoid->InitPrioritySteering();
		//currentBoid->ShowCollisionBox();

		//Create Trail
		trailPool[trailPoolOccupation] = {};
		Trail_Initialize(&trailPool[trailPoolOccupation], 80, 4, 4);
		trailPoolOccupation++;

	}
}

void EcoSystemState::ChangeBoidsBehavior(Behavior newBehavior)
{
	currentBehavior = newBehavior;
	boid->SetBehavior(newBehavior);

	//Reset boid's path
	boid->pathOffset = fabs(boid->pathOffset);
	boid->pathFollowingStarted = false;

	for (int i = 0; i < boidPool->numElements; i++)
	{
		boidPool->pool[i].SetBehavior(newBehavior);
		//Reset Boid's path
		boidPool->pool[i].pathOffset = fabs(boid->pathOffset);
		boidPool->pool[i].pathFollowingStarted = false;
	}
}

void EcoSystemState::InitCollision(int index, bool movable)
{
	//Assign random position and speed to collisions
	int randomX = IntegerUtils::RandomRange(0, FIXED_WIDTH);
	int randomY = IntegerUtils::RandomRange(0, FIXED_HEIGHT);
	collisionPool->pool[index].position = {(float)randomX,(float)randomY };
	randomX = IntegerUtils::RandomRange(0, 120);
	randomY = IntegerUtils::RandomRange(0, 120);
	collisionPool->pool[index].speed = { (float)randomX, (float)randomY };
	collisionPool->pool[index].SetActive(true);
	collisionPool->pool[index].moves = movable;
}

void EcoSystemState::ChangeCollisions(bool movable, int collisionNumber)
{
	boid->CleanTargetsForCollisionAvoidance();
	for (int i = 0; i < boidPool->numElements; i++)
	{
		boidPool->pool[i].CleanTargetsForCollisionAvoidance();
	}

	//Add targets
	collisionPool->Clean();
	collisionPool = new GenericPool<DibObject>(collisionNumber);
	for (int i = 0; i < collisionPool->numElements; i++)
	{
		boidPool->pool[i].AddTargetForCollisionAvoidance(&collisionPool->pool[i]);
	}
	
}

void EcoSystemState::UpdateDebug()
{
	if (currentBehavior == Behavior::PRIORITY_OBSTACLE)
	{
		//Wall Intersection Test
		intersection = false;
		intersectionPoint = {};
		normalVector = {};
		float raycastLength = 100.0f;
		raycastStart = player->position;
		raycastEnd = raycastStart + Vector2D::Normalize(player->speed) * raycastLength;
		intersection = Obstacle_IntersectsSegment(&obstaclePool[0], raycastStart, raycastEnd,
			&intersectionPoint, &normalVector);
	}

	if (currentBehavior == Behavior::PRIORITY_COLLISION
		|| currentBehavior == Behavior::PRIORITY_OBSTACLE
		|| currentBehavior == Behavior::PRIORITY_COLLISION_PATH_FOLLOWING)
	{
		//sprintf(realAlgorithmInformation, "%d", boid->usedGroup);
	}
}

void EcoSystemState::RenderDebug()
{
	// Render Debug 
	if (showDebug)
	{
		boid->DrawDebug();
	}

	if (currentBehavior == Behavior::PRIORITY_COLLISION
		|| currentBehavior == Behavior::PRIORITY_OBSTACLE
		|| currentBehavior == Behavior::PRIORITY_COLLISION_PATH_FOLLOWING)
	{
		FC_DrawAlign(fontBig, Game::Instance().renderer,
			0,
			FIXED_HEIGHT - 30,
			FC_ALIGN_LEFT,
			realAlgorithmInformation);
	}

	if (currentBehavior == Behavior::PRIORITY_COLLISION_PATH_FOLLOWING)
	{
		// Path Debug
		filledCircleColor(Game::Instance().renderer, boid->currentPathTarget.x, boid->currentPathTarget.y, 6, Colors::TURQUOISE);
		filledCircleColor(Game::Instance().renderer, closestPoint.x, closestPoint.y, 6, Colors::CARROT);
	}
	else if (currentBehavior == Behavior::PRIORITY_OBSTACLE)
	{
		Uint32 intersectsColor = Colors::CLOUDS;
		if (intersection)
		{
			intersectsColor = Colors::AMETHYST;
			filledCircleColor(Game::Instance().renderer, intersectionPoint.x, intersectionPoint.y, 8, Colors::CARROT);

			Vector2D normalEndPoint = intersectionPoint;
			normalEndPoint += normalVector * normalDistance;
			thickLineColor(Game::Instance().renderer, intersectionPoint.x, intersectionPoint.y,
				normalEndPoint.x, normalEndPoint.y, 5, Colors::MIDNIGHT_BLUE);

			filledCircleColor(Game::Instance().renderer, normalEndPoint.x, normalEndPoint.y, 8, Colors::CARROT);

		}
		// Render Raycast
		thickLineColor(Game::Instance().renderer, raycastStart.x, raycastStart.y, raycastEnd.x, raycastEnd.y, 5, intersectsColor);

		// Render walls
		Obstacle_Render(&obstaclePool[0], Game::Instance().renderer, Colors::AMETHYST);
		for (int i = 1; i < OBSTACLE_POOL_SIZE; ++i)
		{
			Obstacle_Render(&obstaclePool[i], Game::Instance().renderer, Colors::CARROT);
		}
	}
}

void EcoSystemState::introGame()
{
	if (Timer_GetTicks(gameTime) > playerTime)
	{
		playerDamaged = false;
	}
	if (Timer_GetTicks(gameTime) > redTime)
	{
		redDamaged = false;
	}
	if (Timer_GetTicks(gameTime) > greenTime)
	{
		greenDamaged = false;
	}
}

void EcoSystemState::calculateCollisions()
{
	/*boid->ShowCollisionBox(true,Colors::WHITE);
	player->ShowCollisionBox(true, Colors::WHITE);
	boidPool->pool[0].ShowCollisionBox(true, Colors::WHITE);*/
	
		if (CollisionUtils::SDL_CollideBoundingBox(player->GetCollisionBox(), boid->GetCollisionBox()) == 1 && playerDamaged == false)
		{
			player->position = player->position + (Vector2D::Normalize(boid->speed) * 10) ;
			player->damageLife(10);
			
			currentBehavior = PRIORITY_OBSTACLE;
			boid->SetBehavior(PRIORITY_OBSTACLE);
			playerTime = Timer_GetTicks(gameTime) + timeToWait;
		}
		else if (CollisionUtils::SDL_CollideBoundingBox(boidPool->pool[0].GetCollisionBox(), boid->GetCollisionBox()) == 1 && redDamaged == false)
		{
			boid->position = boid->position + (Vector2D::Normalize(boidPool->pool[0].speed) * 10);
			boid->damageCharacter(10);
			redDamaged = true;
			redTime = Timer_GetTicks(gameTime) + timeToWait;
		}
		else if (CollisionUtils::SDL_CollideBoundingBox(boidPool->pool[0].GetCollisionBox(), player->GetCollisionBox()) == 1 &&  greenDamaged== false)
		{
			boidPool->pool[0].position = boidPool->pool[0].position + (Vector2D::Normalize(player->speed) * 10);
			boidPool->pool[0].damageCharacter(10);
			greenDamaged = true;
			greenTime = Timer_GetTicks(gameTime) + timeToWait;
		}
}

void EcoSystemState::seeWhoWins()
{
	if (player->getLife() <= 0)
	{
		
		greenWins = true;

		isPaused = true;
	}
	if(boid->life <= 0.0f)	
	{
		redWins = true;
		isPaused = true;
	}

	if (boidPool->pool[0].life <= 0.0f)
	{
		playerWins = true;
		isPaused = true;
	}

	
}

void EcoSystemState::colorInit()
{
}

void EcoSystemState::stateManager()
{
	if (Vector2D::Distance(boid->GetPosition(), boidPool->pool[0].GetPosition()) <= 100.0f)
	{
		currentBehavior = PRIORITY_OBSTACLE;
		boidPool->pool[0].SetBehavior(PRIORITY_OBSTACLE);
	}

	Vector2D::Distance(boid->GetPosition(), player->GetPosition());
	if (Vector2D::Distance(boid->GetPosition(), player->GetPosition())<= 100.0f)
	{
		currentBehavior = PRIORITY_OBSTACLE;
		boid->SetBehavior(PRIORITY_OBSTACLE);
		
	}
}

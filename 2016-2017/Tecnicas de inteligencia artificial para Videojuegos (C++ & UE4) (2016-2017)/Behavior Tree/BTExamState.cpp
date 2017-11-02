

#include "BTExamState.h"

void BTExamState::Init()
{
	// Seed Random to factor out uncertainty
	srand(12797);

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

	// Initialize Castle Texture
	castleTexture = {};
	assetPath = PathUtils::GetResourcesPath("Images/Castle.png");
	if (Texture_LoadFromFile(&castleTexture, Game::Instance().renderer, assetPath.c_str()) == false)
	{
		SDL_Log("Failed to load Image!\n");
	}
	castleTexture.width = 72;
	castleTexture.height = 72;

	// Initialize Entities

	// Home Position
	homePosition = { 940, 60 };

	// Initialize Path
	Path_AddPoint(&homePath, { 100, 600 });
	Path_AddPoint(&homePath, { 500, 650 });
	Path_AddPoint(&homePath, { 800, 500 });
	Path_AddPoint(&homePath, { 900, 500 });
	Path_AddPoint(&homePath, { 1000, 300 });
	Path_AddPoint(&homePath, { 950, 100 });
	Path_AddPoint(&homePath, { 940, 60 });

	// Draw Path only once
	pathTexture = {};
	StaticTexture_Init(&pathTexture, FIXED_WIDTH, FIXED_HEIGHT, Game::Instance().renderer);
	StaticTexture_StartDrawing(&pathTexture);
	// Render Path
	Path_Render(&homePath, Game::Instance().renderer, 6, Colors::BELIZE_HOLE);
	StaticTexture_EndDrawing(&pathTexture);

	int randomX;
	int randomY;
	int frameSpeed = 14;
	assetPath = PathUtils::GetResourcesPath("images/Gem.png");

	// Initialize Gems
	for (int i = 0; i < numGem; ++i)
	{
		randomX = IntegerUtils::RandomRange(30, FIXED_WIDTH - 30);
		randomY = IntegerUtils::RandomRange(30, FIXED_HEIGHT - 30);
		gemArray[i] = new Gem(randomX, randomY, 28, 30);
		gemArray[i]->LoadGraphic(assetPath, "GemSpritesheet", 32, 32, true);
		gemArray[i]->SetScale(GLOBAL_SCALE, GLOBAL_SCALE);
		gemArray[i]->animationController->Add("Idle", 0, { 0, 1, 2, 3, 4 }, frameSpeed, true);
		gemArray[i]->animationController->Play("Idle");
	}

	// Initialize Player
	kid = new WarriorPlayer(FIXED_WIDTH / 2, FIXED_HEIGHT / 2);

	// Initialize Dragon
	dragon = new DragonAgent(checkExercise2, 100.0f, 100.0f);
	// Path Setup
	dragon->path = &homePath;
	dragon->loopPath = false;
	// Dragon Interface Setup
	dragon->SetReferences((DibObject*)kid, (DibObject**)gemArray, &numGem, &homePath, homePosition);
}

void BTExamState::Clean()
{
	// Free fonts
	FC_FreeFont(fontBig);
	FC_FreeFont(fontSmall);	
	FC_FreeFont(fontVerySmall);

	// Clean textures
	Texture_Free(&castleTexture);
	StaticTexture_Free(&pathTexture);

	// Clean Entities
	for (int i = 0; i < numGem; ++i)
	{
		gemArray[i]->Clean();
		delete gemArray[i];
	}
	kid->Clean();
	delete kid;
	dragon->Clean();
	delete dragon;
}

void BTExamState::Update(float deltaTime)
{
	if (Input::Instance().GetKeyDown(KeyCode::Escape))
	{
		Game::Instance().ChangeState(MENU_STATE);
		return;
	}

	HandleInput();

	//Pause management
	if (isPaused == true && runOneFrame == false)
	{
		return;
	}
	runOneFrame = false;

	// Update entities
	if (checkExercise2)
	{
		for (int i = 0; i < numGem; ++i)
		{
			gemArray[i]->Update(deltaTime);
		}
	}

	kid->Update(deltaTime);
	dragon->Update(deltaTime);
}

void BTExamState::Render()
{
	// Render Static Path
	StaticTexture_Render(&pathTexture, Game::Instance().renderer, 0, 0);

	// Render Castle
	Texture_Render(&castleTexture, Game::Instance().renderer,
		(int)homePosition.x - castleTexture.width / 2,
		(int)homePosition.y - castleTexture.height / 2);

	// Render Entities
	if (checkExercise2)
	{
		for (int i = 0; i < numGem; ++i)
		{
			gemArray[i]->Render();
		}
	}
	dragon->Render();
	kid->Render();
}

void BTExamState::HandleInput()
{
	if (Input::Instance().GetKeyDown(KeyCode::Space))
	{
		isPaused = !isPaused;
	}
	else if (Input::Instance().GetKeyDown(KeyCode::N))
	{
		if (isPaused == false)
		{
			isPaused = true;
		}
		else
		{
			runOneFrame = true;
		}
	}

	if (Input::Instance().GetKeyDown(KeyCode::C))
	{
		// Call Dragon!
		dragon->DoCall();
	}
}

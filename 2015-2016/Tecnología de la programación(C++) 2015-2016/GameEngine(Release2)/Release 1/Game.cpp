#include "Game.h"
/**
* Constructor
* Tip: You can use an initialization list to set its attributes
* @param windowTitle is the window title
* @param screenWidth is the window width
* @param screenHeight is the window height
*/
Game::Game(std::string windowTitle, int screenWidth, int screenHeight) :
	_windowTitle(windowTitle),
	_screenWidth(screenWidth),
	_screenHeight(screenHeight),
	_gameState(GameState::INIT){
}

/**
* Destructor
*/
Game::~Game()
{
}

/*
* Game execution
*/
void Game::run() {
		//Prepare the game components
	init();
		//Start the game if everything is ready
	gameLoop();
}

/*
* Initialize all the components
*/
void Game::initSprites()
{
	_graphic.loadTexture(SPRITE_FIRE, "../sharedResources/images/characters/Enemy.png");
	_graphic.loadTexture(SPRITE_ANIM, "../sharedResources/images/characters/Animation.png");
	_graphic.loadTexture(SPRITE_NPC, "../sharedResources/images/characters/NPC.png");
	_graphic.loadTexture(SPRITE_TERRAIN_1, "../sharedResources/images/terrain/grass1.bmp");
	_graphic.loadTexture(SPRITE_TERRAIN_2, "../sharedResources/images/terrain/snowibl.png");
	_graphic.loadTexture(SPRITE_MENU, "../sharedResources/images/Scenes/menu.png");
	_graphic.loadTexture(SPRITE_TITLE, "../sharedResources/images/Scenes/TitleScene.png");
	_graphic.loadTexture(SPRITE_HEART, "../sharedResources/images/characters/Hearth.png");
	_graphic.loadTexture(SPRITE_ROADLEFT, "../sharedResources/images/terrain/roadtopleft.bmp");
	_graphic.loadTexture(SPRITE_ROADDOWN, "../sharedResources/images/terrain/roadtopright.bmp");
	_graphic.loadTexture(SPRITE_ROADRIGHT, "../sharedResources/images/terrain/roadh.bmp");
	_graphic.loadTexture(SPRITE_ROADUP, "../sharedResources/images/terrain/roadv.bmp");
	_graphic.loadTexture(SPRITE_WATER, "../sharedResources/images/terrain/Water.png");
	_graphic.loadTexture(SPRITE_BOTTOM_LEFT, "../sharedResources/images/terrain/roadbottomleft.bmp");
	_graphic.loadTexture(SPRITE_BOTTOM_RIGHT, "../sharedResources/images/terrain/roadbottomright.bmp");
	_graphic.loadTexture(BULLET_SPRITE, "../sharedResources/images/characters/NPC.png");

	//OBJECT
	_graphic.loadTexture(SPRITE_EMTPY_OBJECT, "../sharedResources/images/inventory/spriteEmptyObject.png");
	_graphic.loadTexture(SPRITE_SPEED_POWERUP, "../sharedResources/images/inventory/speedPowerUp.png");
	_graphic.loadTexture(SPRITE_ADDHEART_POWERUP, "../sharedResources/images/inventory/healthPotion.png");
	_graphic.loadTexture(SPRITE_ADDATTACK_POWERUP, "../sharedResources/images/inventory/addAttackPowerUp.png");
	_graphic.loadTexture(SPRITE_HEALTHOBJECT, "../sharedResources/images/inventory/addHeartPowerUp.png");

	_graphic.loadTexture(SPRITE_TREE_ENVIRONMENT, "../sharedResources/images/inventory/treeEnvironment.png");
	_graphic.loadTexture(SPRITE_BOX_ENVIRONMENT, "../sharedResources/images/inventory/boxEnvironment.png");
	_graphic.loadTexture(SPRITE_PLANT_ENVIRONMENT, "../sharedResources/images/inventory/plantEnvironment.png");

	_graphic.loadTexture(WIN_SPRITE, "../sharedResources/images/Scenes/win.png");
	_graphic.loadTexture(LOSE_SPRITE, "../sharedResources/images/Scenes/defeat.png");

}

void Game::initObjects()
{
	srand(time_t(NULL));
	
	
	/*//Creation of the pause menu button colliders
	titleMenu.setColliders(395, 154, 35, 0);
	titleMenu.setColliders(395, 216, 35, 1);
	//Setting the background image
	titleMenu.setSprite(title);

	//Creation of the pause menu button colliders
	pauseMenu.setColliders(393, 59, 89, 0);
	pauseMenu.setColliders(391, 214, 125, 1);
	pauseMenu.setColliders(393, 352, 45, 2);
	//Setting the background image
	pauseMenu.setSprite(menu);*/
	//PRUEBAAA
	Coord<int> posit(10, 10);
	//PRUEBAAAAA
	_menuList.init();
	_map.init(_graphic);


	
}
void Game::init() {
	srand((unsigned int)time(NULL));
		//Create a window
	_graphic.createWindow(_windowTitle, _screenWidth, _screenHeight, false);	
	_graphic.setWindowBackgroundColor(255, 255, 255, 255);
	_graphic.setFontStyle(TTF_STYLE_NORMAL);
		//Load the sprites associated to the different game elements
		//Initialize the game elements
		initSprites();
		initObjects();
		//Set the font style
	
		

	
	
}


/*
* Game execution: Gets input events, processes game logic and draws sprites on the screen
*/
void Game::gameLoop() {	
	_gameState = GameState::INIT;

	while (_gameState != GameState::EXIT) {		
			//Detect keyboard and/or mouse events
		_graphic.detectInputEvents();
			//Execute the player commands 
		executePlayerCommands();
			//Update the game physics
		doPhysics();
			//Render game
		renderGame();			
	}
}

/**
* Executes the actions sent by the user by means of the keyboard and mouse
* Reserved keys:
- up | left | right | down moves the player object
- m opens the menu
*/


void Game::executePlayerCommands() {
	mainCharacterInputs();
	if (_gameState == GameState::PLAY)
	{
		_map.moveCharacterList();
		if (_map.getList().getCharacter(_map.getList().getLength() - 1)->getCharacterHealth() <= 0)
		{
			_gameState = GameState::LOSE;
		}
		if (_map.getList().getEnemyNumber() <= 0)
		{
			_gameState = GameState::WIN;
		}
	}
	scenesInputs();

}
void Game::mainCharacterInputs()
{
	Coord<int> vectorUp(0, -_map.getMainCharacter()->getVelocity());
	Coord<int> vectorDown(0, _map.getMainCharacter()->getVelocity());
	Coord<int> vectorRight(_map.getMainCharacter()->getVelocity(), 0);
	Coord<int> vectorLeft(-_map.getMainCharacter()->getVelocity(), 0);



	if (_graphic.isKeyDown(SDLK_UP))
	{

		_map.getList().getCharacter(_map.getList().getLength() -1 )->moveCharacter(vectorUp);//Movemos al jugador hacia arriba.
		if (_map.getTerrainVector().getVectorY() <= 0)
		{
			_map.changeCamera(vectorUp);
			_map.changePositionTerrain(vectorDown);
		}

	}

	if (_graphic.isKeyDown(SDLK_DOWN))
	{
		_map.getList().getCharacter(_map.getList().getLength() - 1)->moveCharacter(vectorDown);
		if (_map.getLimitVector().getVectorY() < _map.getNumberLayersY() - 1)
		{
			_map.changeCamera(vectorDown);
			_map.changePositionTerrain(vectorUp);
		}


	}

	if (_graphic.isKeyDown(SDLK_RIGHT))
	{
		_map.getList().getCharacter(_map.getList().getLength() - 1)->moveCharacter(vectorRight);
		if (_map.getLimitVector().getVectorX() < _map.getNumberLayersX() - 1)
		{

			_map.changeCamera(vectorRight);
			_map.changePositionTerrain(vectorLeft);
		}



	}

	if (_graphic.isKeyDown(SDLK_LEFT))
	{
		_map.getList().getCharacter(_map.getList().getLength() - 1)->moveCharacter(vectorLeft);

		if (_map.getTerrainVector().getVectorX() <= 0)
		{
			_map.changeCamera(vectorLeft);
			_map.changePositionTerrain(vectorRight);
		}
	}

	if (_graphic.isKeyDown(SDLK_w))
	{
		_map.getBulletList().addBullet(_map.getList().getCharacter(_map.getList().getLength() - 1)->getPosition(),vectorUp);
	}
	if (_graphic.isKeyDown(SDLK_d))
	{
		_map.getBulletList().addBullet(_map.getList().getCharacter(_map.getList().getLength() - 1)->getPosition(), vectorRight);
	}
	if (_graphic.isKeyDown(SDLK_a))
	{
		_map.getBulletList().addBullet(_map.getList().getCharacter(_map.getList().getLength() - 1)->getPosition(), vectorLeft);
	}
	if (_graphic.isKeyDown(SDLK_s))
	{
		_map.getBulletList().addBullet(_map.getList().getCharacter(_map.getList().getLength() - 1)->getPosition(), vectorDown);
	}


	_map.actualCharacterPosition(_map.getList().getCharacter(_map.getList().getLength() - 1)-> getPosition());
}
void Game::scenesInputs()
{
	//Entering to the pause screen
	if (_graphic.isKeyPressed(SDLK_SPACE)) {
		if (_gameState == GameState::PLAY)
		{
			_gameState = GameState::MENU;
		}
	}
	//Exiting the game
	if (_graphic.isKeyPressed(SDLK_ESCAPE)) {
		_gameState = GameState::EXIT;
	}

	
}


/*
* Execute the game physics
*/
void Game::doPhysics() {
		//Check if player has hit a/some monster/s
	if (_gameState == GameState::INIT) {
		
		glm::ivec2 mouseCoords = _graphic.getMouseCoords();
		//Button detection
		if (_graphic.isKeyPressed(SDL_BUTTON_LEFT)) {
			//Play button
			if (_menuList.selectAction(MENU_TITLE,0,mouseCoords.x,mouseCoords.y)) {
				
				_gameState = GameState::PLAY;
			}
			//Exit button
			if (_menuList.selectAction(MENU_TITLE, 1, mouseCoords.x, mouseCoords.y)) {
				_gameState = GameState::EXIT;
			}
		}
	}
	
	//Pause Screen functions
	if (_gameState == GameState::MENU) {
	
		glm::ivec2 mouseCoords = _graphic.getMouseCoords();
		//Button detection
		if (_graphic.isKeyPressed(SDL_BUTTON_LEFT)) {
			//Resume button
			
			if (_menuList.selectAction(MENU_PAUSE, 0, mouseCoords.x, mouseCoords.y)) {
				_gameState = GameState::PLAY;
			}
			//Main menu button
			if (_menuList.selectAction(MENU_PAUSE, 1, mouseCoords.x, mouseCoords.y)) {
				_gameState = GameState::INIT;
			}
			//Exit button
			if (_menuList.selectAction(MENU_PAUSE, 2, mouseCoords.x, mouseCoords.y)) {
				_gameState = GameState::EXIT;
			}
		}
	}
	if (_gameState == GameState::WIN || _gameState == GameState::LOSE)
	{
		glm::ivec2 mouseCoords = _graphic.getMouseCoords();
		if (_graphic.isKeyPressed(SDL_BUTTON_LEFT)) {
			if (_menuList.selectAction(MENU_WIN, 0, mouseCoords.x, mouseCoords.y) || _menuList.selectAction(MENU_LOSE, 0, mouseCoords.x, mouseCoords.y))
			{
				_gameState = GameState::INIT;
			}
		}
	}
	
}

/**
* Render the game on the screen
*/
void Game::renderGame() {
		//Clear the screen
	_graphic.clearWindow();
	if (_gameState == GameState::INIT) {
		drawSprite(_menuList.getMenu(MENU_TITLE).getSprite());
	}
		//Draw the screen's content based on the game state
	if (_gameState == GameState::MENU) {
		drawMenu();
	}

	if (_gameState == GameState::LOSE)
	{
		drawSprite(_menuList.getMenu(MENU_LOSE).getSprite());
	}
	if (_gameState == GameState::WIN)
	{
		drawSprite(_menuList.getMenu(MENU_WIN).getSprite());
	}

	if(_gameState == GameState::PLAY)
	{
		drawGame();
	}
		//Refresh screen
	_graphic.refreshWindow();
}

/*
* Draw the game menu
*/
void Game::drawMenu() {
	drawSprite(_menuList.getMenu(MENU_PAUSE).getSprite());
	
}

/*
* Draw the game, winner or loser screen
*/
void Game::drawGame()	{
		//Check if game is over
	if(_gameState == GameState::PLAY)
	_map.renderTerrain();
	//drawSprite(mainCharacter.getSprite());
	//mainCharacter.printHearts();
	
	
	
	
}

/*
* Draw the sprite on the screen
* @param sprite is the sprite to be displayed
*/
void Game::drawSprite(Sprite & sprite) {
	_graphic.drawTexture(sprite.getSpriteId(), sprite.getSpriteWidth()*sprite.getCurrentFrame(), 0, sprite.getSpriteWidth(), sprite.getSpriteHeight()
		, sprite.getXAtWorld(), sprite.getYAtWorld(), sprite.getSpriteWidth(), sprite.getSpriteHeight());
}
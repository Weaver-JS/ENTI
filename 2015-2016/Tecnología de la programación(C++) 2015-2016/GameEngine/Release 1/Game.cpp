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
	
	_graphic.loadTexture(SPRITE_ANIM, "../sharedResources/images/characters/Anim.png");
	_graphic.loadTexture(SPRITE_TERRAIN_1, "../sharedResources/images/terrain/grass1.bmp");
	_graphic.loadTexture(SPRITE_TERRAIN_2, "../sharedResources/images/terrain/snowibl.png");
	_graphic.loadTexture(SPRITE_MENU, "../sharedResources/images/Scenes/menu.png");
	_graphic.loadTexture(SPRITE_TITLE, "../sharedResources/images/Scenes/TitleScene.png");
	_graphic.loadTexture(SPRITE_HEART, "../sharedResources/images/characters/Hearth.png");
}

void Game::initObjects()
{
	title.setInitialValues(0,0,SPRITE_TITLE,WIDTH,HEIGHT,0,1);
	menu.setInitialValues(0, 0, SPRITE_MENU, WIDTH, HEIGHT, 0, 1);
	//Creation of the pause menu button colliders
	titleMenu.setColliders(395, 154, 35, 0);
	titleMenu.setColliders(395, 216, 35, 1);
	//Setting the background image
	titleMenu.setSprite(title);

	//Creation of the pause menu button colliders
	pauseMenu.setColliders(393, 59, 89, 0);
	pauseMenu.setColliders(391, 214, 125, 1);
	pauseMenu.setColliders(393, 352, 45, 2);
	//Setting the background image
	pauseMenu.setSprite(menu);

	_map.init(_graphic);
	mainCharacter.setCharacterCoords(_map.getCameraWidht() / 2, _map.getCameraHeight() / 2);
	mainCharacter.getSprite().setPositionAtWorld(mainCharacter.getXcoordCamera(), mainCharacter.getYcoordCamera());
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
void Game::mainCharacterInputs()
{
	if (_gameState == GameState::PLAY)
	{
		if (_graphic.isKeyPressed(SDL_BUTTON_LEFT)) {
			glm::ivec2 mouseCoords = _graphic.getMouseCoords();

		}

		if (_graphic.isKeyPressed(SDLK_ESCAPE)) {
			_gameState = GameState::EXIT;
		}

		if (_graphic.isKeyDown(SDLK_UP))
		{
			mainCharacter.moveCharacter(0, -mainCharacter.getVelocity());//Movemos al jugador hacia arriba.
			mainCharacter.nextAnimationframe(_graphic.getCurrentTicks());//
			if (_map.getTerrainPositionY() <= 0)// Si no nos encontramos en los límites del mapa.
			{
				_map.changeCamera(0, -mainCharacter.getVelocity());
				_map.changePositionTerrain(0, mainCharacter.getVelocity());
			}

		}

		if (_graphic.isKeyDown(SDLK_DOWN))
		{
			mainCharacter.moveCharacter(0, mainCharacter.getVelocity());
			mainCharacter.nextAnimationframe(_graphic.getCurrentTicks());
			if (_map.getLimitY() < _map.getNumberLayersY() - 1)
			{
				_map.changeCamera(0, mainCharacter.getVelocity());
				_map.changePositionTerrain(0, -mainCharacter.getVelocity());
			}

		}

		if (_graphic.isKeyDown(SDLK_RIGHT))
		{
			mainCharacter.moveCharacter(mainCharacter.getVelocity(), 0);
			mainCharacter.nextAnimationframe(_graphic.getCurrentTicks());
			if (_map.getLimitX() < _map.getNumberLayersX() - 1)
			{

				_map.changeCamera(mainCharacter.getVelocity(), 0);
				_map.changePositionTerrain(-mainCharacter.getVelocity(), 0);
			}


		}

		if (_graphic.isKeyDown(SDLK_LEFT))
		{
			mainCharacter.moveCharacter(-mainCharacter.getVelocity(), 0);

			if (_map.getTerrainPositionX() <= 0)
			{
				_map.changeCamera(-mainCharacter.getVelocity(), 0);
				_map.changePositionTerrain(mainCharacter.getVelocity(), 0);
			}
			mainCharacter.nextAnimationframe(_graphic.getCurrentTicks());
		}

		_map.actualCharacterPosition(mainCharacter.getXcoord(), mainCharacter.getYcoord());
	}
}
void Game::executePlayerCommands() {

	mainCharacterInputs();
	scenesInputs();

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
			if (titleMenu.buttons[0].onColisionEnter(mouseCoords.x, mouseCoords.y)) {
				_gameState = GameState::PLAY;
			}
			//Exit button
			if (titleMenu.buttons[1].onColisionEnter(mouseCoords.x, mouseCoords.y)) {
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
			if (pauseMenu.buttons[0].onColisionEnter(mouseCoords.x, mouseCoords.y)) {
				_gameState = GameState::PLAY;
			}
			//Main menu button
			if (pauseMenu.buttons[1].onColisionEnter(mouseCoords.x, mouseCoords.y)) {
				_gameState = GameState::INIT;
			}
			//Exit button
			if (pauseMenu.buttons[2].onColisionEnter(mouseCoords.x, mouseCoords.y)) {
				_gameState = GameState::EXIT;
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
		drawSprite(titleMenu.getSprite());
	}
		//Draw the screen's content based on the game state
	if (_gameState == GameState::MENU) {
		drawMenu();
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
	drawSprite(pauseMenu.getSprite());
}

/*
* Draw the game, winner or loser screen
*/
void Game::drawGame()	{
		//Check if game is over
	_map.renderTerrain();
	drawSprite(mainCharacter.getSprite());
	for (int i = 0; i < mainCharacter.getNumLife(); i++)
	{
		drawSprite(mainCharacter.getHealth()[i].getSprite());
	}
	
	
}

/*
* Draw the sprite on the screen
* @param sprite is the sprite to be displayed
*/
void Game::drawSprite(Sprite & sprite) {
	_graphic.drawTexture(sprite.getSpriteId(), sprite.getSpriteWidth()*sprite.getCurrentFrame(), 0, sprite.getSpriteWidth(), sprite.getSpriteHeight()
		, sprite.getXAtWorld(), sprite.getYAtWorld(), sprite.getSpriteWidth(), sprite.getSpriteHeight());
}
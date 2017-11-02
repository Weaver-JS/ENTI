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
void Game::deleteEverything()
{
	_map.destroy();
}
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
	_graphic.loadTexture(BULLET_SPRITE, "../sharedResources/images/inventory/addHeartPowerUp.png");

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

	_graphic.loadTexture(SPRITE_BASE, "../sharedResources/images/objects/Base.png");
	_graphic.loadTexture(RANKING_SPRITE, "../sharedResources/images/Scenes/Ranking.png");
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
void Game::rankingS()
{
	std::string name;
	std::cout << "Submit your name to be in the ranking :" << std::endl;
	std::getline(std::cin, name);
	rankingUser User(name, _map.getScore());
	//rankingUser User(name, 1200);
	_ranking.loadRanking();
	 _ranking.AddnsortRanking(User);

	_ranking.saveRanking();
	
	
	for (int i = 0; i < 10;i++)
	{
		std::cout << _ranking.getRanking()[i].getName()<<" " << _ranking.getRanking()[i].getScore()<<std::endl;
	}

}
void Game::init() {
	system("color 2");
	_ranking.loadRanking();
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
			rankingS();
			
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
	Coord<int> vectorUpMap(0, -_map.getMainCharacter()->getVelocity());
	Coord<int> vectorDownMap(0, _map.getMainCharacter()->getVelocity());
	Coord<int> vectorRightMap(_map.getMainCharacter()->getVelocity(), 0);
	Coord<int> vectorLeftMap(-_map.getMainCharacter()->getVelocity(), 0);
	
		_map.getList().getCharacter(_map.getList().getLength() - 1)->setCharacterTick(0);
	

	if (_graphic.isKeyDown(SDLK_UP))
	{

		_map.getList().getCharacter(_map.getList().getLength() -1 )->moveCharacter(vectorUpMap);//Movemos al jugador hacia arriba.
		if (_map.getTerrainVector().getVectorY() <= 0)
		{
			_map.changeCamera(vectorUpMap);
			_map.changePositionTerrain(vectorDownMap);
		}
		vectorUp = vectorUp * 2;
		for (int i = 0; i < _map.getBulletList().getLength();i++)
		{
	
			if (_map.getBulletList().getCharacter(i) != NULL && _map.getBulletList().getCharacter(i)->getPos().getVectorY() <= _map.getList().getCharacter(_map.getList().getLength() - 1)->getPosition().getVectorY())
			{
				_map.getBulletList().getCharacter(i)->getVelocity().setVector(vectorUp.getVectorX(), vectorUp.getVectorY());

			}
			if (_map.getBulletList().getCharacter(i) != NULL && _map.getBulletList().getCharacter(i)->getPos().getVectorY() >= _map.getList().getCharacter(_map.getList().getLength() - 1)->getPosition().getVectorY())
			{
				_map.getBulletList().getCharacter(i)->moveBullet();
			}
		}
		
		_map.getList().getCharacter(_map.getList().getLength() - 1)->setCharacterTick(1);

	}

	if (_graphic.isKeyDown(SDLK_DOWN))
	{
		_map.getList().getCharacter(_map.getList().getLength() - 1)->moveCharacter(vectorDownMap);
		if (_map.getLimitVector().getVectorY() < _map.getNumberLayersY() - 1)
		{
			_map.changeCamera(vectorDownMap);
			_map.changePositionTerrain(vectorUpMap);
		}
		vectorDown = vectorDown * 2;
		for (int i = 0; i < _map.getBulletList().getLength(); i++)
		{


			if (_map.getBulletList().getCharacter(i) != NULL && _map.getBulletList().getCharacter(i)->getPos().getVectorY() >= _map.getList().getCharacter(_map.getList().getLength() - 1)->getPosition().getVectorY())
			{
				_map.getBulletList().getCharacter(i)->getVelocity().setVector(vectorDown.getVectorX(), vectorDown.getVectorY());

			}
			if (_map.getBulletList().getCharacter(i) != NULL && _map.getBulletList().getCharacter(i)->getPos().getVectorY() <= _map.getList().getCharacter(_map.getList().getLength() - 1)->getPosition().getVectorY())
			{
				_map.getBulletList().getCharacter(i)->moveBullet();
			}
		}

		_map.getList().getCharacter(_map.getList().getLength() - 1)->setCharacterTick(0);
	}

	if (_graphic.isKeyDown(SDLK_RIGHT))
	{

		_map.getList().getCharacter(_map.getList().getLength() - 1)->moveCharacter(vectorRightMap);
		if (_map.getLimitVector().getVectorX() < _map.getNumberLayersX() - 1)
		{

			_map.changeCamera(vectorRightMap);
			_map.changePositionTerrain(vectorLeftMap);
		}
		vectorRight = vectorRight * 2;
		
		for (int i = 0; i < _map.getBulletList().getLength(); i++)
		{
			if (_map.getBulletList().getCharacter(i) != NULL && _map.getBulletList().getCharacter(i)->getPos().getVectorX() >= _map.getList().getCharacter(_map.getList().getLength() - 1)->getPosition().getVectorX())
			{
				_map.getBulletList().getCharacter(i)->getVelocity().setVector(vectorRight.getVectorX(), vectorRight.getVectorY());
			
			}
			if (_map.getBulletList().getCharacter(i) != NULL && _map.getBulletList().getCharacter(i)->getPos().getVectorX() <= _map.getList().getCharacter(_map.getList().getLength() - 1)->getPosition().getVectorX())
			{
				_map.getBulletList().getCharacter(i)->moveBullet();
			}
			//_map.getBulletList().getCharacter(i)->moveBullet();
		}
		/*for (int i = 0; i < _map.getBulletList().getLength(); i++)
		{
			
			if (_map.getBulletList().getCharacter(i) != NULL && _map.getBulletList().getCharacter(i)->getPos().getVectorX() >= _map.getList().getCharacter(_map.getList().getLength() - 1)->getPosition().getVectorX())
			{
				_map.getBulletList().getCharacter(i)->moveBullet();
			}
		}*/

		_map.getList().getCharacter(_map.getList().getLength() - 1)->setCharacterTick(2);

	}

	if (_graphic.isKeyDown(SDLK_LEFT))
	{
		_map.getList().getCharacter(_map.getList().getLength() - 1)->moveCharacter(vectorLeftMap);

		if (_map.getTerrainVector().getVectorX() <= 0)
		{
			_map.changeCamera(vectorLeftMap);
			_map.changePositionTerrain(vectorRightMap);
		}
		vectorLeft = vectorLeft * 2;

		for (int i = 0; i < _map.getBulletList().getLength(); i++)
		{
			if (_map.getBulletList().getCharacter(i) != NULL && _map.getBulletList().getCharacter(i)->getPos().getVectorX() <= _map.getList().getCharacter(_map.getList().getLength() - 1)->getPosition().getVectorX())
			{
				_map.getBulletList().getCharacter(i)->getVelocity().setVector(vectorLeft.getVectorX(), vectorLeft.getVectorY());

			}
			if (_map.getBulletList().getCharacter(i) != NULL && _map.getBulletList().getCharacter(i)->getPos().getVectorX() >= _map.getList().getCharacter(_map.getList().getLength() - 1)->getPosition().getVectorX())
			{
				_map.getBulletList().getCharacter(i)->moveBullet();
			}
			//_map.getBulletList().getCharacter(i)->moveBullet();
		}
		/*for (int i = 0; i < _map.getBulletList().getLength(); i++)
		{
			
			if (_map.getBulletList().getCharacter(i) != NULL && _map.getBulletList().getCharacter(i)->getPos().getVectorX() <= _map.getList().getCharacter(_map.getList().getLength() - 1)->getPosition().getVectorX())
			{
				_map.getBulletList().getCharacter(i)->moveBullet();
		}
		}*/
		_map.getList().getCharacter(_map.getList().getLength() - 1)->setCharacterTick(3);
	}
	

	if (_graphic.isKeyPressed(SDLK_q))
	{
		_map.copyMap();
	}
	if (_graphic.isKeyPressed(SDLK_f))
	{
	/*	Coord<int> c = _map.getTerrainVector();
		c.setVector(c.getVectorX() / SPRITE_DEFAULT_WIDTH,c.getVectorY()/SPRITE_DEFAULT_HEIGHT);
		_map.placeWater(c.getVectorX()  - 1, c.getVectorY()  - 1, c.getVectorX() + 1, c.getVectorY() + 1,false);
		//_map.placeWater(5, 5, 8, 8, false);*/
	}
	if (_graphic.isKeyPressed(SDLK_e))
	{
		_map.changeEnemybool();
		
	}

	if (_graphic.isKeyPressed(SDLK_w))
	{
		
		_map.getBulletList().addBullet(_map.getList().getCharacter(_map.getList().getLength() - 1)->getPosition(),vectorUp);
	}
	if (_graphic.isKeyPressed(SDLK_d))
	{
		_map.getBulletList().addBullet(_map.getList().getCharacter(_map.getList().getLength() - 1)->getPosition(), vectorRight);
	}
	if (_graphic.isKeyPressed(SDLK_a))
	{
		_map.getBulletList().addBullet(_map.getList().getCharacter(_map.getList().getLength() - 1)->getPosition(), vectorLeft);
	}
	if (_graphic.isKeyPressed(SDLK_s))
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
				
				//
				
				_gameState = GameState::PLAY;
			}
			if (_menuList.selectAction(MENU_TITLE, 1, mouseCoords.x, mouseCoords.y))
			{
				_map.destroy();
				_map.initAfterLoad();
				_map.loadMap();
				_gameState = GameState::PLAY;
			}
			//Exit button
			if (_menuList.selectAction(MENU_TITLE, 2, mouseCoords.x, mouseCoords.y)) {
				_gameState = GameState::EXIT;
			}
			if (_menuList.selectAction(MENU_TITLE, 3, mouseCoords.x, mouseCoords.y))
			{
				
				_gameState = GameState::RANKING;
			}
		}
	}
	else if (_gameState == GameState::RANKING)
	{
		glm::ivec2 mouseCoords = _graphic.getMouseCoords();
		if (_graphic.isKeyPressed(SDL_BUTTON_LEFT))
		{
			if (_menuList.selectAction(MENU_RANKING, 0, mouseCoords.x, mouseCoords.y))
			{
				_gameState = GameState::INIT;
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
					_map.destroy();
					_map.initAfterLoad();
					_map.init(_graphic);
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
				_map.destroy();
				_map.initAfterLoad();
				_map.init(_graphic);
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
	if(_gameState == GameState::INIT) {
		drawSprite(_menuList.getMenu(MENU_TITLE).getSprite());
		_graphic.drawText("Play", WHITE, WHITE, WIDTH / 2 - 25, HEIGHT / 2 + 120);
		_graphic.drawText("Load Game", WHITE, WHITE, WIDTH / 2 - 65, HEIGHT / 2 + 150);
		_graphic.drawText("Exit", WHITE, WHITE, WIDTH / 2 - 20, HEIGHT / 2 + 180);
		_graphic.drawText("Ranking", WHITE, WHITE, LIMITX - 30, LIMITY + 45);
		glm::ivec2 mouseCoords = _graphic.getMouseCoords();

		if (_menuList.selectAction(MENU_TITLE, 0, mouseCoords.x, mouseCoords.y))
		{
			
				_graphic.drawText("Play", RED, RED, WIDTH / 2 - 25, HEIGHT / 2 + 120);
			
		}
		if (_menuList.selectAction(MENU_TITLE, 1, mouseCoords.x, mouseCoords.y))
		{
			
				_graphic.drawText("Load Game", RED, RED, WIDTH / 2 - 65, HEIGHT / 2 + 150);
			
		}

		if (_menuList.selectAction(MENU_TITLE, 2, mouseCoords.x, mouseCoords.y))
		{
			_graphic.drawText("Exit", RED, RED, WIDTH / 2 - 20, HEIGHT / 2 + 180);
		}

		if (_menuList.selectAction(MENU_TITLE, 3, mouseCoords.x, mouseCoords.y))
		{
			_graphic.drawText("Ranking", RED, RED, LIMITX - 30, LIMITY + 45);
		}
	}
		//Draw the screen's content based on the game state
	if (_gameState == GameState::MENU) {
		drawMenu();
	}
	if (_gameState == GameState::RANKING)
	{
		drawSprite(_menuList.getMenu(MENU_RANKING).getSprite());

		std::string _name;
		std::string _score;
		int scoreP;
		int sumDistance = 120;
		for (int i = 0; i < 10;i++)
		{

			
				_name = _ranking.getRankingUser(i).getName();
				scoreP = _ranking.getRankingUser(i).getScore();
				_score = std::to_string(scoreP);
				_graphic.drawText(_name, WHITE, WHITE, 100, sumDistance);
				_graphic.drawText(_score, WHITE, WHITE, 600, sumDistance);
				sumDistance += 30;
			
		
	
			

		}
	_graphic.drawText("Exit", WHITE, WHITE, LIMITX, LIMITY + 50);

		
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
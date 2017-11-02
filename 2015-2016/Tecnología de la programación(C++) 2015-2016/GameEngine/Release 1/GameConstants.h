#pragma once

//Game general information
#define GAME_SPEED 0.1f
#define GAME_TEXTURES 2

#define LIMITX WIDTH - 80
#define LIMITY HEIGHT- 80
//Sprite information
#define SPRITE_SPEED 0.01f
#define SPRITE_DEFAULT_WIDTH 64	
#define SPRITE_DEFAULT_HEIGHT 64
#define SPRITE_HERO 0
#define SPRITE_FIRE 1
#define SPRITE_TERRAIN_1 2
#define SPRITE_TERRAIN_2 3
#define SPRITE_ANIM 5
#define SPRITE_TITLE 6
#define SPRITE_MENU 7
#define SPRITE_HEART 8
#define layerNum 2

//Color information
#define GAME_BASIC_COLORS 5
#define RED 0
#define GREEN 1
#define BLUE 2
#define BLACK 3
#define WHITE 4

//Window WIDTH HEIGHT
#define WIDTH 800
#define HEIGHT 450






//Game has four possible states: INIT (Preparing environment), PLAY (Playing), EXIT (Exit from the game) or MENU (Game menu)
enum class GameState{ INIT, PLAY, EXIT, MENU };


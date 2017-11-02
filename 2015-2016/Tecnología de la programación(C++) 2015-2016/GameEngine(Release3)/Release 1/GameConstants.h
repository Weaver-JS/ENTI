#pragma once

//Game general information
#define GAME_SPEED 0.005f
#define GAME_TEXTURES 30
#define ENEMY_NUMBER 5
#define NPC_NUMBER 1
#define LIMITX WIDTH - 80
#define LIMITY HEIGHT- 80
//Sprite information
#define SPRITE_SPEED 0.01f
#define SPRITE_DEFAULT_WIDTH 64	
#define SPRITE_DEFAULT_HEIGHT 64
#define SPRITE_FIRE 0//0
#define SPRITE_ANIM 1//1
#define SPRITE_NPC 2//2
#define SPRITE_TERRAIN_1 3//3
#define SPRITE_TERRAIN_2 4//4
#define SPRITE_MENU 5//5
#define SPRITE_TITLE 6//6
#define SPRITE_HEART 7//7
#define SPRITE_ROADLEFT 8//14
#define SPRITE_ROADDOWN 9//9
#define SPRITE_ROADRIGHT 10//13
#define SPRITE_ROADUP 11//8
#define SPRITE_WATER 12//12
#define SPRITE_BOTTOM_LEFT 13//10
#define SPRITE_BOTTOM_RIGHT 14//11



#define NPC_WIDTH 24
#define NPC_HEIGHT 32



#define layerNum 3
#define LAYERLENGTH 50
//Hearts
#define initialNumHearts 3
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

//MENU NUMBERS
#define NUM_SCENES 5
#define MENU_TITLE 0
#define MENU_PAUSE 1
#define MENU_WIN 2
#define MENU_LOSE 3
#define MENU_RANKING 4


#define SPRITE_SPEED_POWERUP 16
#define SPRITE_ADDHEART_POWERUP 17
#define SPRITE_ADDATTACK_POWERUP 18
//Environment
#define SPRITE_TREE_ENVIRONMENT 21
#define SPRITE_BOX_ENVIRONMENT 22
#define SPRITE_PLANT_ENVIRONMENT 23
#define TREE_WIDTH 128
#define TREE_HEIGHT 128
#define ENVIRONMENT_WIDTH 64
#define ENVIRONMENT_HEIGTH 64
#define POWER_UP_NUM 5
#define ENVIRONMENT_OBJECT_NUM 0
#define HEALTH_OBJECT_NUM 0
#define TOTAL_OBJECTS HEALTH_OBJECT_NUM+ENVIRONMENT_OBJECT_NUM+POWER_UP_NUM
//healthObject
#define SPRITE_HEALTHOBJECT 24
//Inventory
#define SPRITE_EMTPY_OBJECT 25
#define INVENTORY_X_POSITION WIDTH -500
#define INVENTORY_Y_POSITION HEIGHT-32
#define INVENTORY_WIDTH 32
#define INVENTORY_HEIGHT 32

#define ENEMY_WIDTH 45
#define ENEMY_HEIGHT 46
 
#define MainCharacter_WIDTH 32
#define MainCharacter_HEIGHT 39

#define BULLET_SPRITE 26

#define WIN_SPRITE 27
#define LOSE_SPRITE 28
#define RANKING_SPRITE 30
#define SPRITE_BASE 29
#define BASE_WIDTH 274
#define Base_Height 250


//Game has four possible states: INIT (Preparing environment), PLAY (Playing), EXIT (Exit from the game) or MENU (Game menu)
enum class GameState{ INIT, PLAY, EXIT, MENU,WIN,LOSE,RANKING};
enum class enemyState { ATTACKBASE, ATTACKPLAYER, WALK };

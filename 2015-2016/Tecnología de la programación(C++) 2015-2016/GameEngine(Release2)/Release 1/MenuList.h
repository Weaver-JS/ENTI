#pragma once
#include "MenuButtons.h"
#include "GameConstants.h"
class MenuList
{
	/*
	Lista de MenuButtons
	se encarga de gestionar las diferentes escenas que hay en el juego.
	*/
private:
	int currentMenu;
	MenuButtons scenes[NUM_SCENES];
	Sprite menu;
	Sprite title;
	Sprite win;
	Sprite lose;
public:
	MenuList();
	~MenuList();
	void init();
	MenuButtons getMenu(int menuID);
	bool selectAction(int menuID, int colliderNum, int x, int y);
};


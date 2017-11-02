#include "MenuList.h"



MenuList::MenuList()
{

}


MenuList::~MenuList()
{
}

void MenuList::init()
{
	title.setInitialValues(0, 0, SPRITE_TITLE, WIDTH, HEIGHT, 0, 1);
	menu.setInitialValues(0, 0, SPRITE_MENU, WIDTH, HEIGHT, 0, 1);
	win.setInitialValues(0, 0, WIN_SPRITE, WIDTH, HEIGHT, 0, 1);
	lose.setInitialValues(0, 0, LOSE_SPRITE, WIDTH, HEIGHT, 0, 1);
	Ranking.setInitialValues(0, 0, RANKING_SPRITE, WIDTH, HEIGHT, 0, 1);
	
		scenes[MENU_TITLE] = MenuButtons(4);
		scenes[MENU_PAUSE] = MenuButtons(3);
		scenes[MENU_WIN] = MenuButtons(1);
		scenes[MENU_LOSE] = MenuButtons(1);
		scenes[MENU_RANKING] = MenuButtons(1);
	
	scenes[MENU_TITLE].setNumColliders(4);//= MenuButtons(2);
	scenes[MENU_PAUSE].setNumColliders(3); //= MenuButtons(3);
	scenes[MENU_RANKING].setNumColliders(1);

	//Creation of the pause menu button colliders
	scenes[MENU_TITLE].setColliders(WIDTH / 2 - 25, HEIGHT / 2 + 120, 20, 0);
	scenes[MENU_TITLE].setColliders(WIDTH / 2 - 25, HEIGHT / 2 + 150,20, 1);
	scenes[MENU_TITLE].setColliders(WIDTH / 2 - 20, HEIGHT / 2 + 180,20, 2);
	scenes[MENU_TITLE].setColliders(LIMITX, LIMITY + 45, 50, 3);
	//Setting the background image
	scenes[MENU_TITLE].setSprite(title);

	//Creation of the pause menu button colliders
	scenes[MENU_PAUSE].setColliders(393, 59, 89, 0);
	scenes[MENU_PAUSE].setColliders(391, 214, 125, 1);
	scenes[MENU_PAUSE].setColliders(393, 352, 45, 2);
	//Setting the background image
	scenes[MENU_PAUSE].setSprite(menu);

	scenes[MENU_WIN].setNumColliders(1);
	scenes[MENU_WIN].setColliders(WIDTH / 2, HEIGHT / 2, 60, 0);
	scenes[MENU_WIN].setSprite(win);

	scenes[MENU_LOSE].setNumColliders(1);
	scenes[MENU_LOSE].setColliders(WIDTH / 2, HEIGHT / 2, 60, 0);
	scenes[MENU_LOSE].setSprite(lose);

	scenes[MENU_RANKING].setColliders(LIMITX, LIMITY + 50, 50, 0);
	scenes[MENU_RANKING].setSprite(Ranking);
}

MenuButtons  MenuList::getMenu(int menuID)
{
	return scenes[menuID];
}



bool MenuList::selectAction(int menuID, int colliderNum, int x, int y)
{

	if (scenes[menuID].buttons[colliderNum].onColisionEnter(x, y))
	{
		return true;
	}
	
	return false;
}

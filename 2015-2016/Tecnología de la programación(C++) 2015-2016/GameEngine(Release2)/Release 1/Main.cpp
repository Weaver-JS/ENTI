#include "Game.h"
#include "Array.h"

int main(int argc, char ** argv) {
	
	
	Game game("GameEngine Cutre Edition", WIDTH, HEIGHT);

	try {
		game.run();
	}
	catch (std::exception e) {
		std::cerr << "ERROR: " << e.what() << std::endl;
	}

	return 0;
}
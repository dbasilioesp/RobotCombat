#include "Game.h"

int main(int argc, char* argv[])
{
	srand(time(0));
	
	Game game;

	game.initialize();
	game.play();
	game.finalize();

	return 0;
}
#include "Game.h"

Game *game = nullptr;

int main() {


	game = new Game();
	game->init("GameWindow", 800, 600, false);

	while (game->running()) {
		game->handleEvents();
		game->update();
		game->render();
	}

	game->clean();
	return 0;
}
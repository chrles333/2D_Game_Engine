#include "Game.h"

Game *game = nullptr;

int main(int argc, char *argv[]) {
	game = new Game();
	game->init("GameWindow", 800, 600, false);

	// While game is running
	while (game->running()) {
		game->handleEvents(); // Handle any user input
		game->update(); // Update all objects e.g. positions
		game->render(); // Render changes to the display
	}

	// Free resources
	game->clean();
	return 0;
}
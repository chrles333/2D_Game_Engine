#include "Game.h"

Game *game = nullptr;

int main(int argc, char *argv[]) {
	const int FPS = 60; // Set target framerate
	const int frameDelay = 1000 / FPS; // How long frame is meant to take

	// To know game time and how long we have been running the game
	Uint32 frameStart; // Maybe use float here instead
	int frameTime;

	game = new Game();
	game->init("GameWindow", 800, 640, false);

	// While game is running
	while (game->running()) {
		// Get current running time (milliseconds)
		frameStart = SDL_GetTicks();

		game->handleEvents(); // Handle any user input
		game->update(); // Update all objects e.g. positions
		game->render(); // Render changes to the display

		frameTime = SDL_GetTicks() - frameStart; // Time taken for frame

		// Check if we need to delay next frame
		if (frameDelay > frameTime) {
			SDL_Delay(frameDelay - frameTime);
		}
	}

	// Free resources
	game->clean();
	return 0;
}
#pragma once

#include "SDL.h"
#include "SDL_image.h"
#include <iostream>

class Game {
public:
	// Constructor
	Game();

	// Destructor
	~Game();


	void init(const char* title, int width, int height, bool fullscreen);

	void handleEvents(); // Handle any user input
	void update(); // Update all objects e.g. positions
	void render(); // Render changes to the display window
	void clean(); // Memory management

	bool running() { return isRunning; } // Return current state of game

	static SDL_Renderer* renderer; // To avoid creating copies of the same pointer
	static SDL_Event event;

private:
	bool isRunning = false;
	int cnt = 0;
	SDL_Window *window;
};
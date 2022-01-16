#include "Game.h"
#include "TextureManager.h"
#include "GameObject.h"

GameObject *player;
GameObject* enemy;

Game::Game()
{}

Game::~Game()
{}

void Game::init(const char* title, int width, int height, bool fullscreen) {
	int flags = 0;
	
	if (fullscreen) {
		flags = SDL_WINDOW_FULLSCREEN;
	}

	// If succesfully initialised SDL subsystems
	if (SDL_Init(SDL_INIT_EVERYTHING) == 0) {
		window = SDL_CreateWindow(title, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, flags);
		renderer = SDL_CreateRenderer(window, -1, 0);
		if (renderer) {
			SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
		}

		isRunning = true;
	} else {
		isRunning = false;
	}

	// Create new game objects
	player = new GameObject("assets/player.png", renderer, 0, 0);
	enemy = new GameObject("assets/enemy.png", renderer, 50, 50);
}

void Game::handleEvents() {
	SDL_Event event;
	SDL_PollEvent(&event);

	// Check if user closed window
	switch (event.type) {
		case SDL_QUIT :
			isRunning = false;
			break;
		default:
			break;
	}
}

void Game::update() {
	player->update();
	enemy->update();
}

void Game::render() {
	SDL_RenderClear(renderer);

	// Add stuff to do
	// Render in players
	player->render();
	enemy->render();

	SDL_RenderPresent(renderer);
}

void Game::clean() {
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
	SDL_Quit();
}
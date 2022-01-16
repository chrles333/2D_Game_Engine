#include "Game.h"
#include "TextureManager.h"
#include "Map.h"
#include "ECS/Components.h"

Map *map;
Manager manager;

SDL_Renderer *Game::renderer = nullptr;
auto& player(manager.addEntity());

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

	// Create new map (default full of water)
	map = new Map();

	// Add position component to new player
	player.addComponent<PositionComponent>(100, 100);
	player.addComponent<SpriteComponent>("assets/player.png");
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
	manager.refresh();
	manager.update(); // Update all entities -> updates all components

	// For fun
	if (player.getComponent<PositionComponent>().x() > 100) {
		player.getComponent<SpriteComponent>().setTex("assets/enemy.png");
	}
}

void Game::render() {
	SDL_RenderClear(renderer);

	// Render map
	map->drawMap();
	manager.draw();

	SDL_RenderPresent(renderer);
}

void Game::clean() {
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
	SDL_Quit();
}
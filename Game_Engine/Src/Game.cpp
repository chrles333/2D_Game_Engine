#include "Game.h"
#include "TextureManager.h"
#include "Map.h"
#include "ECS/Components.h"
#include "Vector2D.h"
#include "Collision.h"

Map *map;
Manager manager;

SDL_Renderer *Game::renderer = nullptr;
SDL_Event Game::event;

std::vector<ColliderComponent*> Game::colliders;

auto& player(manager.addEntity());
auto& wall(manager.addEntity());

// Various tiles
auto& tile0(manager.addEntity());
auto& tile1(manager.addEntity());
auto& tile2(manager.addEntity());

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

	tile0.addComponent<TileComponent>(200, 200, 32, 32, 0); // Water
	tile1.addComponent<TileComponent>(250, 250, 32, 32, 1); // Dirt
	// Add collision component to dirt tile
	tile1.addComponent<ColliderComponent>("dirt");
	tile2.addComponent<TileComponent>(150, 150, 32, 32, 2); // Grass
	// Add collision component to grass tile
	tile2.addComponent<ColliderComponent>("grass");

	// Add transform component to new player
	player.addComponent<TransformComponent>(2);
	// Add sprite component to entity
	player.addComponent<SpriteComponent>("assets/player.png");
	// Add keyboard controller component to entity
	player.addComponent<KeyboardController>();
	// Add collider component to entity
	player.addComponent<ColliderComponent>("player");

	// Place wall and set dimensions
	wall.addComponent<TransformComponent>(300.0f, 300.0f, 300, 20, 1);
	// Add sprite component to wall to see it in game window
	wall.addComponent<SpriteComponent>("assets/dirt.png");
	wall.addComponent<ColliderComponent>("wall");
}

void Game::handleEvents() {
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

	// Check for collision
	for (auto cc : colliders) {
		Collision::AABB(player.getComponent<ColliderComponent>(), *cc);
	}
}

void Game::render() {
	SDL_RenderClear(renderer);

	// Render map
	//map->drawMap();
	manager.draw();

	SDL_RenderPresent(renderer);
}

void Game::clean() {
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
	SDL_Quit();
}
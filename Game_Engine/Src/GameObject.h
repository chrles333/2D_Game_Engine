#pragma once
#include "Game.h"

class GameObject {
public:
	// Constructor
	GameObject(const char* textureSheet, SDL_Renderer* ren, int x, int y);

	// Destructor
	~GameObject();

	void update();
	void render();

private:
	// Position on screen
	int xpos;
	int ypos;

	// Drawing on window
	SDL_Texture* objTexture;

	// Display
	SDL_Rect srcRect, destRect;
	SDL_Renderer* renderer;
};
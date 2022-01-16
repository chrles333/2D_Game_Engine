#include "GameObject.h"
#include "TextureManager.h"

GameObject::GameObject(const char* textureSheet, int x, int y) {
	// Create game object for player
	objTexture = TextureManager::LoadTexture(textureSheet);

	// Initialise starting position
	xpos = x;
	ypos = y;
}

void GameObject::update() {
	// Update position
	xpos++; // Move diagonal for test rn
	ypos++;

	srcRect.h = 300;
	srcRect.w = 600;
	srcRect.x = 0;
	srcRect.y = 0;

	destRect.x = xpos;
	destRect.y = ypos;
	destRect.w = srcRect.w;
	destRect.h = srcRect.h;


}

void GameObject::render() {
	// Render texture
	SDL_RenderCopy(Game::renderer, objTexture, &srcRect, &destRect);
}
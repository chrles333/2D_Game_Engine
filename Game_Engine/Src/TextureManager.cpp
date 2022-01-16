#include "TextureManager.h"

SDL_Texture* TextureManager::LoadTexture(const char* texture) {
	// Generate a texture

	// Create a surface
	SDL_Surface* tempSurface = IMG_Load(texture);
	// Create texture
	SDL_Texture* tex = SDL_CreateTextureFromSurface(Game::renderer, tempSurface);
	// Free the surface
	SDL_FreeSurface(tempSurface);

	return tex;
}
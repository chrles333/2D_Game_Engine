#pragma once

#include "Game.h"

class TextureManager {
public:
	// Want to be able to call this without instantiating an obj
	static SDL_Texture* LoadTexture(const char* texture, SDL_Renderer* ren);
};
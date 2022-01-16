#pragma once
#include "Game.h"

class Map {
public:
	// Constructor
	Map();

	// Destructor
	~Map();

	void loadMap(int arr[20][25]);
	void drawMap();

private:
	SDL_Rect src, dest;

	SDL_Texture *dirt;
	SDL_Texture *grass;
	SDL_Texture *water;

	// 2d int array to hold the map
	int map[20][25]; // Might change later
};
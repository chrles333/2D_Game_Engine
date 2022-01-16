#pragma once

#include "Components.h"
#include "../Vector2D.h"

// Will hold position, rotation and scale component

class TransformComponent : public Component {
public:
	Vector2D position;
	Vector2D velocity;

	int height = 32;
	int width = 32;
	int scale = 1;

	// Default speed of player movement
	int speed = 3;

	// Constructors
	// Default starting pos
	TransformComponent() {
		// Maybe add 0 method in vector class to clean up this code
		position.x = 0.0f;
		position.y = 0.0f;
	}

	TransformComponent(int sc) {
		position.x = 0.0f;
		position.y = 0.0f;
		scale = sc;
	}

	// Initialise starting position
	TransformComponent(float x, float y) {
		position.x = x;
		position.y = y;
	}

	TransformComponent(float x, float y, int h, int w, int sc) {
		position.x = x;
		position.y = y;
		height = h;
		width = w;
		scale = sc;
	}

	void init() override {
		velocity.x = 0;
		velocity.y = 0;
	}

	void update() override {
		position.x += velocity.x * speed;
		position.y += velocity.y * speed;
	}
};
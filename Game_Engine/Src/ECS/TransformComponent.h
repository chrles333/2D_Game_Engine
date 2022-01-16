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
		// Set values to 0
		position.Zero();
	}

	TransformComponent(int sc) {
		position.Zero();
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
		velocity.Zero();
	}

	void update() override {
		position.x += velocity.x * speed;
		position.y += velocity.y * speed;
	}
};
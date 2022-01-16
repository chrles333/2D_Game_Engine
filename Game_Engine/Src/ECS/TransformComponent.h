#pragma once

#include "Components.h"
#include "../Vector2D.h"

// Will hold position, rotation and scale component

class TransformComponent : public Component {
public:
	Vector2D position;

	// Constructors
	// Default starting pos
	TransformComponent() {
		position.x = 0.0f;
		position.y = 0.0f;
	}

	// Initialise starting position
	TransformComponent(float x, float y) {
		position.x = x;
		position.y = y;
	}

	void update() override {
		
	}
};
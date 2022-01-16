#pragma once

#include <string>
#include "SDL.h"
#include "Components.h"

/*
 * Allows for representation of area that is collidable on the map
 */

class ColliderComponent : public Component {
public:
	// Collider dimensions
	SDL_Rect collider;

	// Tagging system for future use:
	// Can grab tag from objects we collide with to find out specifics of collided object
	// Can later attach specific actions that are triggered for specific tags
	// E.g. attack action for 'enemy' tag
	std::string tag;

	TransformComponent *transform;

	ColliderComponent(std::string t) {
		tag = t;
	}

	void init() override {
		// Error check before getting component from entity
		// Need to check for transform component to add any other component that relised on transform component
		if (!entity->hasComponent<TransformComponent>()) {
			entity->addComponent<TransformComponent>();
		}
		transform = &entity->getComponent<TransformComponent>();
	}

	void update() override {
		// Set collider position to origin, width & height are scaled
		collider.x = static_cast<int>(transform->position.x);
		collider.y = static_cast<int>(transform->position.y);
		collider.w = transform->width * transform->scale;
		collider.h = transform->height * transform->scale;
	}
};
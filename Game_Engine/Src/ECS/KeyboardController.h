#pragma once


#include "../Game.h"
#include "ECS.h"
#include "Components.h"

class KeyboardController : public Component {
public:
	// Need access to transform component on the entity
	TransformComponent *transform;

	void init() override {
		transform = &entity->getComponent<TransformComponent>();
	}

	// Need to normalise vectors later on to maintain constant speed

	// Check for input key
	void update() override {
		// When key is pressed
		if (Game::event.type == SDL_KEYDOWN) {
			// Based on WASD
			switch (Game::event.key.keysym.sym) {
			case SDLK_w:
				// If 'w' is pressed
				transform->velocity.y = -1; // '-' to position.y
				break;
			case SDLK_a:
				// If 'a' is pressed
				transform->velocity.x = -1; // '-' to position.x
				break;
			case SDLK_d:
				// If 'd' is pressed
				transform->velocity.x = 1; // '+' to position.x
				break;
			case SDLK_s:
				// If 's' is pressed
				transform->velocity.y = 1; // '+' to position.y
				break;
			default:
				break;
			}
		}

		// When key is released
		if (Game::event.type == SDL_KEYUP) {
			// Reset respective velocity axis back to 0
			switch (Game::event.key.keysym.sym) {
			case SDLK_w:
				// If 'w' is released
				transform->velocity.y = 0;
				break;
			case SDLK_a:
				// If 'a' is released
				transform->velocity.x = 0;
				break;
			case SDLK_d:
				// If 'd' is released
				transform->velocity.x = 0;
				break;
			case SDLK_s:
				// If 's' is released
				transform->velocity.y = 0;
				break;
			default:
				break;
			}
		}
	}
};
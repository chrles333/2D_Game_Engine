#pragma once

#include "SDL.h"

class ColliderComponent;

/*
 * Implements axis aligned bounding box (AABB) collision detection
 * - Checks x and y position of each rectangle and determines whether they are coliding based
 *	 on their bounds
 */
class Collision {
public:
	// For SDL_Rect
	static bool AABB(const SDL_Rect& recA, const SDL_Rect& recB);

	// For Collider objects
	static bool AABB(const ColliderComponent& colA, const ColliderComponent& colB);
};
#include "Collision.h"
#include "ECS\ColliderComponent.h"

bool Collision::AABB(const SDL_Rect& recA, const SDL_Rect& recB) {
	// Check x and y bounds in both rectangles for any collision
	if (
		recA.x + recA.w >= recB.x &&
		recB.x + recB.w >= recA.x &&
		recA.y + recA.h >= recB.y &&
		recB.y + recB.h >= recA.y
		) {
		return true; // Yes collision
	}

	return false; // No collision
}

bool Collision::AABB(const ColliderComponent& colA, const ColliderComponent& colB) {
	if (AABB(colA.collider, colB.collider)) {
		std::cout << colA.tag << " hit: " << colB.tag << std::endl; // For testing
		return true; // Yes collision
	}

	return false; // No collision
}
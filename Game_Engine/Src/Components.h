#pragma once
#include "ECS.h"

// Will eventually create separate class for each component
class PositionComponent : public Component {
private:
	int xpos;
	int ypos;

public:
	// Getter functions
	int x() { return xpos; }
	int y() { return ypos; }

	// Will call as soon as it obj is insantiated
	void init() override {
		xpos = 0;
		ypos = 0;
	}

	void update() override {
		xpos++;
		ypos++;
	}

	// Setter functions
	void setPos(int x, int y) {
		xpos = x;
		ypos = y;
	}
};
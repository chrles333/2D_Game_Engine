#pragma once

#include "Components.h"

class PositionComponent : public Component {
private:
	int xpos;
	int ypos;

public:
	// Constructors
	// Default starting pos
	PositionComponent() {
		xpos = 0;
		ypos = 0;
	}

	// Initialise starting position
	PositionComponent(int x, int y) {
		xpos = x;
		ypos = y;
	}

	// Getter functions
	int x() { return xpos; }
	int y() { return ypos; }

	// Setter functions
	void x(int x) { xpos = x; }
	void y(int y) { ypos = y; }
	void setPos(int x, int y) {
		xpos = x;
		ypos = y;
	}

	// Will call as soon as it obj is insantiated
	void init() override {
		xpos = 0;
		ypos = 0;
	}

	void update() override {
		xpos++;
		ypos++;
	}
};
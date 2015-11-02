#pragma once

#include <vector>
#include "Gamepad.h"

using namespace std;

class Player
{
public:
	Player(int, int, int, vector<Vector2>, Gamepad);

	void Update();
	void Draw();

	int red,
		green,
		blue;
	float throttle,
		  friction;
	Vector2 location,
			velocity;
	vector<Vector2> shape;
	Gamepad gamepad;
};
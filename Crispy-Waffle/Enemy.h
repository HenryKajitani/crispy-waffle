#pragma once

#include <Windows.h>
#include <vector>
#include "Vector2.h"

using namespace std;

class Enemy
{
public:
	Enemy();
	Enemy(float, float, float, Vector2, Vector2, float, int, POINT, POINT);

	void update();
	void draw();

	Vector2 location,
			velocity,
			target;
	float friction,
		  maxSpeed,
		  range,
		  pointValue;
	float red,
		  green,
		  blue;
	int size;
	POINT winOrigin,
		  winEdge;
	vector<Vector2> shape;
};
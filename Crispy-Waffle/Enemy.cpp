#include <GL/glut.h>
#include "Enemy.h"

bool onScreen = false;

Enemy::Enemy(float red, float green, float blue, Vector2 location, Vector2 target, float maxSpeed, int size, POINT winOrigin, POINT winEdge)
{
	this->red = red;
	this->green = green;
	this->blue = blue;
	this->location = location;
	this->target = target;
	this->maxSpeed = maxSpeed;
	this->size = size;
	this->winOrigin = winOrigin;
	this->winEdge = winEdge;

	velocity = target - location;
	velocity.SetMagnitude(maxSpeed);

	pointValue = 5;

	shape = vector<Vector2>();
	shape.push_back(Vector2(-.5, .5));
	shape.push_back(Vector2(-.5, -.5));
	shape.push_back(Vector2(.5, -.5));
	shape.push_back(Vector2(.5, .5));
}

void Enemy::update()
{
	location.X += velocity.X;
	location.Y += velocity.Y;

	if (onScreen)
	{
		if (location.X < winOrigin.x || location.X > winEdge.x)
			velocity.X *= -1;

		if (location.Y < winOrigin.y || location.Y > winEdge.y)
			velocity.Y *= -1;
	}
	else if (location.X > winOrigin.x && location.X < winEdge.x && location.Y > winOrigin.y && location.Y < winEdge.y)
		onScreen = true;
}

void Enemy::draw()
{
	glColor3f(red, green, blue);

	glBegin(GL_POLYGON);
	{
		for each(Vector2 v in shape)
			glVertex2f(v.X, v.Y);
	}
	glEnd();
}
#include <GL\glut.h>

#include "Player.h"
#include "Vector2.h"

Player::Player(int red, int green, int blue, vector<Vector2> shape, Gamepad gamepad)
{
	this->red = red;
	this->green = green;
	this->blue = blue;

	this->shape = shape;

	this->gamepad = gamepad;
}

void Player::Update()
{
	gamepad.Update();

	// Get stick input as a normalized vector
	Vector2 leftStick = Vector2(gamepad.LeftStick_X(), -gamepad.LeftStick_Y()).Normal();
	Vector2 rightStick = Vector2(gamepad.RightStick_X(), -gamepad.RightStick_Y()).Normal();

	// Use stick input to change velocity
	velocity += leftStick * throttle;

	// Add velocity to location
	location += velocity;

	if (friction < .2)
		friction += .005;

	gamepad.RefreshState();
}

void Player::Draw()
{
	glTranslatef(location.X, location.Y, 0);

	glColor3f(red, green, blue);

	glBegin(GL_POLYGON);
	{
		for each(Vector2 v in shape)
			glVertex2f(v.X, v.Y);
	}
	glEnd();
}
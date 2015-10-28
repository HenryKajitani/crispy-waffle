#pragma once

#include <math.h>

class Vector2
{
	friend bool operator==(const Vector2& L, const Vector2& R);
	friend bool operator!=(const Vector2& L, const Vector2& R);
public:
	Vector2(void);
	Vector2(float, float);
	float Magnitude();
	float MagnitudeSquared();
	Vector2 Normal();
	void setMagnitude(float);

	Vector2 operator+(Vector2);
	Vector2 operator-(Vector2);
	Vector2 operator*(float);

	Vector2 operator-();

	Vector2& operator+=(const Vector2&);
	Vector2& operator-=(const Vector2&);
	Vector2& operator*=(const Vector2&);
	Vector2& operator/=(const Vector2&);

	float X, Y;
};
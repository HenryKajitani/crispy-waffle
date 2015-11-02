#pragma once

#include <math.h>

class Vector3
{
	friend bool operator==(const Vector3&, const Vector3&);
	friend bool operator!=(const Vector3&, const Vector3&);
public:
	Vector3(void);
	Vector3(float X, float Y, float Z);
	float Magnitude();
	float MagnitudeSquared();
	Vector3 Normal();
	void SetMagnitude(float);

	float Dot(Vector3);
	Vector3 Cross(Vector3);

	Vector3 operator+(Vector3);
	Vector3 operator-(Vector3);
	Vector3 operator*(float);
	Vector3 operator/(float);

	Vector3 operator-();

	Vector3& operator+=(const Vector3&);
	Vector3& operator-=(const Vector3&);
	Vector3& operator*=(const Vector3&);
	Vector3& operator/=(const Vector3&);

	float X, Y, Z;
};
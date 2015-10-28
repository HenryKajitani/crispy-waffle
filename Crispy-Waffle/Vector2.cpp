#include <tuple>

#include "Vector2.h"

Vector2::Vector2(void)
{
}

Vector2::Vector2(float X, float Y)
{
	this->X = X;
	this->Y = Y;
}

// Returns the length of the vector
float Vector2::Magnitude()
{
	return sqrt(X * X + Y * Y);
}

// Returns the length of the vector squared
// Used for length comparisons without needing roots
float Vector2::MagnitudeSquared()
{
	return X * X + Y * Y;
}

// Normalizes the vector
Vector2 Vector2::Normal()
{
	float length = this->Magnitude();

	if (length != 0)
		return Vector2(X / length, Y / length);

	return Vector2();
}

// Sets the magnitude of the vector
void Vector2::SetMagnitude(float mag)
{
	Vector2 v = this->Normal();
	X = v.X*mag;
	Y = v.Y*mag;
}

float Vector2::Dot(Vector2 other)
{
	return X * other.X + Y * other.Y;
}

float Vector2::Cross(Vector2 other)
{
	return X * other.Y - Y * other.X;
}

Vector2 Vector2::operator+(Vector2 other)
{
	return Vector2(X + other.X, Y + other.Y);
}

Vector2 Vector2::operator-(Vector2 other)
{
	return Vector2(X - other.X, Y - other.Y);
}

Vector2 Vector2::operator*(float scalar)
{
	return Vector2(X * scalar, Y * scalar);
}

Vector2 Vector2::operator-()
{
	return Vector2(-X, -Y);
}

Vector2& Vector2::operator+=(const Vector2& other)
{
	X += other.X;
	Y += other.Y;
	return *this;
}

Vector2& Vector2::operator-=(const Vector2& other)
{
	X -= other.X;
	Y -= other.Y;
	return *this;
}

Vector2& Vector2::operator*=(const Vector2& other)
{
	X *= other.X;
	Y *= other.Y;
	return *this;
}

Vector2& Vector2::operator/=(const Vector2& other)
{
	X /= other.X;
	Y /= other.Y;
	return *this;
}

bool operator==(const Vector2& L, const Vector2& R)
{
	return std::tie(L.X, L.Y) == std::tie(R.X, R.Y);
}
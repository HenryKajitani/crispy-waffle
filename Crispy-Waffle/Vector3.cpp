#include <tuple>

#include "Vector3.h"

Vector3::Vector3(void)
{
}

Vector3::Vector3(float X, float Y, float Z)
{
	this->X = X;
	this->Y = Y;
	this->Z = Z;
}

// Returns the length of the vector
float Vector3::Magnitude()
{
	return sqrt(X * X + Y * Y + Z * Z);
}

// Returns the length of the vector squared
// Used for length comparisons without needing roots
float Vector3::MagnitudeSquared()
{
	return X * X + Y * Y + Z * Z;
}

// Normalizes the vector
Vector3 Vector3::Normal()
{
	float length = this->Magnitude();

	if (length != 0)
		return Vector3(X / length, Y / length, Z / length);

	return Vector3();
}

// Sets the magnitude of the vector
void Vector3::SetMagnitude(float mag)
{
	Vector3 v = this->Normal();
	X = v.X*mag;
	Y = v.Y*mag;
	Z = v.Z*mag;
}

float Vector3::Dot(Vector3 other)
{
	return X * other.X + Y * other.Y + Z * other.Z;
}

Vector3 Vector3::Cross(Vector3 other)
{
	return Vector3(Y * other.Z - Z * other.Y, Z * other.X - X * other.Z, X * other.Y - Y * other.X);
}

Vector3 Vector3::operator+(Vector3 other)
{
	return Vector3(X + other.X, Y + other.Y, Z + other.Z);
}

Vector3 Vector3::operator-(Vector3 other)
{
	return Vector3(X - other.X, Y - other.Y, Z - other.Z);
}

Vector3 Vector3::operator*(float scalar)
{
	return Vector3(X * scalar, Y * scalar, Z * scalar);
}

Vector3 Vector3::operator/(float scalar)
{
	return Vector3(X / scalar, Y / scalar, Z / scalar);
}

Vector3 Vector3::operator-()
{
	return Vector3(-X, -Y, -Z);
}

Vector3& Vector3::operator+=(const Vector3& other)
{
	X += other.X;
	Y += other.Y;
	Z += other.Z;
	return *this;
}

Vector3& Vector3::operator-=(const Vector3& other)
{
	X -= other.X;
	Y -= other.Y;
	Z -= other.Z;
	return *this;
}

Vector3& Vector3::operator*=(const Vector3& other)
{
	X *= other.X;
	Y *= other.Y;
	Z *= other.Z;
	return *this;
}

Vector3& Vector3::operator/=(const Vector3& other)
{
	X /= other.X;
	Y /= other.Y;
	Z /= other.Z;
	return *this;
}

bool operator==(const Vector3& L, const Vector3& R)
{
	return std::tie(L.X, L.Y, L.Z) == std::tie(R.X, R.Y, R.Z);
}
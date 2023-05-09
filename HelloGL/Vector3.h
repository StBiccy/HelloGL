#pragma once
#include <math.h>

struct Vector3
{
	float x;
	float y;
	float z;


	Vector3 operator+=(const Vector3& other)
	{
		x += other.x;
		y += other.y;
		z += other.z;
		return *this;
	}

	Vector3 operator-=(const Vector3& other)
	{
		x -= other.x;
		y -= other.y;
		z -= other.z;
		return *this;
	}

	Vector3 operator-(const Vector3& other)
	{
		return Vector3{ x - other.x, y - other.y, z - other.z };

	}

	Vector3 operator+(const Vector3& other)
	{
		return Vector3{ x + other.x, y + other.y, z + other.z };
	}

#pragma region int maths

	Vector3 operator*=(const int& other)
	{
		x *= other;
		y *= other;
		z *= other;
		return *this;
	}

	Vector3 operator*(const int& other)
	{
		return Vector3{ x * other, y * other,z * other };
	}

	friend Vector3 operator*(const int& lhs, const Vector3& rhs)
	{
		return Vector3{ lhs * rhs.x, lhs * rhs.y, lhs * rhs.z };
	}

	Vector3 operator/=(const int& other)
	{
		x /= other;
		y /= other;
		z /= other;
		return *this;
	}

	Vector3 operator/(const int& other)
	{
		return Vector3{ x / other,y / other,z / other };
	}

	friend Vector3 operator/(const int& lhs, const Vector3 rhs)
	{
		return Vector3{ lhs / rhs.x , lhs / rhs.y,lhs / rhs.z };
	}

#pragma endregion

#pragma region float maths

	Vector3 operator*=(const float& other)
	{
		x *= other;
		y *= other;
		z *= other;
		return *this;
	}

	Vector3 operator*(const float& other)
	{
		return Vector3{ x * other,y * other,z * other };
	}

	friend Vector3 operator*(const float& lhs, const Vector3 rhs)
	{
		return Vector3{ lhs * rhs.x, lhs * rhs.y ,lhs * rhs.z };
	}

	Vector3 operator/=(const float& other)
	{
		x /= other;
		y /= other;
		z /= other;
		return *this;
	}

	Vector3 operator/(const float& other)
	{
		return Vector3{ x / other,y / other,z / other };
	}

	friend Vector3 operator/(const float& lhs, const Vector3 rhs)
	{
		return Vector3{ lhs / rhs.x , lhs / rhs.y,lhs / rhs.z };
	}

#pragma endregion

	float Magnitude() { return sqrtf(powf(x, 2) + powf(y, 2) + powf(z, 2)); } //calculates teh magnitude of a vector3


	Vector3 Normalise()  // finds the normalised values of a vector3
	{
		Vector3 result;
		result.x = x / Magnitude(); result.y = y / Magnitude(); result.z = z / Magnitude();
		return result;
	}
};

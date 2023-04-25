#pragma once
#include "Structures.h"
#define PI 3.141592653589793f

namespace Mathf
{
	static float Radian(float val) { return PI * val / 180; } //calculates the radian of a float

	static float Magnitude(Vector3 val) { return sqrtf(powf(val.x, 2) + powf(val.y, 2) + powf(val.z, 2)); } //calculates teh magnitude of a vector3

	static Vector3 Normalise(Vector3 val)  // finds the normalised values of a vector3
	{
		Vector3 result;
		result.x = val.x / Magnitude(val); result.y = val.y / Magnitude(val); result.z = val.z / Magnitude(val);
		return result;
	}
}; 
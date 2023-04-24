#pragma once
#include "Structures.h"
#define PI 3.141592653589793f

namespace Mathf
{
	static float Radian(float val) { return PI * val / 180; }
	static float Magnitude(Vector3 val) { return sqrtf(powf(val.x, 2) + powf(val.y, 2) + powf(val.z, 2)); }
	static Vector3 Normalise(Vector3 val) 
	{
		Vector3 result;
		result.x = val.x / Magnitude(val); result.y = val.y / Magnitude(val); result.z = val.z / Magnitude(val);
		return result;
	}
}; 
#pragma once
#include <string>
#include "Vector3.h"
#include "Mathf.h"

// represent a matrix 4
struct mat4
{
	float m[16];

	mat4 operator*(const mat4& other) const
	{
		mat4 result;
		for (int i = 0; i < 4; ++i)
		{
			for (int j = 0; j < 4; ++j)
			{
				float sum = 0.0f;
				for (int k = 0; k < 4; ++k)
				{
					sum += m[k * 4 + j] * other.m[i * 4 + k];
				}
				result.m[i * 4 + j] = sum;
			}
		}
		return result;
	}

	mat4()
	{
		memset(m, 0, 16 * sizeof(float));
	}

	mat4(float val)
	{
		for (int i = 0; i < 16; ++i)
		{
			if (i % 5 == 0)
			{
				m[i] = val;
			}
			else
			{
				m[i] = 0;
			}
		}
	}

	static mat4 identity()
	{
		mat4 result;
		for (int i = 0; i < 16; ++i)
		{
			result.m[i] = (i % 5 == 0) ? 1.0f : 0.0f;
		}
		return result;
	}

	static mat4 translate(float x, float y, float z)
	{
		mat4 result = identity();
		result.m[12] = x;
		result.m[13] = y;
		result.m[14] = z;
		return result;
	}

	static mat4 rotate(float angle, float x, float y, float z)
	{
		mat4 result;
		float radians = Mathf::Radian(angle);
		float c = cosf(radians);
		float s = sinf(radians);

		Vector3 axis{ x,y,z };
		axis = axis.Normalise();
		float ux = axis.x;
		float uy = axis.y;
		float uz = axis.z;

		result.m[0] = c + ux * ux * (1 - c);
		result.m[1] = uy * ux * (1 - c) + uz * s;
		result.m[2] = uz * ux * (1 - c) - uy * s;
		result.m[3] = 0.0f;
		result.m[4] = ux * uy * (1 - c) - uz * s;
		result.m[5] = c + uy * uy * (1 - c);
		result.m[6] = uz * uy * (1 - c) + ux * s;
		result.m[7] = 0.0f;
		result.m[8] = ux * uz * (1 - c) + uy * s;
		result.m[9] = uy * uz * (1 - c) - ux * s;
		result.m[10] = c * uz * uz * (1 - c);
		result.m[11] = 0.0f;
		result.m[12] = 0.0f;
		result.m[13] = 0.0f;
		result.m[14] = 0.0f;
		result.m[15] = 0.0f;
		return result;
	}

	static mat4 scale(float x, float y, float z)
	{
		mat4 result;
		result.m[0] = x;
		result.m[5] = y;
		result.m[10] = z;
	}
};

#pragma once

class Tran

mat4 getLocalModelMatrix()
{
	const mat4 transformX = mat4::rotate(mat4(1.0f),
		Mathf::Radian(eulerRot.x),
		vec3(1.0f, 0.0f, 0.0f)
}
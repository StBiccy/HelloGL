#include "CharacterController.h"

CharacterController::CharacterController(float posX, float posY, float posZ, float frountX, float frountY, float frountZ, float upX, float upY, float upZ)
{
	//setup position
	position.x = posX, position.y = posY, position.z = posZ;

	pitch = 0.0f;
	yaw = -90.0f;
	
	DirectionUpdate();

	//setup camera
	cam = new Camera;
	cam->eye.x = posX, cam->eye.y = posY, cam->eye.z = posZ;
	cam->up.x = upX, cam->up.y = upY, cam->up.z = upZ;
	cam->frount.x = frountX, cam->frount.y = frountY, cam->frount.z = frountZ;

	//setup  input checks
	wDown = false;
	aDown = false;
	sDown = false;
	dDown = false;
}

CharacterController::~CharacterController()
{
	delete cam;
}

Vector3 CharacterController::DirectionUpdate()
{
	camDirection.x = cos(math::radian(yaw)) * cos(math::radian(pitch));
	camDirection.y = sin(math::radian(pitch));
	camDirection.z = sin(math::radian(yaw)) * cos(math::radian(pitch));
	return camDirection;
}

void CharacterController::Update()
{
	//set camera look at
	gluLookAt(cam->eye.x, cam->eye.y, cam->eye.z, cam->frount.x + cam->eye.x, cam->frount.y + cam->eye.y, cam->frount.z + cam->eye.z, cam->up.x, cam->up.y, cam->up.z);

	//reset velocity
	velocity.x = 0, velocity.y = 0, velocity.z = 0;

	// input checks
	//if (wDown == true)
	//{
	//	velocity.z -= 1 * SPEED;
	//}
	//if (sDown == true)
	//{
	//	velocity.z += 1 * SPEED;
	//}
	//if (aDown == true)
	//{
	//	velocity.x -= 1 * SPEED;
	//}
	//if (dDown == true)
	//{
	//	velocity.x += 1 * SPEED;
	//}

	////set position
	//position.x += velocity.x, position.y += velocity.y, position.z += velocity.z;

	// updated cam with position values
	//cam->eye.x = position.x, cam->eye.y = position.y, cam->eye.z = position.z;
	//cam->center.x = position.x, cam->center.y = position.y, cam->center.z = position.z - 5;
}
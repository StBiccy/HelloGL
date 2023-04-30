#include "CharacterController.h"

CharacterController::CharacterController(float posX, float posY, float posZ, float frountX, float frountY, float frountZ, float upX, float upY, float upZ)
{
	//setup position
	position.x = posX, position.y = posY, position.z = posZ;


	//Predefining the rotation
	pitch = 00.0f;
	yaw = -90.0f;
	
	// Camaera sensitvity
	sensitivity = 0.05f;

	//setup camera
	cam = new Camera;
	cam->eye.x = posX, cam->eye.y = posY, cam->eye.z = posZ;
	cam->up.x = upX, cam->up.y = upY, cam->up.z = upZ;

	DirectionUpdate();


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

// update which way the camera is facing
void CharacterController::DirectionUpdate()
{
	// uses the yaw and pitch to find the direction the camera is facing with triganomatry
	Vector3 camDirection;
	camDirection.x = cosf(Mathf::Radian(yaw)) * cosf(Mathf::Radian(pitch));
	camDirection.y = sinf(Mathf::Radian(pitch));
	camDirection.z = sinf(Mathf::Radian(yaw)) * cosf(Mathf::Radian(pitch));
	
	// set the direction of the camera to eaqual the noremal of the direction found
	cam->frount = Mathf::Normalise(camDirection);
}

void CharacterController::Update()
{
	//set camera look at
	//gluLookAt(cam->eye.x, cam->eye.y, cam->eye.z, cam->frount.x + cam->eye.x, cam->frount.y + cam->eye.y, cam->frount.z + cam->eye.z, cam->up.x, cam->up.y, cam->up.z);

	//reset velocity
	velocity.x = 0, velocity.y = 0, velocity.z = 0;

	

	// input checks
	if (wDown == true)
	{
		// moves in the direction the camera is facing
		velocity.x += cam->frount.x;
		velocity.z += cam->frount.z;
	}
	if (sDown == true)
	{
		// movies the opposite way the camera is facing
		velocity.x -= cam->frount.x;
		velocity.z -= cam->frount.z;
	}
	if (aDown == true)
	{
		// moves to the right of the direction the camera is facing
		velocity.x += cam->frount.z;
		velocity.z -= cam->frount.x;
	}
	if (dDown == true)
	{
		// moves to the left of the direction the camera is facing
		velocity.x -= cam->frount.z;
		velocity.z += cam->frount.x;
	}

	// if the velocity is not 0 then normalise it so that the character speed doesn't increse when moving diagonally;
	if (velocity.x != 0 && velocity.z != 0)
	velocity = Mathf::Normalise(velocity);

	// add speed to the velocity;
	velocity.x *= SPEED; velocity.z *= SPEED;

	//set position
	position.x += velocity.x, position.y += velocity.y, position.z += velocity.z;

	//updated cam with position values
	cam->eye.x = position.x, cam->eye.y = position.y, cam->eye.z = position.z;
	
}

//updates when mouse moves
void CharacterController::PassiveMotion(int x, int y)
{
	//set the cursor to center of screen
	glutWarpPointer(400, 400);

	// find the move delta of the mouse
	float xDelta = 400.0f - x;
	float yDelta = 400.0f - y;

	// roatate depending on sensitivity and the mouse deltas
	pitch += yDelta * sensitivity;
	yaw -= xDelta * sensitivity;

	// update the camera direction
	DirectionUpdate();
}

Camera* CharacterController::GetCamera()
{
	return cam;
}
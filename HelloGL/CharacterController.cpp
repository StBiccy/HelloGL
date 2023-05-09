#include "CharacterController.h"

CharacterController::CharacterController(Vector3 pos, Vector3 front, Vector3 up)
{
	//setup position
	position = pos;


	//Predefining the rotation
	pitch = 00.0f;
	yaw = -90.0f;
	
	// Camaera sensitvity
	sensitivity = 0.05f;

	//setup camera
	cam = new Camera;
	cam->eye = pos;
	cam->up = up;

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
	cam->front.x = cosf(Mathf::Radian(yaw)) * cosf(Mathf::Radian(pitch));
	cam->front.y = sinf(Mathf::Radian(pitch));
	cam->front.z = sinf(Mathf::Radian(yaw)) * cosf(Mathf::Radian(pitch));
	
	// set the direction of the camera to eaqual the noremal of the direction found
	cam->front = cam->front.Normalise();
}

void CharacterController::Update()
{
	//set camera look at
	gluLookAt(cam->eye.x, cam->eye.y, cam->eye.z, cam->front.x + cam->eye.x, cam->front.y + cam->eye.y, cam->front.z + cam->eye.z, cam->up.x, cam->up.y, cam->up.z);

	//reset velocity
	velocity = { 0,0,0 } ;

	

	// input checks
	if (wDown == true)
	{
		// moves in the direction the camera is facing
		velocity.x += cam->front.x;
		velocity.z += cam->front.z;
	}
	if (sDown == true)
	{
		// movies the opposite way the camera is facing
		velocity.x -= cam->front.x;
		velocity.z -= cam->front.z;
	}
	if (aDown == true)
	{
		// moves to the right of the direction the camera is facing
		velocity.x += cam->front.z;
		velocity.z -= cam->front.x;
	}
	if (dDown == true)
	{
		// moves to the left of the direction the camera is facing
		velocity.x -= cam->front.z;
		velocity.z += cam->front.x;
	}

	// if the velocity is not 0 then normalise it so that the character speed doesn't increse when moving diagonally;
	if (velocity.x != 0 && velocity.z != 0)
	velocity = velocity.Normalise();

	// add speed to the velocity;
	velocity.x *= SPEED; velocity.z *= SPEED;

	//set position
	position += velocity;

	//updated cam with position values
	cam->eye = position;
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

Camera CharacterController::GetCamera()
{
	return *cam;
}
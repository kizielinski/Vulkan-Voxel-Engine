//Kyle Zielinski
//11/05/2021
//Class implementation of a camera object that the user can operate to navigate around the scene.
#include "Camera.h"

Camera::Camera(float x, float y, float z, float aspectRatio)
{
	transform.SetPosition(x, y, z);

	UpdateViewMatrix();
	UpdateProjectionMatrix(aspectRatio);
}

Camera::~Camera()
{
}


void Camera::Update(float deltaTime, HWND windowHandle)
{
	
		float speed = deltaTime * 2.0f;

		//Check for user key press
		if (GetAsyncKeyState('W') & 0x8000) { transform.MoveRelative(0, 0, speed); }
		if (GetAsyncKeyState('S') & 0x8000) { transform.MoveRelative(0, 0, -speed); }
		if (GetAsyncKeyState('A') & 0x8000) { transform.MoveRelative(-speed, 0, 0); }
		if (GetAsyncKeyState('D') & 0x8000) { transform.MoveRelative(speed, 0, 0); }

		//Get current Mouse position
		POINT mousePos = {};
		GetCursorPos(&mousePos);
		ScreenToClient(windowHandle, &mousePos);

		if (GetAsyncKeyState(VK_LBUTTON) & 0x8000)
		{
			//Calculate change in cursor pos
			float xDifference = deltaTime * (mousePos.x - prevMousePosition.x);
			float yDifference = deltaTime * (mousePos.y - prevMousePosition.y);

			transform.Rotate(yDifference, xDifference, 0); //Yes in that order :(
		}

		UpdateViewMatrix();
		prevMousePosition = mousePos;
}

void Camera::UpdateViewMatrix()
{
	//Get rotation value
	glm::vec3 pitchYawRollValues = transform.GetRotation();
	glm::vec3 forwardDirection = glm::vec4(0, 0, 1, 0) *
		glm::yawPitchRoll(pitchYawRollValues.y, pitchYawRollValues.x, pitchYawRollValues.z);

	//Look to is looking in a direction
	//Look at matarix means look at specific location
	glm::vec3 position = transform.GetPosition();
	glm::mat4x4 view = glm::lookAtLH(position, forwardDirection, glm::vec3(0, 1, 0));

	viewMatrix = view;
}

void Camera::UpdateProjectionMatrix(float aspectRatio)
{
	glm::mat4x4 proj = glm::perspectiveFovLH(
		glm::pi<float>()/4, //RADIAN VALUE
		400.0f,
		400.0f,
		0.01f, //Small but never zero, that way view doesn't disappear. Near clip
		100.0f); //Large but not massive (1k is general limit); Far clip

	projectionMatrix = proj;
}

void Camera::CenterCamera()
{
}

glm::mat4x4 Camera::GetViewMatrix()
{
	return viewMatrix;
}

glm::mat4x4 Camera::GetProjectionMatrix()
{
	return projectionMatrix;
}

glm::vec3 Camera::GetPosition()
{
	return transform.GetPosition();
}

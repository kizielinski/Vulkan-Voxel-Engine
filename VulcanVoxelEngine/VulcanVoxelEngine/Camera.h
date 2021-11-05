#include "Transform.h"
//#include <DirectXMath.h>
#include <Windows.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

class Camera
{

public:
	Camera(float x, float y, float z, float aspectRatio);
	~Camera();

	//Update functions
	void Update(float deltaTime, HWND windowHandle);
	void UpdateViewMatrix();
	void UpdateProjectionMatrix(float aspectRatio);
	void CenterCamera(); //Needs parameters of entities;

	//Getters
	glm::mat4x4 GetViewMatrix();
	glm::mat4x4 GetProjectionMatrix();
	glm::vec3 GetPosition();

private:
	glm::mat4x4 viewMatrix;
	glm::mat4x4 projectionMatrix;
	Transform transform;
	POINT prevMousePosition;
};

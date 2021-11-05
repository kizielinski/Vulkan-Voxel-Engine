#pragma 
 
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtx/transform.hpp>
#include<glm/gtc/quaternion.hpp>
#include <glm/gtx/euler_angles.hpp>
#include<glm/common.hpp>
#include <vector>

class Transform
{
public:

	Transform();
	~Transform();

	// Methods to adjust existing transforms
	void MoveAbsolute(float x, float y, float z);
	void MoveRelative(float x, float y, float z);
	void Rotate(float pitch, float yaw, float roll);
	void Scale(float x, float y, float z);

	// Methods to overwrite existing transforms
	void SetPosition(float x, float y, float z);
	void SetRotation(float pitch, float yaw, float roll);
	void SetScale(float x, float y, float z);

	// Methods to retrieve transform data
	glm::vec3 GetPosition();
	glm::vec3 GetRotation();
	glm::vec3 GetScale();

	// Method to return/calculate the resulting world matrix
	glm::mat4x4 GetWorldMatrix();
	glm::mat4x4 GetWorldITMatrix();
	// No reason to have a SET, the result will always be the total result of the 3 transformations.

	//Hierarchy Methods
	void AddChild(Transform* child);
	void RemoveChild(Transform* child);
	void SetChild(Transform* newParent);
	Transform* GetParent();
	Transform* GetChild(unsigned int index);
	int IndexOfChild(Transform* child);
	unsigned int GetChildCount();

private:

	void MarkChildTransformDirty();

	//A place to store the raw transform values
	glm::vec3 position;
	glm::vec3 pitchYawRoll; // Not a quaternion, simply 3 Euler angles
	glm::vec3 scale;

	glm::mat4x4 worldMatrix; // Most recent matrix created
	glm::mat4x4 worldInverseTransposeMatrix; // Inverse&transpose of current worldmatrix
	bool isDirty; // Has the matrix value been changed? If so remake matrix

	Transform* parent; //Should be null(0) if there is no parent

	std::vector<Transform*> children;
};


#include "Transform.h"

Transform::Transform()
{
	position = glm::vec3(0, 0, 0);
	pitchYawRoll = glm::vec3(0, 0, 0);
	scale = glm::vec3(1, 1, 1);

	parent = nullptr;
	worldMatrix = glm::mat4(1.0f);
	worldInverseTransposeMatrix = glm::mat4(1.0f);
	isDirty = false;
}

Transform::~Transform()
{
	for (int i = 0; i < children.size(); i++)
	{
		children[i] = nullptr;
	}
	parent = nullptr;
}

void Transform::MoveAbsolute(float x, float y, float z)
{
	position = position + glm::vec3(x, y, z);
	MarkChildTransformDirty();
	isDirty = true;
	//simple version - this is the same as above, but the above code becomes optimized by compiler 
	//idk abotu GLM though, in directX it is optimized
	/*
	* position.x += x;
	* position.y += y;
	* position.z += z;
	*/
}

void Transform::MoveRelative(float x, float y, float z)
{
	//Overall, this will adjust position, not through adding xyz to current values
	//but by taking into account how the need to be rotated to match our rotation. 

	// Desired movement in "world" space
	glm::vec3 vecMove = glm::vec3(x, y, z);

	//Pitch yaw roll as our current rotation in quaternion form.
	glm::quat Quat = glm::quat(pitchYawRoll.x, pitchYawRoll.y, pitchYawRoll.z, 0);

	//Rotate desiredMovement by the same amount we are rotated.
	
	glm::highp_vec3 relativeMovement = (glm::cross(
			glm::vec3(Quat.x, Quat.y, Quat.z), 
			cross(glm::vec3(Quat.x, Quat.y, Quat.z), vecMove) + Quat.w * vecMove));

	glm::vec3 temp = vecMove + glm::vec3(relativeMovement) * 2.0f;
	
	//Update our position
	//aka pos = pos + relativeMove;
	position = position + relativeMovement;

	//Call update to matrix
	MarkChildTransformDirty();
	isDirty = true;
}

void Transform::Rotate(float pitch, float yaw, float roll)
{
	pitchYawRoll = pitchYawRoll + glm::vec3(pitch, yaw, roll);
	MarkChildTransformDirty();
	isDirty = true;
}

void Transform::Scale(float x, float y, float z)
{
	scale = scale * glm::vec3(x, y, z);
	MarkChildTransformDirty();
	isDirty = true;
}

void Transform::SetPosition(float x, float y, float z)
{
	position = glm::vec3(x, y, z);
	MarkChildTransformDirty();
	isDirty = true;
}

void Transform::SetRotation(float pitch, float yaw, float roll)
{
	pitchYawRoll = glm::vec3(pitch, yaw, roll);
	isDirty = true;
}

void Transform::SetScale(float x, float y, float z)
{
	scale = glm::vec3(x, y, z);
	isDirty = true;
}

glm::vec3 Transform::GetPosition()
{
	return position;
}

glm::vec3 Transform::GetRotation()
{
	return pitchYawRoll;
}

glm::vec3 Transform::GetScale()
{
	return scale;
}

glm::mat4x4 Transform::GetWorldMatrix()
{
	if (isDirty)
	{
		glm::mat4x4 translationMat = glm::translate(glm::mat4(), position);
		glm::mat4x4 rotationMat = glm::yawPitchRoll(pitchYawRoll.y, pitchYawRoll.x, pitchYawRoll.z);
		glm::mat4x4 scaleMat = glm::scale(glm::mat4(), scale);

		//Store world matrix & store it once you invert and transpose
		glm::mat4x4 worldMat = scaleMat * rotationMat * translationMat;
		if (parent)
		{
			glm::mat4x4 parentMatrix = GetParent()->worldMatrix;
			worldMat = worldMat * parentMatrix;
		}
		worldMatrix = worldMat;
		
		worldInverseTransposeMatrix = glm::inverse(glm::transpose(worldMat));

		isDirty = false;
	}

	return worldMatrix;
}

glm::mat4x4 Transform::GetWorldITMatrix()
{
	return worldInverseTransposeMatrix;
}

void Transform::AddChild(Transform* child)
{
	if (child != nullptr)
	{
		bool duplicateLock = false;
		for (int i = 0; i < children.size(); i++)
		{
			if (&children[i] == &child)
			{
				duplicateLock = true;
				break;
			}
		}

		if (!duplicateLock)
		{
			child->parent = this;
			child->isDirty = true;
			child->MarkChildTransformDirty();
			children.push_back(child);
		}
	}
}

void Transform::RemoveChild(Transform* child)
{
	if (child != nullptr)
	{
		bool removeLock = false;
		int indexToRemove;
		for (int i = 0; i < children.size(); i++)
		{
			if (children[i] == child)
			{
				removeLock = true;
				indexToRemove = i;
				break;
			}
		}

		if (removeLock)
		{
			children[indexToRemove]->parent = nullptr;
			children[indexToRemove]->isDirty = true;
			children[indexToRemove]->MarkChildTransformDirty();
			children.erase(children.begin() + indexToRemove);
		}
	}
}

void Transform::SetChild(Transform* newParent)
{
	this->parent = newParent;

	if (newParent != nullptr)
	{
		newParent->AddChild(this);
		this->isDirty = true;
		this->MarkChildTransformDirty();
	}
}

Transform* Transform::GetParent()
{
	return parent;
}

Transform* Transform::GetChild(unsigned int index)
{
	if (index < 0 || index >= children.size())
	{
		return nullptr;
	}
	else
	{
		return children[index];
	}
}

int Transform::IndexOfChild(Transform* child)
{
	int indexToReturn = -1;
	for (int i = 0; i < children.size(); i++)
	{
		if (&children[i] == &child)
		{
			indexToReturn = i;
			break;
		}
	}

	return indexToReturn;
}

unsigned int Transform::GetChildCount()
{
	return children.size();
}

void Transform::MarkChildTransformDirty()
{
	for (int i = 0; i < children.size(); i++)
	{
		children[i]->isDirty = true;
		children[i]->MarkChildTransformDirty();
	}
}

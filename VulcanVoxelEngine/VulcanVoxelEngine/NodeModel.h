#pragma once

#include <tiny_obj_loader.h>
#include <string>
#include <vector>
#include <stdexcept>
#include "Vertex.h"
using namespace std;

class NodeModel
{
public:

	NodeModel();
	NodeModel(string modelPath, glm::vec3 offset);
	~NodeModel();

	void SetVertices(vector<Vertex> newVerts);
	void SetIndices(vector<uint32_t> newIndices);
	vector<Vertex> ReturnVertices();
	vector<uint32_t> ReturnIndices();
	size_t ReturnVertexVectorSize();
	size_t ReturnIndexVectorSize();
	uint32_t& ReturnIndex(int index);
	Vertex& ReturnVertex(int index);
	void PushVertex(Vertex V);
	void PushIndex(uint32_t I);

private:
	VkBuffer vertexBuffer;
	VkBuffer indexBuffer;
	VkBuffer commandBuffer;
	VkBuffer uniformBuffer;
	
	const std::string MODEL_PATH = "models/cube.obj";
	const std::string TEXTURE_PATH = "textures/square.jpg";

	//Model Information
	vector<Vertex> vertices;
	vector<uint32_t> indices;

	void loadModel(string modelPath, glm::vec3 offset);
};


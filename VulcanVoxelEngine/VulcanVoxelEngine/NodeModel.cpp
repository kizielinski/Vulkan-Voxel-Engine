#include "NodeModel.h"

NodeModel::NodeModel()
{
	loadModel(MODEL_PATH, { 0, 0, 0 });
}

NodeModel::NodeModel(string modelPath, glm::vec3 offset)
{
	loadModel(modelPath, offset);
}

NodeModel::~NodeModel()
{
}

void NodeModel::SetVertices(vector<Vertex> newVerts)
{
	vertices = newVerts;
}

void NodeModel::SetIndices(vector<uint32_t> newIndices)
{
	indices = newIndices;
}

Vertex& NodeModel::ReturnVertex(int index)
{
	return vertices[index];
}

vector<Vertex> NodeModel::ReturnVertices()
{
	return vertices;
}

size_t NodeModel::ReturnVertexVectorSize()
{
	return vertices.size();
}

size_t NodeModel::ReturnIndexVectorSize()
{
	return indices.size();
}

uint32_t& NodeModel::ReturnIndex(int index)
{
	return indices[index];
}

void NodeModel::PushVertex(Vertex v)
{
	vertices.push_back(v);
}

void NodeModel::PushIndex(uint32_t i)
{
	indices.push_back(i);
}

void NodeModel::loadModel(string modelPath, glm::vec3 offset)
{
	tinyobj::attrib_t attrib;
	std::vector<tinyobj::shape_t> shapes;
	std::vector<tinyobj::material_t> materials;
	std::string warn, err;

	if (!tinyobj::LoadObj(&attrib, &shapes, &materials, &warn, &err, modelPath.c_str())) {
		throw std::runtime_error(warn + err);
	}

	unordered_map<Vertex, uint32_t> uniqueVertices{};

	for (const auto& shape : shapes) {
		for (const auto& index : shape.mesh.indices) {
			Vertex vertex{};

			vertex.pos = {
				attrib.vertices[3 * index.vertex_index + 0] + offset.x,
				attrib.vertices[3 * index.vertex_index + 1] + offset.y,
				attrib.vertices[3 * index.vertex_index + 2] + offset.z
			};

			vertex.texCoord = {
				attrib.texcoords[2 * index.texcoord_index + 0],
				1.0f - attrib.texcoords[2 * index.texcoord_index + 1]
			};

			vertex.color = { 1.0f, 1.0f, 1.0f };

			size_t one;
			size_t two;
			size_t three;

			three = sizeof(vertex);

			if (uniqueVertices.count(vertex) == 0) {
				uniqueVertices[vertex] = static_cast<uint32_t>(vertices.size());
				vertices.push_back(vertex);
			}

			indices.push_back(uniqueVertices[vertex]);
		}
	}

	int x = 0;
	/*createVertexBuffer();
	createIndexBuffer();
	createUniformBuffers();
	createDescriptorPool();
	createDescriptorSets();
	createCommandBuffers();
	createSyncObjects();*/
}

vector<uint32_t> NodeModel::ReturnIndices()
{
	return indices;
}

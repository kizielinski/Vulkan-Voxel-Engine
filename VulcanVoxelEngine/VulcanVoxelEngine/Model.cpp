#include "Model.h"

Model::Model()
{
}

Model::~Model()
{
}

Vertex& Model::ReturnVertex(int index)
{
	return vertices[index][0];
}

vector<Vertex*> Model::ReturnVertices()
{
	return vertices;
}

size_t Model::ReturnVertexVectorSize()
{
	return vertices.size();
}

size_t Model::ReturnIndexVectorSize()
{
	return indices.size();
}

uint32_t& Model::ReturnIndex(int index)
{
	return indices[index][0];
}

void Model::PushVertex(Vertex* v)
{
	size_t temp = sizeof(v);
	vertices.push_back(v);
}

void Model::PushIndex(uint32_t* I)
{
	indices.push_back(I);
}

vector<uint32_t*> Model::ReturnIndices()
{
	return indices;
}

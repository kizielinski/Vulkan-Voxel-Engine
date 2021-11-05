#pragma once

#include <string>
#include <vector>
#include "Vertex.h"
using namespace std;

class Model
{
public:

	Model();
	~Model();
	Vertex& ReturnVertex(int index);
	vector<Vertex*> ReturnVertices();
	size_t ReturnVertexVectorSize();
	size_t ReturnIndexVectorSize();
	uint32_t& ReturnIndex(int index);
	vector<uint32_t*> ReturnIndices();
	void PushVertex(Vertex* V);
	void PushIndex(uint32_t* I);

private:
	const string MODEL_PATH;
	const string TEXTURE_PATH;

	//Model Information
	vector<Vertex*> vertices;
	vector<uint32_t*> indices;
};


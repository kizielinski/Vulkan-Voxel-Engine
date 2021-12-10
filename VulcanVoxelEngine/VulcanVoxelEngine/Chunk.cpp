#include "Chunk.h"

Chunk::Chunk()
{
	chunkID = 0;
	dimensions = glm::vec3(1, 1, 1);
	numVoxels = 1;
}

Chunk::Chunk(glm::vec3 _dimensions)
{
	chunkID = 0;
	dimensions = _dimensions;
	numVoxels = dimensions.x * dimensions.y * dimensions.z;
}

Chunk::~Chunk()
{
}

glm::vec3 Chunk::ReturnChunkDimensions()
{
	return dimensions;
}



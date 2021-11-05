#include "Chunk.h"

Chunk::Chunk()
{
	chunkID = 0;
	dimensions = glm::vec3(1, 1, 1);
}

Chunk::Chunk(glm::vec3 _dimensions)
{
	chunkID = 0;
	dimensions = _dimensions;
}

Chunk::~Chunk()
{
}

glm::vec3 Chunk::ReturnChunkDimensions()
{
	return dimensions;
}



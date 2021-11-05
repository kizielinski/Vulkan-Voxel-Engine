#pragma once
#include <string>
#include <vector>
#include <glm/glm.hpp>



class Chunk
{
public:
	Chunk();
	Chunk(glm::vec3 _dimensions);
	~Chunk();
	glm::vec3 ReturnChunkDimensions();
	uint32_t chunkID; //Multiply this by the chunkCount to get the start position of that chunk. 
	glm::vec3 dimensions = { 10, 10, 0 };
	uint32_t numVoxels;
private:

};


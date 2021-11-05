#pragma once

#include "Chunk.h"
#include "Voxel.h"

class World
{
public:
	World();
	World(int _chunkCount);
	~World();
	int GetChunkCount();
	Chunk* GetChunkByIndex(int index);
	void CreateChunks();
	void GenerateVoxels(glm::vec3 dimensions);
private:
	int chunkCount;
	vector<Chunk*> chunks; //Straight forward vector
	//Heuristic for accessing voxels. 
	//ChunkID * its ChunkSize brings you to the end of that chunk.
	vector<Voxel*> voxels;

};


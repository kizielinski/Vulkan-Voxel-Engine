#pragma once

#include "Chunk.h"
#include "Voxel.h"
#include "Node.h"
#include <vector>

struct Vector3D 
{
	float x;
	float y;
	float z;
};

class World
{
public:
	World();
	World(Vector3D dimensions);
	World(int _chunkCount, Vector3D dimensions);
	~World();
	int GetChunkCount();
	Chunk* GetChunkByIndex(int index);
	void CreateChunks(Vector3D dimensions);
	void GenerateVoxels(Vector3D dimensions);
	std::vector<Node*> GetNodes();
private:
	int chunkCount;
	std::vector<Chunk*> chunks; //Straight forward vector
	//Heuristic for accessing voxels. 
	//ChunkID * its ChunkSize brings you to the end of that chunk.
	std::vector<Voxel*> voxels;
	std::vector<Node*> nodes; 

};


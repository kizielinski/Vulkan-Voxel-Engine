#include "world.h"

World::World(int _chunkCount)
{
    chunkCount = _chunkCount;
    CreateChunks();
}

World::~World()
{
}

int World::GetChunkCount()
{
    return chunks.size();
}

Chunk World::GetChunkByIndex(int index)
{
    return chunks[index];
}

void World::CreateChunks()
{
    for (int i = 0; i < chunkCount; i++)
    {
        chunks.push_back(Chunk());
        GenerateVoxels(chunks[chunks.size() - 1].dimensions);
    }
}

void World::GenerateVoxels(glm::vec3 dimensions)
{
    for (int x = 0; x < dimensions.x; x++) {
        for (int y = 0; y < dimensions.y; y++) {
            for (int z = 0; z < dimensions.z; z++)
            {
                voxels.push_back(Voxel(glm::vec3(x, y, z)));
            }
        }
    }
    
    
}

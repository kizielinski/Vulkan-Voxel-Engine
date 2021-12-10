#include "world.h"

World::World()
{
    chunkCount = 1;
    CreateChunks({1, 1, 1});
}

World::World(Vector3D dimensions)
{
    chunkCount = 1;
    CreateChunks(dimensions);
}

World::World(int _chunkCount, Vector3D dimensions)
{
    chunkCount = 1;
    CreateChunks(dimensions);
}

World::~World()
{
}

int World::GetChunkCount()
{
    return chunks.size();
}

Chunk* World::GetChunkByIndex(int index)
{
    return chunks[index];
}

std::vector<Node*> World::GetNodes()
{
    return nodes;
}

void World::CreateChunks(Vector3D dimensions)
{
    for (int i = 0; i < chunkCount; i++)
    {
        chunks.push_back(new Chunk());
        GenerateVoxels(dimensions);
    }
}

void World::GenerateVoxels(Vector3D dimensions)
{
    for (int x = 0; x < dimensions.x; x++) {
        for (int y = 0; y < dimensions.y; y++) {
            for (int z = 0; z < dimensions.z; z++)
            {
                voxels.push_back(new Voxel(glm::vec3(x, y, z)));
                nodes.push_back(new Node(x, y-2, z-2));
            }
        }
    }
}
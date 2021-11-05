#include "Voxel.h"

Voxel::Voxel(glm::vec3 pos)
{
    vData.position = pos;
}

Voxel::~Voxel()
{
}

void Voxel::SetTexture(int index, string textureFile)
{
}

uint32_t Voxel::GetGlobalID()
{
    return vData.globalId;
}

uint32_t Voxel::GetLocalID()
{
    return vData.localId;
}

glm::vec3 Voxel::GetPosition()
{
    return vData.position;
}

VoxelData Voxel::AccessDataStruct()
{
    return vData;
}

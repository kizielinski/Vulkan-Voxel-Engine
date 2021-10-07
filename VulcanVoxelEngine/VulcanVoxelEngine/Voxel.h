#pragma once
#include <string>

//Combinations of these enum values add up to the necessary spec.
//For example 4 + 8 = 12 so that means it's Forward & Backward equals X_Axis;
enum Sides {
	Left = 1,
	Right = 2,
	Forward = 4,
	Backward = 8,
	Top = 16,
	Bottom = 32,
	Z_Axis = 3,
	X_Axis = 12,
	Y_Axis = 48,
	All = 63
};

class Voxel
{
public:
	Voxel();
	~Voxel();

private:
	std::string voxelName;
	uint32_t globalId;
	uint32_t localId;
	int scaledDimensions; //Upon creation is this an object that's a composition of voxels (i.e. 2x2 cube?)
};


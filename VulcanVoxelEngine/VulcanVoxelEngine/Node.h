#pragma once

#include "NodeTransform.h"
#include "NodeModel.h"

enum NodeType 
{
	NodeBase2,
	NodeTransform2,
	NodeModel2,
	NodeTexture2,
	NodeLight2,
	NodeMaterial2
};

class Node
{
public:

	Node();
	Node(std::string modelPath, glm::vec3 offset);
	Node(std::string modelPath);
	Node(float x, float y, float z);
	~Node();

	Node* parentNode;
	vector<Node*> children;

	NodeTransform* transform;
	NodeModel* model;


private:

	NodeType nodeType;
};


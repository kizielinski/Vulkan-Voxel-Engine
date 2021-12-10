#include "Node.h"

Node::Node()
{
    transform = new NodeTransform();
    model = new NodeModel();
    parentNode = nullptr;
    nodeType = NodeTransform2;
}

Node::Node(std::string modelPath, glm::vec3 offset)
{
    transform = new NodeTransform();
    transform->MoveAbsolute(offset.x, offset.y, offset.z);
    model = new NodeModel(modelPath, transform->GetPosition());
    parentNode = nullptr;
    nodeType = NodeTransform2;
}

Node::Node(std::string modelPath)
{
    transform = new NodeTransform();
    model = new NodeModel(modelPath, transform->GetPosition());
    parentNode = nullptr;
    nodeType = NodeTransform2;
}

Node::Node(float x, float y, float z)
{
    transform = new NodeTransform();
    transform->MoveAbsolute(x, y, z);
    model = new NodeModel("models/cube.obj", transform->GetPosition());

    parentNode = nullptr;
    nodeType = NodeTransform2;
}

Node::~Node()
{
}

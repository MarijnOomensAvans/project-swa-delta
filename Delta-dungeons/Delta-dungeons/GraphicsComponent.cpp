#include "GraphicsComponent.h"

GraphicsComponent::GraphicsComponent() {};
GraphicsComponent::~GraphicsComponent() {};
void GraphicsComponent::PlayAnimation(std::string path) {};
void GraphicsComponent::draw() { 
	//grab the vector2D source and vector2D destination
	GraphicsComponent::textureManager->DrawTexture();
};
void GraphicsComponent::SetTexture(std::string tex, std::string name) {};
void GraphicsComponent::CallBackFunction() {};

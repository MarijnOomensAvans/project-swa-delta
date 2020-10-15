#include "GraphicsComponent.h"

GraphicsComponent::GraphicsComponent() {};
GraphicsComponent::~GraphicsComponent() {};
void GraphicsComponent::PlayAnimation(std::string path) {};
//void GraphicsComponent::draw() { 
//	//grab the vector2D source and vector2D destination
//	GraphicsComponent::textureManager->DrawTexture();
//};
void GraphicsComponent::SetTexture(std::string name) {};
void GraphicsComponent::callbackFunction() {
};

void GraphicsComponent::Update() {
	textureManager->DrawTexture(textureName);
}

void GraphicsComponent::connectCallback() {

}

void GraphicsComponent::addTextureManager(std::shared_ptr<TextureManager> tm) {
	textureManager = tm;
}
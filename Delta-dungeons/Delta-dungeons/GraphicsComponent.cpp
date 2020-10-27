#include "GraphicsComponent.h"

GraphicsComponent::GraphicsComponent() {};

GraphicsComponent::~GraphicsComponent() {};

void GraphicsComponent::playAnimation(std::string path) {};

void GraphicsComponent::setTexture(std::string name)
{
	this->textureName = name;
}

void GraphicsComponent::callbackFunction() {}


void GraphicsComponent::update()
{
	textureManager->drawTexture(textureName, this->transform, this->imageCoordinates, this->imageDimensions);
}

void GraphicsComponent::connectCallback() {}

void GraphicsComponent::addTextureManager(std::shared_ptr<TextureManager> tm)
{
	textureManager = tm;
}

void GraphicsComponent::handleInput(const KeyCodes keyCode, const KeyboardEvent keyboardEvent) {}

std::shared_ptr<TextureManager> GraphicsComponent::getTextureManager() {
	return this->textureManager;
}
#pragma once
#include "GameObject.h"
#include "GraphicsComponent.h"
#include <string>
#include <memory>

class Advertisement : public GameObject
{
public:
	Advertisement(int x, int y, const std::vector<std::string>& textureList);
	void update(int time) override {}
	void handleInput(const KeyCodes& keyCode, const KeyboardEvent& keyboardEvent, Vector2D& mousePos) override {}
	void interact(std::shared_ptr<BehaviourObject> interactor) override {}
	void setParent() override {}
	void start() override {}
	void registerCollision(int x, int y, bool isDamaged, bool isTransitioned, bool isWinTrigger) override {}
private:
	std::string text;
	std::vector<std::string> possibleTextures;
	std::shared_ptr<GraphicsComponent> m_gc;
}; 

#pragma once
#include "GameObject.h"
#include <map>
#include "SceneModifier.h"

class IEquipment : public GameObject
{
public:

	std::string name;
	std::string collectMessage;
	std::map<std::string, std::string> textures;

	virtual void use() = 0;

	void handleInput(const KeyCodes& keyCode, const KeyboardEvent& keyboardEvent, Vector2D& mousePos) override;
	void update() override;
	void interact() override;
};
#pragma once

#include "InteractiveObject.h"
#include "GraphicsComponent.h"
#include "ColliderComponent.h"
#include <string>
#include <map>

class Pokemon : public InteractiveObject
{
public:
	Pokemon(int x, int y, std::string &texture);
	void interact() override;

protected:
	std::string sfxPath;

private:
	std::shared_ptr<GraphicsComponent> gc;
	std::shared_ptr<ColliderComponent> cc;
	std::string type;
	int id;
	int catchRate;
	const int animationSpeed = 120;
};
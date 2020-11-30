#pragma once

#include "InteractiveObject.h"
#include "GraphicsComponent.h"
#include "CollidingComponent.h"
#include <string>
#include <map>
#include "DamageStrategy.h"

class Pokemon : public InteractiveObject
{
public:
	Pokemon(int x, int y, std::string &texture);
	void interact(std::shared_ptr<BehaviourObject> interactor) override;
	void registerCollision(int x, int y, bool isDamaged, bool isTransitioned) override;
	void setParent() override;
protected:
	std::string sfxPath;

private:
	std::shared_ptr<CollisionStrategy> stp;
	std::shared_ptr<GraphicsComponent> gc;
	std::string type;
	int id;
	int catchRate;
	const int animationSpeed = 130;
};
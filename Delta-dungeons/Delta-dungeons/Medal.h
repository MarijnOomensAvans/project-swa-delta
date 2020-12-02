#pragma once
#include "IEquipment.h"
#include "StopStrategy.h"
class Medal : public IEquipment
{
public:
	Medal(int x, int y, std::string texture);

	void interact() override;
	void use() override;

private:
	std::shared_ptr<CollisionStrategy> stp;
	std::shared_ptr<GraphicsComponent> gc;
	std::shared_ptr<CollidingComponent> cc;
};


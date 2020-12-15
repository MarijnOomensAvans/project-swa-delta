#include "DamageStrategy.h"

void DamageStrategy::actCollision(std::shared_ptr<BehaviourObject> collider, int x, int y, KeyCodes direction)
{
	auto col = dynamic_cast<IInteractiveObject*>(collider.get());
	col->registerCollision(x, y, true, false, false);
}

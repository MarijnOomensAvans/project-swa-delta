#include "TransitionStrategy.h"

void TransitionStrategy::actCollision(std::shared_ptr<BehaviourObject> collider, int x, int y, KeyCodes direction)
{
	auto col = dynamic_cast<InteractiveObject*>(collider.get());
	col->registerCollision(x, y, false, true);
}
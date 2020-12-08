#pragma once

#include "CollisionStrategy.h"
#include "IInteractiveObject.h"

class PuzzleExitStrategy : public CollisionStrategy
{
public:
    ENGINE_API PuzzleExitStrategy() {}
    ENGINE_API ~PuzzleExitStrategy() {}

    ENGINE_API void actCollision(std::shared_ptr<BehaviourObject> collider, int x, int y, KeyCodes direction) override;

private:
};

#pragma once
#include "XMLSceneParser.h"
#include "GameObjectBuilder.h"
#include "GameObjectFactory.h"
#include "Puzzle.h"

typedef void(*cbCollision) (void*, std::shared_ptr<CollidingComponent>, std::shared_ptr<BehaviourObject>, int, int, KeyCodes, int);
typedef void(*cbInteract) (void*, std::shared_ptr<BehaviourObject>, int, int);
typedef void(*cbTriggerCollision) (void*);

class PuzzleFactory : public GameObjectFactory
{
public:
	std::shared_ptr<GameObjectBuilder> builder;
	std::multimap<std::string, std::shared_ptr<IInteractiveObject>> puzzleObjects;

	PuzzleFactory();
	
	void createPuzzle(std::string levelName, cbInteract interactCb, cbCollision collisionCb, void* p);

	std::map<std::string, std::string> passTextures() const;

private:
	std::unique_ptr<Puzzle> puzzle;

};

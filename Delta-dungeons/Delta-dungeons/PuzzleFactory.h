#pragma once

#include "XMLSceneParser.h"
#include "GameObjectBuilder.h"
#include "GameObjectFactory.h"
#include "Puzzle.h"

#include <memory>

typedef void(*cbCollision) (void*, std::shared_ptr<CollidingComponent>, std::shared_ptr<BehaviourObject>, int, int, KeyCodes, int);
typedef void(*cbInteract) (void*, std::shared_ptr<BehaviourObject>, int, int, int, int);

class PuzzleFactory : public GameObjectFactory
{
public:
	std::shared_ptr<GameObjectBuilder> builder;
	std::shared_ptr<Puzzle> puzzle;

	std::multimap<std::string, std::shared_ptr<IInteractiveObject>> puzzleObjects;

	PuzzleFactory();
	
	void createPuzzle(std::string levelName, cbInteract interactCb, cbCollision collisionCb, void* p);
	void createPuzzleOne(std::shared_ptr<ParserData> parsedData, const std::string& puzzleName, cbInteract interactCb, cbCollision collisionCb, void* p);
	void createPuzzleTwo(std::shared_ptr<ParserData> parsedData, const std::string& puzzleName, cbInteract interactCb, cbCollision collisionCb, void* p);

	void createPuzzleObject(std::shared_ptr<ParserData> parsedData, const std::string& puzzleName, const std::string& objectName, cbInteract interactCb, cbCollision collisionCb, void* p);

	std::map<std::string, std::string> passTextures() const;

};


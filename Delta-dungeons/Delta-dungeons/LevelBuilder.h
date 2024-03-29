#pragma once
#include "LevelScene.h"
#include "Vector2D.h"
#include "EquipmentFactory.h"
#include "HUDFactory.h"
#include "PokemonFactory.h"
#include "NPCFactory.h"
#include "PlayerFactory.h"
#include "PuzzleFactory.h"
#include "EngineFacade.h"
#include "World.h"

typedef void(*cbCamera) (void*, int, int);
typedef void(*cbInteract) (void*, std::shared_ptr<BehaviourObject>, int, int, int, int);
typedef void(*cbGameOver) (void*);
typedef void(*cbCollision) (void*, std::shared_ptr<CollidingComponent>, std::shared_ptr<BehaviourObject> behaviourObject, int, int, KeyCodes, int);
typedef void(*cbThrowCollision) (void*, std::shared_ptr<BehaviourObject>, int, int, KeyCodes, int);
typedef void(*cbNextLevel) (void*);

class LevelBuilder
{
public:
	LevelBuilder(const std::string& levelName, std::shared_ptr<EngineFacade> ef);
	~LevelBuilder() {};
	void reset();
	void setPlayer(cbNextLevel f, void* gm);
	Vector2D getPlayerPosition();
	void setNPCs();
	void setPokemon();
	void setHud();
	void setWorld();
	void setEquipment();
	void setPuzzle();
	Scene getScene();

	static void staticCheckCollisionCallbackFunction(void* p, std::shared_ptr<CollidingComponent> collider, std::shared_ptr<BehaviourObject> behaviourObject, int x, int y, KeyCodes direction, int w);
	void passCollisionCheck(std::shared_ptr<CollidingComponent> collider, std::shared_ptr<BehaviourObject> behaviourObject, int x, int y, KeyCodes direction, int w);

	static void staticThrowCollisionCallbackFunction(void* p, std::shared_ptr<BehaviourObject> collider, int x, int y, KeyCodes direction, int w);
	void throwCollisionCheck(std::shared_ptr<BehaviourObject> collider, int x, int y, KeyCodes direction, int w);

	static void staticCameraCallbackFunction(void* p, int x, int y);
	void passPlayerPosition(int x, int y);

	static void staticInteractCallbackFunction(void* p, std::shared_ptr<BehaviourObject> player, int x, int y, int w, int h);
	void interactCallbackFunction(std::shared_ptr<BehaviourObject> player, int x, int y, int w, int h);

	static void staticGameOverbackFunction(void* p);
	void gameOverCallbackFunction();

	static bool staticCheckInRangeCameraCallBack(void* p, int x, int y);
	bool checkInRangeCameraCallBack(int x, int y);

	static void staticAiCollisionCallback(void* p, std::shared_ptr<CollidingComponent> collider, std::shared_ptr<BehaviourObject> behaviourObject, int x, int y, KeyCodes direction, int w);
	void aiCollisionCallback(std::shared_ptr<CollidingComponent> collider, std::shared_ptr<BehaviourObject> behaviourObject, int x, int y, KeyCodes direction, int w);

private:
	std::string levelName;
	LevelScene scene;

	PlayerFactory playerFactory;
	EquipmentFactory equipmentFactory;
	NPCFactory npcFactory;
	PokemonFactory pokemonFactory;
	HUDFactory hudFactory;
	PuzzleFactory puzzleFactory;
	std::shared_ptr<World> world;

	std::vector<std::shared_ptr<BehaviourObject>> behaviourObjects;
	std::shared_ptr<EngineFacade> engineFacade;
};

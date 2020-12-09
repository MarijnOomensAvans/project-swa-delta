#pragma once
#include <vector>
#include <memory>
#include "PuzzleObject.h"
#include "ParserData.h"
#include "BoulderPuzzleObject.h"
#include "TriggerPuzzleObject.h";

typedef void(*cbInteract) (void*, std::shared_ptr<BehaviourObject>, int, int);
typedef void(*cbCollision) (void*, std::shared_ptr<BehaviourObject>, int, int, KeyCodes, int);

class Puzzle
{
public:
	Puzzle() {}
	~Puzzle() {}

	//interactive object: 
		//door, trigger, boulder

	//deur die open kan gaan, //interact bevat opendoorBoolean check
	std::vector<std::shared_ptr<IInteractiveObject>> doors;



	//boulder die gepushed kan worden, //interact bevat direction
	std::map<std::string, std::shared_ptr<IInteractiveObject>> boulders;

	//gameobject die checkt of iets op //interact bevat isTriggered bool
	std::map<std::string, std::shared_ptr<IInteractiveObject>> triggers;

	//std::vector<std::shared_ptr<IInteractiveObject>> boulders;

	//verzamel alle behaviourobjects
	//en paas ze door 


	//interact->gaat pas open 
																			//check x, y, cast to door, settrue
	//player --- boulder -> interact(behaviourobject) --- func --- puzzle->doors->settrue() --- puzzle->checkTrue() --- opendoor 

	//todo
	//static method

	void createBoulder(std::shared_ptr<ParserData> parser, cbCollision cbCollision, cbInteract cbInteract, void* gPointer);
	void createTrigger(std::shared_ptr<ParserData> parser);

	static void staticTriggerCallbackFunction(void* p);
	void trigger();

private:
};
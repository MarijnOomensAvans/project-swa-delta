#pragma once
#include <string>
#include <map>
#include "NPC.h"
#include "Pokemon.h"
#include "GameObjectBuilder.h"
#include <memory>

class NPCManager 
{
public:
	NPCManager();
	~NPCManager();

	std::map<std::string, std::shared_ptr<InteractiveObject>> npcs;

	void createNPC();
	std::shared_ptr<GameObjectBuilder> builder;
	std::map<std::string, std::string> passTextures() const;
};
#pragma once

#include "UIManager.h"
#include "EquipmentManager.h"
#include "PlayerManager.h"
#include "EngineFacade.h"
#include "XMLSceneParser.h"
#include "SceneLoader.h"
#include "NPCManager.h"
#include "Scene.h"
#include "DebugUtilities.h"
#include "SceneModifier.h"

class GameManager {
public: 
	GameManager();
	~GameManager() {}
	void registerBehaviourObjects();
	void registerTextures(std::map<std::string, std::string> textures);

	static void staticPlayerToTileCallbackFunction(void* p, int x, int y);
	static void staticTileToPlayerCallbackFunction(void* p);
	static void staticCameraCallbackFunction(void* p, int x, int y);
	static void staticInteractCallbackFunction(void* p, int x, int y);


	void playerToTileCallbackFunction(int x, int y);
	void tileToPlayerCallbackFunction();
	void npcManagerCallbackFunction(int x, int y);


	void passPlayerPosition(int x, int y);
	void registerFonts(std::map<std::string, std::string> fonts);
	void passInteraction(int x, int y);

private:
	std::shared_ptr<EngineFacade> engineFacade;
	std::shared_ptr<Scene> scene;
	UIManager uiManager;
	PlayerManager playerManager;
	EquipmentManager eqManager;
	NPCManager npcManager;
};
#pragma once

#include "UIManager.h"
#include "EquipmentManager.h"
#include "PlayerManager.h"
#include "EngineFacade.h"
#include "XMLSceneParser.h"
#include "SceneLoader.h"

class GameManager {
public: 
	std::shared_ptr<EngineFacade> engineFacade;
	UIManager uiManager;
	PlayerManager playerManager;
	EquipmentManager eqManager;
	Scene scene;

	GameManager();
	~GameManager();
	void registerBehaviourObjects();
	void registerTextures(std::map<std::string, std::string> textures);
	static void staticCameraCallbackFunction(void* p,int x, int y);
	void passPlayerPosition(int x, int y);
	void registerFonts(std::map<std::string, std::string> fonts);

private:

};
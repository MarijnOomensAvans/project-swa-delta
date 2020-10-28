#pragma once
#include "BehaviourObject.h"
#include "AssetManager.h"
#include "GameObject.h"
#include "Input.h"
#include "RenderFacade.h"
#include "SceneManager.h"
#include "TextureManager.h"
#include <vector>

// Engincontroller class
//
// This class is the main controller class of the Engine, where all other controllers and managers get instantiated and passed into other objects.

class EngineController {
public:
	ENGINE_API EngineController();
	ENGINE_API EngineController(std::vector<std::shared_ptr<BehaviourObject>> behaviourObjects, std::shared_ptr<RenderFacade>renderFacade, std::shared_ptr<AssetManager>assetManager, std::shared_ptr<TextureManager>textureManager);
	ENGINE_API ~EngineController();

	void update(std::vector<std::shared_ptr<BehaviourObject>>& bhObjects);
	static void staticInputCallbackFunction(void* p, const KeyCodes keyCode, const KeyboardEvent keyboardEvent);
	void inputCallbackFunction(const KeyCodes keyCode, const KeyboardEvent keyboardEvent);
	ENGINE_API void addTexture(std::string name, std::string path);
	ENGINE_API void registerBehaviourObjects(std::vector<std::shared_ptr<BehaviourObject>> objects);
	ENGINE_API void registerTextures(std::map<std::string, std::string> textures);
	ENGINE_API void startGame();

private:
	std::vector<std::shared_ptr<BehaviourObject>> behaviourObjects;
	std::vector<int> hudLayers;
	std::shared_ptr<SceneManager> sceneManager;
	std::shared_ptr<RenderFacade> renderFacade;
	std::shared_ptr<TextureManager> textureManager;
	std::shared_ptr<AssetManager> assetManager;
	std::shared_ptr<Input> input;

	void initRenderer(const char* title, int width, int height, bool fullscreen);
};
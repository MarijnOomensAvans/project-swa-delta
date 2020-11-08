#include "EngineController.h"
#include "GraphicsComponent.h"
#include <vector>
//Debug
#include "Button.h"
#include "Player.h"
#include "Tile.h"
#include "MainMenu.h"
#include "XMLSceneParser.h"

/// <summary>
/// This class has the responsibility of managing different classes in the engine. It communicaties with classes like TextureManager and RenderFacade.
/// </summary>
EngineController::EngineController() 
{
	assetManager = std::make_shared<AssetManager>();
	renderFacade = std::make_shared<RenderFacade>();
	textureManager = std::make_shared<TextureManager>(renderFacade,assetManager);
	input = std::make_shared<Input>(staticInputCallbackFunction, this);
	initRenderer("Delta Dungeons", 1280, 960, false);
}

EngineController::~EngineController() {}

/// <summary>
/// This method keeps executing while the gaming is running. It keeps updating all behaviour objects.
/// </summary>
/// <param name="bhObjects">Vector of all available behaviour objects.</param>
void EngineController::update(std::vector<std::shared_ptr<BehaviourObject>>& bhObjects)
{
	for (auto& bo : bhObjects)
	{
		bo.get()->update();
	}
}


/// <summary>
/// Receives input data from the class Input and passes it to a new function.
/// </summary>
/// <param name="p">Void pointer.</param>
/// <param name="keyCode">The key that is read, like 'W'.</param>
/// <param name="keyboardEvent">The key that is read, like 'W'.</param>
void EngineController::staticInputCallbackFunction(void* p, const KeyCodes keyCode, const KeyboardEvent keyboardEvent)
{
	((EngineController*)p)->inputCallbackFunction(keyCode, keyboardEvent);
}

/// <summary>
/// Calls the handleInput function for each game object.
/// </summary>
/// <param name="keyCode">The key that is read, like 'W'.</param>
/// <param name="keyboardEvent">The key that is read, like 'W'.</param>
void EngineController::inputCallbackFunction(const KeyCodes keyCode, const KeyboardEvent keyboardEvent)
{
	if (keyCode == KeyCodes::KEY_ESC) 
	{
		renderFacade.get()->quitGame();
	}
	else if (keyCode == KeyCodes::KEY_P)
	{
		renderFacade.get()->pauseGame();
	}
	else {
		for (auto& gameObject : behaviourObjects)
		{
			gameObject.get()->handleInput(keyCode, keyboardEvent);
		}
	}
}
#pragma endregion Input handling

/// <summary>
/// This method adds a texture to the AssetManager so that the texture is a known asset.
/// </summary>
/// <param name="name">Texture name.</param>
/// <param name="path">Texture path.</param>
void EngineController::addTexture(std::string name, std::string path) {
	assetManager->addTexture(name, path);
}

/// <summary>
/// This method calls an initialization function in RenderFacade with the given data, like resolution of the game window.
/// </summary>
/// <param name="title">Title of game window.</param>
/// <param name="width">Width of game window.</param>
/// <param name="height">Height of game window.</param>
/// <param name="fullscreen">Boolean whether game is fullscreen or not.</param>
void EngineController::initRenderer(const char* title, int width, int height, bool fullscreen)
{
	EngineController::renderFacade->init(title, width, height, fullscreen);
}



void EngineController::createCamera(int x, int y)
{
	renderFacade->createCamera(x,y);
}

/// <summary>
/// This method contains the game loop from which a few functions that need constant updating, are executed.
/// </summary>
void EngineController::startGame()
{
	while (renderFacade->renderer->isRunning) {

		renderFacade->setFrameStart();

		input.get()->handleInput(renderFacade->renderer->isPaused);
		if (!renderFacade->renderer->isPaused) 
		{
			renderFacade->beforeFrame();
			EngineController::update(behaviourObjects);
		}
		renderFacade->afterFrame();

		renderFacade->setFrameDelay();
	}
}

void EngineController::passPlayerPosition(int x, int y)
{
	std::tuple<int, int> positions = renderFacade->passPlayerPosition(x, y);
}

/// <summary>
/// This method registers all behaviour objects in a vector.
/// </summary>
/// <param name="objects">Vector of behaviour objects.</param>
void EngineController::registerBehaviourObjects(std::vector<std::shared_ptr<BehaviourObject>> objects) {
	for (auto& o : objects) 
	{
		if (dynamic_cast<GraphicsComponent*>(o.get()) != nullptr)
		{
			auto ngc = dynamic_cast<GraphicsComponent*>(o.get());
			ngc->addTextureManager(textureManager);
			this->behaviourObjects.emplace_back(ngc);
		}
		else if (dynamic_cast<TextComponent*>(o.get()) != nullptr)
		{
			auto ntc = dynamic_cast<TextComponent*>(o.get());
			ntc->addTextureManager(textureManager);
			this->behaviourObjects.emplace_back(ntc);
		}
		else 
		{
			this->behaviourObjects.emplace_back(o);
		}
	}
}

/// <summary>
/// This method registers all given textures, in the AssetManager.
/// </summary>
/// <param name="textures">Map of multiple textures.</param>
void EngineController::registerTextures(std::map<std::string, std::string> textures) {
	for (auto& t : textures) {
		assetManager.get()->addTexture(t.first, t.second);
	}
}

/// <summary>
/// This method registers all given fonts, in the AssetManager.
/// </summary>
/// <param name="fonts">Map of multiple fonts.</param>
void EngineController::registerFonts(std::map<std::string, std::string> fonts) {
	for (auto& t : fonts) {
		assetManager.get()->addFont(t.first, t.second);
	}
}

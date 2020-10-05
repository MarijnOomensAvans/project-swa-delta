#pragma once
#include <list>
#include "GameObject.h"
#include "SceneManager.h"
#include "SDLFacade.h"
#include "TextureManager.h"

class EngineController {
public:
		EngineController();
		~EngineController();
private:
	std::list<GameObject> gameObjects;
	std::list<int> hudLayers;
	SceneManager sceneManager;
	SDLFacade* sdlFacade;
	TextureManager* textureManager;
	void CreateGameObject();
	void Update(std::list<GameObject> gameObjects);
	void Render(std::list<GameObject> gameObjects);
	void StartGame();
	void Init();

};
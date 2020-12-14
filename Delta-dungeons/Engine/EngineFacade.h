#pragma once

#include <string>
#include "EngineController.h"
#include "main.h"

class EngineFacade 
{
public:
	ENGINE_API EngineFacade() {}
	ENGINE_API ~EngineFacade() {}

	ENGINE_API void init(const std::string& title, int screenWidth, int screenHeight, bool fullScreen);
	ENGINE_API void addTexture(const std::string& name, const std::string& path);
	ENGINE_API void registerBehaviourObjects(std::vector<std::shared_ptr<BehaviourObject>> objects);
	ENGINE_API void registerTextures(std::map<std::string, std::string> textures);
	ENGINE_API void registerFonts(std::map<std::string, std::string> fonts);
	ENGINE_API void registerAudio(std::map<std::string, std::string> tracks);
	ENGINE_API void startGame();
	ENGINE_API void createCamera(int x, int y);
	ENGINE_API void passPlayerPosition(int x, int y);
	ENGINE_API void registerScene(const std::string& sceneName, std::vector<std::shared_ptr<BehaviourObject>> behaviourObjects);
	ENGINE_API void loadScene(const std::string& sceneName, const std::string& fromScene, bool clearPrevious);
	ENGINE_API void loadPreviousScene();
	ENGINE_API void addOverlayScene(const std::string& sceneName);
	ENGINE_API void quitGame();
	ENGINE_API int getFPS();
	ENGINE_API void slowDownGame();
	ENGINE_API void speedUpGame();
	ENGINE_API void resetSpeedGame();
	ENGINE_API void pauseGame();
	ENGINE_API void addObjectToScene(std::shared_ptr<BehaviourObject> addObject);
	ENGINE_API void passInteract(std::shared_ptr<BehaviourObject> player, int x, int y, int w);
	ENGINE_API void passCollisionCheck(std::shared_ptr<CollidingComponent> collider, std::shared_ptr<BehaviourObject> behaviourObject, int x, int y, KeyCodes direction, int w);
	ENGINE_API void throwCollisionCheck(std::shared_ptr<BehaviourObject> collider, int x, int y, KeyCodes direction, int w);

	ENGINE_API void deleteObjectFromScene(std::shared_ptr<BehaviourObject> deletedObject);
	ENGINE_API void deleteColliderFromScene(std::shared_ptr<CollidingComponent> deletedCollider);
	ENGINE_API void gameOver();
	ENGINE_API void playAudio(const std::string& trackName, bool looped);
	ENGINE_API void deleteScene(const std::string& sceneName);
	ENGINE_API void replaceScene(const std::string sceneName, std::vector<std::shared_ptr<BehaviourObject>> objects);

private:
	std::unique_ptr<EngineController> engineController;
};
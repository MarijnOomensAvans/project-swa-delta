#include "EngineFacade.h"
/// <summary>
/// Facade between EngineController & GameManager
/// </summary>

//EngineFacade::EngineFacade() {
//	engineController = std::make_unique<EngineController>();
//}

/// <summary>
///  Init creates a unique EngineController object.
/// </summary>
void EngineFacade::init() {
	engineController = std::make_unique<EngineController>();
}

/// <summary>
/// Init creates a unique EngineController object.
/// </summary>

void EngineFacade::addTexture(std::string name, std::string path) {
	engineController->addTexture(name, path);
};

/// <summary>
/// Calls registerBehaviourObjects from the GameManager in the EngineController.
/// </summary>
void EngineFacade::registerBehaviourObjects(std::vector<std::shared_ptr<BehaviourObject>> objects) {
	engineController->registerBehaviourObjects(objects);
}

/// <summary>
/// Calls registerTextures from the GameManager in the EngineController.
/// </summary>
void EngineFacade::registerTextures(std::map<std::string, std::string> textures) {
	engineController.get()->registerTextures(textures);
}

/// <summary>
/// Calls registerFonts from the GameManager in the EngineController.
/// </summary>
void EngineFacade::registerFonts(std::map<std::string, std::string> fonts) {
	engineController.get()->registerFonts(fonts);
}

/// <summary>
///  Calls startGame from the GameManager in the EngineController.
/// </summary>
void EngineFacade::startGame() {
	engineController.get()->startGame();
}
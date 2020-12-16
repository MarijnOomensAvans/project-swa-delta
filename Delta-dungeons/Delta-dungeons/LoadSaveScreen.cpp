#include "LoadSaveScreen.h"

LoadSaveScreen::LoadSaveScreen()
{
	gc = std::make_unique<GraphicsComponent>();
	gc->setTexture("load_save");
	gc->isScreen = true;
	gc->imageDimensions = { 1280, 960 };
	this->components.emplace_back(std::move(gc));

	Colour color = { 0, 0, 0, 255 };

	std::unique_ptr<TextComponent> loadSaveText = std::make_unique<TextComponent>("Load a save file", "joystix", color, 64);
	loadSaveText->transform.position = { 220, 20 };
	this->components.emplace_back(std::move(loadSaveText));


	std::vector<std::string> possibleButtonTexLoad = { "button_load" };
	std::unique_ptr<Button> load1Button = std::make_unique<Button>(512, 200, possibleButtonTexLoad, staticLoad1CallbackFunction, this);
	this->components.emplace_back(std::move(load1Button));

	std::vector<std::string> possibleButtonTexExit = { "button_back" };
	std::unique_ptr<Button> exitButton = std::make_unique<Button>(512, 850, possibleButtonTexExit, staticBackCallbackFunction, this);
	this->components.emplace_back(std::move(exitButton));
}

void LoadSaveScreen::handleInput(const KeyCodes& keyCode, const KeyboardEvent& keyboardEvent, Vector2D& mousePos)
{
	if (keyboardEvent == KeyboardEvent::KEY_PRESSED)
	{
		if (keyCode == KeyCodes::KEY_BACKSPACE)
		{
			SceneLoader::getInstance().loadPreviousScene();
		}
	}
}

void LoadSaveScreen::staticLoad1CallbackFunction(const void* p)
{
	((LoadSaveScreen*)p)->load1CallbackFunction();
}

void LoadSaveScreen::load1CallbackFunction() const
{
	GameState::getInstance().reset();
	SceneLoader::getInstance().loadScene(SceneLoader::getInstance().getCurrentLevel(), "", true);
}

void LoadSaveScreen::staticBackCallbackFunction(const void* p)
{
	((LoadSaveScreen*)p)->backCallbackFunction();
}

void LoadSaveScreen::backCallbackFunction() const
{
	SceneLoader::getInstance().loadPreviousScene();
}
#include "PauseScreen.h"

PauseScreen::PauseScreen() 
{
	gc = std::make_unique<GraphicsComponent>();
	gc->setTexture("pause");
	gc->isScreen = true;
	gc->imageDimensions = { 1280, 960 };
	this->components.emplace_back(std::move(gc));

	std::vector<std::string> buttonHelp = { "button_help" };
	std::unique_ptr<Button> helpButton = std::make_unique<Button>(512, 300, buttonHelp, staticOpenHelpCallbackFunction, this);
	this->components.emplace_back(std::move(helpButton));

	std::vector<std::string> buttonSave = { "button_save" };
	std::unique_ptr<Button> saveButton = std::make_unique<Button>(512, 500, buttonSave, staticSaveCallbackFunction, this);
	this->components.emplace_back(std::move(saveButton));

	std::vector<std::string> buttonExit = { "button_exit" };
	std::unique_ptr<Button> exitButton = std::make_unique<Button>(512, 700, buttonExit, staticExitCallbackFunction, this);
	this->components.emplace_back(std::move(exitButton));

	Colour color = { 0, 0, 0, 255 };
	std::unique_ptr<TextComponent> pauseText = std::make_unique<TextComponent>("Pause", "joystix", color, 64);
	pauseText->transform.position = { 515, 100 };
	this->components.emplace_back(std::move(pauseText));
}

void PauseScreen::handleInput(const KeyCodes& keyCode, const KeyboardEvent& keyboardEvent, Vector2D& mousePos)
{
	if (keyboardEvent == KeyboardEvent::KEY_PRESSED)
	{
		if (keyCode == KeyCodes::KEY_ESC)
		{
			DebugUtilities::getInstance().pauseGame();
		}
	}
}

void PauseScreen::staticOpenHelpCallbackFunction(const void* p) 
{
	((PauseScreen*)p)->openHelpCallbackFunction();
}

void PauseScreen::openHelpCallbackFunction() const
{
	SceneLoader::getInstance().addOverlayScene("HelpScreen");
}

void PauseScreen::staticSaveCallbackFunction(const void* p) 
{
	((PauseScreen*)p)->saveCallbackFunction();
}

void PauseScreen::saveCallbackFunction() const {}

void PauseScreen::staticExitCallbackFunction(const void* p) 
{
	((PauseScreen*)p)->exitCallbackFunction();
}

void PauseScreen::exitCallbackFunction() const
{
	SceneLoader::getInstance().loadScene("MainMenuScreen", "", true);
}
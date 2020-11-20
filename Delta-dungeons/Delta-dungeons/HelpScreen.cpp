#include "HelpScreen.h"

HelpScreen::HelpScreen()
{
	this->textures.try_emplace("help", "Assets/help.png");
	this->fonts.try_emplace("comic", "Assets/comic.ttf");

	gc = std::make_unique<GraphicsComponent>();
	gc->setTexture("help");
	gc->isScreen = true;
	gc->imageDimensions = { 1280, 960 };
	this->components.emplace_back(std::move(gc));

	Colour color = { 0, 0, 0, 255 };

	std::unique_ptr<TextComponent> helpText = std::make_unique<TextComponent>("Help screen", "comic", color, 64);
	helpText->transform.position = { 450, 20 };
	this->components.emplace_back(std::move(helpText));

	std::unique_ptr<TextComponent> helpMove = std::make_unique<TextComponent>("Use arrow keys or W, A, S and D to move your character.", "comic", color, 32);
	helpMove->transform.position = { 100, 220 };
	this->components.emplace_back(std::move(helpMove));

	std::unique_ptr<TextComponent> helpInteract = std::make_unique<TextComponent>("Use E to interact.", "comic", color, 32);
	helpInteract->transform.position = { 100, 320 };
	this->components.emplace_back(std::move(helpInteract));

	std::unique_ptr<TextComponent> helpBack = std::make_unique<TextComponent>("Press BACKSPACE to go back to the previous screen.", "comic", color, 32);
	helpBack->transform.position = { 100, 420 };
	this->components.emplace_back(std::move(helpBack));

	std::unique_ptr<TextComponent> helpFps = std::make_unique<TextComponent>("Press TAB to toggle the FPS counter in the upper right corner in-game.", "comic", color, 32);
	helpFps->transform.position = { 100, 520 };
	this->components.emplace_back(std::move(helpFps));

	std::unique_ptr<TextComponent> helpGameSpeed = std::make_unique<TextComponent>("Press , to decrease FPS. Press . to increase FPS. Press / to reset FPS to 60.", "comic", color, 32);
	helpGameSpeed->transform.position = { 100, 620 };
	this->components.emplace_back(std::move(helpGameSpeed));

	std::vector<std::string> possibleButtonTexExit = { "button_exit" };
	std::unique_ptr<Button> exitButton = std::make_unique<Button>(500, 720, possibleButtonTexExit, staticBackCallbackFunction, this);
	this->components.emplace_back(std::move(exitButton));
}

void HelpScreen::handleInput(const KeyCodes &keyCode, const KeyboardEvent &keyboardEvent, Vector2D &mousePos)
{
	if (keyboardEvent == KeyboardEvent::KEY_PRESSED)
	{
		if (keyCode == KeyCodes::KEY_BACKSPACE)
		{
			SceneLoader::getInstance().loadPreviousScene();
		}
	}
}

void HelpScreen::staticBackCallbackFunction(const void* p)
{
	((HelpScreen*)p)->backCallbackFunction();
}

void HelpScreen::backCallbackFunction() const
{
	SceneLoader::getInstance().loadPreviousScene();
}
#include "DialoguePopup.h"

DialoguePopup::DialoguePopup()
{
	gc = std::make_unique<GraphicsComponent>();
	gc->setTexture("dialogue_box");
	gc->isScreen = true;
	gc->imageDimensions = { 1280, 292 };

	this->transform.position = { 5, 700 };
	gc->transform.position = this->transform.position;

	this->components.emplace_back(std::move(gc));
}

void DialoguePopup::handleInput(const KeyCodes& keyCode, const KeyboardEvent& keyboardEvent, Vector2D& mousePos)
{
	if (keyboardEvent == KeyboardEvent::KEY_PRESSED && keyCode == KeyCodes::KEY_E)
	{
		SceneLoader::getInstance().loadPreviousScene();
	}
}

void DialoguePopup::playDialogue(std::vector<std::string> param)
{

}
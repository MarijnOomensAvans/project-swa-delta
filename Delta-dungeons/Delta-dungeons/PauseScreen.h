#pragma once

#include "Screen.h"
#include "Button.h"
#include "TextComponent.h"
#include "SceneLoader.h"
#include "DebugUtilities.h"
#include "GameState.h"
#include "AudioUtilities.h"

class PauseScreen : public Screen
{
public:
	PauseScreen();
	void setParent() override {}

	void handleInput(const KeyCodes& keyCode, const KeyboardEvent& keyboardEvent, Vector2D& mousePos) override;
	static void staticOpenHelpCallbackFunction(const void* p);
	void openHelpCallbackFunction() const;
	static void staticSaveCallbackFunction(const void* p);
	void saveCallbackFunction() const;
	static void staticExitCallbackFunction(const void* p);
	void exitCallbackFunction() const;
private:
	std::vector<Button> buttons;
};
#pragma once

#include "Screen.h"
#include "TextComponent.h"
#include "Button.h"
#include "SceneLoader.h"
#include "AudioUtilities.h"

class GameWinScreen : public Screen
{
public:
	GameWinScreen();
	void setParent() override {}

	void start() override;

	void handleInput(const KeyCodes& keyCode, const KeyboardEvent& keyboardEvent, Vector2D& mousePos) override;

	static void staticNextCallbackFunction(const void* p);
	void nextCallbackFunction() const;
};


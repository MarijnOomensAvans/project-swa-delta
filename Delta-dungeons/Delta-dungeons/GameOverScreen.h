#pragma once

#include "Screen.h"
#include "TextComponent.h"
#include "Button.h"

class GameOverScreen : public Screen
{
public:
	GameOverScreen();
	~GameOverScreen();

	void closeScreen() override;

	void restartGame();
};
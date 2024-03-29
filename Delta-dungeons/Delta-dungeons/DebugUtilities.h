#pragma once

#include "EngineFacade.h"

class DebugUtilities
{
public:
	static DebugUtilities& getInstance();

	int getFPS() const;
	void setEngineFacade(std::shared_ptr<EngineFacade> engineFacade);
	void toggleShowFPS();
	bool isShowingFPS();
	void slowDownGame() const;
	void speedUpGame() const;
	void resetSpeedGame() const;
	void pauseGame() const;
	void pauseInput() const;

	void toggleCheatCollision();
	bool isCheatCollisionOn();

private:
	static DebugUtilities debugUtilities;
	std::shared_ptr<EngineFacade> engineFacade;
	bool showFPS = false;
	bool cheatCollision = false;

	DebugUtilities() {}
};
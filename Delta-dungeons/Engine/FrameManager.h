#pragma once

#include "SDL.h"

class FrameManager {
public:
	int FPS;
	int frameDelay;
	int frameTime;
	Uint32 frameStart;

	FrameManager();
	~FrameManager();

	void setFrameStart();
	void setFrameDelay();
};
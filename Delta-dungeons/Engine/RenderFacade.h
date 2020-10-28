#pragma once

#include "SDL.h"
#include "main.h"
#include "DrawController.h"
#include "FrameManager.h"
#include "Renderer.h"
#include "Vector2D.h"
#include <iostream>
#include <vector>
#include <map>

class RenderFacade {
public:
	ENGINE_API RenderFacade();
	ENGINE_API ~RenderFacade();

	std::shared_ptr<DrawController> drawController;
	std::shared_ptr<FrameManager> frameManager;
	std::shared_ptr<Renderer> renderer;
	std::string constructorError() const noexcept;

	SDL_Texture* loadTexture(const std::string* imageLocation);
	SDL_Texture* loadFontTexture(const std::string* fontLocation, const std::string* color, const std::string* stringValue);

	void setFrameStart();
	void setFrameDelay();
	void drawTexture(std::string path, const Transform& transform, const Vector2D& coordinates, const Vector2D& sourceDimensions);
	void init(const char* title, const int width, const int height, const bool fullscreen);
	void render(std::vector<std::shared_ptr<GameObject>> gameObjects);
	void update(std::vector<GameObject> gameObjects);
	void clean();
	void beforeFrame();
	void afterFrame();
};
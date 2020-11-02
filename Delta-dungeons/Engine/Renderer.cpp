#include "Renderer.h"

/// <summary>
/// The renderer class is responsible for setting up everything before rendering.
/// </summary>
Renderer::Renderer() {
	camera = { 0, 0, 0, 0 };
};

Renderer::~Renderer() {};

/// <summary>
/// The init methods creates all SDL required items to render a screen and textures within that screen.
/// </summary>
/// <param name="title">The title of the screen.</param>
/// <param name="width">The width of the screen.</param>
/// <param name="height">The height of the screen.</param>
/// <param name="fullscreen">If the screen is fullscreen or not.</param>
void Renderer::init(const char* title, int width, int height, bool fullscreen) {
	camera = { 0,0, width, height };

	int flags = 0;
	if (fullscreen) {
		flags = SDL_WINDOW_FULLSCREEN;
	}
	try {
		if (SDL_Init(SDL_INIT_EVERYTHING) == 0) {
			std::cout << "Subsystems initialised!!!" << std::endl;
			sdlWindow = SDL_CreateWindow(title, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, flags);
			if (sdlWindow) {
				std::cout << "Window created!" << std::endl;
			}
			else {
				isRunning = false;
				throw("Failed to create window!");
			}
			sdlRenderer = SDL_CreateRenderer(sdlWindow, -1, 0);
			if (sdlRenderer)
			{
				SDL_SetRenderDrawColor(sdlRenderer, 128, 128, 128, 255);
				std::cout << "Renderer created!" << std::endl;
			}
			else {
				isRunning = false;
				throw("Failed to create Render!");
			}
			isRunning = true;
		}
		else {
			throw("Subsystems are not initialised!");
			isRunning = false;
		}
		std::cout << "Image is loaded and created!" << std::endl;
		if (TTF_Init() == -1)
		{
			std::cout << "Failed to initialise SDL_ttf!" << std::endl;
		}
	}
	catch (std::string error) {
		std::cout << "Error: " << error << std::endl;
	}
}


/// <summary>
/// updateCamera updates the camera based on the position of the player.
/// </summary>
void Renderer::updateCamera()
{

	//update gameobjects positioning based on camera x and y

	//camera.x = player.position.x - 400;
	//camera.y = player.position.y - 320;

	if (Renderer::camera.x < 0) {
		Renderer::camera.x = 0;
	}
	if (Renderer::camera.y < 0) {
		Renderer::camera.y = 0;
	}
	if (Renderer::camera.x > camera.w) {
		Renderer::camera.x = camera.w;
	}

	if (Renderer::camera.y > camera.h) {
		Renderer::camera.y = camera.h;
	}
}


/// <summary>
/// This methods cleans the game files and destroys all sdl components to makes sure all memory is cleared.
/// </summary>
void Renderer::clean()
{
	SDL_DestroyWindow(sdlWindow);
	SDL_DestroyRenderer(sdlRenderer);
	SDL_Quit();
	std::cout << "Game Cleaned" << std::endl;
}

/// <summary>
/// This method pauzes the game.
/// </summary>
void Renderer::stop()
{
	isRunning = false;
}

/// <summary>
/// This methods cleans the screen before the frame is called.
/// </summary>
void Renderer::beforeFrame()
{
	SDL_RenderClear(sdlRenderer);
}

/// <summary>
/// This method draws the screen after the frame is done.
/// </summary>
void Renderer::afterFrame()
{
	SDL_RenderPresent(sdlRenderer);
}
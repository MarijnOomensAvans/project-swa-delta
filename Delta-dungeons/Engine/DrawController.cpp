#include "DrawController.h"

/// <summary>
/// The drawcontroller renders all the items in the game using a single renderer.
/// </summary>
/// <param name="r">The game renderer (SDL)</param>
DrawController::DrawController(std::shared_ptr<Renderer> renderer) : renderer(renderer) {}

/// <summary>
/// The loadtexture method loads in a textures based on a given path. If the texture is already made, it will return it without creating a new one.
/// </summary>
/// <param name="path">The path of where the .png can be found.</param>
/// <returns>Returns a SDL_Texture to be drawn on the screen in another method.</returns>
SDL_Texture* DrawController::loadTexture(const std::string& path)
{
	if (textures.count(path))
	{
		return textures.find(path)->second;
	}
	else
	{
		SDL_Surface* tempSurface = IMG_Load(path.c_str());
		try 
		{
			if (!tempSurface) {
				throw("Image not loaded in!");
			}
		}
		catch (std::string error) {
			std::cout << "Error: " << error << std::endl;
		}
		SDL_Texture* tex = SDL_CreateTextureFromSurface(renderer->sdlRenderer, tempSurface);
		textures.try_emplace(path, tex);
		SDL_FreeSurface(tempSurface);
		return tex;
	}
}

/// <summary>
/// The loadFont method loads in a textures based on a font and string of text. If the texture is already made, it will return it without creating a new one.
/// </summary>
/// <param name="text">This is the text that will appear in the label.</param>
/// <param name="font">This is the font the text will be written in.</param>
/// <param name="colour">This is the color the text will appear in.</param>
/// <param name="fontSize">This is the size of the text.</param>
/// <returns>Returns a SDL_Texture to be drawn on the screen in another method.</returns>
SDL_Texture* DrawController::loadFont(const std::string& text, const std::string& font, const Colour& colour, int fontSize)
{
	if (textures.count(text))
	{
		return textures.find(text)->second;
	}
	else 
	{
		SDL_Color textColour = { static_cast<Uint8>(colour.r), static_cast<Uint8>(colour.g), static_cast<Uint8>(colour.b), static_cast<Uint8>(colour.a) };
		SDL_Surface* tempSurface = TTF_RenderText_Blended_Wrapped(TTF_OpenFont(font.c_str(), fontSize), text.c_str(), textColour, 1200);
		try
		{
			if (!tempSurface)
			{
				throw("Font not loaded in!");
			}
		}
		catch (std::string error)
		{
			std::cout << "Error: " << error << std::endl;
		}
		SDL_Texture* tex = SDL_CreateTextureFromSurface(renderer->sdlRenderer, tempSurface);
		textures.try_emplace(text, tex); // TODO: Meer unieke manier vinden om op te zoeken
		SDL_FreeSurface(tempSurface);
		return tex;
	}
}

void DrawController::deleteTexture(const std::string& textureName)
{
	if (textures.find(textureName) != textures.end()) 
	{
		SDL_DestroyTexture(textures.find(textureName)->second);
		textures.erase(textureName);
	}
}
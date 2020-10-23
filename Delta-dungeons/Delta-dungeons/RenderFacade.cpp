#include "RenderFacade.h"
RenderFacade::~RenderFacade() {}

std::string RenderFacade::constructorError() const noexcept {
	return "SDLFacade constructor is not called";
}

RenderFacade::RenderFacade() {
	RenderFacade::frameManager = std::make_shared<FrameManager>();
	RenderFacade::renderer = std::make_shared<Renderer>();
	RenderFacade::drawController = std::make_shared<DrawController>(renderer);
}

void RenderFacade::init(const char* title, const int width, const int height, const bool fullscreen) {
	RenderFacade::renderer->init(title, width, height, fullscreen);
}

void RenderFacade::setFrameStart() 
{
	RenderFacade::frameManager->setFrameStart();
}

void RenderFacade::setFrameDelay() 
{
	RenderFacade::frameManager->setFrameDelay();
}

void RenderFacade::render(std::list<std::shared_ptr<GameObject>> gameObjects) 
{
	RenderFacade::renderer->render(gameObjects);
}

void RenderFacade::clean()
{
	RenderFacade::renderer->clean();
}

SDL_Texture* RenderFacade::loadTexture(const std::string* path) {
	return RenderFacade::drawController->loadTexture(path->c_str());
}
void RenderFacade::drawTexture(const char* path, const Vector2D& destination2D, const Vector2D& coordinates) {
	Vector2D size;
	SDL_Rect source;
	source.x = coordinates.x;	// Moet 0 zijn om de volledige texture te tekenen, omdat de source rectangle aangeeft welk deel van de texture wordt getekend. Dus als dit 32 is, wordt x positie 32 + width
	source.y = coordinates.y;	// getekend en dat kan niet met een 32 x 32 texture. Dan wordt als het ware de 'data' buiten de texture getekend, terwijl daar niets zit.
	source.w = 32; // Moet eigenlijk width en height zijn, maar 'Vector2D' heeft alleen x en y variabelen.
	source.h = 32; //
    SDL_Texture* texture = drawController->loadTexture(path);

    SDL_Rect source;
    source.x = 0;    // Moet 0 zijn om de volledige texture te tekenen, omdat de source rectangle aangeeft welk deel van de texture wordt getekend. Dus als dit 32 is, wordt x positie 32 + width
    source.y = 0;    // getekend en dat kan niet met een 32 x 32 texture. Dan wordt als het ware de 'data' buiten de texture getekend, terwijl daar niets zit.
    source.w = sprite2D.spriteLocationInPNGWidth; // Moet eigenlijk width en height zijn, maar 'Vector2D' heeft alleen x en y variabelen.
    source.h = sprite2D.spriteLocationInPNGHeight; //


    SDL_Rect destination;
    destination.x = destination2D.x; // Locatie waar je de texture wilt tekenen.
    destination.y = destination2D.y; //
    destination.w = 32; // Moet eigenlijk width en height zijn, maar 'Vector2D' heeft alleen x en y variabelen.
    destination.h = 32; //


    RenderFacade::drawController->drawTexture(texture, source, destination);
}

void RenderFacade::beforeFrame()
{
	RenderFacade::renderer->beforeFrame();
}

void RenderFacade::afterFrame() 
{
	RenderFacade::renderer->afterFrame();
}
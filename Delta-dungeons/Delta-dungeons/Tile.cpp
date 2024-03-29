#include "Tile.h"

/// <summary>
/// Grab the image from the first row only of the png
/// </summary>
/// <param name="x">The horizontal placement of tile</param>
/// <param name="y">The vertical placement of tile</param>
/// <param name="xImage">Specific horizontal image location of tile png</param>
Tile::Tile(int x, int y, int xImage, bool collider, bool isTrigger, bool isWinTrigger)
{
	originX = x * 128;
	originY = y * 128;
	isCollider = collider;

	this->transform.scale.multiply({ 4, 4 });
	transform.position.x = x * 128;
	transform.position.y = y * 128;
	imageCoordinates = Vector2D(xImage * 32, 0);

	if (collider)
	{
		if (isTrigger) 
		{
			stp = std::make_shared<TransitionStrategy>();
		}
		else if (isWinTrigger)
		{
			stp = std::make_shared<LevelWinStrategy>();
		}
		else 
		{
			stp = std::make_shared<StopStrategy>();
		}
		cc = std::make_shared<CollidingComponent>(stp);
		cc->tag = "tile";
		cc->transform.position = this->transform.position;
		this->components.emplace_back(cc);
	}
}

/// <summary>
/// Grabs the images from the second row and beyond of the png
/// </summary>
/// <param name="x">The horizontal placement of tile</param>
/// <param name="y">The vertical placement of tile</param>
/// <param name="xImage">Horizontal image location of tile png</param>
/// <param name="yImage">Vertical image location of tile png</param>

Tile::Tile(int x, int y, int yImage, int xImage, bool collider, bool isTrigger, bool isWinTrigger)
{
	originX = x * 128;
	originY = y * 128;
	isCollider = collider;
	this->transform.scale.multiply({ 4, 4 });
	transform.position.x = x * 128;
	transform.position.y = y * 128;
	imageCoordinates = Vector2D(xImage * 32, yImage * 32);

	if (collider)
	{
		if (isTrigger)
		{
			stp = std::make_shared<TransitionStrategy>();
		}
		else if (isWinTrigger)
		{
			stp = std::make_shared<LevelWinStrategy>();
		}
		else
		{
			stp = std::make_shared<StopStrategy>();
		}
		cc = std::make_shared<CollidingComponent>(stp);
		cc->tag = "tile";
		cc->transform.position = this->transform.position;
		this->components.emplace_back(cc);
	}
}

/// <summary>
/// Add the graphics component and set the tranform-, imagecoordinate- and texture values.
/// </summary>
/// <param name="graphicsComnponent">An clean graphicscomponent without tile information</param>
/// <param name="name">Texture name of the png</param>
void Tile::addGraphicsComponent(const std::string& name)
{
	gc = std::make_shared<GraphicsComponent>();
	gc->transform = transform;
	gc->imageCoordinates = imageCoordinates;
	gc->setTexture(name);
	gc->isScreen = false;
	this->components.emplace_back(gc);
}
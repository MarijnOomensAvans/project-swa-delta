#include "Button.h"

/// <summary>
/// The constructor intialises the graphicscomponent and defines the size, scale and textures.
/// </summary>
/// <param name="x">The horizontal position</param>
/// <param name="y">The vertical position</param>
/// <param name="textureList">Information of texture names.</param>
Button::Button(int x, int y, const std::vector<std::string>& textureList, buttonCb onClick, const void* p) : onCLickFunc(onClick), pointer(p)
{
	m_gc = std::make_shared<GraphicsComponent>();
	transform.position = { x, y };

	m_gc->transform = this->transform;
	m_gc->imageDimensions = { 140, 50 };
	m_gc->transform.scale.multiply({ 2, 2 });
	m_gc->isScreen = true;

	possibleTextures = textureList;
	m_gc->setTexture(possibleTextures[0]);
	this->components.emplace_back(m_gc);
}

void Button::handleInput(const KeyCodes& keyCode, const KeyboardEvent& keyboardEvent, Vector2D& mousePos)
{
	if (cursorInBouds(mousePos))
	{
		if (keyboardEvent == KeyboardEvent::MOUSE_CLICKED)
		{
			m_gc->setTexture(possibleTextures[0]);
			onCLickFunc(pointer);
		}
		if (keyboardEvent == KeyboardEvent::MOUSE_MOVED)
		{
			if (possibleTextures.size() > 1)
			{
				m_gc->setTexture(possibleTextures[1]);
			}
		}
	}
	else if (keyboardEvent == KeyboardEvent::MOUSE_MOVED)
	{
		m_gc->setTexture(possibleTextures[0]);
	}
}

bool Button::cursorInBouds(const Vector2D& mousePos)
{
	return (mousePos.x > m_gc->transform.position.x && mousePos.x < m_gc->transform.position.x + m_gc->imageDimensions.x * m_gc->transform.scale.x
		&& mousePos.y > m_gc->transform.position.y && mousePos.y < m_gc->transform.position.y + m_gc->imageDimensions.y * m_gc->transform.scale.y);
}

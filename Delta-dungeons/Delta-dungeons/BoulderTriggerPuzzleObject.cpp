#include "BoulderTriggerPuzzleObject.h"

BoulderTriggerPuzzleObject::BoulderTriggerPuzzleObject(int x, int y, const std::string& texture)
{
	this->transform.position = { x * 128, y * 128 };
	this->transform.scale.multiply({ 4, 4 });

	gc = std::make_shared<GraphicsComponent>();
	gc->setTexture(texture);

	gc->imageDimensions = { 32, 32 };
	gc->transform = transform;
	gc->isScreen = false;

	this->components.emplace_back(gc);
}

void BoulderTriggerPuzzleObject::setBoulderTriggerCallback(cbTriggerCollision triggerCB, void* p)
{
	this->tFunc = triggerCB;
	this->pointer = p;
}

void BoulderTriggerPuzzleObject::handleInput(const KeyCodes& keyCodes, const KeyboardEvent& keyboardEvent, Vector2D& mousePos) {}

void BoulderTriggerPuzzleObject::interact(std::shared_ptr<BehaviourObject> interactor) 
{
	auto object = dynamic_cast<BoulderPuzzleObject*>(interactor.get());
	if (object != nullptr)
	{
		triggered = true;
		tFunc(pointer);
	}
}

void BoulderTriggerPuzzleObject::setParent() 
{
	sharedFromThis = shared_from_this();
}

void BoulderTriggerPuzzleObject::start() 
{
	triggered = false;
}


#include "OrderTriggerPuzzleObject.h"

OrderTriggerPuzzleObject::OrderTriggerPuzzleObject(int x, int y, const std::string& texture, int tileId)
{
	this->textures.try_emplace("order_pressed", "Assets/Equipment/order_pressed.png");
	this->transform.position = { x * 128, y * 128 };
	this->transform.scale.multiply({ 4, 4 });
	setOrderNumber(tileId);

	gc = std::make_shared<GraphicsComponent>();
	gc->setTexture(texture);

	gc->imageDimensions = { 32, 32 };
	gc->transform = transform;
	gc->isScreen = false;
	
	stp = std::make_shared<StopStrategy>();
	cc = std::make_shared<CollidingComponent>(stp);
	cc->tag = "door";
	cc->transform.position = this->transform.position;

	this->components.emplace_back(gc);
	this->components.emplace_back(cc);
}

void OrderTriggerPuzzleObject::setOrderNumber(int tileId)
{
	switch (tileId)
	{
	case 12:
		this->orderNumber = 0;
		break;
	case 13:
		this->orderNumber = 1;
		break;
	case 14:
		this->orderNumber = 2;
		break;
	case 15:
		this->orderNumber = 3;
		break;
	}
}

void OrderTriggerPuzzleObject::setOrderTriggerCallback(cbOrderTrigger orderCb, void* p)
{
	this->oFunc = orderCb;
	this->pointer = p;
}

void OrderTriggerPuzzleObject::interact(std::shared_ptr<BehaviourObject> interactor)
{
	gc->setTexture("order_pressed");
	triggered = true;
	oFunc(pointer, orderNumber);
}

void OrderTriggerPuzzleObject::setParent() 
{
	orderPuzzleObject = shared_from_this();
}

void OrderTriggerPuzzleObject::start() 
{
	gc->setTexture("order_not_pressed");
	triggered = false;
}
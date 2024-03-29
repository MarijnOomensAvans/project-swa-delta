#include "ThrowPokeball.h"
#include "Pokemon.h"

ThrowPokeball::ThrowPokeball(const cbThrowCollision tF, const cbSentPokemon f, void* p, void* g) : tFunc(tF), func(f) , playerPointer(p), gameMangerPointer(g)
{
	this->transform.position = { -10, -10 };
	this->transform.scale.multiply({ 4, 4 });
	gc = std::make_shared<GraphicsComponent>();
	gc->setTexture(texture);
	gc->imageDimensions = { 32, 32 };
	gc->transform = transform;
	gc->isScreen = false;

	stp = std::make_shared<StopStrategy>();
	cc = std::make_shared<CollidingComponent>(stp);
	cc->tag = "pokeball";
	cc->transform.position = this->transform.position;
	
	textures.try_emplace("pokeball", "Assets/Equipment/pokeball.png");
	gc->setTexture("pokeball");

	this->components.emplace_back(gc);
	this->components.emplace_back(cc);
}

void ThrowPokeball::interact(std::shared_ptr<BehaviourObject> interactor) 
{
	auto object = dynamic_cast<Pokemon*>(interactor.get());
	if (object != nullptr) {
		GameState::getInstance().addCaughtPokemon(1);
		object->catchPokemon();
		func(playerPointer);
	}
	reset();
}

void ThrowPokeball::moveUp(int x, int y) 
{
	updateTransform(x, y);
	isMoving = true;
	direction = "up";
}

void ThrowPokeball::moveDown(int x, int y) 
{
	updateTransform(x, y);
	isMoving = true;
	direction = "down";
}

void ThrowPokeball::moveLeft(int x, int y) 
{
	updateTransform(x, y);
	isMoving = true;
	direction = "left";
}

void ThrowPokeball::moveRight(int x, int y) 
{
	updateTransform(x, y);
	isMoving = true;
	direction = "right";
}

void ThrowPokeball::update(int time) 
{
	if (isMoving) {
		if (direction == "up") {
			tFunc(gameMangerPointer, cc, transform.position.x, transform.position.y, KeyCodes::KEY_UP, 128);
			updateTransform(transform.position.x, transform.position.y - 16);
		} else 	if (direction == "down") {
			tFunc(gameMangerPointer, cc, transform.position.x, transform.position.y, KeyCodes::KEY_DOWN, 128);
			updateTransform(transform.position.x, transform.position.y + 16);

		} else if (direction == "left") {
			tFunc(gameMangerPointer, cc, transform.position.x, transform.position.y, KeyCodes::KEY_LEFT, 128);
			updateTransform(transform.position.x - 16, transform.position.y);

		} else if (direction == "right") {
			tFunc(gameMangerPointer, cc, transform.position.x, transform.position.y, KeyCodes::KEY_RIGHT, 128);
			updateTransform(transform.position.x + 16, transform.position.y);
		}
	}
}

void ThrowPokeball::updateTransform(int x, int y) 
{
	this->transform.position = { x, y };
	gc->transform = transform;
	cc->transform = transform;
}

void ThrowPokeball::reset() 
{
	updateTransform(-10, -10);
	isMoving = false;
	direction = "";
}

void ThrowPokeball::setParent() 
{
	cc->parent = shared_from_this();
}
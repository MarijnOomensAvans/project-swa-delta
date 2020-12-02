#pragma once
#include <iostream>
#include "IEquipment.h"
#include "GraphicsComponent.h"
#include "StopStrategy.h"
#include "Pokemon.h"

typedef void(*cbSentPokemon) (void*);
typedef void(*cbThrowCollision) (void*, std::shared_ptr<BehaviourObject>, int, int, KeyCodes, int);

class ThrowPokeball : public IEquipment
{
public:
	ThrowPokeball() {}
	ThrowPokeball(const cbThrowCollision tF, const cbSentPokemon f, void* p, void* g);

	void interact(std::shared_ptr<BehaviourObject> interactor) override;
	void use() override;
	void setParent() override;
	void update() override;
	void moveUp(int x, int y);
	void moveDown(int x, int y);
	void moveLeft(int x, int y);
	void moveRight(int x, int y);
	void updateTransform(int x, int y);
	void reset();

	bool isMoving = false;
private:
	cbSentPokemon func;
	cbThrowCollision tFunc;
	void* playerPointer;
	void* gameMangerPointer;

	std::string direction;
	std::shared_ptr<GraphicsComponent> gc;
	std::shared_ptr<CollidingComponent> cc;	
	std::shared_ptr<CollisionStrategy> stp;
	
};
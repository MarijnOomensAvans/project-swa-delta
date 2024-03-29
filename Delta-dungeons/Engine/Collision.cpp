#include "Collision.h"

Collision::Collision(cbGetObject f, void* p): func(f), pointer(p) {}

void Collision::registerColliders(std::vector<std::shared_ptr<BehaviourObject>> colliders)
{
	colliderObjects = colliders;
}

void Collision::deleteColliderFromScene(std::shared_ptr<BehaviourObject> deletedCollider)
{
	auto index = std::find(colliderObjects.begin(), colliderObjects.end(), deletedCollider);
	if (index != colliderObjects.end())
	{
		colliderObjects.erase(index);
	}
}

void Collision::setCameraDimensions(const Transform& transform) {
	cameraX = transform.position.x;
	cameraY = transform.position.y;
	cameraW = transform.scale.x;
	cameraH = transform.scale.y;
}

void Collision::checkCollision(std::shared_ptr<CollidingComponent> collider, std::shared_ptr<BehaviourObject> behaviourObject, int x, int y, KeyCodes direction, int w)
{
	w = w - 32;
	for (auto& collider2 : colliderObjects)
	{
		auto col2 = dynamic_cast<CollidingComponent*>(collider2.get());
		if (
			collider.get() != col2 &&
			collider2->transform.position.x + 128 >= cameraX &&
			1280 + cameraX >= collider2->transform.position.x &&
			collider2->transform.position.y + 128 >= cameraY &&
			cameraY + 1024 >= collider2->transform.position.y
			)
		{
			if (x + w > col2->transform.position.x &&
				col2->transform.position.x + w > x &&
				y + w + 16 > col2->transform.position.y &&
				col2->transform.position.y + w > y)
			{
				std::shared_ptr<BehaviourObject> bo = func(pointer, col2);
				collider->actCollision(bo, x, y, direction);
				col2->actCollision(behaviourObject, x, y, direction);
				break;
			}
		}
	}
}

void Collision::checkProjectileCollision(std::shared_ptr<BehaviourObject> collider, int x, int y, KeyCodes direction, int w) {
	auto col1 = dynamic_cast<CollidingComponent*>(collider.get());
	if (
		collider->transform.position.x + 128 >= cameraX &&
		1280 + cameraX >= collider->transform.position.x &&
		collider->transform.position.y + 128 >= cameraY &&
		cameraY + 1024 >= collider->transform.position.y
		)
	{
		
		for (auto collider2 : colliderObjects)
		{
			if (
				collider2->transform.position.x + 128 >= cameraX &&
				1280 + cameraX >= collider2->transform.position.x &&
				collider2->transform.position.y + 128 >= cameraY &&
				cameraY + 1024 >= collider2->transform.position.y
				)
			{
				auto col2 = dynamic_cast<CollidingComponent*>(collider2.get());
				if (
					col1 != col2 &&
					x + w > col2->transform.position.x &&
					col2->transform.position.x + w > x &&
					y + w > col2->transform.position.y &&
					col2->transform.position.y + w > y)
				{
					col1->parent->interact(col2->parent);
					break;
				}
			}
		}
	}
	else {
		col1->parent->interact(nullptr);
	}
}


void Collision::checkAiCollision(std::shared_ptr<CollidingComponent> collider, std::shared_ptr<BehaviourObject> behaviourObject, int x, int y, KeyCodes direction, int w)
{
	for (auto& collider2 : colliderObjects)
	{
		auto col2 = dynamic_cast<CollidingComponent*>(collider2.get());
		if (
			collider.get() != col2 &&
			collider2->transform.position.x + 128 >= cameraX &&
			1280 + cameraX >= collider2->transform.position.x &&
			collider2->transform.position.y + 128 >= cameraY &&
			cameraY + 1024 >= collider2->transform.position.y
			)
		{
			if (x + w > col2->transform.position.x &&
				col2->transform.position.x + w > x &&
				y + w > col2->transform.position.y &&
				col2->transform.position.y + w > y)
			{
				std::shared_ptr<BehaviourObject> bo = func(pointer, col2);
				behaviourObject->interact(bo);
				break;
			}
		}
	}
}
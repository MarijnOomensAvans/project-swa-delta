#pragma once

#include "Player.h"
#include <iostream>
#include <string>
typedef void(*cbCamera) (void*, int, int);
typedef void(*cbInteract) (void*, int, int);
typedef void(*cbGameOver) (void*);
typedef void(*cbHUD) (void*, bool);
typedef void(*cbCollision) (void*, std::shared_ptr<BehaviourObject>, int, int, KeyCodes);
typedef void(*cbNextLevel) (void*);

class PlayerManager
{
public:
	std::shared_ptr<Player> player;

	PlayerManager() {}
	~PlayerManager() {}

	void createPlayer(cbCollision collisionCB, cbNextLevel nextLevelcb, cbCamera cb, cbInteract interactCB, cbGameOver gameOverCB, cbHUD hudCB, void* p);

	std::map<std::string, std::string> passTextures() const;
	std::shared_ptr<Player> getPlayerObject();
	std::vector<std::string> getItems();
};
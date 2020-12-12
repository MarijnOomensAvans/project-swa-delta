#include "GameOverScreenScene.h"

GameOverScreenScene::GameOverScreenScene()
{
	this->name = "GameOverScreen";
	this->setBehaviourObjects({ std::make_shared<GameOverScreen>() });
	this->setTexture("game_over", "Assets/Menu/Game-Over/background.png");
}
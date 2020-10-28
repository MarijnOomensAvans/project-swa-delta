#include "MainMenu.h"

MainMenu::MainMenu() {
	this->textures.try_emplace("mainmenu", "Assets/mainmenu-2.png");
	this->textures.try_emplace("button_play", "Assets/button-play-1.png");
	this->textures.try_emplace("button_credits", "Assets/button-credits-1.png");
	this->textures.try_emplace("button_exit", "Assets/button-exit-1.png");

	text = "Delta Dungeons";
	gc = std::make_shared<GraphicsComponent>();
	gc->setTexture("mainmenu");
	gc->imageDimensions = { 1024, 768 };
	this->components.emplace_back(gc);

	// Play button
	std::vector<std::string> possibleButtonTexPlay = { "button_play" };
	std::shared_ptr<Button> playButton = std::make_shared<Button>(372, 204, possibleButtonTexPlay);
	this->components.emplace_back(playButton);

	// Credits button
	std::vector<std::string> possibleButtonTexCredits = { "button_credits" };
	std::shared_ptr<Button> creditsButton = std::make_shared<Button>(372, 334, possibleButtonTexCredits);
	this->components.emplace_back(creditsButton);

	// Exit button
	std::vector<std::string> possibleButtonTexExit = { "button_exit" };
	std::shared_ptr<Button> exitButton = std::make_shared<Button>(372, 464, possibleButtonTexExit);
	this->components.emplace_back(exitButton);
};

MainMenu::~MainMenu() {};

void MainMenu::startGame() {};
void MainMenu::openCreditScreen() {};
void MainMenu::closeScreen() {};

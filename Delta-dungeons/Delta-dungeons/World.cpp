#include "World.h"

/// <summary>
/// Scene is where a TileMap can be created.
/// </summary>

World::World(int x, int y) : x(x), y(y) {}

void World::addGraphics(const std::string& levelName)
{
	this->levelName = levelName;
	components.clear();
	XMLSceneParser xmlSceneParser;

	tileMap = xmlSceneParser.loadScene("Assets/Map/" + levelName + "/level.xml");

	for (std::shared_ptr<Tile> t : tileMap)
	{
		t->addGraphicsComponent(levelName);
		components.emplace_back(std::move(t));
	}

	Colour color = { 0, 0, 0, 255 };
	fpsText = std::make_shared<TextComponent>("", "joystix", color, 32);
	fpsText->transform.position = { 1200, 10 };
	components.emplace_back(fpsText);

	beats.try_emplace("match", "Assets/Audio/match.ogg");
	beats.try_emplace("desert", "Assets/Audio/desert.ogg");
	beats.try_emplace("finale", "Assets/Audio/finale.ogg");
	beats.try_emplace("lava", "Assets/Audio/lava.ogg");

	beats.try_emplace("eueu", "Assets/Audio/eueu.wav");
	beats.try_emplace("hurt", "Assets/Audio/hurt.wav");
	beats.try_emplace("caught", "Assets/Audio/caught.wav");
	beats.try_emplace("pickup", "Assets/Audio/pickup.wav");
	beats.try_emplace("berry", "Assets/Audio/berry.wav");
	beats.try_emplace("boulder", "Assets/Audio/boulder.wav");
	beats.try_emplace("gate", "Assets/Audio/gate.wav");
	beats.try_emplace("reset", "Assets/Audio/reset.wav");
	beats.try_emplace("puzzlefail", "Assets/Audio/puzzlefail.wav");
}

std::map<std::string, std::string> World::passTextures(std::string levelName) const
{
	std::map<std::string, std::string> texture;
	texture.try_emplace(levelName, "Assets/Map/" + levelName + "/tileset.png");
	return texture;
}

std::map<std::string, std::string> World::passBeats() const
{
	return beats;
}

void World::handleInput(const KeyCodes& keyCode, const KeyboardEvent& keyboardEvent, Vector2D& mousePos)
{
	if (keyboardEvent == KeyboardEvent::KEY_PRESSED)
	{
		switch (keyCode)
		{
		case KeyCodes::KEY_TAB:
			DebugUtilities::getInstance().toggleShowFPS();
			break;
		case KeyCodes::KEY_COMMA:
			DebugUtilities::getInstance().slowDownGame();
			break;
		case KeyCodes::KEY_PERIOD:
			DebugUtilities::getInstance().speedUpGame();
			break;
		case KeyCodes::KEY_SLASH:
			DebugUtilities::getInstance().resetSpeedGame();
			break;
		case KeyCodes::KEY_ESC:
			DebugUtilities::getInstance().pauseGame();
			GameState::getInstance().setIsPaused();
			break;
		default:
			break;
		}
	}
}

void World::update(int time)
{
	if (DebugUtilities::getInstance().isShowingFPS())
	{
		fpsString.str(std::to_string(DebugUtilities::getInstance().getFPS()));
		fpsText->changeText(fpsString.str());
	}
	else
	{
		fpsText->changeText("");
	}
}

void World::start()
{
	if (levelName == "Level1" || levelName == "Dungeon1")
	{
		AudioUtilities::getInstance().playAudio("match", true);
	}
	else if (levelName == "Level2" || levelName == "Dungeon2")
	{
		AudioUtilities::getInstance().playAudio("desert", true);
	}
	else if (levelName == "Level3" || levelName == "Dungeon3")
	{
		AudioUtilities::getInstance().playAudio("lava", true);
	}
	else if (levelName == "Level4")
	{
		AudioUtilities::getInstance().playAudio("finale", true);
	}
}
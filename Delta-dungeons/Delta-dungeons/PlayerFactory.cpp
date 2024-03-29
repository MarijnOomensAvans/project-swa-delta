#include "PlayerFactory.h"

/// <summary>
/// This is a manager class for the player in which the Player is created and the texture is stored.
/// </summary>
void PlayerFactory::createPlayer(const std::string& levelName, cbCollision collisionCb, cbThrowCollision throwCB, cbNextLevel nextLevelCb, cbCamera cb, cbInteract interactCB, cbGameOver gameOverCB, void* p, void* gm)
{
    std::unique_ptr<XMLSceneParser> parser = std::make_unique<XMLSceneParser>();
    std::shared_ptr<ParserData> positionData = parser->getPlayerPosition("Assets/Map/" + levelName + "/level.xml");
	player = std::make_shared<Player>(std::stoi(positionData->x), std::stoi(positionData->y), collisionCb, throwCB, nextLevelCb, cb, interactCB, gameOverCB, p, gm);
    player->setParent();
}

/// <summary>
/// This method gives all the textures back in a map.
/// </summary>
/// <returns>Returns a map of the textures.</returns>
std::map<std::string, std::string> PlayerFactory::passTextures() const
{
    std::map<std::string, std::string> texture = player->textures;
    return texture;
}

/// <summary>
/// This method gives back the playerObject as a shared_pointer.
/// </summary>
/// <returns>Returns the playerObject shared_pointer.</returns>
std::shared_ptr<Player> PlayerFactory::getPlayerObject()
{
    return player;
}

std::vector<std::string> PlayerFactory::getItems()
{
    return player->getItems();
}
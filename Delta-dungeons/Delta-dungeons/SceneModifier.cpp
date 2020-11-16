#include "SceneModifier.h"

SceneModifier SceneModifier::sceneModifier;

SceneModifier& SceneModifier::getInstance()
{
	return sceneModifier;
}

void SceneModifier::deleteObjectFromScene(std::shared_ptr<BehaviourObject> deletedObject)
{
	engineFacade->deleteObjectFromScene(deletedObject);
}

void SceneModifier::setEngineFacade(std::shared_ptr<EngineFacade> engineFacade)
{
	this->engineFacade = engineFacade;
}
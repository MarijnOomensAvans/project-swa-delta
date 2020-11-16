#pragma once
#include "EngineFacade.h"

class SceneModifier
{
public:
	static SceneModifier& getInstance();
	void addObjectToScene(std::shared_ptr<BehaviourObject> addObject);
	void updateObjectToScene(std::shared_ptr<BehaviourObject> updateObject);
	void deleteObjectFromScene(std::shared_ptr<BehaviourObject> deletedObject);
	void setEngineFacade(std::shared_ptr<EngineFacade> engineFacade);

private:
	static SceneModifier sceneModifier;
	std::shared_ptr<EngineFacade> engineFacade;
};
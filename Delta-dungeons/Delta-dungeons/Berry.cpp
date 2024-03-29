#include "Berry.h"

Berry::Berry(int x, int y, std::string texture) {
    this->transform.position = { x * 128, y * 128 };
    this->transform.scale.multiply({ 4, 4 });

    gc = std::make_shared<GraphicsComponent>();
    gc->setTexture(texture);
    gc->imageDimensions = { 32, 32 };
    gc->transform = transform;
    gc->isScreen = false;

    stp = std::make_shared<StopStrategy>();
    cc = std::make_shared<CollidingComponent>(stp);
    cc->tag = "berry";
    cc->transform.position = this->transform.position;

    this->components.emplace_back(gc);
    this->components.emplace_back(cc);
}

void Berry::interact(std::shared_ptr<BehaviourObject> interactor)
{
    AudioUtilities::getInstance().playEffect("berry");
    auto col = dynamic_cast<Player*>(interactor.get());
    if(col != nullptr) { col->addBerry(); }
    

    if (gc != nullptr) {
        SceneModifier::getInstance().deleteObjectFromScene(gc);
        SceneModifier::getInstance().deleteColliderFromScene(cc);
        SceneModifier::getInstance().deleteObjectFromScene(shared_from_this());
        gc = nullptr;
    }
}

void Berry::setParent() 
{
    cc->parent = shared_from_this();
}
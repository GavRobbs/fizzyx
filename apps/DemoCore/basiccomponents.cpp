#include <basiccomponents.h>

BoxRendererComponent::BoxRendererComponent(const GraphicsManager& _graphics, const GraphicsManager::Color& color, const math::Vector2& dimensions):Component(), graphicsManager(_graphics), color(color), dimensions(dimensions)
{

}

void BoxRendererComponent::setDimensions(const math::Vector2 & dimensions)
{
    this->dimensions = dimensions;
}

const math::Vector2 & BoxRendererComponent::getDimensions()
{
    return dimensions;
}

void BoxRendererComponent::render(float dt)
{
    graphicsManager.drawRectFilled(this->getOwner()->getTransform().position, dimensions.x, dimensions.y, color);
}


void SimpleDynamicRigidbodyComponent::physicsUpdate(float dt)
{
    if(entity == nullptr)
    {
        return;
    }

    Entity * sceneEntity = getOwner();
    Transform t = sceneEntity->getTransform();
    t.position = entity->getPosition();
    sceneEntity->setTransform(t);
}
    
void SimpleDynamicRigidbodyComponent::setEntity(fizzyx::core::IPhysicsEntity * physent)
{
    entity = physent;    
}

fizzyx::core::IPhysicsEntity * SimpleDynamicRigidbodyComponent::getEntity()
{
    return entity;
}
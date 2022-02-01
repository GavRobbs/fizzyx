#include <basiccomponents.h>

BoxRendererComponent::BoxRendererComponent(const GraphicsManager& _graphics, const GraphicsManager::Color& color, const math::Vector2& dimensions, bool filled):Component(), graphicsManager(_graphics), color(color), dimensions(dimensions), filled(filled)
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
    if(filled)
    {
        graphicsManager.drawRectFilled(this->getOwner()->getTransform().position, dimensions.x, dimensions.y, color);
    } else
    {
        graphicsManager.drawRectOutline(this->getOwner()->getTransform().position, dimensions.x, dimensions.y, color);
    }
}

CircleRendererComponent::CircleRendererComponent(const GraphicsManager& _graphics, const GraphicsManager::Color& color, const float & radius, bool filled=true):Component(), graphicsManager(_graphics), color(color), radius(radius), filled(filled)
{

}

void CircleRendererComponent::setRadius(const float & radius)
{
    this->radius = radius;
}

const float & CircleRendererComponent::getRadius()
{
    return radius;
}

void CircleRendererComponent::render(float dt)
{
    if(filled)
    {
        graphicsManager.drawCircleFilled(this->getOwner()->getTransform().position, radius, color);
    } else
    {
        graphicsManager.drawCircleOutline(this->getOwner()->getTransform().position, radius, color);
    }
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
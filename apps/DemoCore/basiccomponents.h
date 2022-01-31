#ifndef BASIC_COMPONENTS_H
#define BASIC_COMPONENTS_H

#include <ecs.h>
#include <graphicsmanager.h>
#include <core/physicsentity.h>

/* A class to draw the box on the end of our spring*/
class BoxRendererComponent : public IRenderable, public Component
{
    public:
    void render(float dt=0.0f) override;
    BoxRendererComponent(const GraphicsManager& _graphics, const GraphicsManager::Color& color, const math::Vector2& dimensions);

    void setDimensions(const math::Vector2 & dimensions);
    const math::Vector2 & getDimensions();

    private:
    const GraphicsManager &graphicsManager;
    math::Vector2 dimensions{};
    GraphicsManager::Color color;
};

class SimpleDynamicRigidbodyComponent : public IPhysicsable, public Component
{
    public:
    void physicsUpdate(float dt) override;
    
    void setEntity(fizzyx::core::IPhysicsEntity * physent);
    fizzyx::core::IPhysicsEntity * getEntity();

    private:
    fizzyx::core::IPhysicsEntity * entity;
};


#endif
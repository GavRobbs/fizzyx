#ifndef BASIC_COMPONENTS_H
#define BASIC_COMPONENTS_H

#include <ecs.h>
#include <graphicsmanager.h>
#include <bodies/physicsentity.h>

/* Draws a simple colored box, can be filled or an outline */
class BoxRendererComponent : public IRenderable, public Component
{
    public:
    void render(float dt=0.0f) override;
    BoxRendererComponent(const GraphicsManager& _graphics, const GraphicsManager::Color& color, const math::Vector2& dimensions, bool filled=true);

    void setDimensions(const math::Vector2 & dimensions);
    const math::Vector2 & getDimensions();

    private:
    const GraphicsManager &graphicsManager;
    math::Vector2 dimensions{};
    GraphicsManager::Color color;
    bool filled;
};

/* Draws a simple colored circle, can be filled or an outline */
class CircleRendererComponent : public IRenderable, public Component
{
    public:
    void render(float dt=0.0f) override;
    CircleRendererComponent(const GraphicsManager& _graphics, const GraphicsManager::Color& color, const float & radius, bool filled=true);

    void setRadius(const float & radius);
    const float & getRadius();

    private:
    const GraphicsManager &graphicsManager;
    float radius;
    GraphicsManager::Color color;
    bool filled;
};

/* Puts a body in the scene under the control of the physics engine. Only handles linear kinematic properties.*/
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
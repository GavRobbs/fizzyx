#include "fireworkscomponents.h"
#include "particlespawner.h"
#include <iostream>

PointRendererComponent::PointRendererComponent(GraphicsManager &gm, const GraphicsManager::Color &_color):Component(), graphicsManager(gm), color(_color)
{
}

void PointRendererComponent::render(float dt)
{
    math::Vector2 position = owner->getTransform().position;
    graphicsManager.drawPoint(position, color, 1.0f);
}

PointSpawnerKillerComponent::PointSpawnerKillerComponent(const float &_lifespan, ParticleSpawner &_spawner):Component(), lifespan(_lifespan), spawner(_spawner)
{

}

void PointSpawnerKillerComponent::think(float dt) 
{
    lifespan -= dt;
    if(lifespan <= 0.0f)
    {
        getOwner()->Destroy();
        spawner.spawnParticles(owner->getTransform().position);
        spawner.registerDestruction();
    } else
    {
        auto position = this->getOwner()->getTransform().position;
        if(position.x > 1024 || position.x < 0 || position.y > 768 || position.y < 0)
        {
            getOwner()->Destroy();
            spawner.registerDestruction();
        }
    }
   
}

PointPhysicsBodyComponent::PointPhysicsBodyComponent(fizzyx::tutorial::PointMassEntity * _physicsBody):Component(), physicsBody(_physicsBody)
{

}

void PointPhysicsBodyComponent::physicsUpdate(float dt)
{
    Transform transform = owner->getTransform();
    transform.position = physicsBody->getPosition();
    owner->setTransform(transform);
}

PointPhysicsBodyComponent::~PointPhysicsBodyComponent()
{
    physicsBody->Destroy();
}



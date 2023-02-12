#ifndef FIREWORKS_COMPONENTS_H
#define FIREWORKS_COMPONENTS_H

#include "ecs.h"
#include "graphicsmanager.h"
#include "fizzyx/bodies/pointmass.h"

class ParticleSpawner;

/* Displays the point that represents the firework */
class PointRendererComponent : public Component, public IRenderable
{
    public:
    PointRendererComponent(GraphicsManager &gm, const GraphicsManager::Color &_color);
    void render(float dt=0.0f) override;
    private:
    GraphicsManager &graphicsManager;
    GraphicsManager::Color color;
};

/* Controls the lifetime countdown for the firework and spawns new ones when the old firework runs out of life or goes out of screen bounds */
class PointSpawnerKillerComponent : public Component, public ILogicable
{
    public:
    PointSpawnerKillerComponent(const float &_lifespan, ParticleSpawner &_spawner);
    void think(float dt) override;

    private:
    float lifespan;
    ParticleSpawner &spawner;
};

/* Updates the scene entity with the position data from the physics entity */
class PointPhysicsBodyComponent : public Component, public IPhysicsable
{
    public:
    PointPhysicsBodyComponent(fizzyx::tutorial::PointMassEntity * _physicsBody);
    ~PointPhysicsBodyComponent();
    void physicsUpdate(float dt=0.0f) override;

    private:
    fizzyx::tutorial::PointMassEntity *physicsBody;
};

#endif
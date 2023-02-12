#ifndef PARTICLE_SPAWNER_H
#define PARTICLE_SPAWNER_H

#include "ecs.h"
#include "graphicsmanager.h"
#include "fizzyx/math/mathutils.h"

class ParticleSpawner
{
    public:
    void spawnParticles(const math::Vector2 &position, int numParticles = -1, const float &minLifetime = 6.0f, const float &maxLifeTime = 14.0f);
    ParticleSpawner(SceneManager &_sceneManager, GraphicsManager &_graphicsManager, unsigned int maxParticles=1500);
    ~ParticleSpawner();
    void registerDestruction();

    private:
    unsigned int currentParticleCount{0};
    unsigned int maxParticleCount;

    math::Random random{};

    SceneManager &sceneManager;
    GraphicsManager &graphicsManager;

    GraphicsManager::Color getRandomColor();

    math::Vector2 getRandomAcceleration();
};

#endif
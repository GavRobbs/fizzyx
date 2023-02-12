#include "particlespawner.h"
#include "fireworkscomponents.h"
#include "fizzyx/math/vector2.h"
#include <iostream>

void ParticleSpawner::spawnParticles(const math::Vector2 &position, int numParticles, const float &minLifetime, const float &maxLifeTime)
{

    /* -1 is the default value and it tells the systm to generate a random number of particles. If a random number of 0 is generated, the particle dies and doesn't generate any child particles. Also if the pool of particles is nearly full, the particle generates as many kids as the pool will allow, or dies without kids if the pool is full.*/

    if(numParticles == -1)
    {
        numParticles = random.getRandomInteger(0, 12);

        /* This gives a nicer distribution - yielding about a 25% chance that a particle will be fully killed off with no kids,
        giving a change for other particles to spawn*/
        if(numParticles == 4)
        {
            return;
        } else{
            numParticles /= 2;
            numParticles--;
        }
    }

    int numToBeSpawned = std::min<int>(
        std::max<int>(
            maxParticleCount - currentParticleCount - numParticles, 
            0), 
            numParticles);

    if(numToBeSpawned == 0)
    {
        return;
    }

    fizzyx::PhysicsWorld &world = sceneManager.getPhysicsWorld();


    for(int i = 0; i < numToBeSpawned; ++i)
    {
        PointRendererComponent * prc = new PointRendererComponent{graphicsManager, getRandomColor()};

        float lifetime = random.getRandomFloat(minLifetime, maxLifeTime);
        PointSpawnerKillerComponent * pskc = new PointSpawnerKillerComponent{lifetime, *this};

        fizzyx::tutorial::PointMassEntity * physicsBody = new fizzyx::tutorial::PointMassEntity{};
        physicsBody->setGravity(6.0f);
        physicsBody->setAcceleration(getRandomAcceleration());
        physicsBody->setPosition(position);
        world.addEntity(physicsBody);

        PointPhysicsBodyComponent * ppbc = new PointPhysicsBodyComponent{physicsBody};

        Entity * particleEntity = new Entity{};
        Transform transform = particleEntity->getTransform();
        transform.position = position;

        particleEntity->setTransform(transform);
        particleEntity->addComponent(ppbc);
        particleEntity->addComponent(prc);
        particleEntity->addComponent(pskc);

        sceneManager.addEntity(particleEntity);
        currentParticleCount++;
    }

}

ParticleSpawner::ParticleSpawner(SceneManager &_sceneManager, GraphicsManager &_graphicsManager, unsigned int maxParticles):maxParticleCount(maxParticles), sceneManager(_sceneManager), graphicsManager(_graphicsManager)
{

}

ParticleSpawner::~ParticleSpawner()
{

}

void ParticleSpawner::registerDestruction()
{
    currentParticleCount--;
}

GraphicsManager::Color ParticleSpawner::getRandomColor()
{
    GraphicsManager::Color col;
    
    do{
        col = {(uint8_t)random.getRandomInteger(0, 255),
        (uint8_t)random.getRandomInteger(0, 255),
        (uint8_t)random.getRandomInteger(0, 255),
        255};
    }while(col.magnitude() < 120);

    return col;
}

math::Vector2 ParticleSpawner::getRandomAcceleration()
{
    return math::Vector2{
        random.getRandomFloat(-4.5f, 4.5f),
        random.getRandomFloat(-8.0f, 8.0f),
    };
}

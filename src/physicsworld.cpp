#include <physicsworld.h>
#include <core/physicsentity.h>
#include <core/forcegenerator.h>
#include <iostream>
#include <memory>
#include <limits>

using namespace fizzyx;

PhysicsWorld::PhysicsWorld():solver{nullptr}, collisionDetector{nullptr}
{

}

void PhysicsWorld::resolveCollisionPairs(const float & dt)
{
    if(collisionDetector == nullptr)
    {
        return;
    }

    uint8_t numIterations = 3;
    std::vector<std::unique_ptr<collision::ICollisionData>> collisions;

    auto potentialContactPairs = entityStorage->getPotentialContactPairs();

    /* This iterates through all the potential contact pairs to check for collision (this is narrow phase collision detection) */
    for(auto it = potentialContactPairs.begin(); it != potentialContactPairs.end(); ++it)
    {
        if(it->first->isForDeletion() || it->second->isForDeletion())
        {
            continue;
        }

        collision::ICollisionData * result = collisionDetector->detectCollision(it->first, it->second);

        if(result != nullptr)
        {
            collisions.push_back(std::move(std::unique_ptr<collision::ICollisionData>(result)));
        }
    }

    //We then resolve the contact pair with the highest closing velocity first
    for(size_t j = 0; j < numIterations; ++j)
    {
        for(size_t i = 0; i < collisions.size(); ++i)
        {
            float maxCV = std::numeric_limits<float>::lowest();
            size_t maxIndex = collisions.size();

            for(size_t j = 0; j < collisions.size(); ++j)
            {
                float cv = collisions[j]->getClosingVelocity();
                if(cv > 0.0f && cv > maxCV)
                {
                    maxCV = cv;
                    maxIndex = j;
                }
            }

            if(maxIndex == collisions.size())
            {
                break;
            }

            if(solver != nullptr)
            {
                solver->solve(collisions[i].get(), dt);
            }

            ++i;
        }

    }
    
}

void PhysicsWorld::processForceGenerators(const float & dt)
{
    for(auto it = fg_registry.begin(); it != fg_registry.end(); ++it)
    {
        if(it->forceGenerator == nullptr || it->entity == nullptr)
        {
            continue;
        }

        it->forceGenerator->update(it->entity, dt);
    }
}

void PhysicsWorld::updateAllEntities(const float & dt)
{
    entityStorage->update(dt);
}

void PhysicsWorld::deleteFlaggedEntities()
{
    entityStorage->cleanup();
    /*auto it = entities.begin();
    while(it != entities.end())
    {
        if(it->get()->isForDeletion())
        {
            it = entities.erase(it);
            removeAllForceGeneratorsFromEntity(it->get());
        } else{
            ++it;
        }
    }*/
}

void PhysicsWorld::update(float dt)
{
    /*
        This part of the main loop is where the bulk of the processing takes place. We update the positions of each entity, remove the entities for deletion, apply forces from the force generator, check for collisions and update the body's velocity/position so it can be applied on the next frame
    */

    if(entityStorage->isEmpty())
    {
        return;
    }
    
    processForceGenerators(dt);
    resolveCollisionPairs(dt);
    updateAllEntities(dt);
    deleteFlaggedEntities();    
}

void PhysicsWorld::setCollisionDetector(collision::ICollisionDetector *detector)
{
    if(this->collisionDetector != nullptr)
    {
        delete this->collisionDetector;
    }

    this->collisionDetector = detector;
}


void PhysicsWorld::setSolver(core::IPhysicsSolver * solver)
{
    if(this->solver != nullptr)
    {
        delete this->solver;
    }

    this->solver = solver;
}

void PhysicsWorld::setAccelerationStructure(acceleration::IAccelerationStructure *accelerator)
{
    if(this->entityStorage != nullptr)
    {
        delete this->entityStorage;
    }
    
    this->entityStorage = accelerator;
}


PhysicsWorld::~PhysicsWorld()
{
    if(solver != nullptr)
    {
        delete solver;
    }

    if(collisionDetector != nullptr)
    {
        delete collisionDetector;
    }
}

void PhysicsWorld::emptyWorld()
{
    entityStorage->emptyWorld();
}

void PhysicsWorld::addEntity(core::IPhysicsEntity *entity)
{
    entityStorage->addEntity(entity);
}

 void PhysicsWorld::removeEntity(unsigned int id)
 {
    entityStorage->removeEntity(id);
    /*for(auto it = entities.begin(); it != entities.end(); ++it)
    {
        if(it->get()->getID() == id)
        {
            entities.erase(it);
            return;
        }
    }*/

 }

void PhysicsWorld::removeEntity(core::IPhysicsEntity *entity)
{
    entityStorage->removeEntity(entity->getID());
}

PhysicsWorld::PhysicsWorld(PhysicsWorld &&other)
{
    if(other.entityStorage != nullptr)
    {
        entityStorage = other.entityStorage->clone();
    }

    if(other.solver != nullptr)
    {
        solver = other.solver->clone();
    }

    if(other.collisionDetector != nullptr)
    {
        collisionDetector = other.collisionDetector->clone();
    }
}

PhysicsWorld& PhysicsWorld::operator=(PhysicsWorld &&other)
{
    if(this == &other)
    {

    } else
    {
        if(other.entityStorage != nullptr)
        {
            entityStorage = other.entityStorage->clone();
        }

        if(other.solver != nullptr)
        {
            solver = other.solver->clone();
        }

        if(other.collisionDetector != nullptr)
        {
            collisionDetector = other.collisionDetector->clone();
        }
    }

    return *this;
}

void PhysicsWorld::addForceGeneratorPair(core::IPhysicsEntity* entity, core::ForceGenerator * generator)
{
    ForceGeneratorPair fgpair;
    fgpair.entity = entity;
    fgpair.forceGenerator = generator;

    fg_registry.push_back(fgpair);
}

void PhysicsWorld::removeAllForceGeneratorsFromEntity(core::IPhysicsEntity * entity)
{
    auto it = fg_registry.begin();
    while(it != fg_registry.end())
    {
        if(it->entity == entity)
        {
            it = fg_registry.erase(it);
        } else{
            ++it;
        }
    }
}

void PhysicsWorld::removeForceGenerator(core::IPhysicsEntity * entity, core::ForceGenerator * generator)
{
    auto it = fg_registry.begin();
    while(it != fg_registry.end())
    {
        if(it->entity == entity && it->forceGenerator == generator)
        {
            it = fg_registry.erase(it);
            break;
        } else{
            ++it;
        }
    }
}
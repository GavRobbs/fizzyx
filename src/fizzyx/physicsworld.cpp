#include <physicsworld.h>
#include <core/physicsentity.h>
#include <core/forcegenerator.h>
#include <memory>

using namespace fizzyx;

PhysicsWorld::PhysicsWorld():solver{nullptr}, collisionDetector{nullptr}
{

}

void PhysicsWorld::update(float dt)
{
    /*
        This loop is where the bulk of the processing takes place. We update the positions of each entity, remove the entities for deletion, apply forces from the force generator, check for collisions and update the body's velocity/position so it can be applied on the next frame
    */

    if(entities.empty())
    {
        return;
    }

    for(auto it = entities.begin(); it != entities.end(); ++it)
    {
        it->get()->update(dt);
    }

    auto it = entities.begin();
    while(it != entities.end())
    {
        if(it->get()->isForDeletion())
        {
            it = entities.erase(it);
            removeAllForceGeneratorsFromEntity(it->get());
        } else{
            ++it;
        }
    }

    for(auto it = fg_registry.begin(); it != fg_registry.end(); ++it)
    {
        it->forceGenerator->update(it->entity, dt);
    }

    uint8_t numIterations = 3;

    /* Iterate over the list of collisions multiple times to get the best result */
    for(uint8_t i = 0; i < numIterations; ++i)
    {
        std::vector<std::unique_ptr<collision::ICollisionData>> collisions;

        for(auto it = entities.begin(); it != std::prev(entities.end()); ++it)
        {
            for(auto it2 = std::next(it); it2 != entities.end(); ++it2)
            {
                if(it->get()->isForDeletion() || it2->get()->isForDeletion())
                {
                    continue;
                }

                collision::ICollisionData * result = collisionDetector->detectCollision((*it).get(), (*it2).get());

                if(result != nullptr)
                {
                    collisions.push_back(std::move(std::unique_ptr<collision::ICollisionData>(result)));
                }
            }
        }

        if(solver != nullptr)
        {
            for(auto it = collisions.begin(); it != collisions.end(); ++it)
            {
                solver->solve(it->get(), dt);
            }
        }
    }

    
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

void PhysicsWorld::addEntity(core::IPhysicsEntity *entity)
{
    entities.push_back(std::unique_ptr<core::IPhysicsEntity>(entity));
}

 void PhysicsWorld::removeEntity(unsigned int id)
 {
    for(auto it = entities.begin(); it != entities.end(); ++it)
    {
        if(it->get()->getID() == id)
        {
            entities.erase(it);
            return;
        }
    }

 }

void PhysicsWorld::removeEntity(core::IPhysicsEntity *entity)
{
    removeEntity(entity->getID());
}

PhysicsWorld::PhysicsWorld(PhysicsWorld &&other)
{
    for(int i = 0; i < other.entities.size(); ++i)
    {
        entities.push_back(std::move(other.entities[i]));
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
        for(int i = 0; i < other.entities.size(); ++i)
        {
            entities.push_back(std::move(other.entities[i]));
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
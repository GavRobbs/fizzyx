#include <physicsworld.h>
#include <core/physicsentity.h>
#include <memory>

using namespace fizzyx;

void PhysicsWorld::update(float dt)
{
    /*
        This is where the bulk of the processing takes place. We evaluate constraints, generate the appropriate forces/impulses
        and torques, then integrate for the new position, velocity and acceleration of each body in the scene.
    */

   //Need to add multiple loops here

    for(auto it = entities.begin(); it != std::prev(entities.end()); ++it)
    {
        for(auto it2 = std::next(it); it2 != entities.end(); ++it2)
        {
            collision::ICollisionData * result = collisionDetector->detectCollision((*it).get(), (*it2).get());

            if(result != nullptr)
            {
                solver->solve(result, dt);
            }

        }
    }
}

void PhysicsWorld::setCollisionDetector(collision::ICollisionDetector *detector)
{
    if(collisionDetector != nullptr)
    {
        delete this->collisionDetector;
        collisionDetector = nullptr;
    }

    this->collisionDetector = detector;
}


void PhysicsWorld::setSolver(core::IPhysicsSolver * solver)
{
    if(solver != nullptr)
    {
        delete this->solver;
        solver = nullptr;
    }

    this->solver = solver;
}

PhysicsWorld::~PhysicsWorld()
{
    if(solver != nullptr)
    {
        delete solver;
    }
}

void PhysicsWorld::addEntity(core::IPhysicsEntity *entity)
{
    std::unique_ptr<core::IPhysicsEntity> entity_ptr(entity);
    entities.push_back(std::move(entity_ptr));
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
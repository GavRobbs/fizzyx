#include <physicsworld.h>
#include <core/physicsentity.h>
#include <memory>

using namespace fizzyx;

PhysicsWorld::PhysicsWorld():solver{nullptr}, collisionDetector{nullptr}
{

}

void PhysicsWorld::update(float dt)
{
    /*
        This is where the bulk of the processing takes place. We evaluate constraints, generate the appropriate forces/impulses
        and torques, then integrate for the new position, velocity and acceleration of each body in the scene.
    */

   //Need to add multiple loops here

    if(entities.empty())
    {
        return;
    }

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
        } else{
            ++it;
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
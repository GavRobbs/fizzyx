#include <physicsworld.h>
#include <physicsentity.h>
#include <memory>

using namespace fizzyx;

void PhysicsWorld::update(float dt)
{

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
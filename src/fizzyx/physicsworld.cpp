#include <physicsworld.h>

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

}

 void PhysicsWorld::removeEntity(unsigned int id)
 {

 }

void PhysicsWorld::removeEntity(core::IPhysicsEntity *entity)
{

}
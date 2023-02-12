#include "fizzyx/acceleration/accelerationstructure.h"

using namespace fizzyx::acceleration;
using namespace fizzyx::core;

void IAccelerationStructure::addEntity(IPhysicsEntity *entity)
{

}

void IAccelerationStructure::removeEntity(unsigned int id)
{

}

void IAccelerationStructure::removeEntity(IPhysicsEntity *entity)
{

}

void IAccelerationStructure::emptyWorld()
{

}

IPhysicsEntity * IAccelerationStructure::getEntity(unsigned int id)
{
    return NULL;
}

void IAccelerationStructure::update(const float &dt)
{

}

bool IAccelerationStructure::isEmpty()
{
    return true;
}

void IAccelerationStructure::cleanup()
{

}

std::vector<std::pair<IPhysicsEntity*, IPhysicsEntity*>> IAccelerationStructure::getPotentialContactPairs()
{
    return std::vector<std::pair<core::IPhysicsEntity*, core::IPhysicsEntity*>>();
}
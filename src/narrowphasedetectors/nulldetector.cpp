#include "fizzyx/narrowphasedetectors/nulldetector.h"

using namespace fizzyx::collision;
using namespace fizzyx::tutorial;

ICollisionData * NullCollisionDetector::detectCollision(fizzyx::core::IPhysicsEntity * a, fizzyx::core::IPhysicsEntity * b)
{
    return nullptr;
}

ICollisionDetector * NullCollisionDetector::clone()
{
    return new NullCollisionDetector{};
}
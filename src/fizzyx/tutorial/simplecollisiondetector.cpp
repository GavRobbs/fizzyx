#include <tutorial/simplecollisiondetector.h>

using namespace fizzyx::tutorial;

fizzyx::collision::ICollisionData * SimpleCollisionDetector::detectCollision(fizzyx::core::IPhysicsEntity * a, fizzyx::core::IPhysicsEntity * b)
{
    return nullptr;
}

fizzyx::collision::ICollisionDetector * SimpleCollisionDetector::clone()
{
    SimpleCollisionDetector * detector = new SimpleCollisionDetector;
    return detector;
}
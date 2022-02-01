#include <collision/collisiondetector.h>

using namespace fizzyx::collision;
using namespace fizzyx::core;

void ICollisionData::invert()
{
    IPhysicsEntity * temp = a;
    a = b;
    b = temp;
    collisionNormal = collisionNormal * -1.0f;
}

float ICollisionData::getClosingVelocity()
{
    return 0.0f;
}

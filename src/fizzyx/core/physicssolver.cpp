#include <physicssolver.h>

using namespace fizzyx::core;

void ICollisionData::invert()
{
    IPhysicsEntity * temp = a;
    a = b;
    b = temp;
    collisionNormal = collisionNormal * -1.0f;
}
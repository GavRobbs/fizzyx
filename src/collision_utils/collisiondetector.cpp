#include <collision_utils/collisiondetector.h>

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
    return math::Vector2::dotProduct(a->getVelocity() - b->getVelocity(), collisionNormal);
}

std::vector<math::Vector2> ICollisionData::getContactPoints()
{
    std::vector<math::Vector2> blank;
    return blank;
}

void ICollisionDetector::addDetectorEntry(uint8_t shape1, uint8_t shape2, CollisionDetectorFunction func)
{
    entries.push_back(CollisionDetectorEntry{shape1, shape2, func});
}


/* Returns 0 if there is no valid collision detector pair. Returns 1 if there is a pair registered that matches exactly and returns -1 if the detector pair is present but reversed (so the collision data would have to be inverted). */
int ICollisionDetector::CollisionDetectorEntry::isCompatible(std::uint8_t s1, std::uint8_t s2)
{
    if(s1 == shape1 && s2 == shape2)
    {
        return 1;
    }

    if(s1 == shape2 && s2 == shape1)
    {
        return -1;
    }

    return 0;
}


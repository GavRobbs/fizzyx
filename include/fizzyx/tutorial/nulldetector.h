#ifndef NULL_COLLISION_DETECTOR_H
#define NULL_COLLISION_DETECTOR_H

#include <collision/collisiondetector.h>

using namespace fizzyx::collision;

class NullCollisionDetector : public ICollisionDetector
{
    public:
    ICollisionData * detectCollision(fizzyx::core::IPhysicsEntity * a, fizzyx::core::IPhysicsEntity * b);
};

#endif
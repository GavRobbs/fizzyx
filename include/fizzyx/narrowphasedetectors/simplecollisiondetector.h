#ifndef SIMPLE_COLLISION_DETECTOR_H
#define SIMPLE_COLLISION_DETECTOR_H

#include "fizzyx/collision_utils/collisiondetector.h"

namespace fizzyx::tutorial
{
    class SimpleCollisionDetector : public fizzyx::collision::ICollisionDetector
    {
        public:
        fizzyx::collision::ICollisionData * detectCollision(fizzyx::core::IPhysicsEntity * a, fizzyx::core::IPhysicsEntity * b) override;
        ICollisionDetector * clone() override;
    };

}

#endif
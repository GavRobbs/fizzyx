#ifndef NULL_COLLISION_DETECTOR_H
#define NULL_COLLISION_DETECTOR_H

#include <collision_utils/collisiondetector.h>

namespace fizzyx::tutorial
{
    class NullCollisionDetector : public fizzyx::collision::ICollisionDetector
    {
        public:
        fizzyx::collision::ICollisionData * detectCollision(fizzyx::core::IPhysicsEntity * a, fizzyx::core::IPhysicsEntity * b);
        ICollisionDetector * clone() override;
    };

}



#endif
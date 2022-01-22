#ifndef COLLISION_DETECTOR_H
#define COLLISION_DETECTOR_H

#include <core/physicsentity.h>
#include <math/vector2.h>

namespace fizzyx::collision
{
    struct ICollisionData
    {
        fizzyx::core::IPhysicsEntity * a;
        fizzyx::core::IPhysicsEntity * b;
        math::Vector2 collisionNormal;
        float penetrationDepth;

        virtual void invert();
    };

    class ICollisionDetector
    {
        public:
        virtual ICollisionData * detectCollision(fizzyx::core::IPhysicsEntity * a, fizzyx::core::IPhysicsEntity * b) = 0;
    };

}


#endif
#ifndef FIZZYX_SOLVER_H
#define FIZZYX_SOLVER_H

#include <physicsentity.h>
#include <vector2.h>

namespace fizzyx
{
    namespace core
    {
        struct ICollisionData
        {
            IPhysicsEntity * a;
            IPhysicsEntity * b;
            math::Vector2 collisionNormal;
            float penetrationDepth;

            virtual void invert();
        };

        class IPhysicsSolver
        {
            public:
            virtual void update(ICollisionData * collision, float dt) = 0;
        };
    }
}

#endif
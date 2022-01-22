#ifndef FIZZYX_SOLVER_H
#define FIZZYX_SOLVER_H

#include <core/physicsentity.h>
#include <math/vector2.h>
#include <collision/collisiondetector.h>

namespace fizzyx
{
    namespace core
    {

        class IPhysicsSolver
        {
            public:
            virtual void solve(collision::ICollisionData * collision, float dt) = 0;
        };
    }
}

#endif
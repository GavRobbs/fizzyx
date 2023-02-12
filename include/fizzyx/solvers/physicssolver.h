#ifndef FIZZYX_SOLVER_H
#define FIZZYX_SOLVER_H

#include <bodies/physicsentity.h>
#include <math/vector2.h>
#include <collision_utils/collisiondetector.h>

namespace fizzyx
{
    namespace core
    {

        class IPhysicsSolver
        {
            public:
            virtual void solve(collision::ICollisionData * collision, float dt) = 0;
            virtual IPhysicsSolver * clone() = 0;
        };
    }
}

#endif
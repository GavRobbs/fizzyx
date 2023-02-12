#ifndef FIZZYX_SOLVER_H
#define FIZZYX_SOLVER_H

#include "fizzyx/bodies/physicsentity.h"
#include "fizzyx/math/vector2.h"
#include "fizzyx/collision_utils/collisiondetector.h"

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
#ifndef NULL_SOLVER_H
#define NULL_SOLVER_H

#include "fizzyx/solvers/physicssolver.h"
#include "fizzyx/collision_utils/collisiondetector.h"

namespace fizzyx::tutorial
{
    //The null solver doesn't process collisions, its just a placeholder
    class NullSolver: public fizzyx::core::IPhysicsSolver
    {
        public:
        void solve(fizzyx::collision::ICollisionData * collision, float dt);
        fizzyx::core::IPhysicsSolver * clone() override;

    };
}

#endif
#ifndef NULL_SOLVER_H
#define NULL_SOLVER_H

#include <core/physicssolver.h>

//The null solver doesn't process collisions, its just a placeholder
class NullSolver: public fizzyx::core::IPhysicsSolver
{
    public:
    void update(fizzyx::core::ICollisionData * collision, float dt);
};

#endif
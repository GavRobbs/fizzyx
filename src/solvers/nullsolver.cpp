#include "fizzyx/solvers/nullsolver.h"

using namespace fizzyx::collision;
using namespace fizzyx::tutorial;

void NullSolver::solve(ICollisionData * collision, float dt)
{
    
}

fizzyx::core::IPhysicsSolver * NullSolver::clone()
{
    return new NullSolver();
}

#ifndef LINEAR_SOLVER_H
#define LINEAR_SOLVER_H

#include <solvers/physicssolver.h>
#include <collision_utils/collisiondetector.h>

namespace fizzyx::tutorial
{
    /* The linear solver only processes linear forces, acceleration, velocity etc. and updates position. It does not update any angular quantities. It can handle resting contacts, but does not by default.*/
    class SimpleLinearSolver: public fizzyx::core::IPhysicsSolver
    {
        public:
        void solve(fizzyx::collision::ICollisionData * collision, float dt);
        fizzyx::core::IPhysicsSolver * clone() override;

        void enableRestingContactResolution();
        void disableRestingContactResolution();

        private:
        void resolveImpulse(fizzyx::collision::ICollisionData * collision, const float & dt);
        void resolveInterpenetration(fizzyx::collision::ICollisionData * collision, const float & dt);
        bool handleRestingContacts{false};
    };
}

#endif
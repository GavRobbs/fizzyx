#include <tutorial/simplelinearsolver.h>

using namespace fizzyx::tutorial;

void SimpleLinearSolver::solve(fizzyx::collision::ICollisionData * collision, float dt)
{
    resolveImpulse(collision, dt);
    resolveInterpenetration(collision, dt);
}

fizzyx::core::IPhysicsSolver * SimpleLinearSolver::clone()
{
    return new SimpleLinearSolver();
}

void SimpleLinearSolver::resolveImpulse(fizzyx::collision::ICollisionData * collision, const float & dt)
{
    float separatingVelocity = collision->getClosingVelocity() * -1.0f;

    if(separatingVelocity > 0.0f)
    {
        return;
    }

    float combinedRestitution =  0.5f * (collision->a->getPhysicsMaterial().restitution + collision->b->getPhysicsMaterial().restitution);
    float newSeparatingVelocity = -separatingVelocity * combinedRestitution;

    float deltaVelocity = newSeparatingVelocity - separatingVelocity;

    float totalInverseMass = collision->a->getInverseMass() + collision->b->getInverseMass();

    if(totalInverseMass <= 0.0f)
    {
        return;
    }

    float impulse = deltaVelocity / totalInverseMass; //m * s^-1 * kg
    math::Vector2 impulsePerUnitInverseMass = impulse * collision->collisionNormal;

    collision->a->setVelocity(collision->a->getVelocity() + (impulsePerUnitInverseMass * collision->a->getInverseMass()));
    collision->b->setVelocity(collision->b->getVelocity() + (impulsePerUnitInverseMass * collision->b->getInverseMass() * -1.0f));
}
        
void SimpleLinearSolver::resolveInterpenetration(fizzyx::collision::ICollisionData * collision, const float & dt)
{
    if(collision->penetrationDepth <= 0.0f)
    {
        return;
    }

    float totalInverseMass = collision->a->getInverseMass() + collision->b->getInverseMass();

    if(totalInverseMass <= 0.0f)
    {
        return;
    }

    math::Vector2 movementPerInverseMass = collision->collisionNormal * collision->penetrationDepth / totalInverseMass;

    math::Vector2 pos_a = collision->a->getPosition();
    pos_a += movementPerInverseMass * collision->a->getInverseMass();
    collision->a->setPosition(pos_a);

    math::Vector2 pos_b = collision->b->getPosition();
    pos_b += movementPerInverseMass * collision->b->getInverseMass() * -1.0f;
    collision->b->setPosition(pos_b);
}

void SimpleLinearSolver::enableRestingContactResolution()
{
    handleRestingContacts = true;
}

void SimpleLinearSolver::disableRestingContactResolution()
{
    handleRestingContacts = false;
}